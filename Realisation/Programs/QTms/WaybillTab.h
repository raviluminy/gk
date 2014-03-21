#ifndef WAYBILLTAB_H
#define WAYBILLTAB_H

#include "LogisticDao.h"

#include <QWidget>

namespace Ui {
class WaybillTab;
}

class WaybillTab : public QWidget {

	Q_OBJECT

public:

	explicit WaybillTab(QWidget* parent = 0);

	~WaybillTab();

private slots:

	void on_idTitle_toggled(const bool checked);

	void on_planningTitle_toggled(const bool checked);

	void on_statusTitle_toggled(const bool checked);

	void on_transportTitle_toggled(const bool checked);

protected:

	Ui::WaybillTab* ui;

	LogisticDao dao;

private slots:

	void on_requestDateEdit_dateChanged(const QDate &date);

	void on_requisitionIdComboBox_textChanged(const QString &newText);

	void on_warehouseLineEdit_textChanged(const QString &newText);

	void on_countryCodeLineEdit_textChanged(const QString &newtext);

	void on_transportVehicleLineEdit_textChanged(const QString &newText);

	void on_transportRegistrationNoLineEdit_textChanged(const QString &newText);

	void on_plannedLoadingActorLineEdit_textChanged(const QString &newText);

	void on_plannedTransportActorLineEdit_textChanged(const QString &newText);

	void on_plannedReceptionActorLineEdit_textChanged(const QString &newText);

	void on_plannedLoadingDateEdit_dateChanged();

	void on_realLoadingDateEdit_dateChanged();

	void on_plannedTransportDateEdit_dateChanged();

	void on_realTransportDateEdit_dateChanged();

	void on_plannedReceptionDateEdit_dateChanged();

	void on_realReceptionDateEdit_dateChanged();

private:

	void initBooleans();

	void initFields();

	void checkPlannedDates();

	void checkRealDates();

	void setAlertMessageOn(const QVariant& alert, const char* message, const QList<QWidget*> widgets);

private:

	bool countryCodeIsValid;
	bool requestedDateIsValid;
	bool requisitionIdIsValid;
	bool warehouseIsValid;
	bool vehicleIsValid;
	bool registrationNumberIsvalid;
	bool plannedLoadingActorIsValid;
	bool realLoadingActorIsValid;
	bool plannedTransportActorIsValid;
	bool realTransportActorIsValid;
	bool plannedReceptionActorIsValid;
	bool realReceptionActorIsValid;
	bool plannedLoadingDateIsValid;
	bool realLoadingDateIsValid;
	bool plannedTransportDateIsValid;
	bool realTransportDateIsValid;
	bool plannedReceptionDateIsValid;
	bool realReceptionDateIsValid;

};

#endif // WAYBILLTAB_H
