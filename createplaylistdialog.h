#ifndef CREATEPLAYLISTDIALOG_H
#define CREATEPLAYLISTDIALOG_H

#include <QDialog>
#include <QMediaPlayer>
#include <QSet>
#include "playlistmanager.h"
#include "playlistitem.h"

namespace Ui {
class CreatePlaylistDialog;
}

class CreatePlaylistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreatePlaylistDialog(QWidget *parent = nullptr);
    ~CreatePlaylistDialog();

private slots:
    void on_CancelCreationPlaylistButton_clicked();
    void on_SubmittionCreatePlaylistButton_clicked();
    void onSongCheckStateChanged(bool checked, const QString &audioFilePath);

private:
    Ui::CreatePlaylistDialog *ui;
    PlaylistManager *playlistManager;
    QSet<QString> currentPlaylistSongs;  // To track selected songs
};

#endif // CREATEPLAYLISTDIALOG_H
