#ifndef VEHICLETAB_H
#define VEHICLETAB_H

#include "LogisticTab.h"

class QAbstractItemModel;
class QWidget;

namespace Ui {
class VehicleTab;
}

class VehicleTab : public LogisticTab {

	Q_OBJECT

public:

	explicit VehicleTab(QWidget* parent = 0);

	virtual ~VehicleTab();

	virtual void setModel(QAbstractItemModel* model);

protected:

	Ui::VehicleTab *ui;

};

#endif // VEHICLETAB_H
