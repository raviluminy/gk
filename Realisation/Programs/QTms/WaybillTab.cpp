#include "WaybillTab.h"
#include "ui_WaybillTab.h"

WaybillTab::WaybillTab(QWidget* parent) :
	LogisticTab(parent),
	ui(new Ui::WaybillTab) {
	ui->setupUi(this);

	dao.connect();
	ui->dataListView->setModel(dao.waybillModel());

	ui->idWidget->hide();
	ui->planningWidget->hide();
	ui->statusWidget->hide();
	ui->transportWidget->hide();

	ui->idTitle->toggle();
	ui->statusTitle->toggle();

	initBooleans();
	initFields();
}

WaybillTab::~WaybillTab() {
	dao.disconnect();
	delete ui;
}

/*---- TOGGLED TITLES --------------------------------------------------------*/

void
WaybillTab::on_idTitle_toggled(const bool checked) {
	ui->idWidget->setVisible(checked);
}

void
WaybillTab::on_planningTitle_toggled(const bool checked) {
	ui->planningWidget->setVisible(checked);
}

void
WaybillTab::on_statusTitle_toggled(const bool checked) {
	ui->statusWidget->setVisible(checked);
}

void
WaybillTab::on_transportTitle_toggled(const bool checked) {
	ui->transportWidget->setVisible(checked);
}

/*---- FILED VALIDATORS ------------------------------------------------------*/

void
WaybillTab::initBooleans() {
	countryCodeIsValid           = false;
	requestedDateIsValid         = false;
	requisitionIdIsValid         = true;//false;
	warehouseIsValid             = false;
	vehicleIsValid               = false;
	registrationNumberIsvalid    = false;
	plannedLoadingActorIsValid   = false;
	plannedTransportActorIsValid = false;
	plannedReceptionActorIsValid = false;
	plannedLoadingDateIsValid    = false;
	plannedTransportDateIsValid  = false;
	plannedReceptionDateIsValid  = false;
	realLoadingActorIsValid      = true; // Not required
	realTransportActorIsValid    = true; // Not required
	realReceptionActorIsValid    = true; // Not required
	realLoadingDateIsValid       = true; // Not required
	realTransportDateIsValid     = true; // Not required
	realReceptionDateIsValid     = true; // Not required
}

void
WaybillTab::initFields() {
	ui->plannedLoadingDateEdit  ->setDate(QDate::currentDate());
	ui->plannedTransportDateEdit->setDate(QDate::currentDate());
	ui->plannedReceptionDateEdit->setDate(QDate::currentDate());
	ui->realLoadingDateEdit     ->setDate(QDate::currentDate());
	ui->realTransportDateEdit   ->setDate(QDate::currentDate());
	ui->realReceptionDateEdit   ->setDate(QDate::currentDate());
	ui->requestDateEdit         ->setDate(QDate::currentDate());

	ui->countryCodeLineEdit->setToolTip(tr("Country code field must be filled"));
	ui->requisitionIdComboBox->setToolTip(tr("Requisition ID field must be filled"));
	ui->warehouseLineEdit->setToolTip(tr("Warehouse field must be filled"));
	ui->transportVehicleLineEdit->setToolTip(tr("Vehicle field must be filled"));
	ui->transportRegistrationNoLineEdit->setToolTip(tr("Registration number field must be filled"));
	ui->plannedLoadingActorLineEdit->setToolTip(tr("Planned loading actor field must be filled"));
	ui->plannedReceptionActorLineEdit->setToolTip(tr("Planned reception actor field must be filled"));
	ui->plannedTransportActorLineEdit->setToolTip(tr("Planned transport actor field must be filled"));

	//on_requestDateEdit_dateChanged(const QDate &date);
	on_requisitionIdComboBox_textChanged(QString());
	on_warehouseLineEdit_textChanged(QString());
	on_countryCodeLineEdit_textChanged(QString());
	on_transportVehicleLineEdit_textChanged(QString());
	on_transportRegistrationNoLineEdit_textChanged(QString());
	on_plannedLoadingActorLineEdit_textChanged(QString());
	on_plannedTransportActorLineEdit_textChanged(QString());
	on_plannedReceptionActorLineEdit_textChanged(QString());
	on_plannedLoadingDateEdit_dateChanged();
	on_realLoadingDateEdit_dateChanged();
	on_plannedTransportDateEdit_dateChanged();
	on_realTransportDateEdit_dateChanged();
	on_plannedReceptionDateEdit_dateChanged();
	on_realReceptionDateEdit_dateChanged();
}

