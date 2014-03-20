#include "waybillframe.h"
#include "ui_waybillframe.h"

WayBillFrame::WayBillFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::WayBillFrame)
{
    ui->setupUi(this);

    //dao.connect();
    //ui->waybillListTableView->setModel(dao.waybillModel());
    ui->waybillCountryCodeWidget->setProperty("alert","warning");
    ui->waybillIdLineEdit->setProperty("alert","info");
    ui->waybillRequestDateWidget->setProperty("alert","error");
    ui->waybillRequisitionIdLabel->setProperty("alert","success");

    ui->waybillIdWidget->hide();
    ui->waybillPlanningWidget->hide();
    ui->waybillStatusWidget->hide();
    ui->waybillTransportWidget->hide();

    ui->waybillIdTitle->toggle();
    ui->waybillStatusTitle->toggle();
    //	connect(ui->waybillListTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(on_waybillTableView_clicked(QModelIndex)));
}

WayBillFrame::~WayBillFrame()
{
    delete ui;
}


void
WayBillFrame::on_waybillIdTitle_toggled(const bool checked) {
    if (checked) ui->waybillIdWidget->show();
    else         ui->waybillIdWidget->hide();
}

void
WayBillFrame::on_waybillPlanningTitle_toggled(const bool checked) {
    if (checked) ui->waybillPlanningWidget->show();
    else         ui->waybillPlanningWidget->hide();
}

void
WayBillFrame::on_waybillStatusTitle_toggled(const bool checked) {
    if (checked) ui->waybillStatusWidget->show();
    else         ui->waybillStatusWidget->hide();
}

void
WayBillFrame::on_waybillTransportTitle_toggled(const bool checked) {
    if (checked) ui->waybillTransportWidget->show();
    else         ui->waybillTransportWidget->hide();
}


/*
void
MainWindow::on_waybillTableView_clicked(const QModelIndex index) {
    if (!index.isValid()) return;
    QModelIndex pkindex = index.sibling(index.row(), 0);
    qDebug() << "primary key clicked:" << pkindex.data();
}
*/
