#include "Directory.h"
#include <string.h>

using namespace std;

Directory::Directory(const string& hostname, int port) :
        LDAPConnection(hostname, port){
}

Directory::~Directory() {
}

bool Directory::chercheField(char* str, const std::string& str2){
    bool found = false;
    char * pch;
     pch = strtok (str,"("); //on enleve le nom de la Table
     pch = strtok (NULL,",)"); // on commence avec les attributs

     while (pch != NULL && !found) {

         found = (str2.compare(pch) == 0);

         pch = strtok (NULL,",)");
     }

    return found;
}

int Directory::chercheTab(const StringList& str,const std::string& str2){

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


bool Directory::authentification(const string &uid, const string &pwd){
    bool found = false;
    entries = search(BASEDN,LDAPConnection::SEARCH_SUB,"uid="+uid);

    if(entries != NULL){
        entry = get_first_entry(entries);
        found = bind(get_dn_entry(entry),pwd);

        ldap_msgfree( entries );
    }
    return found;
}

bool Directory::canAdd(const string &uid, const string &tableName){

    bool found = false;
    entries = search(BASEDN,LDAPConnection::SEARCH_SUB,"uid="+uid);
    //il existe une personne avec cet uid
    if(entries != NULL){
        entry = get_first_entry(entries);
        // liste de droits permis
        StringList liste = get_attribute_by_name_values(entry,A_TABLE_ADD);
        if(!liste.empty()){
            if(chercheTab(liste,tableName) != -1){
                found = true;
            }
        } else {
            // liste de droits non permis
            liste = get_attribute_by_name_values(entry,R_TABLE_ADD);
            if(chercheTab(liste,tableName) == -1){
                found = true;
            }
        }

        ldap_msgfree( entries );
     }
    return found;
}

bool Directory::canDelete(const string &uid, const string &tableName){
    bool found = false;
    entries = search(BASEDN,LDAPConnection::SEARCH_SUB,"uid="+uid);
    if(entries != NULL){
        entry = get_first_entry(entries);

        StringList liste = get_attribute_by_name_values(entry,A_TABLE_DELETE);
        if(!liste.empty()){
            std::cout << "-oui---- " << tableName << std::endl;
            if(chercheTab(liste,tableName) != -1){
                found = true;
            }
        } else {

            liste = get_attribute_by_name_values(entry,R_TABLE_DELETE);
            if(chercheTab(liste,tableName) == -1){
                found = true;
            }
        }

        ldap_msgfree( entries );
     }

    return found;
}

bool Directory::canRead(const string &uid, const string &tableName, const string &fieldName){
    bool found = false;

    entries = search(BASEDN,LDAPConnection::SEARCH_SUB,"uid="+uid);

    if(entries != NULL){
        entry = get_first_entry(entries);
        // les droits permis
        StringList liste = get_attribute_by_name_values(entry,A_FIELD_READ);

        int index = chercheTab(liste,tableName);
        //si on trouve la table parmi les permis
        if(index != -1){
            const std::string table (liste.toCharArray()[index]);
            //si n'est pas une table avec aucun droits
            if (!(table.compare(tableName+"()") == 0)) {
                found = chercheField(liste.toCharArray()[index],fieldName) ;
            }

        }

        if(!found){
            //les interdits
            liste = get_attribute_by_name_values(entry,R_FIELD_READ);
            index = chercheTab(liste,tableName);
            if(index != -1){
                const std::string table (liste.toCharArray()[index]);
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

bool Directory::canWrite(const string &uid, const string &tableName, const string &fieldName){
    bool found = false;

    entries = search(BASEDN,LDAPConnection::SEARCH_SUB,"uid="+uid);

    if(entries != NULL){
        entry = get_first_entry(entries);
        StringList liste = get_attribute_by_name_values(entry,A_FIELD_WRITE);

        int index = chercheTab(liste,tableName);
        if(index != -1){
            const std::string table (liste.toCharArray()[index]);

            if (!(table.compare(tableName+"()") == 0)) {
                found = chercheField(liste.toCharArray()[index],fieldName) ;
            }

        }

        if(!found){
            liste = get_attribute_by_name_values(entry,R_FIELD_WRITE);
            index = chercheTab(liste,tableName);
            if(index != -1){
                const std::string table (liste.toCharArray()[index]);
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
