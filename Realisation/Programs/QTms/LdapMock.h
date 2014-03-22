#ifndef LDAPMOCK_H
#define LDAPMOCK_H
#include <QString>
#include <QWidget>

class LdapMock :public QWidget
{
public:
    explicit LdapMock(QWidget* parent = 0);
    ~LdapMock();


    bool connection(const QString hostname, const int port);
    /**
     */
    bool authentification(const QString uid, const QString pwd);
    /**
     */
    bool canRead(const QString uid,const QString tableName,const QString fieldName);
    /**
     */
    bool canWrite(const QString uid,const QString tableName,const QString fieldName);
    /**
     */
    bool canAdd(const QString uid,const QString tableName);
    /**
     */
    bool canDelete(const QString uid,const QString tableName);
private:


};

#endif // LDAPMOCK_H
