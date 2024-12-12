#include "uiutils.h"

extern QList<SongData> allSongs;

void populatePlaylists(QListWidget* playlistWidget, const QStringList& playlists) {
    playlistWidget->clear();
    for (const QString &playlist : playlists) {
        QListWidgetItem *item = new QListWidgetItem(playlist, playlistWidget);
        item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    }
}

void populateSongs(QListWidget* songListWidget, QList<SongData>& songs) {
    if (!songListWidget) return;
    songListWidget->clear();
    for (SongData &song : songs) {
        QListWidgetItem *item = new QListWidgetItem(songListWidget);
        SongItem *songWidget = new SongItem();
        songWidget->setSongData(song.picture, song.name, song.author, song.length, song.isFavorited);
        item->setSizeHint(songWidget->sizeHint());
        songListWidget->setItemWidget(item, songWidget);
    }
}
