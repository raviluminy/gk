#include "LdapMock.h"


LdapMock::LdapMock(QWidget *parent) :
    QWidget(parent)
{

}

LdapMock::~LdapMock()
{

}

bool LdapMock::connection(const QString hostname, const int port)
{
    if (hostname==QString("localhost") && port == 389){
        return true;
    }
    return false;
}

bool LdapMock::authentification(const QString uid, const QString pwd)
{
    if (uid==QString("admin") && pwd == QString("mickey")){
        return true;
    }
    return false;
}

bool LdapMock::canRead(const QString uid, const QString tableName, const QString fieldName)
{
    if (uid==QString("admin") && tableName == QString("waybill") && fieldName == QString("waybillId")){
        return true;
    }
    return false;
}

bool LdapMock::canWrite(const QString uid, const QString tableName, const QString fieldName)
{
    if (uid==QString("admin") && tableName == QString("waybill") && fieldName == QString("waybillId")){
        return true;
    }
    return false;
}

bool LdapMock::canAdd(const QString uid, const QString tableName)
{
    if (uid==QString("admin") && tableName == QString("waybill")){
        return true;
    }
    return false;
}

bool LdapMock::canDelete(const QString uid, const QString tableName)
{
    if (uid==QString("admin") && tableName == QString("waybill")){
        return true;
    }
    return false;
}


