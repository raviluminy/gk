#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QFile>

void
MainWindow::loadTheme(const QString& name) {
    QFile css("Theme/" + name + "/main.css");
    if (css.open(QIODevice::ReadOnly)) {
        qApp->setStyleSheet(css.readAll());
        css.close();
    }
}

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    theme("Web"),
    ui(new Ui::MainWindow) {
    dao.connect();
    ui->setupUi(this);
    connect(ui->signInAction,  SIGNAL(triggered()), this, SLOT(onSignIn()));
    connect(ui->signOutAction, SIGNAL(triggered()), this, SLOT(onSignOut()));
    setWindowFlags(Qt::Window); // | Qt::FramelessWindowHint); permet de supprimer les contours de fenetre
    loadTheme(theme);
    ui->providerTab   ->setModel(dao.providerModel());
    ui->requisitionTab->setModel(dao.requisitionModel());
    ui->staffTab      ->setModel(dao.staffModel());
    ui->vehicleTab    ->setModel(dao.vehicleModel());
    ui->waybillTab    ->setModel(dao.waybillModel());
    ui->providerTab   ->setTheme(theme);
    ui->requisitionTab->setTheme(theme);
    ui->staffTab      ->setTheme(theme);
    ui->vehicleTab    ->setTheme(theme);
    ui->waybillTab    ->setTheme(theme);
    loggedField = new QLabel("Not logged");
    currentUser = "default";
    previousTab = 0;
    ui->statusbar->addWidget(loggedField);
    dir = new Directory();
    dir->init_file_config();
    ui->requisitionTab->setDirectory(dir);
    connect(this, SIGNAL(userChanged(QString)), ui->requisitionTab, SLOT(userChanged(QString)));
}

MainWindow::~MainWindow() {
    dao.disconnect();
    delete ui;
}

#if 0
void
MainWindow::on_waybillTableView_clicked(const QModelIndex index) {
    if (!index.sisValid()) return;
    QModelIndex pkindex = index.sibling(index.row(), 0);
    qDebug() << "primary key clicked:" << pkindex.data();
}
#endif

void
MainWindow::onSignIn() {
    SignInDialog *loginDial = new SignInDialog(dir, this);
    QFrame *loginFrame = new QFrame();
    loginFrame->setWindowTitle("Login");
    loginFrame->setLayout(new QGridLayout());
    loginFrame->layout()->setMargin(0);
    loginFrame->layout()->setSpacing(0);
    loginFrame->layout()->addWidget(loginDial);
    loginFrame->show();
    connect(loginDial, SIGNAL(auth(bool, QString)), this, SLOT(auth(bool, QString)));
}

void
MainWindow::onSignOut() {
    if (currentUser.compare("default") == 0) return;
    loggedField->setText("Not logged");
    QMessageBox::about(this, "Logout succeed", "You are no longer logged as " + currentUser);
    currentUser = "default";
    emit userChanged(currentUser);
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::auth(bool logged, QString user){
    if (logged){
        loggedField->setText("Logged as " + user);
        currentUser = user;
        emit userChanged(currentUser);
    }
    else{
        loggedField->setText("Not logged");
        currentUser = "default";
        emit userChanged(currentUser);
    }
    ui->tabWidget->setCurrentIndex(0);

}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    switch(index){
    case 0:
        previousTab = 0;
        break;
    case 1:
        if (!dir->canRead(currentUser, "Requisition", "RequisitionId")) ui->tabWidget->setCurrentIndex(previousTab);
        else previousTab = 1;
        break;
    case 2:
        if (!dir->canRead(currentUser, "Driver", "DriverId")) ui->tabWidget->setCurrentIndex(previousTab);
        else previousTab = 2;
        break;
    case 3:
        if (!dir->canRead(currentUser, "Vehicle", "VehicleId")) ui->tabWidget->setCurrentIndex(previousTab);
        else previousTab = 3;
        break;
    case 4:
        if (!dir->canRead(currentUser, "Provider", "ProviderId")) ui->tabWidget->setCurrentIndex(previousTab);
        else previousTab = 4;
        break;
    }
}
