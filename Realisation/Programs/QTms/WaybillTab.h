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

	Ui::WaybillTab *ui;

	LogisticDao dao;

};

#endif // WAYBILLTAB_H
