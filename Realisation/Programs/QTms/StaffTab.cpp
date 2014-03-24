#include "StaffTab.h"
#include "ui_StaffTab.h"

StaffTab::StaffTab(QWidget* parent) :
	LogisticTab(parent),
	ui(new Ui::StaffTab) {
	ui->setupUi(this);
}

StaffTab::~StaffTab() {
	delete ui;
}

void
StaffTab::setModel(QAbstractItemModel* newModel) {
	QItemSelectionModel* oldModel = ui->dataListView->selectionModel();
	ui->dataListView->setModel(newModel);
	if (oldModel) delete oldModel;
}
