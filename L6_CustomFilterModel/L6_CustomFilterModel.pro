#-------------------------------------------------
#
# Project created by QtCreator 2020-03-06T09:50:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = L6_CustomFilterModel
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    MySortFilterProxyModel.cpp

HEADERS  += mainwindow.h \
    MySortFilterProxyModel.h

FORMS    += mainwindow.ui
