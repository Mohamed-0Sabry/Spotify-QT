#ifndef PLAYLISTITEM_H
#define PLAYLISTITEM_H

#include <QWidget>
#include <QPixmap>

namespace Ui {
class PlaylistItem;
}

class PlaylistItem : public QWidget
{
    Q_OBJECT

public:
    explicit PlaylistItem(QWidget *parent = nullptr);
    ~PlaylistItem();

    void setName(const QString &name);
    void setAuthor(const QString &author);
    void setLength(const QString &length);
    void setPicture(const QPixmap &picture);
    void setChecked(bool checked);

    void setAudioFilePath(const QString &path);
    QString getAudioFilePath() const;



    QString getName() const;
    bool isChecked() const;

signals:
    void checkboxToggled(bool checked);
    void checkStateChanged(bool checked, const QString& songName);

private slots:
    void onCheckboxToggled(bool checked);

private:
    Ui::PlaylistItem *ui;
    QString m_audioFilePath;
};

#endif // PLAYLISTITEM_H
