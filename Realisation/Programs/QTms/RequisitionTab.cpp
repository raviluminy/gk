#include "RequisitionTab.h"
#include "ui_RequisitionTab.h"

RequisitionTab::RequisitionTab(QWidget *parent) :
	LogisticTab(parent),
	ui(new Ui::RequisitionTab) {
	ui->setupUi(this);
	initBooleans();
	initFields();
}

RequisitionTab::~RequisitionTab() {
	delete ui;
}

void
RequisitionTab::setModel(QAbstractItemModel* newModel) {
	QItemSelectionModel* oldModel = ui->dataListView->selectionModel();
	ui->dataListView->setModel(newModel);
	if (oldModel) delete oldModel;
}

void
RequisitionTab::initBooleans() {
	countryCodeIsValid = false;
	requisitionIdIsValid = false;
	originIsValid = false;
	destinationIsValid = false;
	deliveryDateIsValid = false;
}

void
RequisitionTab::initFields() {
    ui->requestDateEdit->setDate(QDate::currentDate());
    ui->deliveryDateEdit->setDate(QDate::currentDate());

    ui->countryCodeLineEdit->setToolTip(tr("Country code field must be filled"));
    ui->idLineEdit->setToolTip(tr("Requisition ID field must be filled"));
    ui->originLineEdit->setToolTip(tr("Origin field must be filled"));
    ui->destinationLineEdit->setToolTip(tr("Destination field must be filled"));

    on_countryCodeLineEdit_textChanged(QString());
    on_idLineEdit_textChanged(QString());
    on_originLineEdit_textChanged(QString());
    on_destinationLineEdit_textChanged(QString());
}

void
RequisitionTab::setAlertMessageOn(const QVariant& alert, const char* message, const QList<QWidget*> widgets) {
    if (!widgets.isEmpty()) {
        widgets[0]->setToolTip(QObject::tr(message));
    }
    foreach (QWidget* widget, widgets) {
        widget->setProperty("alert", alert);
        widget->setStyleSheet(
                    "*[alert=success]{border-color: #D6E9C6;color: #3C763D;}"
                    "*[alert=success].QLabel{background-color: #DFF0D8;}"
                    "*[alert=info]{border-color: #BCE8F1;color: #31708F;}"
                    "*[alert=info].QLabel{background-color: #D9EDF7;}"
                    "*[alert=warning]{border-color: #FAEBCC;color: #8A6D3B;}"
                    "*[alert=warning].QLabel{background-color: #FCF8E3;}"
                    "*[alert=error]{border-color: #EBCCD1;color: #A94442;}"
                    "*[alert=error].QLabel{background-color: #F2DEDE;}"
                    );
    }
    ui->confirmationWidgetGroup->setEnabled(/**Check validators heare**/true);
}

void RequisitionTab::on_countryCodeLineEdit_textChanged(const QString &newText)
{
    const QList<QWidget*> widgets = QList<QWidget*>()
                                          << ui->countryCodeLineEdit
                                          << ui->countryCodeLabel;
    // Apply eventual conditions over countryCode
    if (newText.size() != 3) {
        countryCodeIsValid = false;
        setAlertMessageOn(QString("error"), "Country code must be 3 character", widgets);
        return;
    }
    countryCodeIsValid = true;
    setAlertMessageOn(QVariant(), "", widgets);
}

void RequisitionTab::on_idLineEdit_textChanged(const QString &newText)
{
    const QList<QWidget*> widgets = QList<QWidget*>()
                                          << ui->idLineEdit
                                          << ui->idLabel;
    // Apply eventual conditions over requisition id
    if (newText.isEmpty()) {
        requisitionIdIsValid = false;
        setAlertMessageOn(QString("error"), "Requisition ID can't be empty", widgets);
        return;
    }
    requisitionIdIsValid = true;
    setAlertMessageOn(QVariant(), "", widgets);
}

void RequisitionTab::on_originLineEdit_textChanged(const QString &newText)
{
    const QList<QWidget*> widgets = QList<QWidget*>()
                                          << ui->originLineEdit
                                          << ui->originLabel;
    // Apply eventual conditions over origin
    if (newText.isEmpty()) {
        originIsValid = false;
        setAlertMessageOn(QString("error"), "Origin can't be empty", widgets);
        return;
    }
    originIsValid = true;
    setAlertMessageOn(QVariant(), "", widgets);
}

void RequisitionTab::on_destinationLineEdit_textChanged(const QString &newText)
{
    const QList<QWidget*> widgets = QList<QWidget*>()
                                          << ui->destinationLineEdit
                                          << ui->destinationLabel;
    // Apply eventual conditions over destination
    if (newText.isEmpty()) {
        destinationIsValid = false;
        setAlertMessageOn(QString("error"), "Destination can't be empty", widgets);
        return;
    }
    destinationIsValid = true;
    setAlertMessageOn(QVariant(), "", widgets);
}

void RequisitionTab::on_deliveryDateEdit_dateChanged(const QDate &date)
{
        const QList<QWidget*> widgets = QList<QWidget*>()
                                          << ui->deliveryDateEdit
                                          << ui->deliveryDateLabel;
    // Apply eventual conditions over delivery Date
    if (date < ui->requestDateEdit->date()) {
        deliveryDateIsValid = false;
        setAlertMessageOn(QString("error"), "Delivery date must be at least request date", widgets);
        return;
    }
    deliveryDateIsValid = true;
    setAlertMessageOn(QVariant(), "", widgets);
}
