#-------------------------------------------------
#
# Project created by QtCreator 2014-03-16T17:45:46
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTms
TEMPLATE = app


SOURCES += Main.cpp\
        MainWindow.cpp \
    LogisticDao.cpp \
    WidgetGroup.cpp \
    DataInteractionToolBar.cpp \
    DataFrame.cpp \
    Frame/requisitionframe.cpp \
    Frame/waybillframe.cpp \
    Frame/driverframe.cpp \
    Frame/vehicleframe.cpp \
    Frame/providerframe.cpp

HEADERS  += MainWindow.h \
    LogisticDao.h \
    WidgetGroup.h \
    DataInteractionToolBar.h \
    DataFrame.h \
    Frame/requisitionframe.h \
    Frame/waybillframe.h \
    Frame/driverframe.h \
    Frame/vehicleframe.h \
    Frame/providerframe.h

FORMS    += \
    MainWindow.ui \
    WidgetGroup.ui \
    DataInteractionToolBar.ui \
    DataFrame.ui \
    Frame/requisitionframe.ui \
    Frame/waybillframe.ui \
    Frame/driverframe.ui \
    Frame/vehicleframe.ui \
    Frame/providerframe.ui

RESOURCES += \
    Gui.qrc
