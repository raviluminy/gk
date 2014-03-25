#ifndef LDAPTEST_H
#define LDAPTEST_H

#include "Util.h"
#include "Ldap/Directory.h"

class LdapTest : public Directory {

	Q_OBJECT

public:

	explicit LdapTest(QWidget* parent = 0);
	virtual ~LdapTest();

private slots:

    void testConnection();

	void testConnectionBadHostname();

	void testConnectionBadPort();

	void testConnectionBadHostnameAndPort();

	void testAuthentification();

	void testAuthentificationBadUid();

	void testAuthentificationBadPwd();

	void testAuthentificationBadUidAndPwd();

	void testCanRead();

    void testCanReadGroup();

    void testCanReadGroup2();

	void testCanReadBadUid();

	void testCanReadBadTableName();

	void testCanReadBadFieldName();

	void testCanWrite();

	void testCanWriteBadUid();

	void testCanWriteBadTableName();

	void testCanWriteBadFieldName();

	void testCanAdd();

	void testCanAddBadUid();

	void testCanAddBadTableName();

	void testCanDelete();

	void testCanDeleteBadUid();

	void testCanDeleteBadTableName();

	void cleanupTestCase();

	void initTestCase();

private:

	Directory lm;

};

#endif // LDAPTEST_H