void
WaybillTab::setAlertMessageOn(const QVariant& alert, const char* message, const QList<QWidget*> widgets) {
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
	ui->confirmationWidgetGroup->setEnabled(
				countryCodeIsValid           && requestedDateIsValid      &&
				requisitionIdIsValid         && warehouseIsValid          &&
				vehicleIsValid               && registrationNumberIsvalid &&
				plannedLoadingActorIsValid   && realLoadingActorIsValid   &&
				plannedTransportActorIsValid && realTransportActorIsValid &&
				plannedReceptionActorIsValid && realReceptionActorIsValid &&
				plannedLoadingDateIsValid    && realLoadingDateIsValid    &&
				plannedTransportDateIsValid  && realTransportDateIsValid  &&
				plannedReceptionDateIsValid  && realReceptionDateIsValid
				);
}

void
WaybillTab::on_countryCodeLineEdit_textChanged(const QString& newtext) {
	const QList<QWidget*> widgets = QList<QWidget*>()
										  << ui->countryCodeLineEdit
										  << ui->countryCodeLabel;
	// Apply eventual conditions over countryCode
	if (newtext.size() != 3) {
		countryCodeIsValid = false;
		setAlertMessageOn(QString("error"), "Country code must be 3 character", widgets);
		return;
	}
	countryCodeIsValid = true;
	setAlertMessageOn(QVariant(), "", widgets);
}

void
WaybillTab::on_requestDateEdit_dateChanged(const QDate& date) {
	const QList<QWidget*> widgets = QList<QWidget*>()
										  << ui->requestDateEdit
										  << ui->requestDateLabel;
	// Apply eventual conditions over requestDate
	if (date < QDate::currentDate()) {
		requestedDateIsValid = false;
		setAlertMessageOn(QString("error"), "Requested date must be at least today", widgets);
		return;
	}
	requestedDateIsValid = true;
	setAlertMessageOn(QVariant(), "", widgets);
}

void
WaybillTab::on_requisitionIdComboBox_textChanged(const QString& newText) {
#if 0
	const QList<QWidget*> widgets = QList<QWidget*>()
									<< ui->requisitionIdComboBox
									<< ui->requisitionIdLabel;
	// Apply eventual conditions over requisitionId
	if (newText.isNull() || newText.isEmpty()) {
		requisitionIdIsValid = false;
		setAlertMessageOn(QString("error"), "Requisition ID can't be empty", widgets);
		return;
	}
	requisitionIdIsValid = true;
	setAlertMessageOn(QVariant(), "", widgets);
#endif
}

void
WaybillTab::on_warehouseLineEdit_textChanged(const QString& newText) {
	const QList<QWidget*> widgets = QList<QWidget*>()
									<< ui->warehouseLineEdit
									<< ui->warehouseLabel;
	// Apply eventual conditions over warehouse
	if (newText.isNull() || newText.isEmpty()) {
		warehouseIsValid = false;
		setAlertMessageOn(QString("error"), "Warehouse can't be empty", widgets);
		return;
	}
	warehouseIsValid = true;
	setAlertMessageOn(QVariant(), "", widgets);
}

void
WaybillTab::on_transportVehicleLineEdit_textChanged(const QString& newText) {
	const QList<QWidget*> widgets = QList<QWidget*>()
									<< ui->transportVehicleLineEdit
									<< ui->transportVehicleLabel;
	// Apply eventual conditions over vehicle
	if (newText.isNull() || newText.isEmpty()) {
		vehicleIsValid = false;
		setAlertMessageOn(QString("error"), "Vehicle can't be empty", widgets);
		return;
	}
	vehicleIsValid = true;
	setAlertMessageOn(QVariant(), "", widgets);
}

