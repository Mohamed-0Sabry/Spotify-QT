#include "createplaylistdialog.h"
#include "ui_createplaylistdialog.h"
#include "uiutils.h"
#include <QDebug>
#include <QMessageBox>


extern QList<SongData> allSongs;

CreatePlaylistDialog::CreatePlaylistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatePlaylistDialog),
    currentPlaylistSongs()  // Initialize the set to track selected songs
{
    ui->setupUi(this);
    playlistManager = new PlaylistManager(this);

    for (const SongData &song : allSongs) {
        // Create a new PlaylistItem widget
        PlaylistItem *playlistItem = new PlaylistItem();

        // Populate the data for this PlaylistItem
        playlistItem->setName(song.name);
        playlistItem->setAuthor(song.author);
        playlistItem->setLength(song.length);
        playlistItem->setPicture(QPixmap(song.picture)); // Load the picture
        playlistItem->setAudioFilePath(song.AudiofilePath); // Set the file path
        playlistItem->setChecked(false); // Unchecked by default

        // Create a QListWidgetItem and set the PlaylistItem widget
        QListWidgetItem *item = new QListWidgetItem(ui->AllSongsSelectionWidget);
        item->setSizeHint(playlistItem->sizeHint());
        ui->AllSongsSelectionWidget->setItemWidget(item, playlistItem);

        connect(playlistItem, &PlaylistItem::checkStateChanged, this, &CreatePlaylistDialog::onSongCheckStateChanged);
    }
}

CreatePlaylistDialog::~CreatePlaylistDialog()
{
    delete ui;
}

void CreatePlaylistDialog::onSongCheckStateChanged(bool checked, const QString& audioFilePath)
{
    if (checked) {
        // Add song to the current playlist
        currentPlaylistSongs.insert(audioFilePath);
        qDebug() << "Added song:" << audioFilePath;
    } else {
        // Remove song from the current playlist
        currentPlaylistSongs.remove(audioFilePath);
        qDebug() << "Removed song:" << audioFilePath;
    }

    // Optional: Update UI to show number of selected songs
    // ui->SelectedSongsCountLabel->setText(QString("Selected Songs: %1").arg(currentPlaylistSongs.size()));
}

void CreatePlaylistDialog::on_CancelCreationPlaylistButton_clicked()
{
    reject();
}

void CreatePlaylistDialog::on_SubmittionCreatePlaylistButton_clicked()
{
    QString name = ui->PlaylistNameLineEdit->text();
    QString description = ui->PlaylistDescriptionLineEdit->text();

    // Check if name is empty
    if (name.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a name for the playlist.");
        return;
    }

    // Check if any songs are selected
    if (currentPlaylistSongs.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please select at least one song for the playlist.");
        return;
    }

    qDebug() << "Creating playlist with name:" << name
             << "description:" << description
             << "and" << currentPlaylistSongs.size() << "songs";

    // Try to create the playlist using PlaylistManager
    bool success = playlistManager->createPlaylist(name, description, currentPlaylistSongs.values());

    if (success) {
        QMessageBox::information(this, "Success", "Playlist created successfully.");
        accept();  // Close the dialog with a successsful result
    } else {
        QMessageBox::warning(this, "Error", "Failed to create playlist. It may already exist.");
    }
}
