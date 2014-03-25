#include "RequisitionTab.h"
#include "ui_RequisitionTab.h"

RequisitionTab::RequisitionTab(QWidget *parent) :
    LogisticTab(parent),
    ui(new Ui::RequisitionTab) {
    ui->setupUi(this);
    ui->dataEditionWidget->setEnabled(false);
    currentRequisition = NULL;
    adding = false;
    editing = false;
    reloadTableView();
    initBooleans();
    initFields();
}

RequisitionTab::~RequisitionTab() {
    delete ui;
}

/**Reload from database*/
void RequisitionTab::reloadTableView(){
    idList.clear();
    ui->dataListView->clear();
    requisitionList = Requisition::getList();
    foreach (Requisition *req, *requisitionList){
        QTreeWidgetItem *tw = new QTreeWidgetItem();
        QLabel *status = new QLabel();
        status->setStyleSheet("background-color : rgba(0,255, 0, 0.5);");
        ui->dataListView->addTopLevelItem(tw);
        ui->dataListView->setItemWidget(tw, 0, status);
        ui->dataListView->setItemWidget(tw, 1, new QLabel(req->getRequisitionId()));
        idList.append(req->getRequisitionId());
        ui->dataListView->setItemWidget(tw, 2, new QLabel(req->getRequisitionDate().toString("dd-MM-yyyy")));
        ui->dataListView->setItemWidget(tw, 3, new QLabel(req->getDesiredDeliveryDate().toString("dd-MM-yyyy")));
        ui->dataListView->setItemWidget(tw, 4, new QLabel(req->getCountryCode()));
    }
}

/**Reload from memory*/
void RequisitionTab::refreshTableView(){
    idList.clear();
    ui->dataListView->clear();
    foreach (Requisition *req, *requisitionList){
        QTreeWidgetItem *tw = new QTreeWidgetItem();
        QLabel *status = new QLabel();
        if (req->getIsNew()){
            status->setStyleSheet("background-color : rgba(255, 0, 0, 0.5);");
        }
        else if (req->getEdited()){
            status->setStyleSheet("background-color : rgba(255, 150, 50, 0.5);");
        }
        else status->setStyleSheet("background-color : rgba(0, 255, 0, 0.5);");
        QLabel *id = new QLabel(req->getRequisitionId());
        QLabel *requisitionDate = new QLabel(req->getRequisitionDate().toString("dd-MM-yyyy"));
        QLabel *desiredDeliveryDate = new QLabel(req->getDesiredDeliveryDate().toString("dd-MM-yyyy"));
        QLabel *countryCode = new QLabel(req->getCountryCode());
        ui->dataListView->addTopLevelItem(tw);
        ui->dataListView->setItemWidget(tw, 0, status);
        ui->dataListView->setItemWidget(tw, 1, id);
        idList.append(req->getRequisitionId());
        ui->dataListView->setItemWidget(tw, 2, requisitionDate);
        ui->dataListView->setItemWidget(tw, 3, desiredDeliveryDate);
        ui->dataListView->setItemWidget(tw, 4, countryCode);
    }
}

void
RequisitionTab::setModel(QAbstractItemModel* newModel) {
    //    QItemSelectionModel* oldModel = ui->dataListView->selectionModel();
    //    ui->dataListView->setModel(newModel);
    //    if (oldModel) delete oldModel;
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
    currentRequisitionIsEdited = true;
    countryCodeIsValid = true;
    if (currentRequisition != NULL) currentRequisition->setCountryCode(newText);
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
    currentRequisitionIsEdited = true;
    requisitionIdIsValid = true;
    if (currentRequisition != NULL)  currentRequisition->setRequisitionId(newText);
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
    currentRequisitionIsEdited = true;
    originIsValid = true;
    if (currentRequisition != NULL) currentRequisition->setLocalisationId(newText);
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
    currentRequisitionIsEdited = true;
    destinationIsValid = true;
    if (currentRequisition != NULL) currentRequisition->setLocalisationId_1(newText);
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
    currentRequisitionIsEdited = true;
    deliveryDateIsValid = true;
    if (currentRequisition != NULL) currentRequisition->setDesiredDeliveryDate(date);
    setAlertMessageOn(QVariant(), "", widgets);
}

