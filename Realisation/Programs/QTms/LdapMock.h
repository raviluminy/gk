#ifndef LDAPMOCK_H
#define LDAPMOCK_H

#include <QString>
#include <QWidget>

class LdapMock : public QWidget {

public:

	explicit LdapMock(QWidget* parent = 0);
	virtual ~LdapMock();

	bool authentification(const QString& uid, const QString& pwd);

	bool canAdd(const QString& uid,const QString& tableName);

	bool canDelete(const QString& uid,const QString& tableName);

	bool canRead(const QString& uid,const QString& tableName,const QString& fieldName);

	bool canWrite(const QString& uid, const QString& tableName, const QString& fieldName);

	bool connection(const QString& hostname, const int port);

};

#endif // LDAPMOCK_H