void
WaybillTab::on_transportRegistrationNoLineEdit_textChanged(const QString& newText) {
	const QList<QWidget*> widgets = QList<QWidget*>()
									<< ui->transportRegistrationNoLineEdit
									<< ui->transportRegistrationNoLabel;
	// Apply eventual conditions over registrationNo
	if (newText.isNull() || newText.isEmpty()) {
		registrationNumberIsvalid = false;
		setAlertMessageOn(QString("error"), "Registration n° can't be empty", widgets);
		return;
	}
	registrationNumberIsvalid = true;
	setAlertMessageOn(QVariant(), "", widgets);
}

void
WaybillTab::on_plannedLoadingActorLineEdit_textChanged(const QString& newText) {
	const QList<QWidget*> widgets = QList<QWidget*>()
										  << ui->plannedLoadingActorLineEdit
										  << ui->plannedLoadingLeftHeader
										  << ui->plannedActorTopHeader;
	// Apply eventual conditions over planned loading actor
	if (newText.isNull() || newText.isEmpty()) {
		plannedLoadingActorIsValid = false;
		setAlertMessageOn(QString("error"), "Planned loading actor can't be empty", widgets);
		return;
	}
	plannedLoadingActorIsValid = true;
	setAlertMessageOn(QVariant(), "", widgets);
}

void
WaybillTab::on_plannedTransportActorLineEdit_textChanged(const QString& newText) {
	const QList<QWidget*> widgets = QList<QWidget*>()
										  << ui->plannedTransportActorLineEdit
										  << ui->plannedTransportLeftHeader
										  << ui->plannedActorTopHeader;
	// Apply eventual conditions over planned transport actor
	if (newText.isNull() || newText.isEmpty()) {
		plannedTransportActorIsValid = false;
		setAlertMessageOn(QString("error"), "Planned transport actor can't be empty", widgets);
		return;
	}
	plannedTransportActorIsValid = true;
	setAlertMessageOn(QVariant(), "", widgets);
}

void
WaybillTab::on_plannedReceptionActorLineEdit_textChanged(const QString& newText) {
	const QList<QWidget*> widgets = QList<QWidget*>()
										  << ui->plannedReceptionActorLineEdit
										  << ui->plannedReceptionLeftHeader
										  << ui->plannedActorTopHeader;
	// Apply eventual conditions over planned transport actor
	if (newText.isNull() || newText.isEmpty()) {
		plannedReceptionActorIsValid = false;
		setAlertMessageOn(QString("error"), "Planned reception actor can't be empty", widgets);
		return;
	}
	plannedReceptionActorIsValid = true;
	setAlertMessageOn(QVariant(), "", widgets);
}

void
WaybillTab::on_plannedLoadingDateEdit_dateChanged() {
	checkPlannedDates();
}

void
WaybillTab::on_plannedReceptionDateEdit_dateChanged() {
	checkPlannedDates();
}

void
WaybillTab::on_plannedTransportDateEdit_dateChanged() {
	checkPlannedDates();
}

void
WaybillTab::on_realLoadingDateEdit_dateChanged() {
	checkRealDates();
}

void
WaybillTab::on_realReceptionDateEdit_dateChanged() {
	checkRealDates();
}

void
WaybillTab::on_realTransportDateEdit_dateChanged() {
	checkRealDates();
}

