#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QFile>

void
MainWindow::loadTheme(const QString& name) {
	QFile css("Theme/" + name + "/main.css");
	if (css.open(QIODevice::ReadOnly)) {
		qApp->setStyleSheet(css.readAll());
		css.close();
	}
}

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	theme("Web"),
	ui(new Ui::MainWindow) {
	ui->setupUi(this);
	connect(ui->signInAction,  SIGNAL(triggered()), this, SLOT(onSignIn()));
	connect(ui->signOutAction, SIGNAL(triggered()), this, SLOT(onSignOut()));
	setWindowFlags(Qt::Window); // | Qt::FramelessWindowHint); permet de supprimer les contours de fenetre
	loadTheme(theme);
	dao.connect();
	ui->providerTab   ->setModel(dao.providerModel());
	ui->requisitionTab->setModel(dao.requisitionModel());
	ui->staffTab      ->setModel(dao.staffModel());
	ui->vehicleTab    ->setModel(dao.vehicleModel());
	ui->waybillTab    ->setModel(dao.waybillModel());
	ui->providerTab   ->setTheme(theme);
	ui->requisitionTab->setTheme(theme);
	ui->staffTab      ->setTheme(theme);
	ui->vehicleTab    ->setTheme(theme);
	ui->waybillTab    ->setTheme(theme);
}

MainWindow::~MainWindow() {
	dao.disconnect();
	delete ui;
}

#if 0
void
MainWindow::on_waybillTableView_clicked(const QModelIndex index) {
	if (!index.sisValid()) return;
	QModelIndex pkindex = index.sibling(index.row(), 0);
	qDebug() << "primary key clicked:" << pkindex.data();
}
#endif

void
MainWindow::onSignIn() {
	qDebug() << "on sign in";
}

void
MainWindow::onSignOut() {
	qDebug() << "on sign out";
}
