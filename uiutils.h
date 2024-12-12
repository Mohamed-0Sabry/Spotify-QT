#ifndef UIUTILS_H
#define UIUTILS_H

#include <QListWidget>
#include <QStringList>
#include "songitem.h"
#include <QString>
#include <QList>

struct SongData {
    QString picture;
    QString name;
    QString author;
    QString length;
    QString AudiofilePath;
    bool isFavorited;
};


void populatePlaylists(QListWidget* playlistWidget, const QStringList& playlists);
void populateSongs(QListWidget* songListWidget, QList<SongData>& songs);

#endif // UIUTILS_H
