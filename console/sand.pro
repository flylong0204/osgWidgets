QT       += core gui opengl widgets

TARGET = sand
TEMPLATE = app

RESOURCES += \
    console.qrc

FORMS += \
    console.ui

DISTFILES += \
    sand.pro.user \
    console.vcxproj \
    console.vcxproj.filters

HEADERS += \
    console.h \
    eventadapterwidget.h \
    sandwidget.h

SOURCES += \
    console.cpp \
    eventadapterwidget.cpp \
    main.cpp \
    sandwidget.cpp


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
