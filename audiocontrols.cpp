#include "audiocontrols.h"
#include <QDebug>
#include <QTime>

extern QList<SongData> songs;  // Reference to the global songs list

AudioControls::AudioControls(QObject *parent)
    : QObject(parent),
    m_player(nullptr),
    m_audioOutput(nullptr),
    m_slider(nullptr),
    m_songName(nullptr),
    m_authorName(nullptr),
    m_currentTime(nullptr),
    m_fullTime(nullptr),
    m_albumArt(nullptr),
    m_playPauseButton(nullptr),
    m_currentSongIndex(-1)
{}

void AudioControls::initializePlayer(QMediaPlayer* player, QAudioOutput* audioOutput)
{
    m_player = player;
    m_audioOutput = audioOutput;
    if (m_player) {
        connect(m_player, &QMediaPlayer::positionChanged, this, &AudioControls::updateSliderPosition);
        connect(m_player, &QMediaPlayer::durationChanged, this, &AudioControls::setSliderRange);
        connect(m_player, &QMediaPlayer::mediaStatusChanged, this, &AudioControls::onMediaStatusChanged);
        connect(m_player, &QMediaPlayer::positionChanged, this, &AudioControls::updateCurrentTime);
    }
}

void AudioControls::setUIComponents(QSlider* slider, QLabel* songName, QLabel* authorName, QLabel* currentTime, QLabel* fullTime, QLabel* albumArt, QPushButton* playPauseButton)
{
    m_slider = slider;
    m_songName = songName;
    m_authorName = authorName;
    m_currentTime = currentTime;
    m_fullTime = fullTime;
    m_albumArt = albumArt;
    m_playPauseButton = playPauseButton;
}

void AudioControls::playPause()
{
    if (!m_player || m_currentSongIndex == -1) {
        return;
    }

    if (m_player->playbackState() == QMediaPlayer::PlayingState) {
        m_player->pause();
        m_playPauseButton->setIcon(QIcon("./icons/PlaySong.svg"));
    } else if (m_player->playbackState() == QMediaPlayer::PausedState || m_player->playbackState() == QMediaPlayer::StoppedState) {
        m_player->play();
        m_playPauseButton->setIcon(QIcon("./icons/PauseSong.svg"));
    }

    emit playbackStateChanged();
}

void AudioControls::playNextSong()
{
    m_currentSongIndex++;
    if (m_currentSongIndex >= songs.size()) {
        m_currentSongIndex = 0; // Loop back to the first song
    }
    playSongAtIndex(m_currentSongIndex);
}

void AudioControls::playPreviousSong()
{
    m_currentSongIndex--;
    if (m_currentSongIndex < 0) {
        m_currentSongIndex = songs.size() - 1; // Loop back to the last song
    }
    playSongAtIndex(m_currentSongIndex);
}

void AudioControls::playSongAtIndex(int index)
{
    if (index < 0 || index >= songs.size()) {
        qDebug() << songs.size();
        qDebug() << "Invalid song index";
        return;
    }

    const SongData& selectedSong = songs.at(index);

    if (!m_player) {
        qDebug() << "Player not initialized";
        return;
    }

    m_currentSongIndex = index;
    m_player->setSource(QUrl::fromLocalFile(selectedSong.AudiofilePath));
    m_player->play();

    updateUIForSong(selectedSong);
    emit songChanged(selectedSong);
    emit songStartedPlaying(selectedSong.AudiofilePath); // Add this line

}

void AudioControls::updateUIForSong(const SongData& song)
{
    if (m_playPauseButton)
        m_playPauseButton->setIcon(QIcon("./icons/PauseSong.svg"));

    if (m_songName)
        m_songName->setText(song.name);

    if (m_authorName)
        m_authorName->setText(song.author);

    if (m_fullTime)
        m_fullTime->setText(song.length);

    if (m_albumArt) {
        QPixmap songImage(song.picture);
        if (!songImage.isNull()) {
            m_albumArt->setPixmap(songImage);
            m_albumArt->setScaledContents(true);
        } else {
            m_albumArt->setPixmap(QPixmap("./covers/DefultImage.png"));
            m_albumArt->setScaledContents(true);
            qDebug() << "Image not found for" << song.name;
        }
    }

    if (m_slider)
        m_slider->setValue(0);
}

void AudioControls::updateSliderPosition(qint64 position)
{
    if (m_slider && !m_slider->isSliderDown()) {
        m_slider->setValue(position);
    }
}

void AudioControls::setSliderRange(qint64 duration)
{
    if (m_slider)
        m_slider->setRange(0, duration);
}

void AudioControls::changePlaybackPosition(int position)
{
    if (m_player)
        m_player->setPosition(position);
}

void AudioControls::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia) {
        playNextSong();
    }
}

void AudioControls::updateCurrentTime(qint64 position)
{
    if (!m_currentTime) return;

    int seconds = position / 1000;
    int minutes = seconds / 60;
    seconds %= 60;

    QString timeStr = QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));

    m_currentTime->setText(timeStr);
}

void AudioControls::updateSongList(const QList<SongData>& newSongs)
{
    songs = newSongs;
    qDebug() << "Songs updated. New size:" << songs.size();
}




