#ifndef STAFFTAB_H
#define STAFFTAB_H

#include <QWidget>

namespace Ui {
class StaffTab;
}

class StaffTab : public QWidget {

	Q_OBJECT

public:

	explicit StaffTab(QWidget *parent = 0);

	virtual ~StaffTab();

protected:

	Ui::StaffTab *ui;

};

#endif // STAFFTAB_H