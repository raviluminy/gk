#include "Directory.h"

using namespace std;

Directory::Directory(QWidget* parent) :
	QWidget(parent) {
}

Directory::~Directory() {
}

bool
Directory::initialize(const QString& hostname, const int port) {
	return con.connection(hostname, port);
}

bool
Directory::chercheField(char* str, const QString& str2){
	bool found = false;
	char * pch;
	pch = strtok (str,"("); // on enleve le nom de la Table
	pch = strtok (NULL,",)"); // on commence avec les attributs

	while (pch != NULL && !found) {
		found = (str2.compare(pch) == 0);
		pch = strtok (NULL,",)");
	}
	return found;
	}

int
Directory::chercheTab(const StringList& str, const QString& str2) {
    int found = -1;
    char** chaine = str.toCharArray();
    char * pch;
    // recherche approfondie
    for (int var = 0; (var < str.size()) && (found == -1 ); ++var) {
        pch = strtok (chaine[var],"(");

        if((pch != NULL) && (str2.compare(pch) == 0)){
            found = var;
        }

        delete pch;
    }
    delete chaine;
    return found;
}


bool
Directory::authentification(const QString& uid, const QString& pwd) {
    bool found = false;
    entries = con.search(BASEDN,LDAPConnection::SEARCH_SUB,"uid="+uid);

    if(entries != NULL){
        entry = con.get_first_entry(entries);
        found = con.bind(con.get_dn_entry(entry),pwd);

        ldap_msgfree( entries );
    }
    return found;
}

bool
Directory::canAdd(const QString& uid, const QString& tableName) {

    bool found = false;
    entries = con.search(BASEDN,LDAPConnection::SEARCH_SUB,"uid="+uid);
    //il existe une personne avec cet uid
    if(entries != NULL){
        entry = con.get_first_entry(entries);
        // liste de droits permis
        StringList liste = con.get_attribute_by_name_values(entry,A_TABLE_ADD);
        if(!liste.empty()){
            if(chercheTab(liste,tableName) != -1){
                found = true;
            }
        } else {
            // liste de droits non permis
            liste = con.get_attribute_by_name_values(entry,R_TABLE_ADD);
            if(chercheTab(liste,tableName) == -1){
                found = true;
            }
        }

        ldap_msgfree( entries );
    }
    return found;
}

bool
Directory::canDelete(const QString& uid, const QString& tableName) {
    bool found = false;
    entries = con.search(BASEDN,LDAPConnection::SEARCH_SUB,"uid="+uid);
    if(entries != NULL){
        entry = con.get_first_entry(entries);

        StringList liste = con.get_attribute_by_name_values(entry,A_TABLE_DELETE);
        if(!liste.empty()){
            if(chercheTab(liste,tableName) != -1){
                found = true;
            }
        } else {

            liste = con.get_attribute_by_name_values(entry,R_TABLE_DELETE);
            if(chercheTab(liste,tableName) == -1){
                found = true;
            }
        }

        ldap_msgfree( entries );
    }

    return found;
}

bool
Directory::canRead(const QString& uid, const QString& tableName, const QString& fieldName){
    bool found = false;
    entries = con.search(BASEDN,LDAPConnection::SEARCH_SUB,"uid="+uid);
    if(entries != NULL){
        entry = con.get_first_entry(entries);
        // les droits permis
        StringList liste = con.get_attribute_by_name_values(entry,A_FIELD_READ);

        int index = chercheTab(liste,tableName);
        //si on trouve la table parmi les permis
        if(index != -1){
            const QString table (liste.toCharArray()[index]);
            //si n'est pas une table avec aucun droits
            if (!(table.compare(tableName+"()") == 0)) {
                found = chercheField(liste.toCharArray()[index],fieldName) ;
            }

        }

        if(!found){
            //les interdits
            liste = con.get_attribute_by_name_values(entry,R_FIELD_READ);
            index = chercheTab(liste,tableName);
            if(index != -1){
                const QString  table (liste.toCharArray()[index]);
                // si rien n'est interdit alors il a tous les droits
                if ((table.compare(tableName+"()") == 0)) {
                    found = true;
                } else {
                    // si non c'est interdit
                    found = !(chercheField(liste.toCharArray()[index],fieldName)) ;
                }
            }
        }
        ldap_msgfree( entries );
    }
    return found;
}

bool
Directory::canWrite(const QString& uid, const QString& tableName, const QString& fieldName) {
    bool found = false;
	entries = con.search(BASEDN, LDAPConnection::SEARCH_SUB, "uid=" + uid);

	if (entries != NULL) {
        entry = con.get_first_entry(entries);
        StringList liste = con.get_attribute_by_name_values(entry,A_FIELD_WRITE);
        int index = chercheTab(liste,tableName);
		if (index != -1) {
            const QString  table (liste.toCharArray()[index]);
            if (!(table.compare(tableName+"()") == 0)) {
                found = chercheField(liste.toCharArray()[index],fieldName) ;
            }
        }
		if (!found) {
            liste = con.get_attribute_by_name_values(entry,R_FIELD_WRITE);
            index = chercheTab(liste,tableName);
			if (index != -1) {
                const QString  table (liste.toCharArray()[index]);
                // si rien n'est interdit alors il a tous les droits
                if ((table.compare(tableName+"()") == 0)) {
                    found = true;
                } else {
                    // si non c'est interdit
                    found = !(chercheField(liste.toCharArray()[index],fieldName)) ;
                }
            }
        }
        ldap_msgfree( entries );
    }
    return found;
}
