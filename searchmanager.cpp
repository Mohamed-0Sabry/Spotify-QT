#include "searchmanager.h"
#include <QDebug>

SearchManager::SearchManager(QObject *parent)
    : QObject(parent)
{
}


// Overloading the SearchSongs function
QList<SongData> SearchManager::searchSongs(const QString& searchTerm, const QList<SongData>& songsList)
{
    // Default to searching by name or author
    return searchSongs(searchTerm, songsList, SearchType::ByNameOrAuthor);
}

QList<SongData> SearchManager::searchSongs(const QString& searchTerm, const QList<SongData>& songsList, SearchType searchType)
{
    // If search term is empty, return all songs
    if (searchTerm.trimmed().isEmpty()) {
        return songsList;
    }

    QList<SongData> filteredSongs;

    for (const SongData& song : songsList) {
        bool matchFound = false;

        switch (searchType) {
        case ByName:
            matchFound = containsSearchTerm(song.name, searchTerm);
            break;
        case ByAuthor:
            matchFound = containsSearchTerm(song.author, searchTerm);
            break;
        case ByNameOrAuthor:
            matchFound = containsSearchTerm(song.name, searchTerm) ||
                         containsSearchTerm(song.author, searchTerm);
            break;
        }

        if (matchFound) {
            filteredSongs.append(song);
        }
    }

    return filteredSongs;
}

bool SearchManager::containsSearchTerm(const QString& source, const QString& searchTerm)
{
    // Case-insensitive partial match
    return source.toLower().contains(searchTerm.toLower());
}
