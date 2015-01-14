#-------------------------------------------------
#
# Project created by QtCreator 2014-12-10T15:55:59
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Demo
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -pthread

INCLUDEPATH += /usr/local/include/GraphicsMagick

LIBS += -lGraphicsMagick++ -lGraphicsMagick -ljbig -ltiff -ljpeg -lpng12 -lXext -lX11 -llzma -lz -lm -lgomp -lpthread

SOURCES += main.cpp