void
WaybillTab::checkPlannedDates(){
	QString message = QString("Planned date error:\n");
	QList<QWidget*> loadingWidgets = QList<QWidget*>()
									 << ui->plannedLoadingDateEdit
									 << ui->plannedLoadingLeftHeader
									 << ui->plannedDateTopHeader;
	QList<QWidget*> transportWidgets = QList<QWidget*>()
									 << ui->plannedTransportDateEdit
									 << ui->plannedTransportLeftHeader
									 << ui->plannedDateTopHeader;
	QList<QWidget*> receptionWidgets = QList<QWidget*>()
									 << ui->plannedReceptionDateEdit
									 << ui->plannedReceptionLeftHeader
									 << ui->plannedDateTopHeader;
	const QDate loadingDate   = ui->plannedLoadingDateEdit->date();
	const QDate transportDate = ui->plannedTransportDateEdit->date();
	const QDate receptionDate = ui->plannedReceptionDateEdit->date();

	// Init validators at true
	plannedLoadingDateIsValid   = true;
	plannedTransportDateIsValid = true;
	plannedReceptionDateIsValid = true;

	// Loading > Transport
	if (loadingDate > transportDate){
		message.append("\t- Transport date must be at least loading date\n");
		plannedLoadingDateIsValid   = false;
		plannedTransportDateIsValid = false;
	}
	// Loading > Reception
	if (loadingDate > receptionDate){
		message.append("\t- Reception date must be at least loading date\n");
		plannedLoadingDateIsValid   = false;
		plannedReceptionDateIsValid = false;
	}
	// Transport > Reception
	if (transportDate > receptionDate){
		message.append("\t- Reception date must be at least transport date\n");
		plannedTransportDateIsValid = false;
		plannedReceptionDateIsValid = false;
	}

	if (!plannedLoadingDateIsValid) {
		setAlertMessageOn(QString("error"), message.toStdString().c_str(), loadingWidgets);
	} else {
		setAlertMessageOn(QVariant(), "", loadingWidgets);
	}
	if (!plannedTransportDateIsValid) {
		setAlertMessageOn(QString("error"), message.toStdString().c_str(), transportWidgets);
	} else {
		setAlertMessageOn(QVariant(), "", transportWidgets);
	}
	if (!plannedReceptionDateIsValid) {
		setAlertMessageOn(QString("error"), message.toStdString().c_str(), receptionWidgets);
	} else {
		setAlertMessageOn(QVariant(), "", receptionWidgets);
	}
}

void
WaybillTab::checkRealDates(){
	QString message = QString("Real date error:\n");
	QList<QWidget*> loadingWidgets = QList<QWidget*>()
									 << ui->realLoadingDateEdit
									 << ui->realLoadingLeftHeader
									 << ui->realDateTopHeader;
	QList<QWidget*> transportWidgets = QList<QWidget*>()
									 << ui->realTransportDateEdit
									 << ui->realTransportLeftHeader
									 << ui->realDateTopHeader;
	QList<QWidget*> receptionWidgets = QList<QWidget*>()
									 << ui->realReceptionDateEdit
									 << ui->realReceptionLeftHeader
									 << ui->realDateTopHeader;
	const QDate loadingDate   = ui->realLoadingDateEdit->date();
	const QDate transportDate = ui->realTransportDateEdit->date();
	const QDate receptionDate = ui->realReceptionDateEdit->date();

	// Init validators at true
	realLoadingDateIsValid   = true;
	realTransportDateIsValid = true;
	realReceptionDateIsValid = true;

	// Loading > Transport
	if (loadingDate > transportDate){
		message.append("\t- Transport date must be at least loading date\n");
		realLoadingDateIsValid   = false;
		realTransportDateIsValid = false;
	}
	// Loading > Reception
	if (loadingDate > receptionDate){
		message.append("\t- Reception date must be at least loading date\n");
		realLoadingDateIsValid   = false;
		realReceptionDateIsValid = false;
	}
	// Transport > Reception
	if (transportDate > receptionDate){
		message.append("\t- Reception date must be at least transport date\n");
		realTransportDateIsValid = false;
		realReceptionDateIsValid = false;
	}

	if (!plannedLoadingDateIsValid) {
		setAlertMessageOn(QString("error"), message.toStdString().c_str(), loadingWidgets);
	} else {
		setAlertMessageOn(QVariant(), "", loadingWidgets);
	}
	if (!plannedTransportDateIsValid) {
		setAlertMessageOn(QString("error"), message.toStdString().c_str(), transportWidgets);
	} else {
		setAlertMessageOn(QVariant(), "", transportWidgets);
	}
	if (!plannedReceptionDateIsValid) {
		setAlertMessageOn(QString("error"), message.toStdString().c_str(), receptionWidgets);
	} else {
		setAlertMessageOn(QVariant(), "", receptionWidgets);
	}
}
