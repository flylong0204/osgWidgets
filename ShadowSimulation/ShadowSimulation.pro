QT       += core gui opengl widgets

TARGET = ShadowView
TEMPLATE = app

HEADERS += \
#    AdapterWidget.h \
    ShadowView.h \
    MainWindow.h

SOURCES += \
    main.cpp \
#    AdapterWidget.cpp \
    ShadowView.cpp \
    MainWindow.cpp

FORMS += \
    MainWindow.ui


INCLUDEPATH += $$PWD/../sdk/3rd/x64/include
INCLUDEPATH += $$PWD/../sdk/osg/x64/include

LIBS += -L"$$PWD/../sdk/3rd/x64/lib"
LIBS += -L"$$PWD/../sdk/osg/x64/lib"

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
