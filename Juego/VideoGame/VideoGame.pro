QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ataque_bas.cpp \
    ataque_enemy.cpp \
    boss.cpp \
    boss_CL.cpp \
    boss_jm.cpp \
    caida_libre.cpp \
    enemi_dis.cpp \
    health.cpp \
    inicio.cpp \
    main.cpp \
    mainwindow.cpp \
    mcu.cpp \
    menu.cpp \
    moob.cpp \
    mru.cpp \
    obstaculos.cpp \
    player.cpp \
    registro.cpp \
    score.cpp \
    slime.cpp \
    tiropara.cpp

HEADERS += \
    ataque_bas.h \
    ataque_enemy.h \
    boss.h \
    boss_CL.h \
    boss_jm.h \
    caida_libre.h \
    enemi_dis.h \
    health.h \
    inicio.h \
    mainwindow.h \
    mcu.h \
    menu.h \
    moob.h \
    mru.h \
    obstaculos.h \
    player.h \
    registro.h \
    score.h \
    slime.h \
    tiropara.h

FORMS += \
    inicio.ui \
    mainwindow.ui \
    menu.ui \
    registro.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagenes.qrc

DISTFILES += \
    Imagenes Proyecto final/roca2.gif \
    Imagenes Proyecto final/valla1.gif
