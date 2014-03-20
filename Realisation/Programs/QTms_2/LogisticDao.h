#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <QtSql>

enum ErrorCode {
	NoneSqlDriverLoaded,
	FailedOpeningConnection
};

class LogisticDao {
public:

	LogisticDao();

	virtual ~LogisticDao();

	void load();

	void save();

	void connect();

	void disconnect();

	void checkDriver();

	void checkExistance();

	void checkOpenConnection();

	QAbstractItemModel* waybillModel();
	QAbstractItemModel* activedWaybillModel(const int id);

private:

	QString dbDriver;
	QString dbHostPort;
	QString dbHostName;
	QString dbName;
	QString dbUserName;
	QString dbUserPassword;

	QSqlTableModel* dbWaybillModel;
	QSqlTableModel* dbActivedWaybillModel;

	QSqlDatabase db;

};

#endif // SETTINGS_H
