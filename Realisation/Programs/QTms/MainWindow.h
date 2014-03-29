#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "LogisticDao.h"

#include <QMainWindow>
#include <QLabel>
#include "Ldap/Directory.h"
#include "SignInDialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {

	Q_OBJECT

public:

	explicit MainWindow(QWidget* parent = 0);
	virtual ~MainWindow();

private:
    void setAvailableTab();

private slots:
    void auth(bool, QString);

    void on_tabWidget_currentChanged(int index);

public slots:

	void loadTheme(const QString& name);

	void onSignIn();
	void onSignOut();

signals:
    void userChanged(QString);

private:

	Ui::MainWindow *ui;
	LogisticDao dao;
	QString theme;    
    QString currentUser;
    QLabel *loggedField;
    Directory *dir;
    int previousTab;


};

#endif // MAINWINDOW_H
