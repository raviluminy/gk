#ifndef VEHICLETAB_H
#define VEHICLETAB_H

#include <QWidget>

namespace Ui {
class VehicleTab;
}

class VehicleTab : public QWidget
{
	Q_OBJECT

public:
	explicit VehicleTab(QWidget *parent = 0);
	~VehicleTab();

private:
	Ui::VehicleTab *ui;
};

#endif // VEHICLETAB_H
