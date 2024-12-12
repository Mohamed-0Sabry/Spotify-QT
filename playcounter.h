#ifndef PLAYCOUNT_H
#define PLAYCOUNT_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include "uiutils.h"

class PlayCountManager : public QObject
{
    Q_OBJECT

public:
    explicit PlayCountManager(QObject *parent = nullptr);
    ~PlayCountManager();

    void incrementPlayCount(const QString& songPath);
    int getPlayCount(const QString& songPath) const;
    QList<QPair<QString, int>> getMostPlayedSongs() const;
    void loadPlayCounts();
    void savePlayCounts();
    QList<SongData> getSortedMostPlayedSongs(const QList<SongData>& allSongs) const;

private:
    QMap<QString, int> m_playCounts;
    QString m_playCountsFile;
};

#endif // PLAYCOUNT_H
