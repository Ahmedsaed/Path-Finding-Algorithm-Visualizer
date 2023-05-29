QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    astar.cpp \
    bds.cpp \
    bfs.cpp \
    dfs.cpp \
    dls.cpp \
    gbfs.cpp \
    graphnode.cpp \
    ids.cpp \
    main.cpp \
    mainwindow.cpp \
    ucs.cpp

HEADERS += \
    algorithm.h \
    graphnode.h \
    main.h \
    mainwindow.h \
    pair.h \
    priority_queue.h \
    priotiy_queue.tpp \
    queue.h \
    queue.tpp \
    romania.h \
    stack.h \
    stack.tpp \
    vector.h \
    vector.tpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    assets.qrc \
    assets.qrc
