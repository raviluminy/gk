#include "Directory.h"

#include <QSettings>
#include <QCoreApplication>
using namespace std;


Directory::Directory(QWidget *parent) : QWidget(parent){

}


bool Directory::initialize(const QString hostname, int port){
    return con.connection(hostname,port);
}

bool Directory::init_file_config(){

    QSettings settings("Ldap.ini", QSettings::IniFormat);
    settings.setUserIniPath(QCoreApplication::applicationDirPath());

    settings.beginGroup("LDAP");
    QString HostName  = settings.value("HostName").toString();
    int HostPort     = settings.value("HostPort").toInt();
    settings.endGroup();

    return con.connection(HostName,HostPort);
}

Directory::~Directory() {
}

bool Directory::chercheField(char* str, const QString str2){
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

int Directory::chercheTab(const StringList& str,const QString str2){

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


bool Directory::authentification(const QString uid, const QString pwd){
    bool found = false;
    entries = con.search(BASEDN,LDAPConnection::SEARCH_SUB,"uid="+uid);

    if(entries != NULL){
        entry = con.get_first_entry(entries);
        found = con.bind(con.get_dn_entry(entry),pwd);

        //ldap_msgfree( entries );
    }
    return found;
}

bool Directory::foundTable(LDAPMessage *msg, const QString tableName, const QString CAS1, const QString CAS2, int *pass){
    *pass = 0;
    bool found = false;

    // liste de droits permis
    StringList liste = con.get_attribute_by_name_values(msg,CAS1);
    if(!liste.empty()){
        *pass = 1;
        if(chercheTab(liste,tableName) != -1){
            found = true;
        }
    } else {
        // liste de droits non permis
        liste = con.get_attribute_by_name_values(msg,CAS2);
        if(!liste.empty()){
            if(chercheTab(liste,tableName) == -1){
                // on n'a pas trouve l'interdition, on doit continuer
                *pass = 1;
                found = true;
            }
        }
    }
    return found;
}

bool Directory::canAdd(const QString uid, const QString tableName){

    bool found = false;
    int pass;
    entries = con.search(BASEDN,LDAPConnection::SEARCH_SUB,"uid="+uid);

    if(entries != NULL){
        //il existe une personne avec cet uid
        entry = con.get_first_entry(entries);

        if(entry != NULL){
            found = foundTable(entry,tableName,A_TABLE_ADD,R_TABLE_ADD,&pass);

            // si on n'a pas les droits sur l'entre, on regarde alors les groupes
            if(pass == 0){

                found = false;      // on remet à false pour le nouveau test
                StringList liste = con.get_attribute_by_name_values(entry,"ou");
                int taille = liste.size();
                char** tmpgrp = liste.toCharArray();

                for (int var = 0; (var < taille) && !found; ++var) {
                    entries = con.search(BASEDN,LDAPConnection::SEARCH_SUB,"cn="+QString (tmpgrp[var]));
                    entry = con.get_first_entry(entries);

                    // recherche approfondit pour un groupe
                    while ((entry != NULL)  && !found) {
                        found = foundTable(entry,tableName,A_TABLE_ADD,R_TABLE_ADD,&pass);
                        entry = con.get_next_entry(entries);
                    }

                }
                //ldap_value_free( tmpgrp );
            }

        }
    }

    return found;
}

bool Directory::canDelete(const QString uid, const QString tableName){
    bool found = false;
    int pass;
    entries = con.search(BASEDN,LDAPConnection::SEARCH_SUB,"uid="+uid);

    if(entries != NULL){
        entry = con.get_first_entry(entries);

        if(entry != NULL){
            found = foundTable(entry,tableName,A_TABLE_DELETE,R_TABLE_DELETE,&pass);

            // si on n'a pas les droits sur l'entre, on regarde alors les groupes
            if(pass == 0){

                found = false;      // on remet à false pour le nouveau test
                StringList liste = con.get_attribute_by_name_values(entry,"ou");
                int taille = liste.size();
                char** tmpgrp = liste.toCharArray();

                for (int var = 0; (var < taille) && !found; ++var) {
                    entries = con.search(BASEDN,LDAPConnection::SEARCH_SUB,"cn="+QString (tmpgrp[var]));
                    entry = con.get_first_entry(entries);

                    // recherche approfondit pour un groupe
                    while ((entry != NULL)  && !found) {
                        found = foundTable(entry,tableName,A_TABLE_DELETE,R_TABLE_DELETE,&pass);
                        entry = con.get_next_entry(entries);
                    }

                }
                //ldap_value_free( tmpgrp );
            }
        }
        //ldap_msgfree( entries );
    }


    return found;
}

bool Directory::foundField(LDAPMessage *msg, const QString tableName, const QString fieldName,
                           const QString CAS1, const QString CAS2,int *pass){
    *pass = 0;
    bool found = false;
    // les droits permis
    StringList liste = con.get_attribute_by_name_values(msg,CAS1);

    int index = chercheTab(liste,tableName);
    //si on trouve la table parmi les permis
    if(index != -1){
        const QString table (liste.toCharArray()[index]);

        *pass = 1; // on a trouvé la table
        //si n'est pas une table avec aucun droits
        if (!(table.compare(tableName+"()") == 0)) {
            found = chercheField(liste.toCharArray()[index],fieldName) ;
        }

    }

    if(!found){
        //les interdits
        liste = con.get_attribute_by_name_values(msg,CAS2);
        index = chercheTab(liste,tableName);
        if(index != -1){
            const QString table (liste.toCharArray()[index]);
            *pass = 1; // on a trouvé la table
            // si rien n'est interdit alors il a tous les droits
            if ((table.compare(tableName+"()") == 0)) {
                found = true;
            } else {
                // si non c'est interdit
                found = !(chercheField(liste.toCharArray()[index],fieldName)) ;
            }
        }
    }
    return found;
}

bool Directory::canRead(const QString uid, const QString tableName, const QString fieldName){
    bool found = false;
    int pass;
    entries = con.search(BASEDN,LDAPConnection::SEARCH_SUB,"uid="+uid);

    if(entries != NULL){
        entry = con.get_first_entry(entries);

        if(entry != NULL){
            found = foundField(entry,tableName,fieldName,A_FIELD_READ,R_FIELD_READ,&pass);

            // si on n'a pas les droits sur l'entre, on regarde alors les groupes

            if(pass == 0){
                found = false;      // on remet à false pour le nouveau test
                StringList liste = con.get_attribute_by_name_values(entry,"ou");
                int taille = liste.size();
                char** tmpgrp = liste.toCharArray();
                for (int var = 0; (var < taille) && !found; ++var) {
                    entries = con.search(BASEDN,LDAPConnection::SEARCH_SUB,"cn="+QString (tmpgrp[var]));
                    entry = con.get_first_entry(entries);

                    // recherche approfondit pour un groupe
                    while ((entry != NULL)  && !found) {
                        found = foundField(entry,tableName,fieldName,A_FIELD_READ,R_FIELD_READ,&pass);
                        entry = con.get_next_entry(entries);
                    }

                }
                //ldap_value_free( tmpgrp );
            }
        }
        //ldap_msgfree( entries );

    }

    return found;
}

bool Directory::canWrite(const QString uid, const QString tableName, const QString fieldName){
    bool found = false;
    int pass;
    entries = con.search(BASEDN,LDAPConnection::SEARCH_SUB,"uid="+uid);

    if(entries != NULL){
        entry = con.get_first_entry(entries);

        if(entry != NULL){
            found = foundField(entry,tableName,fieldName,A_FIELD_WRITE,R_FIELD_WRITE,&pass);

            // si on n'a pas les droits sur l'entre, on regarde alors les groupes
            if(pass == 0){
                found = false;      // on remet à false pour le nouveau test
                StringList liste = con.get_attribute_by_name_values(entry,"ou");
                int taille = liste.size();
                char** tmpgrp = liste.toCharArray();

                for (int var = 0; (var < taille) && !found; ++var) {
                    entries = con.search(BASEDN,LDAPConnection::SEARCH_SUB,"cn="+QString (tmpgrp[var]));
                    entry = con.get_first_entry(entries);

                    // recherche approfondit pour un groupe
                    while ((entry != NULL)  && !found) {
                        found = foundField(entry,tableName,fieldName,A_FIELD_WRITE,R_FIELD_WRITE,&pass);
                        entry = con.get_next_entry(entries);
                    }

                }
                //ldap_value_free( tmpgrp );
            }
        }
    }

    return found;
}
