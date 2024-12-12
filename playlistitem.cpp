#include "playlistitem.h"
#include "ui_PlaylistItem.h"

// Constructor
PlaylistItem::PlaylistItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlaylistItem)
{
    ui->setupUi(this); // Set up the UI

    // Connect the checkbox toggle signal
    connect(ui->AddSongCheckBox, &QCheckBox::toggled, this, &PlaylistItem::onCheckboxToggled);
}

// Destructor
PlaylistItem::~PlaylistItem()
{
    delete ui; // Clean up the UI pointer
}

// Setters for the labels and checkbox
void PlaylistItem::setLength(const QString &length) {
    ui->lengthLabel->setText(length);
}

void PlaylistItem::setAuthor(const QString &author) {
    ui->authorLabel->setText(author);
}

void PlaylistItem::setName(const QString &name) {
    ui->nameLabel->setText(name);
}

void PlaylistItem::setPicture(const QPixmap &picture) {
    ui->pictureLabel->setPixmap(picture.scaled(ui->pictureLabel->size(),  Qt::KeepAspectRatio,  Qt::SmoothTransformation));
}

void PlaylistItem::setChecked(bool checked) {
    ui->AddSongCheckBox->setChecked(checked);
}

QString PlaylistItem::getName() const {
    return ui->nameLabel->text();
}

bool PlaylistItem::isChecked() const {
    return ui->AddSongCheckBox->isChecked();
}

void PlaylistItem::setAudioFilePath(const QString &path) {
    m_audioFilePath = path;
}

QString PlaylistItem::getAudioFilePath() const {
    return m_audioFilePath;
}

void PlaylistItem::onCheckboxToggled(bool checked) {
    emit checkboxToggled(checked);
    emit checkStateChanged(checked, m_audioFilePath); // Emit path instead of name
}

