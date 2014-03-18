#include "LogisticDao.h"

LogisticDao::LogisticDao() {
	dbWaybillModel = new QSqlTableModel(this);
	dbWaybillModel->setTable("Waybill");
	dbWaybillModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	dbWaybillModel->select();

	dbActivedWaybillModel = 0;
}

LogisticDao::~LogisticDao() {
}

void
LogisticDao::load() {
	QSettings settings = QSettings("Logistic.DB.ini", QSettings::IniFormat);
	settings.beginGroup("DB");
	dbDriver       = settings.value("Driver");
	dbHostName     = settings.value("HostName");
	dbHostPort     = settings.value("HostPort");
	dbName         = settings.value("Name");
	dbUserName     = settings.value("UserName");
	dbUserPassword = settings.value("UserPassword");
	settings.endGroup();
}

void
LogisticDao::save() {
	QSettings settings = QSettings("Logistic.DB.ini", QSettings::IniFormat);
	settings.beginGroup("DB");
	settings.setValue("Driver",       dbDriver);
	settings.setValue("HostName",     dbHostName);
	settings.setValue("HostPort",     dbHostPort);
	settings.setValue("Name",         dbName);
	settings.setValue("UserName",     dbUserName);
	settings.setValue("UserPassword", dbUserPassword);
	settings.endGroup();
}

QAbstractItemModel*
LogisticDao::waybillModel() {
	return dbWaybillModel;
}

QAbstractItemModel*
LogisticDao::activedWaybillModel(const int id) {
	dbActivedWaybillModel = new QSqlTableModel(this);
	dbActivedWaybillModel->setTable("Waybill");
	dbActivedWaybillModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	dbActivedWaybillModel->setFilter(QString("id=%1").arg(id));
	dbActivedWaybillModel->select();
}

