#ifndef DATAINTERACTIONTOOLBAR_H
#define DATAINTERACTIONTOOLBAR_H

#include "Util.h"

#include <QWidget>

namespace Ui {
class DataInteractionToolBar;
}

class DataInteractionToolBar : public QWidget {

	Q_OBJECT

signals:

	void added();
	void commited();
	void rollbacked();

public:

	explicit DataInteractionToolBar(QWidget* parent = 0);
	virtual ~DataInteractionToolBar();

public slots:

	void loadCss();

private slots:

	void on_addPushButton_clicked();
	void on_commitPushButton_clicked();
	void on_rollbackPushButton_clicked();

private:

	Ui::DataInteractionToolBar *ui;

};

#endif // DATAINTERACTIONTOOLBAR_H
