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
    DataFrame.cpp

HEADERS  += MainWindow.h \
    LogisticDao.h \
    WidgetGroup.h \
    DataInteractionToolBar.h \
    DataFrame.h

FORMS    += \
    MainWindow.ui \
    WidgetGroup.ui \
    DataInteractionToolBar.ui \
    DataFrame.ui

RESOURCES += \
    Gui.qrc
