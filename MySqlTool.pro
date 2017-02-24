TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    SqlData.cpp \
    sqlite3.c

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    SqlData.h \
    sqlite3.h