void RequisitionTab::on_requestDateEdit_dateChanged(const QDate &date)
{
    on_deliveryDateEdit_dateChanged(ui->deliveryDateEdit->date());
    currentRequisitionIsEdited = true;
    if (currentRequisition != NULL) currentRequisition->setRequisitionDate(date);
}


void RequisitionTab::on_requesterNameLineEdit_textChanged(const QString &newText)
{
    currentRequisitionIsEdited = true;
    if (currentRequisition != NULL) currentRequisition->setPersonId_3(newText);
}

void RequisitionTab::on_projectManagerLineEdit_textChanged(const QString &newText)
{
    currentRequisitionIsEdited = true;
    if (currentRequisition != NULL) currentRequisition->setPersonId_2(newText);
}

void RequisitionTab::on_financeOfficerLineEdit_textChanged(const QString &newText)
{
    currentRequisitionIsEdited = true;
    if (currentRequisition != NULL) currentRequisition->setPersonId(newText);
}

void RequisitionTab::on_logisticsLineEdit_textChanged(const QString &newText)
{
    currentRequisitionIsEdited = true;
    if (currentRequisition != NULL) currentRequisition->setPersonId_4(newText);
}

void RequisitionTab::on_globalFleetBaseLineEdit_textChanged(const QString &newText)
{
    currentRequisitionIsEdited = true;
    if (currentRequisition != NULL) currentRequisition->setPersonId_5(newText);
}

void RequisitionTab::on_requesterDateEdit_dateChanged(const QDate &date)
{
    currentRequisitionIsEdited = true;
    if (currentRequisition != NULL) currentRequisition->setAgreementDate_requester(date);
}

void RequisitionTab::on_projectManagerDateEdit_dateChanged(const QDate &date)
{
    if (currentRequisition != NULL) currentRequisition->setAgreementDate_manager(date);
}

void RequisitionTab::on_financeOfficerDateEdit_dateChanged(const QDate &date)
{
    if (currentRequisition != NULL) currentRequisition->setAgreementDate(date);
}

void RequisitionTab::on_logisticsDateEdit_dateChanged(const QDate &date)
{
    if (currentRequisition != NULL) currentRequisition->setAgreementDate_logistics(date);
}

void RequisitionTab::on_globalFleetBaseDateEdit_dateChanged(const QDate &date)
{
    if (currentRequisition != NULL) currentRequisition->setAgreementDate_globalFleetBase(date);
}

void RequisitionTab::on_dataListView_clicked(const QModelIndex &index)
{

    //On récupère l'id de la réquisition sélectionnée
    requisitionId = idList.at(index.row());

    //On récupère la réquisition correspondante
    currentRequisition = requisitionList->at(index.row());
    currentRequisitionIsEdited = false;
    editing = true;
    adding = false;

    //On active la zone d'édition
    ui->dataEditionWidget->setEnabled(true);

    //On remplit les champs avec les informations de cette réquisition
    ui->idLineEdit->setText(currentRequisition->getRequisitionId());
    ui->countryCodeLineEdit->setText(currentRequisition->getCountryCode());
    ui->requestDateEdit->setDate(currentRequisition->getRequisitionDate());
    ui->deliveryDateEdit->setDate(currentRequisition->getDesiredDeliveryDate());

    /** Traiter les moyens de transport**/
    /** Traiter les lieux**/
    ui->originLineEdit->setText(currentRequisition->getLocalisationId());
    ui->destinationLineEdit->setText(currentRequisition->getLocalisationId_1());

    /**Dates et validateurs**/
    /** A vérifier pour la correspondance des champs !**/
    //Finance officer
    ui->financeOfficerDateEdit->setDate(currentRequisition->getAgreementDate());
    ui->financeOfficerLineEdit->setText(currentRequisition->getPersonId());
    //Manager
    ui->projectManagerDateEdit->setDate(currentRequisition->getAgreementDate_manager());
    ui->projectManagerLineEdit->setText(currentRequisition->getPersonId_2());
    //Requester
    ui->requesterDateEdit->setDate(currentRequisition->getAgreementDate_requester());
    ui->requesterNameLineEdit->setText(currentRequisition->getPersonId_3());
    //Logistics
    ui->logisticsDateEdit->setDate(currentRequisition->getAgreementDate_logistics());
    ui->logisticsLineEdit->setText(currentRequisition->getPersonId_4());
    //GlobalFleetBase
    ui->globalFleetBaseDateEdit->setDate(currentRequisition->getAgreementDate_globalFleetBase());
    ui->globalFleetBaseLineEdit->setText(currentRequisition->getPersonId_5());
}


