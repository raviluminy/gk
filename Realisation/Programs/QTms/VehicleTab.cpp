#include "VehicleTab.h"
#include "ui_VehicleTab.h"

VehicleTab::VehicleTab(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::VehicleTab)
{
	ui->setupUi(this);
}

VehicleTab::~VehicleTab()
{
	delete ui;
}
