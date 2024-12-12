#include "playcounter.h"
#include <QDir>
#include <QDebug>
#include <algorithm>

PlayCountManager::PlayCountManager(QObject *parent)
    : QObject(parent)
{
    // Store the play counts in a JSON file in the application directory
    m_playCountsFile = QDir::currentPath() + "/playcounts.json";
    loadPlayCounts();
}

PlayCountManager::~PlayCountManager()
{
    savePlayCounts();
}

void PlayCountManager::incrementPlayCount(const QString& songPath)
{
    m_playCounts[songPath] = m_playCounts.value(songPath, 0) + 1;
    savePlayCounts();
}

int PlayCountManager::getPlayCount(const QString& songPath) const
{
    return m_playCounts.value(songPath, 0);
}

QList<QPair<QString, int>> PlayCountManager::getMostPlayedSongs() const
{
    QList<QPair<QString, int>> sortedSongs;

    // Convert map to list of pairs
    for (auto it = m_playCounts.constBegin(); it != m_playCounts.constEnd(); ++it) {
        sortedSongs.append(qMakePair(it.key(), it.value()));
    }

    // Sort by play count in descending order
    std::sort(sortedSongs.begin(), sortedSongs.end(),
              [](const QPair<QString, int>& a, const QPair<QString, int>& b) {
                  return a.second > b.second;
              });

    return sortedSongs;
}

QList<SongData> PlayCountManager::getSortedMostPlayedSongs(const QList<SongData>& allSongs) const
{
    QList<SongData> sortedSongs = allSongs;

    // Sort the songs based on their play counts
    std::sort(sortedSongs.begin(), sortedSongs.end(),
              [this](const SongData& a, const SongData& b) {
                  return getPlayCount(a.AudiofilePath) > getPlayCount(b.AudiofilePath);
              });

    return sortedSongs;
}

void PlayCountManager::loadPlayCounts()
{
    QFile file(m_playCountsFile);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open play counts file for reading";
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject obj = doc.object();

    m_playCounts.clear();
    for (auto it = obj.constBegin(); it != obj.constEnd(); ++it) {
        m_playCounts.insert(it.key(), it.value().toInt());
    }

    file.close();
}

void PlayCountManager::savePlayCounts()
{
    QFile file(m_playCountsFile);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Could not open play counts file for writing";
        return;
    }

    QJsonObject obj;
    for (auto it = m_playCounts.constBegin(); it != m_playCounts.constEnd(); ++it) {
        obj.insert(it.key(), it.value());
    }

    QJsonDocument doc(obj);
    file.write(doc.toJson());
    file.close();
}
