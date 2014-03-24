#include "ProviderTab.h"
#include "ui_ProviderTab.h"

ProviderTab::ProviderTab(QWidget* parent) :
	LogisticTab(parent),
	ui(new Ui::ProviderTab) {
	ui->setupUi(this);
}

ProviderTab::~ProviderTab() {
	delete ui;
}

void
ProviderTab::setModel(QAbstractItemModel* newModel) {
	QItemSelectionModel* oldModel = ui->dataListView->selectionModel();
	ui->dataListView->setModel(newModel);
	if (oldModel) delete oldModel;
}
