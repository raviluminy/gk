#-------------------------------------------------
#
# Project created by QtCreator 2014-03-16T17:45:46
#
#-------------------------------------------------

QT       += core gui sql testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTms
TEMPLATE = app


SOURCES += Main.cpp\
        MainWindow.cpp \
    LogisticDao.cpp \
    WidgetGroup.cpp \
    DataInteractionToolBar.cpp \
    DataFrame.cpp \
    WaybillTab.cpp \
    RequisitionTab.cpp \
    StaffTab.cpp \
    ProviderTab.cpp \
    VehicleTab.cpp \
    WaybillTabTest.cpp \
    Util.cpp

HEADERS  += MainWindow.h \
    LogisticDao.h \
    WidgetGroup.h \
    DataInteractionToolBar.h \
    DataFrame.h \
    WaybillTab.h \
    RequisitionTab.h \
    StaffTab.h \
    ProviderTab.h \
    VehicleTab.h \
    WaybillTabTest.h \
    Util.h

FORMS    += \
    MainWindow.ui \
    WidgetGroup.ui \
    DataInteractionToolBar.ui \
    DataFrame.ui \
    WaybillTab.ui \
    RequisitionTab.ui \
    StaffTab.ui \
    ProviderTab.ui \
    VehicleTab.ui

RESOURCES += \
    Gui.qrc
