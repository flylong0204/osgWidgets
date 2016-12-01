#-------------------------------------------------
#
# Project created by QtCreator 2016-12-01T17:37:21
#
#-------------------------------------------------

QT       += core gui opengl widgets

TARGET = ShadowSimulation
TEMPLATE = app


SOURCES += main.cpp\
        ShadowView.cpp \
    MainWindow.cpp

HEADERS  += \
            ShadowView.h \
    MainWindow.h

FORMS    += \
    MainWindow.ui

INCLUDEPATH += $$PWD/../sdk/3rd/x86/include
INCLUDEPATH += $$PWD/../sdk/osg/x86/include

LIBS += -L"$$PWD/../sdk/3rd/x86/lib"
LIBS += -L"$$PWD/../sdk/osg/x86/lib"

CONFIG(release, debug|release){
    LIBS += -lOpenThreads \
            -losg \
            -losgDB \
            -losgViewer \
            -losgGA \
            -losgQt \
}else{
    LIBS += -lOpenThreadsd \
            -losgd \
            -losgDBd \
            -losgViewerd \
            -losgGAd \
            -losgQtd \
}

DESTDIR = $$PWD/../bin
DLLDESTDIR = $$PWD/../bin
