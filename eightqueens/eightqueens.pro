# -------------------------------------------------
# Project created by QtCreator 2009-12-01T11:55:55
# -------------------------------------------------
QT += svg
TARGET = eightqueens
TEMPLATE = app
CONFIG += debug_and_release
SOURCES += main.cpp \
    mainwindow.cpp \
    chessboardwidget.cpp \
    chessboard.cpp \
    solutionsmodel.cpp \
    solutionthread_new.cpp \
    progresswidget.cpp \
    aboutdialog.cpp \
    qled.cpp \
    solutionleds.cpp \
    indexiterator.cpp \
    asciiindexiterator.cpp \
    usefulfunctions.cpp \
    solutionsearching.cpp
HEADERS += mainwindow.h \
    chessboardwidget.h \
    chessboard.h \
    solutionsmodel.h \
    solutionsthread.h \
    progresswidget.h \
    aboutdialog.h \
    qled.h \
    solutionleds.h \
    indexiterator.h \
    asciiindexiterator.h \
    usefulfunctions.h \
    solutionsearching.h
FORMS += mainwindow.ui \
    progresswidget.ui \
    aboutdialog.ui
RESOURCES += application.qrc \
    qled.qrc
win32:RC_FILE = eightqueens.rc
OTHER_FILES += TODO.txt \
    readme.txt
