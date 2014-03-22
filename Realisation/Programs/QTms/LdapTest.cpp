#include "LdapTest.h"
#include <QtWidgets>
#include <QtTest>


LdapTest::LdapTest(QWidget *parent):
    LdapMock(parent)
{

}

LdapTest::~LdapTest()
{

}

void LdapTest::testConnection()
{
    QVERIFY(lm.connection(QString("localhost"),389));
}

void LdapTest::testConnectionBadHostname()
{
    QEXPECT_FAIL("", "unknow hostname", Continue);
    QVERIFY(lm.connection(QString("toto"),389));
}

void LdapTest::testConnectionBadPort()
{
    QEXPECT_FAIL("", "unknow port number", Continue);
    QVERIFY(lm.connection(QString("localhost"),666));
}

void LdapTest::testConnectionBadHostnameAndPort()
{
    QEXPECT_FAIL("", "unknow hostname and port number", Continue);
    QVERIFY(lm.connection(QString("toto"),666));
}

void LdapTest::testAuthentification()
{
    QVERIFY(lm.authentification(QString("admin"),QString("mickey")));
}

void LdapTest::testAuthentificationBadUid()
{
    QEXPECT_FAIL("", "bad login", Continue);
    QVERIFY(lm.authentification(QString("toto"),QString("mickey")));
}

void LdapTest::testAuthentificationBadPwd()
{
    QEXPECT_FAIL("", "bad password", Continue);
    QVERIFY(lm.authentification(QString("admin"),QString("pwd")));
}

void LdapTest::testAuthentificationBadUidAndPwd()
{
    QEXPECT_FAIL("", "bad login and password", Continue);
    QVERIFY(lm.authentification(QString("toto"),QString("titi")));
}

void LdapTest::testCanRead()
{
    QVERIFY(lm.canRead(QString("admin"),QString("waybill"),QString("waybillId")));
}

void LdapTest::testCanReadBadUid()
{
    QEXPECT_FAIL("", "bad login", Continue);
    QVERIFY(lm.canRead(QString("toto"),QString("waybill"),QString("waybillId")));
}

void LdapTest::testCanReadBadTableName()
{
    QEXPECT_FAIL("", "unknow table name", Continue);
    QVERIFY(lm.canRead(QString("admin"),QString("avion"),QString("waybillId")));
}

void LdapTest::testCanReadBadFieldName()
{
    QEXPECT_FAIL("", "unknow Field name", Continue);
    QVERIFY(lm.canRead(QString("admin"),QString("waybill"),QString("waybillColor")));
}

void LdapTest::testCanWrite()
{
    QVERIFY(lm.canWrite(QString("admin"),QString("waybill"),QString("waybillId")));
}

void LdapTest::testCanWriteBadUid()
{
    QEXPECT_FAIL("", "bad login", Continue);
    QVERIFY(lm.canWrite(QString("toto"),QString("waybill"),QString("waybillId")));
}

void LdapTest::testCanWriteBadTableName()
{
    QEXPECT_FAIL("", "unknow table name", Continue);
    QVERIFY(lm.canWrite(QString("admin"),QString("Avion"),QString("waybillId")));
}

void LdapTest::testCanWriteBadFieldName()
{
    QEXPECT_FAIL("", "unknow field name", Continue);
    QVERIFY(lm.canWrite(QString("admin"),QString("waybill"),QString("capacity")));
}

void LdapTest::testCanAdd()
{
    QVERIFY(lm.canAdd(QString("admin"),QString("waybill")));
}

void LdapTest::testCanAddBadUid()
{
    QEXPECT_FAIL("", "bad login", Continue);
    QVERIFY(lm.canAdd(QString("toto"),QString("waybill")));
}

void LdapTest::testCanAddBadTableName()
{
    QEXPECT_FAIL("", "unknow table name", Continue);
    QVERIFY(lm.canAdd(QString("admin"),QString("avion")));
}

void LdapTest::testCanDelete()
{
    QVERIFY(lm.canDelete(QString("admin"),QString("waybill")));
}

void LdapTest::testCanDeleteBadUid()
{
    QEXPECT_FAIL("", "bad login", Continue);
    QVERIFY(lm.canDelete(QString("toto"),QString("waybill")));
}

void LdapTest::testCanDeleteBadTableName()
{
    QEXPECT_FAIL("", "unknow table name", Continue);
    QVERIFY(lm.canDelete(QString("admin"),QString("avion")));
}

void LdapTest::cleanupTestCase()
{

}

void LdapTest::initTestCase()
{

}
