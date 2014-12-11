QT          =

TARGET      = ApiExample
TEMPLATE    = app

OBJECTS_DIR += temp
MOC_DIR     += temp
UI_DIR      += temp
RCC_DIR     += temp

INCLUDEPATH += /usr/local/include/GraphicsMagick

QMAKE_CXXFLAGS += -pthread

SOURCES += ApiExample.cpp
LIBS    += -llept -ltesseract -lGraphicsMagick++ -lGraphicsMagick -ljbig -ltiff -ljpeg -lpng12 -lXext -lX11 -llzma -lz -lm -lgomp -lpthread

win32: {
    CONFIG  += console
    DESTDIR = ./bin
    INCLUDEPATH += ./include/
    LIBS += -lws2_32 -L./lib
    DEFINES += WINDOWS __BLOB_T_DEFINED
}
