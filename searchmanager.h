#ifndef SEARCHMANAGER_H
#define SEARCHMANAGER_H

#include <QObject>
#include <QList>
#include <QString>
#include "uiutils.h"

class SearchManager : public QObject {
    Q_OBJECT

public:
    explicit SearchManager(QObject *parent = nullptr);

    // Search method that returns filtered list of songs
    QList<SongData> searchSongs(const QString& searchTerm, const QList<SongData>& songsList);

    // Enum to specify search type
    enum SearchType {
        ByName,
        ByAuthor,
        ByNameOrAuthor
    };

    // Overloaded search method with search type parameter
    QList<SongData> searchSongs(const QString& searchTerm,
                                const QList<SongData>& songsList,
                                SearchType searchType);

private:
    // Helper method to check if a string contains search term (case-insensitive)
    bool containsSearchTerm(const QString& source, const QString& searchTerm);
};

#endif // SEARCHMANAGER_H
