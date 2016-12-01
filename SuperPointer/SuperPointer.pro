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

INCLUDEPATH += $$PWD/../sdk/3rd/x86/include
INCLUDEPATH += $$PWD/../sdk/osg/x86/include

LIBS += -L"$$PWD/../sdk/3rd/x86/lib"
LIBS += -L"$$PWD/../sdk/osg/x86/lib"

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
