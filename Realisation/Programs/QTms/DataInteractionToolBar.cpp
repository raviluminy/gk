#include "DataInteractionToolBar.h"
#include "ui_DataInteractionToolBar.h"

#include <QFile>

DataInteractionToolBar::DataInteractionToolBar(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::DataInteractionToolBar) {
	ui->setupUi(this);
	connect(ui->addPushButton, SIGNAL(clicked()), this, SLOT(loadCss()));
}

DataInteractionToolBar::~DataInteractionToolBar() {
	delete ui;
}

void
DataInteractionToolBar::loadCss() {
	QFile css("Web.css");
	if (css.open(QIODevice::ReadOnly)) {
		qApp->setStyleSheet(css.readAll());
		css.close();
	}
}

void
DataInteractionToolBar::on_addPushButton_clicked() {
	emit added();
	qDebug() << "added";
}

void
DataInteractionToolBar::on_commitPushButton_clicked() {
	emit commited();
	qDebug() << "commited";
}

void
DataInteractionToolBar::on_rollbackPushButton_clicked() {
	emit rollbacked();
	qDebug() << "rollbacked";
}
