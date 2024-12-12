#ifndef AUDIOCONTROLS_H
#define AUDIOCONTROLS_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QListWidgetItem>
#include <QSlider>
#include <QLabel>
#include <QPushButton>
#include "uiutils.h"

class AudioControls : public QObject
{
    Q_OBJECT

public:
    explicit AudioControls(QObject *parent = nullptr);

    void initializePlayer(QMediaPlayer* player, QAudioOutput* audioOutput);
    void setUIComponents(QSlider* slider, QLabel* songName, QLabel* authorName, QLabel* currentTime, QLabel* fullTime, QLabel* albumArt, QPushButton* playPauseButton);
    void playPause();
    void playNextSong();
    void playPreviousSong();
    void playSongAtIndex(int index);
    void changePlaybackPosition(int position);
    void updateSongList(const QList<SongData>& newSongs);


signals:
    void songChanged(const SongData& song);
    void playbackStateChanged();
    void songStartedPlaying(const QString& songPath); // Add this new signal


private slots:
    void updateSliderPosition(qint64 position);
    void setSliderRange(qint64 duration);
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);
    void updateCurrentTime(qint64 position);

private:
    QMediaPlayer* m_player;
    QAudioOutput* m_audioOutput;

    // ui components
    QSlider* m_slider;
    QLabel* m_songName;
    QLabel* m_authorName;
    QLabel* m_currentTime;
    QLabel* m_fullTime;
    QLabel* m_albumArt;
    QPushButton* m_playPauseButton;

    // song management
    QList<SongData> m_songs;
    int m_currentSongIndex;

    void updateUIForSong(const SongData& song);
};

#endif // AUDIOCONTROLS_H
