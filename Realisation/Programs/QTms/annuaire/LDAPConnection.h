
#ifndef LDAP_CONNECTION_H
#define LDAP_CONNECTION_H

#include "StringList.h"
#include <ldap.h>
#include <iostream>
#include <sstream>

/
class LDAPConnection {

    public :
         /** 
         * Constant for the Search-Operation to indicate a Base-Level
         * Search
         */
        static const int SEARCH_BASE=0;
        
        /** 
         * Constant for the Search-Operation to indicate a One-Level
         * Search
         */
        static const int SEARCH_ONE=1;
        
        /** 
         * Constant for the Search-Operation to indicate a subtree 
         * Search
         */
        static const int SEARCH_SUB=2;
        
        /** This Constructor initializes synchronous LDAP-Connection 
         * 
         * During execution of this constructor no network communication
         * is performed. Just some internal data structure are initialized
         * @param hostname Name (or IP-Adress) of the destination host
         * @param port Port the LDAP server is running on
         * @param cons Default constraints to use with operations over 
         *      this connection
         */
        LDAPConnection(const std::string& hostname="localhost", int port=389);
        
        /**
         * Destructor
         */
        ~LDAPConnection();
        
        /** 
         * Initzializes a synchronous connection to a server. 
         * 
         * There is actually no
         * communication to the server. Just the object is initialized
         * (e.g. this method is called within the 
         * LDAPConnection(char*,int,LDAPConstraints) constructor.)
         * @param hostname  The Name or IP-Address of the destination
         *             LDAP-Server
         * @param port      The Network Port the server is running on
         */
        void init(const std::string& hostname, int port);

        /** 
         * Performs a simple authentication with the server
         *
         * @throws LDAPReferralException if a referral is received
         * @throws LDAPException for any other error occuring during the
         *              operation
         * @param dn    The name of the entry to bind as
         * @param passwd    The cleartext password for the entry
         */
        bool bind(const std::string& dn="", const std::string& passwd="");

        /**
         * Performs the UNBIND-operation on the destination server
         * 
         * @throws LDAPException in any case of an error
         */
        void unbind();
        /**
         * @brief get_first_entry renvoi le premier element des entrees
         * @param result la liste d'entrees
         * @return renvoi le premier element des entrees
         */
        LDAPMessage * get_first_entry(LDAPMessage *result);
        /**
         * @brief get_next_entry le suivant
         * @param result la liste d'entrees
         * @return renvoi le suivant element des entrees
         */
        LDAPMessage * get_next_entry(LDAPMessage *result);
        /**
         * @brief get_dn_entry le dn de l'entree
         * @param entry l'entree
         * @return le dn
         */
        std::string get_dn_entry(LDAPMessage *entry);
        /**
         * @brief get_attribute_by_name_values  liste d'attributs
         * @param entry l'entree
         * @param attributeName l'attribut recherché
         * @return une liste d'attributs
         */
        StringList get_attribute_by_name_values(LDAPMessage *entry, std::string attributeName);
        

        /**
         * This method can be used for the sync. SEARCH-operation.
         *
         * @throws LDAPReferralException if a referral is received
         * @throws LDAPException for any other error occuring during the
         *              operation
         * @param base The distinguished name of the starting point for the
         *      search
         * @param scope The scope of the search. Possible values: <BR> 
         *      LDAPAsynConnection::SEARCH_BASE, <BR> 
         *      LDAPAsynConnection::SEARCH_ONE, <BR>
         *      LDAPAsynConnection::SEARCH_SUB
         * @param filter The std::string representation of a search filter to
         *      use with this operation
         * @param attrsOnly true if only the attributes names (no values) 
         *      should be returned
         * @param cons A set of constraints that should be used with this
         *      request
         * @returns A pointer to a LDAPSearchResults-object that can be
         *      used to read the results of the search.
         */
        LDAPMessage* search(const std::string& base, int scope=0, 
                const std::string& filter="objectClass=*", 
                const StringList& attrs=StringList());
       
        const std::string& getHost() const;

        int getPort() const;
        
                        
	private:
        int m_port;
        std::string m_host;
        LDAP     *dir;
};

#endif //LDAP_CONNECTION_H
