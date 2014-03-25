#include "LdapMock.h"

LdapMock::LdapMock(QWidget* parent) :
	QWidget(parent) {
}

LdapMock::~LdapMock() {
}

bool
LdapMock::authentification(const QString& uid, const QString& pwd) {
	return uid == QString("admin")
	  &&   pwd == QString("mickey");
}

bool
LdapMock::canAdd(const QString& uid, const QString& tableName) {
	return uid == QString("admin")
	  &&   tableName == QString("waybill");
}

bool
LdapMock::canDelete(const QString& uid, const QString& tableName) {
	return uid == QString("admin")
	  &&   tableName == QString("waybill");
}

bool
LdapMock::canRead(const QString& uid, const QString& tableName, const QString& fieldName) {
	return uid == QString("admin")
	  &&   tableName == QString("waybill")
	  &&   fieldName == QString("waybillId");
}

bool
LdapMock::canWrite(const QString& uid, const QString& tableName, const QString& fieldName) {
	return uid == QString("admin")
	  &&   tableName == QString("waybill")
	  &&   fieldName == QString("waybillId");
}

bool
LdapMock::connection(const QString& hostname, const int port) {
	return hostname == QString("localhost")
	  &&   port == 389;
}
