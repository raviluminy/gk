#include "VehicleTab.h"
#include "ui_VehicleTab.h"

VehicleTab::VehicleTab(QWidget* parent) :
	LogisticTab(parent),
	ui(new Ui::VehicleTab) {
	ui->setupUi(this);
}

VehicleTab::~VehicleTab() {
	delete ui;
}

void
VehicleTab::setModel(QAbstractItemModel* newModel) {
	QItemSelectionModel* oldModel = ui->dataListView->selectionModel();
	ui->dataListView->setModel(newModel);
	if (oldModel) delete oldModel;
}
