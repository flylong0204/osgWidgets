#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T14:05:37
#
#-------------------------------------------------

QT       += core gui opengl widgets

TARGET = osgWidgetBasic
TEMPLATE = app


SOURCES += main.cpp

HEADERS  +=

FORMS    +=

INCLUDEPATH += $$PWD/../sdk/3rd/x64/include
INCLUDEPATH += $$PWD/../sdk/osg/x64/include

LIBS += -L"$$PWD/../sdk/3rd/x64/lib"
LIBS += -L"$$PWD/../sdk/osg/x64/lib"

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
