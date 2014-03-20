#ifndef WIDGETGROUP_H
#define WIDGETGROUP_H

#include <QWidget>

namespace Ui {
class WidgetGroup;
}

class WidgetGroup : public QWidget
{
	Q_OBJECT

public:
	explicit WidgetGroup(QWidget *parent = 0);
	~WidgetGroup();

private:
	Ui::WidgetGroup *ui;
};

#endif // WIDGETGROUP_H
