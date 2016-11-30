#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T14:05:37
#
#-------------------------------------------------

QT       += core gui opengl widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = osgWidgetBasic
TEMPLATE = app


SOURCES += main.cpp

HEADERS  +=

FORMS    +=

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
}else{
    LIBS += -lOpenThreadsd \
            -losgd \
            -losgDBd \
            -losgViewerd \
            -losgGAd \
}

DESTDIR = $$PWD/../bin
DLLDESTDIR = $$PWD/../bin
