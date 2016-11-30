#-------------------------------------------------
#
# Project created by QtCreator 2016-12-01T00:47:14
#
#-------------------------------------------------

QT       +=

TARGET = SuperPointer
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
}else{
    LIBS += -lOpenThreadsd \
            -losgd \
            -losgDBd \
            -losgViewerd \
}

DESTDIR = $$PWD/../bin
DLLDESTDIR = $$PWD/../bin
