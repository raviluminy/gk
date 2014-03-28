#include "LdapTest.h"

#include <QString>
#include <QtTest>
#include <QtWidgets>

LdapTest::LdapTest(QWidget* parent) :
	Directory(parent) {
    lm.initialize(QString("10.42.0.20"),389);
}

LdapTest::~LdapTest() {
}

void
LdapTest::testConnection() {
    QVERIFY(lm.initialize(QString("10.42.0.20"), 389));
}

void
LdapTest::testConnectionBadHostname() {
	QEXPECT_FAIL("", "unknow hostname", Continue);
	QVERIFY(lm.initialize(QString("toto"), 389));
}

void
LdapTest::testConnectionBadPort() {
	QEXPECT_FAIL("", "unknow port number", Continue);
    QVERIFY(lm.initialize(QString("10.42.0.20"), 666));
}

void
LdapTest::testConnectionBadHostnameAndPort() {
	QEXPECT_FAIL("", "unknow hostname and port number", Continue);
	QVERIFY(lm.initialize(QString("toto"), 666));
}

void
LdapTest::testAuthentification() {
    lm.init_file_config();
	QVERIFY(lm.authentification(QString("biensuanga"), QString("biensuanga")));
}

void
LdapTest::testAuthentificationBadUid() {
    lm.init_file_config();
	QEXPECT_FAIL("", "bad login", Continue);
	QVERIFY(lm.authentification(QString("toto"), QString("nhyh")));
}

void
LdapTest::testAuthentificationBadPwd() {
    lm.init_file_config();
	QEXPECT_FAIL("", "bad password", Continue);
	QVERIFY(lm.authentification(QString("biensuanga"), QString("pwd")));
}

void
LdapTest::testAuthentificationBadUidAndPwd() {
    lm.init_file_config();
	QEXPECT_FAIL("", "bad login and password", Continue);
	QVERIFY(lm.authentification(QString("toto"), QString("titi")));
}

void
LdapTest::testCanRead() {
    lm.init_file_config();
    QVERIFY(lm.canRead(QString("biensuanga"), QString("Waybill"), QString("RequisitionId")));
}

void LdapTest::testCanReadGroup()
{
    lm.init_file_config();
    QVERIFY(lm.canRead(QString("khady"), QString("Provider"), QString("ProviderId")));
}

void LdapTest::testCanReadGroup2()
{
    lm.init_file_config();
    QEXPECT_FAIL("", "droit supprime à l'user", Continue);
    QVERIFY(lm.canRead(QString("lucien"), QString("Vehicle"), QString("VehicleId")));
}

void
LdapTest::testCanReadBadUid() {
    lm.init_file_config();
	QEXPECT_FAIL("", "bad login", Continue);
	QVERIFY(lm.canRead(QString("toto"), QString("Waybill"), QString("RequisitionId")));
}

void
LdapTest::testCanReadBadTableName() {
    lm.init_file_config();
	QEXPECT_FAIL("", "unknow table name", Continue);
	QVERIFY(lm.canRead(QString("biensuanga"), QString("avion"), QString("RequisitionId")));
}

void
LdapTest::testCanReadBadFieldName() {
    lm.init_file_config();
	QEXPECT_FAIL("", "unknow Field name", Continue);
	QVERIFY(lm.canRead(QString("biensuanga"), QString("Waybill"), QString("waybillColor")));
}

void
LdapTest::testCanWrite() {
    lm.init_file_config();
    QVERIFY(lm.canWrite(QString("biensuanga"), QString("Requisition"), QString("waybillId")));
}

void
LdapTest::testCanWriteBadUid() {
    lm.init_file_config();
	QEXPECT_FAIL("", "bad login", Continue);
    QVERIFY(lm.canWrite(QString("toto"), QString("Requisition"), QString("waybillId")));
}

void
LdapTest::testCanWriteBadTableName() {
    lm.init_file_config();
	QEXPECT_FAIL("", "unknow table name", Continue);
	QVERIFY(lm.canWrite(QString("biensuanga"), QString("Avion"), QString("waybillId")));
}

void
LdapTest::testCanWriteBadFieldName() {
    lm.init_file_config();
	QEXPECT_FAIL("", "unknow field name", Continue);
    QVERIFY(lm.canWrite(QString("biensuanga"), QString("Requisition"), QString("PersonId_4")));
}

void
LdapTest::testCanAdd() {
    lm.init_file_config();
	QVERIFY(lm.canAdd(QString("biensuanga"), QString("Waybill")));
}

void
LdapTest::testCanAddBadUid() {
    lm.init_file_config();
	QEXPECT_FAIL("", "bad login", Continue);
	QVERIFY(lm.canAdd(QString("toto"), QString("Waybill")));
}

void
LdapTest::testCanAddBadTableName() {
    lm.init_file_config();
	QEXPECT_FAIL("", "unknow table name", Continue);
    QVERIFY(lm.canAdd(QString("biensuanga"), QString("Requisition")));
}

void
LdapTest::testCanDelete() {
    lm.init_file_config();
	QVERIFY(lm.canDelete(QString("biensuanga"), QString("Waybill")));
}

void
LdapTest::testCanDeleteBadUid() {
    lm.init_file_config();
	QEXPECT_FAIL("", "bad login", Continue);
	QVERIFY(lm.canDelete(QString("toto"), QString("Waybill")));
}

void
LdapTest::testCanDeleteBadTableName() {
    lm.init_file_config();
	QEXPECT_FAIL("", "unknow table name", Continue);
    QVERIFY(lm.canDelete(QString("biensuanga"), QString("Requisition")));
}

void
LdapTest::cleanupTestCase() {
}

void
LdapTest::initTestCase() {
}
