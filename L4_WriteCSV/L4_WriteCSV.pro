#-------------------------------------------------
#
# Project created by QtCreator 2020-02-18T15:55:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WriteCSV
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


unix:!macx: LIBS += -L$$PWD/CSVLib/ -lqtcsv

INCLUDEPATH += $$PWD/CSVLib/include
DEPENDPATH += $$PWD/CSVLib/include
