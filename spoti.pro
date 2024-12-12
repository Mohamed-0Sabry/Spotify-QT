QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    audiocontrols.cpp \
    createplaylistdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    playcounter.cpp \
    playlistitem.cpp \
    playlistmanager.cpp \
    searchmanager.cpp \
    songitem.cpp \
    uiutils.cpp

HEADERS += \
    audiocontrols.h \
    createplaylistdialog.h \
    mainwindow.h \
    playcounter.h \
    playlistitem.h \
    playlistmanager.h \
    searchmanager.h \
    songitem.h \
    uiutils.h

FORMS += \
    createplaylistdialog.ui \
    mainwindow.ui \
    playlistitem.ui \
    songitem.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    icons/CreatePlaylist.svg \
    icons/PauseSong.svg \
    icons/PlayNextSong.svg \
    icons/PlayPreviousSong.svg \
    icons/PlaySong.svg \
    icons/heartfilled.svg \
    icons/heartunfilled.svg \
    images/therealslimshade.png \
    images/withoutme.png \

RESOURCES += \
    allSources.qrc
