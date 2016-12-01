#-------------------------------------------------
#
# Project created by QtCreator 2016-12-01T17:37:21
#
#-------------------------------------------------

QT       += core gui opengl widgets

TARGET = ShadowSimulation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ShadowView.cpp

HEADERS  += mainwindow.h \
    ShadowView.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$PWD/../sdk/3rd/include
INCLUDEPATH += $$PWD/../sdk/osg/include

LIBS += -L"$$PWD/../sdk/3rd/lib"
LIBS += -L"$$PWD/../sdk/osg/lib"

CONFIG(release, debug|release){
    LIBS +=  -lOpenThreads \
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
