#include "MainWindow.h"
#include "ui_MainWindow.h"

void
MainWindow::loadCss() {
    QFile css("WebCommon.css");
	if (css.open(QIODevice::ReadOnly)) {
		qApp->setStyleSheet(css.readAll());
		css.close();
	}
}

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
    setWindowFlags(Qt::Window);// | Qt::FramelessWindowHint);

    /**Initialisation des différentes frames**/
    requisitionTabInit();
    wayBillTabInit();
    driverTabInit();
    vehicleTabInit();
    providerTabInit();

	loadCss();
}

MainWindow::~MainWindow() {
	dao.disconnect();
	delete ui;
}

void
MainWindow::requisitionTabInit(){
    ui->requisitionTabGridLayout->addWidget(new RequisitionFrame());
}

void
MainWindow::wayBillTabInit(){
    ui->waybillTabGridLayout->addWidget(new WayBillFrame());
}

void
MainWindow::driverTabInit(){
    ui->driverTabGridLayout->addWidget(new DriverFrame());
}

void
MainWindow::vehicleTabInit(){
    ui->vehicleTabGridLayout->addWidget(new VehicleFrame());
}

void
MainWindow::providerTabInit(){
    ui->providerTabGridLayout->addWidget(new ProviderFrame());
}