void RequisitionTab::on_confirmationOkPushButton_clicked()
{
    /** Modification dans la abse de donénes à déplacer**/
    //if (currentRequisition != NULL) currentRequisition->update();
    if (adding){
        Requisition *req = new Requisition(
                    ui->idLineEdit->text(),
                    ui->countryCodeLineEdit->text(),
                    "",
                    "",
                    "",
                    ui->requesterDateEdit->date(),
                    ui->deliveryDateEdit->date(),
                    "Road"/**ui->meanComboBox->currentText()*/,
                    ui->originLineEdit->text(),
                    ui->destinationLineEdit->text(),
                    "",
                    ui->financeOfficerDateEdit->date(),
                    ui->financeOfficerLineEdit->text(),
                    ui->projectManagerDateEdit->date(),
                    ui->projectManagerLineEdit->text(),
                    ui->requesterDateEdit->date(),
                    ui->requesterNameLineEdit->text(),
                    ui->logisticsDateEdit->date(),
                    ui->logisticsLineEdit->text(),
                    ui->globalFleetBaseDateEdit->date(),
                    ui->globalFleetBaseLineEdit->text());
        req->setEdited(true);
        req->setIsNew(true);
        requisitionList->append(req);
    }
    else if (editing) currentRequisition->setEdited(currentRequisitionIsEdited);
    editing = false;
    adding = false;
    ui->dataEditionWidget->setEnabled(false);
    resetFields();
    refreshTableView();
}


void RequisitionTab::on_commitPushButton_clicked()
{
    foreach(Requisition *req, *requisitionList){
        /** Vérifier la validité*/
        req->update();
    }
    reloadTableView();
}

void RequisitionTab::on_rollbackPushButton_clicked()
{
    reloadTableView();
}

void RequisitionTab::on_addPushButton_clicked()
{
    adding = true;
    resetFields();
}


void RequisitionTab::resetFields(){
    currentRequisition = NULL;
//    adding = true;
//    editing = true;
    ui->dataEditionWidget->setEnabled(true);
    ui->idLineEdit->setText(adding?Requisition::nextId():"");
    ui->countryCodeLineEdit->clear();
    ui->originLineEdit->clear();
    ui->destinationLineEdit->clear();
    ui->requestDateEdit->setDate(QDate::currentDate());
    ui->deliveryDateEdit->setDate(QDate::currentDate());
    ui->requesterNameLineEdit->clear();
    ui->projectManagerLineEdit->clear();
    ui->financeOfficerLineEdit->clear();
    ui->logisticsLineEdit->clear();
    ui->globalFleetBaseLineEdit->clear();
    ui->requesterDateEdit->setDate(QDate::currentDate());
    ui->projectManagerDateEdit->setDate(QDate::currentDate());
    ui->financeOfficerDateEdit->setDate(QDate::currentDate());
    ui->logisticsDateEdit->setDate(QDate::currentDate());
    ui->globalFleetBaseDateEdit->setDate(QDate::currentDate());
}
