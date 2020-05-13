#-------------------------------------------------
#
# Project created by QtCreator 2020-05-13T17:40:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = L8_EventPropagation
TEMPLATE = app


SOURCES += main.cpp \
    widget.cpp \
    parentbutton.cpp \
    childbutton.cpp \
    parentlineedit.cpp \
    childlineedit.cpp

HEADERS  += \
    widget.h \
    parentbutton.h \
    childbutton.h \
    parentlineedit.h \
    childlineedit.h

FORMS    += \
    widget.ui
