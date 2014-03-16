#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QtSql>
#include <QSqlTableModel>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	/**
	 * Test simple de Dao par model
	 */
	// On défini des constances pour simplifier l'utilisation des indices de colonne.
	enum {
		REQUISITION_ID = 0,
		REQUISITION_COUNTRY_CODE,
		REQUISITION_FOR_COST_ESTIMATE,
		REQUISITION_FOR_PURCHASE,
		REQUISITION_WH_DISPATCH_RELEASE,
		REQUISITION_DATE,
		REQUISITION_DESIRED_DELIVERY_DATE,
		REQUISITION_TRANSPORT_MEANS,
		REQUISITION_ORIGIN_LOCALISATION_ID,
		REQUISITION_DESTINATION_LOCALISATION_ID,
		REQUISITION_CURRENCY_ID,
		REQUISITION_FINANCE_OFFICER_AGREEMENT_DATE,
		REQUISITION_FINANCE_OFFICER_PERSON_ID,
		REQUISITION_MANAGER_AGREEMENT_DATE,
		REQUISITION_MANAGER_PERSON_ID,
		REQUISITION_REQUESTER_AGREEMENT_DATE,
		REQUISITION_REQUESTER_PERSON_ID,
		REQUISITION_LOGISTICS_AGREEMENT_DATE,
		REQUISITION_LOGISTICS_PERSON_ID,
		REQUISITION_GLOBAL_FLEET_BASE_AGREEMENT_DATE,
		REQUISITION_GLOBAL_FLEET_BASE_PERSON_ID
	};

	ui->setupUi(this);

	QString dbDriver = "QMYSQL";
	QString dbHostName = "localhost";
	QString dbName = "gklogistic";
	QString dbUserName = "root";
	QString dbPassword = "";

	QSqlDatabase* db = new QSqlDatabase();

	bool hasDriver = db && db->drivers().indexOf(dbDriver) > -1;
	if (!hasDriver) {
		qDebug() << dbDriver << " driver unavailable.";
		return;
	}
	qDebug() << dbDriver << " driver located.";
	db->addDatabase(dbDriver);
	db->setHostName(dbHostName);
	db->setDatabaseName(dbName);
	db->setUserName(dbUserName);
	db->setPassword(dbPassword);
	if (!db->open()) {
		qDebug() << db->lastError().text();
		db->close();
		return;
	}
	qDebug() << "Successfully connected to database '" << db->databaseName() << "'.";
	// do something...
#if 0
	QSqlTableModel* model = new QSqlTableModel(this);
	model->setTable("Requisition");
	model->setSort(REQUISITION_ID, Qt::AscendingOrder); // Définition du critère de tri
	model->setHeaderData(REQUISITION_ID, Qt::Horizontal, "ID"); // Définition de l'entête
	model->select();

	ui->tableView->setModel(model); // Liaison entre le modèle et le tableau
	ui->tableView->setColumnHidden(REQUISITION_ID, true); // On masque la colonne des identifiants
	ui->tableView->resizeColumnsToContents(); // On redimentionne les colonnes en fonction de leurs contenu
#endif
	db->close();
	return;
}

MainWindow::~MainWindow() {
	delete ui;
}
