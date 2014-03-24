#ifndef PROVIDERTAB_H
#define PROVIDERTAB_H

#include "LogisticTab.h"

class QAbstractItemModel;
class QWidget;

namespace Ui {
class ProviderTab;
}

class ProviderTab : public LogisticTab {

	Q_OBJECT

public:

	explicit ProviderTab(QWidget* parent = 0);

	virtual ~ProviderTab();

	virtual void setModel(QAbstractItemModel* model);

protected:

	Ui::ProviderTab *ui;

};

#endif // PROVIDERTAB_H
