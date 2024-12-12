#ifndef SONGITEM_H
#define SONGITEM_H

#include <QWidget>
#include <QListWidget>

namespace Ui {
class SongItem;
}

class SongItem : public QWidget
{
    Q_OBJECT

public:
    explicit SongItem(QWidget *parent = nullptr);
    ~SongItem();

    void setSongData(const QString &picturePath, const QString &name, const QString &author, const QString &length, bool &isFavorited);
    void updateFavoriteIcon(bool isFavorited);
    Ui::SongItem *ui;

signals:
    void favButtonClicked();




private:
};

#endif // SONGITEM_H

