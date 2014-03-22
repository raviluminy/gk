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

protected:

	Ui::RequisitionTab* ui;

};

#endif // REQUISITIONTAB_H
