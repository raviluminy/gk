#ifndef REQUISITIONTAB_H
#define REQUISITIONTAB_H

#include <QWidget>

namespace Ui {
class RequisitionTab;
}

class RequisitionTab : public QWidget {

	Q_OBJECT

public:

	explicit RequisitionTab(QWidget* parent = 0);

	virtual ~RequisitionTab();

private:

    void initBooleans();
    void initFields();
    void setAlertMessageOn(const QVariant& alert, const char* message, const QList<QWidget*> widgets);

protected:

	Ui::RequisitionTab* ui;

private slots:
    void on_countryCodeLineEdit_textChanged(const QString &newText);

    void on_idLineEdit_textChanged(const QString &newText);

    void on_originLineEdit_textChanged(const QString &newText);

    void on_destinationLineEdit_textChanged(const QString &newText);

    void on_deliveryDateEdit_dateChanged(const QDate &date);

private:
    bool countryCodeIsValid;
    bool requisitionIdIsValid;
    bool originIsValid;
    bool destinationIsValid;
    bool deliveryDateIsValid;
};

#endif // REQUISITIONTAB_H
