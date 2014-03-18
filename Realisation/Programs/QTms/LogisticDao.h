#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <QtSql>

class LogisticDao {
public:

	LogisticDao();

	virtual ~LogisticDao();

	void load();

	void save();

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

};

#endif // SETTINGS_H
