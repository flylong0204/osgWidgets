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

INCLUDEPATH += $$PWD/../sdk/3rd/x64/include
INCLUDEPATH += $$PWD/../sdk/osg/x64/include

LIBS += -L"$$PWD/../sdk/3rd/x64/lib"
LIBS += -L"$$PWD/../sdk/osg/x64/lib"

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
