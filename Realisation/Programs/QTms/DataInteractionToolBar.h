#ifndef DATAINTERACTIONTOOLBAR_H
#define DATAINTERACTIONTOOLBAR_H

#include <QWidget>

namespace Ui {
class DataInteractionToolBar;
}

class DataInteractionToolBar : public QWidget
{
	Q_OBJECT

public:
	explicit DataInteractionToolBar(QWidget *parent = 0);
	~DataInteractionToolBar();

public slots:
	void loadCss();

private:
	Ui::DataInteractionToolBar *ui;
};

#endif // DATAINTERACTIONTOOLBAR_H
