QT          = widgets

TARGET      = ApiExample
TEMPLATE    = app

OBJECTS_DIR += temp
MOC_DIR     += temp
UI_DIR      += temp
RCC_DIR     += temp

INCLUDEPATH += /usr/local/include/GraphicsMagick

QMAKE_CXXFLAGS += -pthread

SOURCES += \
    main.cpp \
    magicconverter.cpp \
    tessreader.cpp \
    fileopener.cpp \
    utility.cpp \
    filemanager.cpp \
    texparser.cpp
LIBS    += -llept -ltesseract -lGraphicsMagick++ -lGraphicsMagick -ljbig -ltiff -ljpeg -lpng12 -lXext -lX11 -llzma -lz -lm -lgomp -lpthread

win32: {
    CONFIG  += console
    DESTDIR = ./bin
    INCLUDEPATH += ./include/
    LIBS += -lws2_32 -L./lib
    DEFINES += WINDOWS __BLOB_T_DEFINED
}

HEADERS += \
    magicconverter.h \
    tessreader.h \
    fileopener.h \
    utility.h \
    filemanager.h \
    texparser.h

FORMS += \
    fileopener.ui

# install
target.path = myqtapp
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro
sources.path = .
INSTALLS += target source
