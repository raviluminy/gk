#ifndef STATUSWIDGETGROUP_H
#define STATUSWIDGETGROUP_H

#include <QWidget>

namespace Ui {
class StatusWidgetGroup;
}

class StatusWidgetGroup : public QWidget {

	Q_OBJECT

public:

	explicit StatusWidgetGroup(QWidget *parent = 0);

	virtual ~StatusWidgetGroup();

private slots:

	void on_statusComboBox_currentIndexChanged(const int index);

private:

	enum Status {
		None = 0,
		Question,
		Idea,
		Information,
		Warning,
		Error
	};

	Ui::StatusWidgetGroup *ui;

};

#endif // STATUSWIDGETGROUP_H
