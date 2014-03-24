#ifndef STAFFTAB_H
#define STAFFTAB_H

#include "LogisticTab.h"

class QAbstractItemModel;
class QWidget;

namespace Ui {
class StaffTab;
}

class StaffTab : public LogisticTab {

	Q_OBJECT

public:

	explicit StaffTab(QWidget* parent = 0);
	virtual ~StaffTab();

	virtual void setModel(QAbstractItemModel* model);

protected:

	Ui::StaffTab *ui;

};

#endif // STAFFTAB_H
