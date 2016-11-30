#-------------------------------------------------
#
# Project created by QtCreator 2016-12-01T01:19:50
#
#-------------------------------------------------

QT       +=

TARGET = ViewerEvent
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
             -losgGa \
}else{
    LIBS += -lOpenThreadsd \
            -losgd \
            -losgDBd \
            -losgViewerd \
            -losgGad \
}

DESTDIR = $$PWD/../bin
DLLDESTDIR = $$PWD/../bin
