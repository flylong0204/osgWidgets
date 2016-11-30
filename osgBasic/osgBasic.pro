QT       +=
TARGET = osgBasic
TEMPLATE = app


SOURCES += main.cpp \

HEADERS  += \

FORMS    += \


INCLUDEPATH += $$PWD/../3rd/include
INCLUDEPATH += $$PWD/../osg/include

LIBS += -L"$$PWD/../3rd/lib"
LIBS += -L"$$PWD/../osg/lib"

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
