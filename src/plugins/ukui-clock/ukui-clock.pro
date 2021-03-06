#-------------------------------------------------
#
# Project created by QtCreator 2014-06-28T21:00:26
#
#-------------------------------------------------

QT       += core gui multimedia sql

# 适配窗口管理器圆角阴影
QT += KWindowSystem dbus x11extras

# 适配窗口管理器圆角阴影
LIBS +=-lpthread
LIBS +=-lX11

# 配置gsettings
CONFIG += link_pkgconfig
PKGCONFIG += gsettings-qt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ukui-clock
TEMPLATE = app

LIBS    +=  -lX11
PKGCONFIG += gsettings-qt

SOURCES += \
    about.cpp \
    adaptscreeninfo.cpp \
    btnNew.cpp \
    clickableLabel.cpp \
    clock.cpp \
    closeOrHide.cpp \
    countdownAnimation.cpp \
    customStyle.cpp \
    deleteMsg.cpp \
    dotlineDemo.cpp \
    itemNew.cpp \
    main.cpp \
    noticeAlarm.cpp \
    noticeDialog.cpp \
    qroundProgressBar.cpp \
    setAlarmRepeatDialog.cpp \
    setUpBtnNew.cpp \
    setupPage.cpp \
    singleApplication.cpp \
    stopwatchItem.cpp \
    verticalScroll24.cpp \
    verticalScroll60.cpp \
    verticalScroll99.cpp \
    xatom-helper.cpp

TRANSLATIONS += ../../../translations/ukui-clock/ukui-clock_tr.ts \
                ../../../translations/ukui-clock/ukui-clock_zh_CN.ts

HEADERS  += clock.h \
    about.h \
    adaptscreeninfo.h \
    btnNew.h \
    clickableLabel.h \
    closeOrHide.h \
    connection.h \
    countdownAnimation.h \
    customStyle.h \
    debug.h \
    deleteMsg.h \
    dotlineDemo.h \
    itemNew.h \
    noticeAlarm.h \
    noticeDialog.h \
    qroundProgressBar.h \
    setAlarmRepeatDialog.h \
    setUpBtnNew.h \
    setupPage.h \
    singleApplication.h \
    stopwatchItem.h \
    verticalScroll24.h \
    verticalScroll60.h \
    verticalScroll99.h \
    xatom-helper.h


FORMS    += clock.ui \
    about.ui \
    closeOrHide.ui \
    deleteMsg.ui \
    noticeAlarm.ui \
    setupPage.ui


RESOURCES += \
    images.qrc

RC_FILE = clock.rc

unix {
    target.path = /usr/bin/
    INSTALLS += target

    music.path = /usr/share/ukui-clock/
    music.files += music/bark.ogg
    music.files += music/drip.ogg
    music.files += music/glass.ogg
    music.files += music/sonar.ogg
    INSTALLS += music

    translation.path = /usr/share/ukui-sidebar/ukui-clock
    translation.files += ../../../translations/ukui-clock/*.qm
    INSTALLS += translation
}
desktopfile.files = ukui-clock.desktop
desktopfile.path = /usr/share/applications/

INSTALLS += desktopfile

DISTFILES += \
    music/bark.ogg \
    music/drip.ogg \
    music/glass.ogg \
    music/sonar.ogg
