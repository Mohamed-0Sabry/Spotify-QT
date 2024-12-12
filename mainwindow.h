#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "audiocontrols.h"
#include "createplaylistdialog.h"
#include "searchmanager.h"
#include "playcounter.h"
#include <QMainWindow>
#include <QtMultimedia>
#include <QFileDialog>
#include <QAudioOutput>
#include <QListWidget>
#include <QScrollBar>
#include <QHBoxLayout>
#include <QStyle>
#include <QPixmap>
#include <QIcon>
#include <QPropertyAnimation>
#include <QDir>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QFileInfo>
#include <QTime>
#include <QDebug>
#include <QDialog>
#include <QFileSystemWatcher>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    PlaylistManager* getPlaylistManager() { return playlistManager; }



signals:
    void songsLoaded();
    void playlistsLoaded();


public slots:
    void onPlaylistSaved();
    void updateFavoriteSongs(const QString& songPath, bool isFavorited);
    void onSongStartedPlaying(const QString& songPath);
    void updateMostPlayedList();



private slots:
    void on_Shrink_ResizeButton_clicked();
    void on_CreatePlaylistButton_clicked();
    void onDirectoryChanged(const QString &path);
    void on_PlaylistsListWidget_itemClicked(QListWidgetItem *item);
    void onSearchBarTextChanged(const QString &searchText);

private:
    // Initialization methods
    void initializeUI();
    void setupMediaPlayer();
    void setupConnections();
    void setupIcons();
    void setupListWidgets();

    // Song loading methods
    void fetchSongsFromFolder(const QString &folderPath);
    void fetchPlaylistsFromFolder(const QString &folderPath);
    void processSongMetadata(const QFileInfo &fileInfo, QMediaPlayer *tempPlayer);
    void createAllSongsPlaylist();
    void loadFavoriteSongsStatus();


    // Method to refresh song list with filtered results
    void refreshSongList(const QList<SongData>& songsToDisplay);



    // UI components
    Ui::MainWindow *ui;
    AudioControls *m_audioControls;
    QMediaPlayer *M_Player;
    QAudioOutput *M_AudioPlayer;
    QPropertyAnimation *animation;
    PlaylistManager *playlistManager;
    QFileSystemWatcher *m_directoryWatcher;
    SongItem *songItem;
    SearchManager *searchManager;
    PlayCountManager* playcountmanager;


    // State variables
    int originalWidth;
    bool isPlayingSong;
    bool isShrunk;
    int currentSongIndex;
    QString playlistDirectory = QDir::currentPath() + "/playlists";
    QString songsDirectory = QDir::currentPath() + "/Songs";
};

#endif // MAINWINDOW_H
