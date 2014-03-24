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

	void connect();

	void disconnect();

	void load();

	void save();

	QAbstractItemModel* model(const QString& tablename);

	QAbstractItemModel* providerModel();

	QAbstractItemModel* requisitionModel();

	QAbstractItemModel* staffModel();

	QAbstractItemModel* vehicleModel();

	QAbstractItemModel* waybillModel();

private:

	void checkDriver();

	void checkExistance();

	void checkOpenConnection();

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
