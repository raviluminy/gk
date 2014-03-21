#ifndef PROVIDERTAB_H
#define PROVIDERTAB_H

#include <QWidget>

namespace Ui {
class ProviderTab;
}

class ProviderTab : public QWidget
{
	Q_OBJECT

public:
	explicit ProviderTab(QWidget *parent = 0);
	~ProviderTab();

private:
	Ui::ProviderTab *ui;
};

#endif // PROVIDERTAB_H
