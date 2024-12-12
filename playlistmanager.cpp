#include "playlistmanager.h"
#include <QDebug>
#include <QDateTime>

PlaylistManager::PlaylistManager(QObject *parent)
    : QObject(parent)
{
    // Create playlists directory if it doesn't exist
    m_playlistDirectory = QDir::currentPath() + "/playlists";
    QDir().mkpath(m_playlistDirectory);
}

bool PlaylistManager::createPlaylist(const QString& name, const QString& description, const QStringList& filePaths)
{
    // Check if playlist already exists
    QString filename = m_playlistDirectory + "/" + name.toLower().replace(" ", "_") + ".json";
    if (QFile::exists(filename)) {
        qDebug() << "Playlist already exists:" << name;
        return false;
    }

    // Create playlist data
    PlaylistData playlist;
    playlist.name = name;
    playlist.description = description;
    playlist.createdAt = QDateTime::currentDateTime().toString(Qt::ISODate);
    playlist.lastModified = playlist.createdAt;

    // Add the selected songs to the playlist
    playlist.songPaths = filePaths;

    // Save playlist
    return savePlaylist(playlist);
}

bool PlaylistManager::updateOrCreatePlaylist(const QString& name, const QString& description, const QStringList& filePaths)
{
    QString filename = m_playlistDirectory + "/" + name.toLower().replace(" ", "_") + ".json";

    PlaylistData playlist;
    playlist.name = name;
    playlist.description = description;
    playlist.lastModified = QDateTime::currentDateTime().toString(Qt::ISODate);
    playlist.songPaths = filePaths;

    if (QFile::exists(filename)) {
        // If playlist exists, just update it
        playlist.createdAt = getPlaylist(name).createdAt; // Preserve original creation date
    } else {
        // If it's a new playlist, set creation date
        playlist.createdAt = playlist.lastModified;
    }

    return savePlaylist(playlist);
}

bool PlaylistManager::addSongToPlaylist(const QString& playlistName, const QString& songPath)
{
    // Load existing playlist
    QString filename = m_playlistDirectory + "/" + playlistName.toLower().replace(" ", "_") + ".json";
    if (!QFile::exists(filename)) {
        qDebug() << "Playlist does not exist:" << playlistName;
        return false;
    }

    PlaylistData playlist = loadPlaylist(filename);

    // Check if song is already in playlist
    if (playlist.songPaths.contains(songPath)) {
        qDebug() << "Song already in playlist";
        return false;
    }

    // Add song path
    playlist.songPaths.append(songPath);
    playlist.lastModified = QDateTime::currentDateTime().toString(Qt::ISODate);

    // Save updated playlist
    return savePlaylist(playlist);
}

bool PlaylistManager::removeSongFromPlaylist(const QString& playlistName, const QString& songPath)
{
    QString filename = m_playlistDirectory + "/" + playlistName.toLower().replace(" ", "_") + ".json";
    if (!QFile::exists(filename)) {
        qDebug() << "Playlist does not exist:" << playlistName;
        return false;
    }

    PlaylistData playlist = loadPlaylist(filename);

    // Remove song from playlist
    playlist.songPaths.removeAll(songPath);
    playlist.lastModified = QDateTime::currentDateTime().toString(Qt::ISODate);

    // Save updated playlist
    return savePlaylist(playlist);
}

QList<PlaylistData> PlaylistManager::getAllPlaylists()
{
    QList<PlaylistData> playlists;
    QDir playlistDir(m_playlistDirectory);

    // Get all JSON files in the playlists directory
    QStringList playlistFiles = playlistDir.entryList(QStringList() << "*.json", QDir::Files);

    for (const QString& filename : playlistFiles) {
        PlaylistData playlist = loadPlaylist(m_playlistDirectory + "/" + filename);
        playlists.append(playlist);
    }

    return playlists;
}

PlaylistData PlaylistManager::getPlaylist(const QString& playlistName)
{
    QString filename = m_playlistDirectory + "/" + playlistName.toLower().replace(" ", "_") + ".json";
    if (!QFile::exists(filename)) {
        qDebug() << "Playlist does not exist:" << playlistName;
        return PlaylistData(); // Return empty playlist
    }

    return loadPlaylist(filename);
}

bool PlaylistManager::deletePlaylist(const QString& playlistName)
{
    QString filename = m_playlistDirectory + "/" + playlistName.toLower().replace(" ", "_") + ".json";
    QFile file(filename);

    if (!file.exists()) {
        qDebug() << "Playlist does not exist:" << playlistName;
        return false;
    }

    return file.remove();
}

bool PlaylistManager::savePlaylist(const PlaylistData& playlist)
{
    // Create filename
    QString filename = m_playlistDirectory + "/" +
                       playlist.name.toLower().replace(" ", "_") + ".json";

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Could not open file for writing:" << filename;
        return false;
    }

    // Convert playlist to JSON
    QJsonDocument doc(playlist.toJson());
    file.write(doc.toJson());
    emit playlistSaved(m_playlistDirectory);  // Emit signal after saving
    file.close();


    return true;
}

PlaylistData PlaylistManager::loadPlaylist(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open file for reading:" << filename;
        return PlaylistData();
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isNull()) {
        qDebug() << "Failed to parse JSON";
        return PlaylistData();
    }

    return PlaylistData::fromJson(doc.object());
}
