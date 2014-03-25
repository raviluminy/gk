#ifndef REQUISITIONTAB_H
#define REQUISITIONTAB_H

#include "LogisticTab.h"

class QAbstractItemModel;
class QWidget;

namespace Ui {
class RequisitionTab;
}

class RequisitionTab : public LogisticTab {

	Q_OBJECT

public:

	explicit RequisitionTab(QWidget* parent = 0);
	virtual ~RequisitionTab();

	virtual void setModel(QAbstractItemModel* model);

protected:

	void setAlertMessageOn(const QVariant& alert, const char* message, const QList<QWidget*> widgets);

	enum DbColumn {
		CountryCode = 0, // destine a disparaitre
		Id,
//		ForCostEstimate,
//		ForPurchase,
//		WhDispatchRelease,
		RequisitionDate,
		DesiredDeliveryDate,
		TransportMeans,
		Origin,
		Destination,
		CurrencyId, // destine a disparaitre
		FinanceOfficerAgreementDate,
		FinanceOfficerId,
		ProjectManagerAgreementDate,
		ProjectManagerId,
		RequesterAgreementDate,
		RequesterId,
		LogisticsAgreementDate,
		LogisticsId,
		GlobalFleetBaseAgreementDate,
		GlobalFleetBaseId
	};

	QVariant dataAt(const QModelIndex& index, const DbColumn column);

protected slots:

	void on_dataListView_clicked(const QModelIndex& index);

private:

	void initBooleans();
	void initFields();

protected:

	Ui::RequisitionTab* ui;

private slots:

	void on_countryCodeLineEdit_textChanged(const QString& newText);
	void on_idLineEdit_textChanged(const QString& newText);
	void on_originLineEdit_textChanged(const QString& newText);
	void on_destinationLineEdit_textChanged(const QString& newText);
	void on_deliveryDateEdit_dateChanged(const QDate& date);

private:

	bool countryCodeIsValid;
	bool requisitionIdIsValid;
	bool originIsValid;
	bool destinationIsValid;
	bool deliveryDateIsValid;

};

#endif // REQUISITIONTAB_H
