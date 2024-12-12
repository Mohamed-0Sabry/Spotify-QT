#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playlistmanager.h"
#include "uiutils.h"


// Global songs list
QList<SongData> songs;
QList<SongData> allSongs;
PlaylistData allSongsPlaylist;
QList<QString> playlistNames;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_audioControls(nullptr),
    M_Player(nullptr),
    M_AudioPlayer(nullptr),
    animation(nullptr),
    playlistManager(new PlaylistManager (this)),
    songItem(new SongItem(this)),
    searchManager(new SearchManager(this)),
    playcountmanager(new PlayCountManager(this)),
    originalWidth(315),
    isPlayingSong(true),
    isShrunk(false),
    currentSongIndex(-1)
{
    ui->setupUi(this);

    // Centralize initialization
    initializeUI();
    setupListWidgets();
    setupMediaPlayer();
    setupConnections();
    setupIcons();

    // Create 'covers' directory
    QDir().mkdir("covers");


    // Load songs
    fetchSongsFromFolder(songsDirectory);
    fetchPlaylistsFromFolder(playlistDirectory);
    loadFavoriteSongsStatus();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateFavoriteSongs(const QString& songPath, bool isFavorited)
{
    PlaylistData favPlaylist = playlistManager->getPlaylist("Favorites");
    QStringList songPaths = favPlaylist.songPaths;

    if (isFavorited && !songPaths.contains(songPath)) {
        // Add to favorites
        songPaths.append(songPath);
    } else if (!isFavorited && songPaths.contains(songPath)) {
        // Remove from favorites
        songPaths.removeOne(songPath);
    }

    // Update the favorites playlist
    playlistManager->updateOrCreatePlaylist(
        "Favorites",
        "Your favorite songs collection",
        songPaths
        );

    // Update the favorite status in allSongs
    for (auto& song : allSongs) {
        if (song.AudiofilePath == songPath) {
            song.isFavorited = isFavorited;
            break;
        }
    }

    // If currently viewing the Favorites playlist, refresh the display
    if (ui->CurrentPlayingPlaylistName->text() == "Favorites") {
        on_PlaylistsListWidget_itemClicked(
            ui->PlaylistsListWidget->findItems("Favorites", Qt::MatchExactly).first()
            );
    }
}

void MainWindow::loadFavoriteSongsStatus() {


    PlaylistData favoritePlaylist = playlistManager->getPlaylist("Favorites");
    for (auto& song : allSongs) {
        song.isFavorited = favoritePlaylist.songPaths.contains(song.AudiofilePath);
    }

    if (ui->SongsListWidget->count() > 0) {
        populateSongs(ui->SongsListWidget, allSongs);
    }

}

void MainWindow::initializeUI()
{
    // Connect songs loaded signal
    connect(this, &MainWindow::songsLoaded, this, [this]() {
        populateSongs(ui->SongsListWidget, allSongs);
        if (m_audioControls) {
            m_audioControls->updateSongList(allSongs);
        }
        qDebug() << "Songs size is:" << allSongs.size();
    });

    connect(this, &MainWindow::playlistsLoaded, this, [this]() {
        populatePlaylists(ui->PlaylistsListWidget, playlistNames);
    });
}

void MainWindow::setupListWidgets()
{
    // Configure song list widget
    ui->SongsListWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->SongsListWidget->verticalScrollBar()->setSingleStep(7);

    // Confiugre PlayList Widget
    ui->PlaylistsListWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->PlaylistsListWidget->verticalScrollBar()->setSingleStep(7);

    // Configure MostPlayed Songs Widget
    ui->MostPlayedSongsListWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->MostPlayedSongsListWidget->verticalScrollBar()->setSingleStep(7);
}

void MainWindow::setupMediaPlayer()
{
    // Create media player components
    m_audioControls = new AudioControls(this);
    M_Player = new QMediaPlayer(this);
    M_AudioPlayer = new QAudioOutput(this);
    M_Player->setAudioOutput(M_AudioPlayer);

    // Initialize audio controls
    m_audioControls->initializePlayer(M_Player, M_AudioPlayer);
    m_audioControls->setUIComponents(
        ui->horizontalSlider,
        ui->SongNameInfo,
        ui->SongAuthorInfo,
        ui->CurrentSongTime,
        ui->FullSongTime,
        ui->CurrentPlayingSongImage,
        ui->Play_PauseButton
        );
}

void MainWindow::setupConnections()
{

    // Connect playback buttons
    connect(ui->Play_PauseButton, &QPushButton::clicked,
            m_audioControls, &AudioControls::playPause);
    connect(ui->PlayNextButton, &QPushButton::clicked,
            m_audioControls, &AudioControls::playNextSong);
    connect(ui->PlayPreviousButton, &QPushButton::clicked,
            m_audioControls, &AudioControls::playPreviousSong);

    // Connect song list double-click
    connect(ui->SongsListWidget, &QListWidget::itemDoubleClicked, this, [this](QListWidgetItem *item) {
                int index = ui->SongsListWidget->row(item);
                m_audioControls->playSongAtIndex(index);
            });

    // Connect slider
    connect(ui->horizontalSlider, &QSlider::sliderMoved, m_audioControls, &AudioControls::changePlaybackPosition);
   // connect(songItem, &SongItem::favButtonClicked, this, &MainWindow::updateFavorites);

    connect(ui->SearchBar, &QLineEdit::textChanged, this, &MainWindow::onSearchBarTextChanged);
    connect(m_audioControls, &AudioControls::songStartedPlaying, this, &MainWindow::onSongStartedPlaying);
    updateMostPlayedList();


    // songs Loaded Signal connections
    connect(this, &MainWindow::songsLoaded, this, [this]() {
        populateSongs(ui->SongsListWidget, allSongs);
        if (m_audioControls) {
            m_audioControls->updateSongList(allSongs);
        }

        updateMostPlayedList(); // Add this line
        loadFavoriteSongsStatus();
        qDebug() << "Songs size is:" << allSongs.size();
    });

    connect(this, &MainWindow::songsLoaded, this, &MainWindow::loadFavoriteSongsStatus);
    connect(this, &MainWindow::songsLoaded, this, [this]() {
        populateSongs(ui->SongsListWidget, allSongs);
        if (m_audioControls) {
            m_audioControls->updateSongList(allSongs);
        }
        // Add this line here too to ensure favorites are loaded after songs
        loadFavoriteSongsStatus();
        qDebug() << "Songs size is:" << allSongs.size();
    });

    // connect saving playlist with Fetching playlists
    connect(playlistManager, &PlaylistManager::playlistSaved, this, &MainWindow::fetchPlaylistsFromFolder);

    // playlist Watcher
    m_directoryWatcher = new QFileSystemWatcher(this);
    m_directoryWatcher->addPath(playlistDirectory);
    connect(m_directoryWatcher, &QFileSystemWatcher::directoryChanged, this, &MainWindow::onDirectoryChanged);

    // songs Watcher
    m_songDirectoryWatcher = new QFileSystemWatcher(this);
    m_songDirectoryWatcher->addPath(songsDirectory);
    connect(m_songDirectoryWatcher, &QFileSystemWatcher::directoryChanged, this, &MainWindow::onSongsDirectoryChanged);



}

void MainWindow::setupIcons()
{
    // Configure next and previous buttons
    ui->PlayNextButton->setIcon(QIcon("./icons/PlayNextSong.svg"));
    ui->PlayPreviousButton->setIcon(QIcon("./icons/PlayPreviousSong.svg"));
    ui->PlayNextButton->setIconSize(QSize(38, 38));
    ui->PlayPreviousButton->setIconSize(QSize(38, 38));

    // Configure play/pause button
    ui->Play_PauseButton->setIcon(QIcon("./icons/PlaySong.svg"));
    ui->Play_PauseButton->setChecked(true);
    ui->Play_PauseButton->setIconSize(QSize(64, 64));


    // Configure Create Playlist button icon
    ui->CreatePlaylistButton->setIcon((QIcon("./icons/CreatePlaylist.svg")));
    ui->CreatePlaylistButton->setIconSize(QSize(20, 20));



    ui->Shrink_ResizeButton->setIcon((QIcon("./icons/CloseWidget.svg")));
}

void MainWindow::fetchSongsFromFolder(const QString &folderPath)
{
    QDir dir(folderPath);
    allSongs.clear();
    songs.clear();
    ui->SongsListWidget->clear();
    QStringList filters = {"*.mp3", "*.wav"};
    QFileInfoList fileList = dir.entryInfoList(filters, QDir::Files);
    int filesToLoad = fileList.size();

    if (filesToLoad == 0) {
        qDebug() << "No songs found in directory:" << folderPath;
        emit songsLoaded();
        return;
    }

    for (const QFileInfo &fileInfo : fileList) {
        QMediaPlayer *tempPlayer = new QMediaPlayer(this);
        tempPlayer->setSource(QUrl::fromLocalFile(fileInfo.absoluteFilePath()));

        // Connect to media status changes
        connect(tempPlayer, &QMediaPlayer::mediaStatusChanged,
                this, [=](QMediaPlayer::MediaStatus status) mutable {
                    if (status == QMediaPlayer::LoadedMedia) {
                        processSongMetadata(fileInfo, tempPlayer);
                    }
                    if (allSongs.size() == filesToLoad) {
                        // createAllSongsPlaylist();
                        emit songsLoaded();
                    }
                });
    }
}

void MainWindow::fetchPlaylistsFromFolder(const QString &folderPath) {

    playlistNames.clear();
    playlistNames << "All Songs";

    QDir dir(folderPath);


    // Filter for .json files in the folder
    QStringList filters;
    filters << "*.json";
    dir.setNameFilters(filters);

    QFileInfoList fileList = dir.entryInfoList(QDir::Files);
    int filesToLoad = fileList.size();

    if (filesToLoad == 0) {
        qDebug() << "No playlists found in directory:" << folderPath;
        emit playlistsLoaded(); // Emit with an empty list
        return;
    }

    for (const QFileInfo &info : fileList) {
        QString playlistName = info.completeBaseName();
        if (playlistName != "All Songs") {
            playlistNames << playlistName;
        }
    }

    // Emit signal with loaded playlists when done
    qDebug() << "Load Playlists";
    qDebug() << "size of the playslits name : " << playlistNames.size();
    emit playlistsLoaded();
}

void MainWindow::onPlaylistSaved() {
    qDebug() << "Should be working!";
    fetchPlaylistsFromFolder(playlistDirectory);
}

void MainWindow::onDirectoryChanged(const QString &path) {
    qDebug() << "It should be fetching again";
    fetchPlaylistsFromFolder(path);
}

void MainWindow::onSongsDirectoryChanged(const QString &path)
{
    qDebug() << "On Songs Directory changed called";

    // Add a small delay to ensure file operations are complete
    QTimer::singleShot(100, this, [this, path]() {
        QDir dir(path);
        QStringList filters = {"*.mp3", "*.wav"};
        QFileInfoList fileList = dir.entryInfoList(filters, QDir::Files);

        // Only fetch songs if files are actually present
        if (!fileList.isEmpty()) {
            fetchSongsFromFolder(path);
        }
    });
}

void MainWindow::processSongMetadata(const QFileInfo &fileInfo, QMediaPlayer *tempPlayer)
{
    QMediaMetaData metaData = tempPlayer->metaData();

    // Extract metadata
    QString title = metaData.stringValue(QMediaMetaData::Title);
    QString artist = metaData.stringValue(QMediaMetaData::AlbumArtist);
    QString duration = QTime::fromMSecsSinceStartOfDay(tempPlayer->duration()).toString("mm:ss");

    // Create song data
    SongData song;
    song.name = title.isEmpty() ? fileInfo.baseName() : title;
    song.author = artist.isEmpty() ? "Unknown Artist" : artist;
    song.length = duration;
    song.AudiofilePath = fileInfo.absoluteFilePath();

    // Handle cover art
    QVariant cover = metaData.value(QMediaMetaData::ThumbnailImage);
    if (cover.isValid()) {
        QImage coverImage = cover.value<QImage>();
        QString coverFileName = song.name;
        QString coverPath = QString("./covers/%1.png").arg(coverFileName.replace(" ", "_"));
        coverImage.save(coverPath);
        song.picture = coverPath;
    } else {
        song.picture = "./images/default_cover.png";
    }

    allSongs.append(song);
    tempPlayer->deleteLater();
}

void MainWindow::on_Shrink_ResizeButton_clicked()
{
    // Animation for resizing the entire CurrentPlayingWidgetSongs
    animation = new QPropertyAnimation(ui->CurrentPlayingWidgetSongs, "maximumWidth");
    animation->setDuration(800);
    animation->setEasingCurve(QEasingCurve::OutCubic);

    // Toggle width based on current state
    int targetWidth = isShrunk ? originalWidth : 100;

    animation->setStartValue(ui->CurrentPlayingWidgetSongs->width());
    animation->setEndValue(targetWidth);

    animation->start(QAbstractAnimation::DeleteWhenStopped);

    // Toggle icon
    if (isShrunk) {
        ui->Shrink_ResizeButton->setIcon(QIcon("./icons/CloseWidget.svg"));
    } else {
        ui->Shrink_ResizeButton->setIcon(QIcon("./icons/OpenWidget.svg"));
    }
    isShrunk = !isShrunk;

    // Opacity animation for specific widgets
    QList<QWidget*> widgetsToFade = {
        ui->CurrentPlayingSongImageWidget,
        ui->PlayingSongControlsAndInfoWidget,
        ui->SongInfoWidget
    };

    for (QWidget* widget : widgetsToFade) {
        QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(widget);
        widget->setGraphicsEffect(opacityEffect);

        QPropertyAnimation* fadeAnimation = new QPropertyAnimation(opacityEffect, "opacity");
        fadeAnimation->setDuration(600);
        fadeAnimation->setEasingCurve(QEasingCurve::OutCubic);
        fadeAnimation->setStartValue(isShrunk ? 1.0 : 0.0);
        fadeAnimation->setEndValue(isShrunk ? 0.0 : 1.0);

        fadeAnimation->start(QAbstractAnimation::DeleteWhenStopped);
    }

    // Specific animation for CurrentPlayingPlaylistName - width and opacity
    QGraphicsOpacityEffect* playlistNameOpacityEffect = new QGraphicsOpacityEffect(ui->CurrentPlayingPlaylistName);
    ui->CurrentPlayingPlaylistName->setGraphicsEffect(playlistNameOpacityEffect);

    QParallelAnimationGroup* playlistNameAnimationGroup = new QParallelAnimationGroup();

    // Opacity animation
    QPropertyAnimation* opacityAnimation = new QPropertyAnimation(playlistNameOpacityEffect, "opacity");
    opacityAnimation->setDuration(600);
    opacityAnimation->setEasingCurve(QEasingCurve::OutCubic);
    opacityAnimation->setStartValue(isShrunk ? 1.0 : 0.0);
    opacityAnimation->setEndValue(isShrunk ? 0.0 : 1.0);

    // Width animation
    QPropertyAnimation* widthAnimation = new QPropertyAnimation(ui->CurrentPlayingPlaylistName, "maximumWidth");
    widthAnimation->setDuration(600);
    widthAnimation->setEasingCurve(QEasingCurve::OutCubic);
    widthAnimation->setStartValue(isShrunk ? ui->CurrentPlayingPlaylistName->width() : 0);
    widthAnimation->setEndValue(isShrunk ? 0 : ui->CurrentPlayingPlaylistName->sizeHint().width());

    playlistNameAnimationGroup->addAnimation(opacityAnimation);
    playlistNameAnimationGroup->addAnimation(widthAnimation);

    playlistNameAnimationGroup->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::on_CreatePlaylistButton_clicked()
{
    CreatePlaylistDialog *createplaylistdialog = new CreatePlaylistDialog(this);
    createplaylistdialog->exec();
}

void MainWindow::on_PlaylistsListWidget_itemClicked(QListWidgetItem *item)
{
    QString playlistFilename = item->text();
    QList<SongData> songstoDisplay;
    qDebug() << "this is the item " << item;
    if(playlistFilename == "All Songs"){
        songs = allSongs;
        populateSongs(ui->SongsListWidget, allSongs);
    } else{
        PlaylistData selectedPlaylist = playlistManager->getPlaylist(playlistFilename);

        for (const SongData& song : allSongs) {
            // Check if the song's AudiofilePath is in the playlist's songPaths

            qDebug() << song.AudiofilePath << "\n";
            if (selectedPlaylist.songPaths.contains(song.AudiofilePath)) {
                songstoDisplay.append(song);
            }
        }

        songs = songstoDisplay;
        populateSongs(ui->SongsListWidget, songstoDisplay);
    }
    ui->CurrentPlayingPlaylistName->setText(playlistFilename);
}

void MainWindow::onSearchBarTextChanged(const QString &searchText)
{
    // Perform search using SearchManager
    QList<SongData> filteredSongs = searchManager->searchSongs(
        searchText,
        allSongs,
        SearchManager::ByNameOrAuthor
        );


    songs = filteredSongs;
    // Refresh the song list with filtered results
    populateSongs(ui->SongsListWidget, filteredSongs);
}

void MainWindow::onSongStartedPlaying(const QString& songPath)
{
    // Increment play count when a song starts playing
    playcountmanager->incrementPlayCount(songPath);
    updateMostPlayedList();
}

void MainWindow::updateMostPlayedList()
{
    // Clear the existing items
    ui->MostPlayedSongsListWidget->clear();

    // Get sorted songs based on play count
    QList<SongData> mostPlayedSongs = playcountmanager->getSortedMostPlayedSongs(allSongs);

    // Display top songs (limit to 10 or adjust as needed)
    const int maxSongsToShow = 10;
    for (int i = 0; i < qMin(maxSongsToShow, mostPlayedSongs.size()); ++i) {
        const SongData& song = mostPlayedSongs[i];
        int playCount = playcountmanager->getPlayCount(song.AudiofilePath);

        // Create a widget to hold the song info
        QWidget* listItemWidget = new QWidget();
        listItemWidget->setStyleSheet("background: transparent;");
        QHBoxLayout* layout = new QHBoxLayout(listItemWidget);
        layout->setContentsMargins(10, 5, 10, 5);
        layout->setSpacing(10);

        // Create labels for song name and play count
        QLabel* songNameLabel = new QLabel(song.name);
        QLabel* playCountLabel = new QLabel(QString::number(playCount));
        playCountLabel->setAlignment(Qt::AlignRight);

        // Ensure labels stretch to fill the available space
        layout->addWidget(songNameLabel, 1);  // Stretch factor 1
        layout->addWidget(playCountLabel, 1);  // Stretch factor 1

        // Create a list widget item
        QListWidgetItem* listItem = new QListWidgetItem(ui->MostPlayedSongsListWidget);
        listItem->setSizeHint(QSize(listItemWidget->sizeHint().width(), 40));

        // Add the custom widget to the list item
        ui->MostPlayedSongsListWidget->setItemWidget(listItem, listItemWidget);

        // Optional: Set a tooltip with more information
        QString tooltipText = QString("%1 by %2\nLength: %3")
                                  .arg(song.name)
                                  .arg(song.author)
                                  .arg(song.length);
        listItem->setToolTip(tooltipText);
    }
}
