#include "LogisticDao.h"

#include <QSettings>
#include <QtDebug>

LogisticDao::LogisticDao() {
}

LogisticDao::~LogisticDao() {
}

void
LogisticDao::load() {
	QSettings settings("Logistic.DB.ini", QSettings::IniFormat);
	settings.beginGroup("DB");
	dbDriver       = settings.value("Driver")      .toString();
	dbHostName     = settings.value("HostName")    .toString();
	dbHostPort     = settings.value("HostPort")    .toString();
	dbName         = settings.value("Name")        .toString();
	dbUserName     = settings.value("UserName")    .toString();
	dbUserPassword = settings.value("UserPassword").toString();
	settings.endGroup();
}

void
LogisticDao::save() {
	QSettings settings("Logistic.DB.ini", QSettings::IniFormat);
	settings.beginGroup("DB");
	settings.setValue("Driver",       dbDriver);
	settings.setValue("HostName",     dbHostName);
	settings.setValue("HostPort",     dbHostPort);
	settings.setValue("Name",         dbName);
	settings.setValue("UserName",     dbUserName);
	settings.setValue("UserPassword", dbUserPassword);
	settings.endGroup();
}

void
LogisticDao::checkDriver() {
	if (db.drivers().contains(dbDriver)) return;
	qDebug() << "DAO:" << dbDriver << "is unavailable.";
	qCritical() << "DAO: None SQL driver found. The application will terminate.";
	exit(NoneSqlDriverLoaded);
}

void
LogisticDao::checkExistance() {
	if (QFile(dbName).exists()) return;
	//createDb();
}

void
LogisticDao::checkOpenConnection() {
	if (db.open()) return;
	qDebug() << "DAO: fail to opening connection with" << dbName << ".";
	qDebug() << "DAO:" << db.lastError().text();
	qCritical() << "DAO: Impossible to connect the database. The application will terminate.";
	exit(FailedOpeningConnection);
}

void
LogisticDao::connect() {
	load();
	checkDriver();
	db = QSqlDatabase::addDatabase(dbDriver);
	db.setDatabaseName(dbName);
	db.setUserName(dbUserName);
	db.setPassword(dbUserPassword);
	checkExistance();
	checkOpenConnection();

	dbWaybillModel = new QSqlTableModel();
	dbWaybillModel->setTable("Waybill");
	dbWaybillModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	dbWaybillModel->select();

	dbActivedWaybillModel = 0;
}

void
LogisticDao::disconnect() {
	db.close();
	save();
}

QAbstractItemModel*
LogisticDao::waybillModel() {
	return dbWaybillModel;
}

QAbstractItemModel*
LogisticDao::activedWaybillModel(const int id) {
	dbActivedWaybillModel = new QSqlTableModel();
	dbActivedWaybillModel->setTable("Waybill");
	dbActivedWaybillModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	dbActivedWaybillModel->setFilter(QString("id=%1").arg(id));
	dbActivedWaybillModel->select();
	return dbActivedWaybillModel;
}

