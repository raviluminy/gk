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
	loadCss();
}

MainWindow::~MainWindow() {
	delete ui;
}
/*
void
MainWindow::on_waybillTableView_clicked(const QModelIndex index) {
	if (!index.isValid()) return;
	QModelIndex pkindex = index.sibling(index.row(), 0);
	qDebug() << "primary key clicked:" << pkindex.data();
}
*/
