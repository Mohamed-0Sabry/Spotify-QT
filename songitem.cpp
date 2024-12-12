#include "songitem.h"
#include "ui_songitem.h"
#include <QGraphicsDropShadowEffect>
#include "uiutils.h"
#include "mainwindow.h"

extern QList<SongData> allSongs;

SongItem::SongItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SongItem)
{
    ui->setupUi(this);
}

SongItem::~SongItem()
{
    delete ui;
}

void SongItem::setSongData(const QString &picturePath, const QString &name, const QString &author, const QString &length, bool &isFavorited) {
    // Set basic song data
    QPixmap pixmap(picturePath);
    ui->pictureLabel->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->nameLabel->setText(name);
    ui->authorLabel->setText(author);
    ui->lengthLabel->setText(length);

    // Create and apply shadow effect
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(30);
    shadowEffect->setColor(Qt::black);
    shadowEffect->setOffset(0, 0);
    ui->pictureLabel->setGraphicsEffect(shadowEffect);
    if(isFavorited){
        ui->favorite->setIcon(QIcon("./icons/heartfilled.svg"));
    }else{
        ui->favorite->setIcon(QIcon("./icons/heartunfilled.svg"));
    }
    // Get the song path
    QString songPath;
    for (const auto& song : allSongs) {
        if (song.name == name) {
            songPath = song.AudiofilePath;
            break;
        }
    }

    // ui->favoriteButton->setIcon(QIcon("./icons/AddFavSong.svg"));


    // Check if song is in Favorites playlist
    MainWindow* mainWindow = qobject_cast<MainWindow*>(window());
    if (mainWindow && !songPath.isEmpty()) {
        PlaylistData favPlaylist = mainWindow->getPlaylistManager()->getPlaylist("Favorites");
        isFavorited = favPlaylist.songPaths.contains(songPath);
        updateFavoriteIcon(isFavorited);
    }

    // Connect button click handler
    connect(ui->favorite, &QPushButton::clicked, this, [this, songPath, name, &isFavorited]() {
        MainWindow* mainWindow = qobject_cast<MainWindow*>(window());
        if (!mainWindow) return;

        // Toggle favorite state
        isFavorited = !isFavorited;

        // Update UI
        updateFavoriteIcon(isFavorited);

        // Update playlist
        mainWindow->updateFavoriteSongs(songPath, isFavorited);

        emit favButtonClicked();
    });
}

void SongItem::updateFavoriteIcon(bool isFavorited) {
    ui->favorite->setChecked(isFavorited);

    if(isFavorited){
        ui->favorite->setIcon(QIcon("./icons/heartfilled.svg"));
    }else{
        ui->favorite->setIcon(QIcon("./icons/heartunfilled.svg"));
    }
}

