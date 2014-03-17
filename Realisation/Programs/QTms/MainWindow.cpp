#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QtDebug>
#include <QtSql>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	QHBoxLayout *horizontalLayout;
	QTableView *requisitionTableView;
	QTableView *waybillTableView;
	requisitionTableView = new QTableView(ui->centralWidget);
	waybillTableView = new QTableView(ui->centralWidget);
	horizontalLayout = new QHBoxLayout(ui->centralWidget);
	horizontalLayout->addWidget(requisitionTableView);
	horizontalLayout->addWidget(waybillTableView);

	QToolBar* requisitionToolBar = new QToolBar(ui->centralWidget);
	horizontalLayout->addWidget(requisitionToolBar);

	QAction* reqAdd = new QAction("Add", this);
	QAction* reqEdi = new QAction("Edit", this);
	QAction* reqRem = new QAction("Remove", this);
	requisitionToolBar->addActions(QList<QAction*>() << reqAdd << reqEdi << reqRem);

	connect(reqAdd, SIGNAL(triggered()), this, SLOT(addRequisition()));

	loadDbSettings();

	QSqlDatabase* db = new QSqlDatabase();

	bool hasDriver = db && db->drivers().indexOf(dbDriver) > -1;
	if (!hasDriver) {
		qDebug() << dbDriver << "driver unavailable.";
		return;
	}
	qDebug() << dbDriver << "driver located.";

	db2 = QSqlDatabase::addDatabase(dbDriver);
	db2.setHostName(dbHostName);
	db2.setDatabaseName(dbName);
	db2.setUserName(dbUserName);
	db2.setPassword(dbPassword);
	if (!db2.open()) {
		qDebug() << db2.databaseName() << "is not accessible.";
		qDebug() << db2.lastError().text();
		db2.close();
		return;
	}
	qDebug() << "Successfully connected to database" << QString("%1/%2").arg(db2.hostName()).arg(db2.databaseName()) << ".";
	// do something...

	requisitionTableView->setModel(requisitionModel()); // Liaison entre le modèle et le tableau
	//requisitionTableView->setColumnHidden(0, true); // On masque la colonne des identifiants
	requisitionTableView->resizeColumnsToContents(); // On redimentionne les colonnes en fonction de leurs contenu
	waybillTableView->setModel(waybillModel()); // Liaison entre le modèle et le tableau
	waybillTableView->resizeColumnsToContents(); // On redimentionne les colonnes en fonction de leurs contenu

}

MainWindow::~MainWindow()
{
	db2.close();
	delete ui;
}

void
MainWindow::addRequisition() {
	QSqlTableModel* model = reqModel;
	model->database().transaction();
	const int row = model->rowCount();
	model->insertRows(row, 1);
	model->setData(model->index(row, 0), row);
	model->setData(model->index(row, 1), "FR");
	model->setData(model->index(row, 8), row);
	model->setData(model->index(row, 9), row);
	if(model->submitAll()) {
			model->database().commit();
			qDebug() << QString("LOG INSERT REQUISITION %1 WITH 0=%1,1=%2,8=%1,9=%1")
						.arg(QString::number(row))
						.arg("FR");
		} else {
			model->database().rollback();
					qDebug() << "Database Write Error" <<
						 "The database reported an error: " <<
						   model->lastError().text();

		}
}

QSqlTableModel*
MainWindow::requisitionModel()
{
	QSqlTableModel* model = new QSqlTableModel(this);
	model->setTable("Requisition");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	//model->setSort(0, Qt::AscendingOrder); // Définition du critère de tri
	model->select();
	//model->setHeaderData(0, Qt::Horizontal, "ID");
	//model->setHeaderData(1, Qt::Horizontal, "Name");
	//model->setHeaderData(2, Qt::Horizontal, "Teacher");
	reqModel= model;
	return model;
}

QSqlTableModel*
MainWindow::waybillModel()
{
	QSqlTableModel* model = new QSqlTableModel(this);
	model->setTable("Waybill");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	//model->setSort(0, Qt::AscendingOrder); // Définition du critère de tri
	model->select();
	//model->setHeaderData(0, Qt::Horizontal, "ID");
	//model->setHeaderData(1, Qt::Horizontal, "Name");
	//model->setHeaderData(2, Qt::Horizontal, "Teacher");
	return model;
}

void
MainWindow::closeEvent(QCloseEvent* e) {
	saveDbSettings();
	e->accept();
}

void
MainWindow::loadDbSettings() {
	qDebug() << "loadDbSettings...";
	QSettings settings("Logistic.DB.ini", QSettings::IniFormat);
	settings.beginGroup("DB");
	dbDriver   = settings.value("Driver")  .toString();
	dbHostName = settings.value("HostName").toString();
	dbName     = settings.value("Name")    .toString();
	dbUserName = settings.value("UserName").toString();
	dbPassword = settings.value("Password").toString();
	settings.endGroup();
}

void
MainWindow::saveDbSettings() {
	qDebug() << "saveDbSettings...";
	QSettings settings("Logistic.DB.ini", QSettings::IniFormat);
	settings.beginGroup("DB");
	settings.setValue("Driver",   dbDriver);
	settings.setValue("HostName", dbHostName);
	settings.setValue("Name",     dbName);
	settings.setValue("UserName", dbUserName);
	settings.setValue("Password", dbPassword);
	settings.endGroup();
}

