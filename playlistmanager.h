#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H

#include <QObject>
#include <QList>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QDir>

struct PlaylistData {
    QString name;
    QString description;
    QList<QString> songPaths;
    QString createdAt;
    QString lastModified;

    // Convert to JSON for storage
    QJsonObject toJson() const {
        QJsonObject playlistJson;
        playlistJson["name"] = name;
        playlistJson["description"] = description;

        QJsonArray songPathsArray;
        for (const QString& path : songPaths) {
            songPathsArray.append(path);
        }

        playlistJson["songPaths"] = songPathsArray;
        playlistJson["createdAt"] = createdAt;
        playlistJson["lastModified"] = lastModified;

        return playlistJson;
    }

    // Create from JSON
    static PlaylistData fromJson(const QJsonObject& json) {
        PlaylistData playlist;
        playlist.name = json["name"].toString();
        playlist.description = json["description"].toString();

        QJsonArray songPathsArray = json["songPaths"].toArray();
        for (const QJsonValue& pathValue : songPathsArray) {
            playlist.songPaths.append(pathValue.toString());
        }

        playlist.createdAt = json["createdAt"].toString();
        playlist.lastModified = json["lastModified"].toString();

        return playlist;
    }
};

class PlaylistManager : public QObject {
    Q_OBJECT

public:
    explicit PlaylistManager(QObject *parent = nullptr);
    bool createPlaylist(const QString& name, const QString& description, const QStringList& songs);
    bool addSongToPlaylist(const QString& playlistName, const QString& songPath);
    bool removeSongFromPlaylist(const QString& playlistName, const QString& songPath);
    bool updateOrCreatePlaylist(const QString& name, const QString& description, const QStringList& filePaths);

    QList<PlaylistData> getAllPlaylists();
    bool savePlaylist(const PlaylistData& playlist);
    PlaylistData loadPlaylist(const QString& filename);
    PlaylistData getPlaylist(const QString& playlistName);
    bool deletePlaylist(const QString& playlistName);

signals:
    void playlistSaved(const QString& folderPath);

private:
    QString m_playlistDirectory;
};

#endif // PLAYLISTMANAGER_H
