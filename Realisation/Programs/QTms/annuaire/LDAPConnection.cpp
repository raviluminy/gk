#include "LDAPConnection.h"


using namespace std;

LDAPConnection::LDAPConnection(const string& hostname, int port){
	
	m_port = port;
	m_host = hostname;
    dir = ldap_init( const_cast<char*>(hostname.c_str()),port);
}

bool LDAPConnection::bind(const string& dn, const string& passwd){

   int result = ldap_simple_bind_s( dir, const_cast<char*>(dn.c_str()), const_cast<char*>(passwd.c_str()) );
   
   return (result == LDAP_SUCCESS);

}
void LDAPConnection::unbind(){
    ldap_unbind_s( dir );
}

LDAPConnection::~LDAPConnection() {
    ldap_unbind_s( dir );
}
/*
void LDAPConnection::start_tls(){
	int ret = ldap_start_tls_s( cur_session, NULL, NULL );
    if( ret != LDAP_SUCCESS ) {
        throw LDAPException("erreur TLS impossible de lancer");
    }
}
*/
const string& LDAPConnection::getHost() const{
	return m_host;
}

int LDAPConnection::getPort() const{
    return m_port;
}

/*
TlsOptions LDAPConnection::getTlsOptions() const {
	
}*/

LDAPMessage * LDAPConnection::search(const std::string &base, int scope, const std::string &filter, const StringList &attrs){
    LDAPMessage *searchResult;
    struct timeval timeOut = {10,0};
    char** tmpattrs = attrs.toCharArray();
    int rc = ldap_search_ext_s(dir,const_cast<char*>(base.c_str()),scope,
                           const_cast<char*>(filter.c_str()),tmpattrs,0,NULL,NULL,&timeOut,LDAP_NO_LIMIT,&searchResult );

    ldap_value_free( tmpattrs );

    if(rc == LDAP_SUCCESS){
        return searchResult;
    }
    return NULL;
}

LDAPMessage * LDAPConnection::get_first_entry(LDAPMessage *result){
    return ldap_first_entry( dir, result );
}

LDAPMessage * LDAPConnection::get_next_entry(LDAPMessage *result){
    return ldap_next_entry( dir, result );
}

std::string LDAPConnection::get_dn_entry(LDAPMessage *entry){
    return ldap_get_dn( dir, entry );
}

StringList LDAPConnection::get_attribute_by_name_values(LDAPMessage *entry, string attributeName){
    BerElement  *ber;
    char        *attribute;

    attribute = ldap_first_attribute(dir,entry,&ber);

    while ((attribute != NULL) && (attributeName.compare(attribute) != 0)) {
        attribute = ldap_next_attribute(dir,entry,ber);
    }

    if(attribute != NULL){
        return StringList(ldap_get_values( dir, entry, attribute ));
    }
    ber_free( ber, 0 );
    return StringList();
}
