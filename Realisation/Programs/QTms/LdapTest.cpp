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
    lm.initialize(QString("10.42.0.20"), 389);
	QVERIFY(lm.authentification(QString("biensuanga"), QString("biensuanga")));
}

void
LdapTest::testAuthentificationBadUid() {
    lm.initialize(QString("10.42.0.20"), 389);
	QEXPECT_FAIL("", "bad login", Continue);
	QVERIFY(lm.authentification(QString("toto"), QString("nhyh")));
}

void
LdapTest::testAuthentificationBadPwd() {
    lm.initialize(QString("10.42.0.20"), 389);
	QEXPECT_FAIL("", "bad password", Continue);
	QVERIFY(lm.authentification(QString("biensuanga"), QString("pwd")));
}

void
LdapTest::testAuthentificationBadUidAndPwd() {
    lm.initialize(QString("10.42.0.20"), 389);
	QEXPECT_FAIL("", "bad login and password", Continue);
	QVERIFY(lm.authentification(QString("toto"), QString("titi")));
}

void
LdapTest::testCanRead() {
    lm.initialize(QString("10.42.0.20"), 389);
    QVERIFY(lm.canRead(QString("biensuanga"), QString("Waybill"), QString("RequisitionId")));
}

void LdapTest::testCanReadGroup()
{
    lm.initialize(QString("10.42.0.20"), 389);
    QVERIFY(lm.canRead(QString("khady"), QString("Provider"), QString("ProviderId")));
}

void LdapTest::testCanReadGroup2()
{
    lm.initialize(QString("10.42.0.20"), 389);
    QEXPECT_FAIL("", "droit supprime à l'user", Continue);
    QVERIFY(lm.canRead(QString("lucien"), QString("Vehicle"), QString("VehicleId")));
}

void
LdapTest::testCanReadBadUid() {
    lm.initialize(QString("10.42.0.20"), 389);
	QEXPECT_FAIL("", "bad login", Continue);
	QVERIFY(lm.canRead(QString("toto"), QString("Waybill"), QString("RequisitionId")));
}

void
LdapTest::testCanReadBadTableName() {
    lm.initialize(QString("10.42.0.20"), 389);
	QEXPECT_FAIL("", "unknow table name", Continue);
	QVERIFY(lm.canRead(QString("biensuanga"), QString("avion"), QString("RequisitionId")));
}

void
LdapTest::testCanReadBadFieldName() {
    lm.initialize(QString("10.42.0.20"), 389);
	QEXPECT_FAIL("", "unknow Field name", Continue);
	QVERIFY(lm.canRead(QString("biensuanga"), QString("Waybill"), QString("waybillColor")));
}

void
LdapTest::testCanWrite() {
    lm.initialize(QString("10.42.0.20"), 389);
    QVERIFY(lm.canWrite(QString("biensuanga"), QString("Requistion"), QString("waybillId")));
}

void
LdapTest::testCanWriteBadUid() {
    lm.initialize(QString("10.42.0.20"), 389);
	QEXPECT_FAIL("", "bad login", Continue);
	QVERIFY(lm.canWrite(QString("toto"), QString("Requistion"), QString("waybillId")));
}

void
LdapTest::testCanWriteBadTableName() {
    lm.initialize(QString("10.42.0.20"), 389);
	QEXPECT_FAIL("", "unknow table name", Continue);
	QVERIFY(lm.canWrite(QString("biensuanga"), QString("Avion"), QString("waybillId")));
}

void
LdapTest::testCanWriteBadFieldName() {
    lm.initialize(QString("10.42.0.20"), 389);
	QEXPECT_FAIL("", "unknow field name", Continue);
	QVERIFY(lm.canWrite(QString("biensuanga"), QString("Requistion"), QString("PersonId_4")));
}

void
LdapTest::testCanAdd() {
    lm.initialize(QString("10.42.0.20"), 389);
	QVERIFY(lm.canAdd(QString("biensuanga"), QString("Waybill")));
}

void
LdapTest::testCanAddBadUid() {
    lm.initialize(QString("10.42.0.20"), 389);
	QEXPECT_FAIL("", "bad login", Continue);
	QVERIFY(lm.canAdd(QString("toto"), QString("Waybill")));
}

void
LdapTest::testCanAddBadTableName() {
    lm.initialize(QString("10.42.0.20"), 389);
	QEXPECT_FAIL("", "unknow table name", Continue);
	QVERIFY(lm.canAdd(QString("biensuanga"), QString("Requistion")));
}

void
LdapTest::testCanDelete() {
    lm.initialize(QString("10.42.0.20"), 389);
	QVERIFY(lm.canDelete(QString("biensuanga"), QString("Waybill")));
}

void
LdapTest::testCanDeleteBadUid() {
    lm.initialize(QString("10.42.0.20"), 389);
	QEXPECT_FAIL("", "bad login", Continue);
	QVERIFY(lm.canDelete(QString("toto"), QString("Waybill")));
}

void
LdapTest::testCanDeleteBadTableName() {
    lm.initialize(QString("10.42.0.20"), 389);
	QEXPECT_FAIL("", "unknow table name", Continue);
	QVERIFY(lm.canDelete(QString("biensuanga"), QString("Requistion")));
}

void
LdapTest::cleanupTestCase() {
}

void
LdapTest::initTestCase() {
}
