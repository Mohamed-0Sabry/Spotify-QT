/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_file;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *CreatePlaylistButton;
    QLabel *label_2;
    QListWidget *PlaylistsListWidget;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QListWidget *MostPlayedSongsListWidget;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *SearchBar;
    QListWidget *SongsListWidget;
    QWidget *CurrentPlayingWidgetSongs;
    QVBoxLayout *verticalLayout;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout;
    QLabel *CurrentPlayingPlaylistName;
    QPushButton *Shrink_ResizeButton;
    QListWidget *NextSongsInQueueListWidget;
    QSpacerItem *verticalSpacer;
    QWidget *CurrentPlayingSongImageWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *CurrentPlayingSongImage;
    QWidget *SongInfoWidget;
    QVBoxLayout *verticalLayout_5;
    QLabel *SongNameInfo;
    QLabel *SongAuthorInfo;
    QWidget *PlayingSongControlsAndInfoWidget;
    QVBoxLayout *verticalLayout_4;
    QWidget *SongControlsWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *PlayPreviousButton;
    QPushButton *Play_PauseButton;
    QPushButton *PlayNextButton;
    QSpacerItem *horizontalSpacer_3;
    QWidget *TimerSliderWidget;
    QVBoxLayout *verticalLayout_6;
    QSlider *horizontalSlider;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *CurrentSongTime;
    QSpacerItem *horizontalSpacer;
    QLabel *FullSongTime;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1143, 675);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:black;"));
        actionOpen_file = new QAction(MainWindow);
        actionOpen_file->setObjectName("actionOpen_file");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("widget_2{\n"
"background-color:#121212;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"\n"
"}\n"
""));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(2);
        gridLayout->setVerticalSpacing(8);
        gridLayout->setContentsMargins(0, 2, 0, 2);
        widget_5 = new QWidget(widget);
        widget_5->setObjectName("widget_5");
        verticalLayout_3 = new QVBoxLayout(widget_5);
        verticalLayout_3->setObjectName("verticalLayout_3");
        widget_7 = new QWidget(widget_5);
        widget_7->setObjectName("widget_7");
        horizontalLayout_6 = new QHBoxLayout(widget_7);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        CreatePlaylistButton = new QPushButton(widget_7);
        CreatePlaylistButton->setObjectName("CreatePlaylistButton");
        CreatePlaylistButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        CreatePlaylistButton->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"border:none;"));

        horizontalLayout_6->addWidget(CreatePlaylistButton);

        label_2 = new QLabel(widget_7);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("Font: bold;\n"
"font-size: 20px;"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(label_2);


        verticalLayout_3->addWidget(widget_7);

        PlaylistsListWidget = new QListWidget(widget_5);
        new QListWidgetItem(PlaylistsListWidget);
        new QListWidgetItem(PlaylistsListWidget);
        new QListWidgetItem(PlaylistsListWidget);
        PlaylistsListWidget->setObjectName("PlaylistsListWidget");
        PlaylistsListWidget->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border: none;\n"
"	 padding:10px 5px;\n"
"border-radius: 8px;\n"
"    background-color: #121212; /* Spotify-like dark background */\n"
"    color: #FFFFFF; /* White text for better contrast */\n"
"    font-size: 14px;\n"
"    outline: none; /* Removes focus rectangle */\n"
"}\n"
"\n"
"QListWidget::item {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    padding: 5px; /* Smaller padding for compact spacing */\n"
"    margin: 2px; /* Minimal margin for tighter layout */\n"
"    border-radius: 5px; /* Subtle rounded corners */\n"
"}\n"
"\n"
"QListWidget::item:hover {\n"
"	 cursor: pointer;\n"
"    background-color: #1DB954; /* Spotify green for hover effect */\n"
"    color: #FFFFFF; /* Keep text white on hover */\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"    background-color: #535353; /* Darker gray for selected item */\n"
"    color: #FFFFFF; /* White text for selected item */\n"
"}\n"
"\n"
"QScrollBar:vertical, QScrollBar:horizontal {\n"
"    background: transpare"
                        "nt; /* Hide scrollbar background */\n"
"    width: 0px; /* Completely hide the scrollbar */\n"
"    height: 0px; /* Completely hide the scrollbar */\n"
"}\n"
""));

        verticalLayout_3->addWidget(PlaylistsListWidget);


        gridLayout->addWidget(widget_5, 1, 0, 1, 1);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName("widget_4");
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(widget_4);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("Font: bold;\n"
"font-size: 20px;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label);

        MostPlayedSongsListWidget = new QListWidget(widget_4);
        new QListWidgetItem(MostPlayedSongsListWidget);
        new QListWidgetItem(MostPlayedSongsListWidget);
        new QListWidgetItem(MostPlayedSongsListWidget);
        MostPlayedSongsListWidget->setObjectName("MostPlayedSongsListWidget");
        MostPlayedSongsListWidget->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border: none;\n"
"	 padding:10px 5px;\n"
"border-radius: 8px;\n"
"    background-color: #121212; /* Spotify-like dark background */\n"
"    color: #FFFFFF; /* White text for better contrast */\n"
"    font-size: 14px;\n"
"    outline: none; /* Removes focus rectangle */\n"
"}\n"
"\n"
"QListWidget::item {\n"
"    cursor: pointer;\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    padding: 5px; /* Smaller padding for compact spacing */\n"
"    margin: 2px; /* Minimal margin for tighter layout */\n"
"    border-radius: 5px; /* Subtle rounded corners */\n"
"}\n"
"\n"
"QListWidget::item:hover {\n"
"    background-color: #1DB954; /* Spotify green for hover effect */\n"
"    color: #FFFFFF; /* Keep text white on hover */\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"    background-color: #535353; /* Darker gray for selected item */\n"
"    color: #FFFFFF; /* White text for selected item */\n"
"}\n"
"\n"
"QScrollBar:vertical, QScrollBar:horizontal {\n"
"    background: transpa"
                        "rent; /* Hide scrollbar background */\n"
"    width: 0px; /* Completely hide the scrollbar */\n"
"    height: 0px; /* Completely hide the scrollbar */\n"
"}\n"
""));

        verticalLayout_2->addWidget(MostPlayedSongsListWidget);


        gridLayout->addWidget(widget_4, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(widget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(5);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        widget_2->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_7 = new QVBoxLayout(widget_2);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 10, 0, 0);
        widget_8 = new QWidget(widget_2);
        widget_8->setObjectName("widget_8");
        horizontalLayout_7 = new QHBoxLayout(widget_8);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(-1, 5, -1, 0);
        SearchBar = new QLineEdit(widget_8);
        SearchBar->setObjectName("SearchBar");
        SearchBar->setStyleSheet(QString::fromUtf8("/* Modern SearchBar Stylesheet */\n"
"QLineEdit#SearchBar {\n"
"    /* Base styling */\n"
"    background-color: #f7f8fa;  /* Light grey background */\n"
"    border: 2px solid #e1e4e8;  /* Soft border */\n"
"    border-radius: 8px;  /* Rounded corners */\n"
"    padding: 8px 15px;  /* Internal padding */\n"
"    color: #333;  /* Dark text color */\n"
"    font-size: 14px;  /* Readable font size */\n"
"    font-weight: 400;  /* Normal font weight */\n"
"    \n"
"    /* Smooth transition for focus and hover effects */\n"
"    transition: border-color 0.3s ease, \n"
"                background-color 0.3s ease;\n"
"}\n"
"\n"
"/* Hover state */\n"
"QLineEdit#SearchBar:hover {\n"
"    background-color: #f0f1f3;\n"
"    border-color: #c8d0d9;\n"
"}\n"
"\n"
"/* Focus state */\n"
"QLineEdit#SearchBar:focus {\n"
"    background-color: white;\n"
"    border-color: #1DB954; \n"
"    box-shadow: 0 0 5px rgba(52, 152, 219, 0.3);\n"
"}\n"
"\n"
"/* Placeholder text styling */\n"
"QLineEdit#SearchBar::placeholder {\n"
"    co"
                        "lor: #888;\n"
"    font-style: italic;\n"
"}\n"
"\n"
"/* Search icon integration (if using a style hint) */\n"
"QLineEdit#SearchBar::left-icon {\n"
"    padding-left: 10px;\n"
"    color: #888;\n"
"}"));

        horizontalLayout_7->addWidget(SearchBar);


        verticalLayout_7->addWidget(widget_8);

        SongsListWidget = new QListWidget(widget_2);
        SongsListWidget->setObjectName("SongsListWidget");
        SongsListWidget->setStyleSheet(QString::fromUtf8("/* Song item widget */\n"
"QListWidget {\n"
"	background-color:#121212;\n"
"	border-radius: 10%;\n"
"	padding: 10px;\n"
"	margin: 15px 0px 10px;\n"
"}\n"
"/* Hover effect for Song Item */\n"
"QListWidget::item{\n"
"	border-radius: 10%;\n"
"}\n"
"QListWidget::item:hover {\n"
"    background-color: #1c1c1c; /* Light green aura */\n"
"}\n"
"\n"
"/* Image label */\n"
"QLabel#pictureLabel {\n"
"    border-radius: 50%; /* Circular image */\n"
"}\n"
"\n"
"/* Song name styling */\n"
"QLabel#nameLabel {\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"    color: #ffffff; /* White text for song name */\n"
"}\n"
"\n"
"/* Author name styling */\n"
"QLabel#authorLabel {\n"
"    font-size: 12px;\n"
"    color: #aaaaaa; /* Light grey for author name */\n"
"}\n"
"\n"
"\n"
"/* Heart button styling */\n"
"QPushButton#favoriteButton {\n"
"    background: none;\n"
"    border: none;\n"
"    qproperty-icon: url(:/icons/heartunfilled.svg); /* Default unfilled heart */\n"
"    qproperty-iconSize: 22px;\n"
"}\n"
"\n"
"/* Chang"
                        "e heart icon when checked (filled) */\n"
"QPushButton#favoriteButton:checked {\n"
"    qproperty-icon: url(:/icons/heartfilled.svg); /* Filled heart */\n"
"}\n"
"\n"
"QScrollBar:vertical, QScrollBar:horizontal {\n"
"    background: transparent; /* Hide scrollbar background */\n"
"    width: 0px; /* Completely hide the scrollbar */\n"
"    height: 0px; /* Completely hide the scrollbar */\n"
"}\n"
"\n"
""));
        SongsListWidget->setFrameShape(QFrame::Shape::NoFrame);
        SongsListWidget->setFrameShadow(QFrame::Shadow::Plain);
        SongsListWidget->setAutoScrollMargin(8);
        SongsListWidget->setMovement(QListView::Movement::Static);
        SongsListWidget->setViewMode(QListView::ViewMode::ListMode);
        SongsListWidget->setSortingEnabled(false);

        verticalLayout_7->addWidget(SongsListWidget);


        horizontalLayout_2->addWidget(widget_2);

        CurrentPlayingWidgetSongs = new QWidget(centralwidget);
        CurrentPlayingWidgetSongs->setObjectName("CurrentPlayingWidgetSongs");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(CurrentPlayingWidgetSongs->sizePolicy().hasHeightForWidth());
        CurrentPlayingWidgetSongs->setSizePolicy(sizePolicy2);
        CurrentPlayingWidgetSongs->setMaximumSize(QSize(315, 16777215));
        CurrentPlayingWidgetSongs->setStyleSheet(QString::fromUtf8("background-color:#121212;\n"
"margin:10px;\n"
"border-radius:10%;"));
        verticalLayout = new QVBoxLayout(CurrentPlayingWidgetSongs);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        widget_6 = new QWidget(CurrentPlayingWidgetSongs);
        widget_6->setObjectName("widget_6");
        horizontalLayout = new QHBoxLayout(widget_6);
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        CurrentPlayingPlaylistName = new QLabel(widget_6);
        CurrentPlayingPlaylistName->setObjectName("CurrentPlayingPlaylistName");
        CurrentPlayingPlaylistName->setStyleSheet(QString::fromUtf8("Font: bold;\n"
"font-size: 20px;"));

        horizontalLayout->addWidget(CurrentPlayingPlaylistName);

        Shrink_ResizeButton = new QPushButton(widget_6);
        Shrink_ResizeButton->setObjectName("Shrink_ResizeButton");

        horizontalLayout->addWidget(Shrink_ResizeButton);


        verticalLayout->addWidget(widget_6);

        NextSongsInQueueListWidget = new QListWidget(CurrentPlayingWidgetSongs);
        new QListWidgetItem(NextSongsInQueueListWidget);
        new QListWidgetItem(NextSongsInQueueListWidget);
        new QListWidgetItem(NextSongsInQueueListWidget);
        new QListWidgetItem(NextSongsInQueueListWidget);
        new QListWidgetItem(NextSongsInQueueListWidget);
        NextSongsInQueueListWidget->setObjectName("NextSongsInQueueListWidget");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(NextSongsInQueueListWidget->sizePolicy().hasHeightForWidth());
        NextSongsInQueueListWidget->setSizePolicy(sizePolicy3);
        NextSongsInQueueListWidget->setMaximumSize(QSize(16777215, 100));

        verticalLayout->addWidget(NextSongsInQueueListWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        CurrentPlayingSongImageWidget = new QWidget(CurrentPlayingWidgetSongs);
        CurrentPlayingSongImageWidget->setObjectName("CurrentPlayingSongImageWidget");
        sizePolicy2.setHeightForWidth(CurrentPlayingSongImageWidget->sizePolicy().hasHeightForWidth());
        CurrentPlayingSongImageWidget->setSizePolicy(sizePolicy2);
        horizontalLayout_5 = new QHBoxLayout(CurrentPlayingSongImageWidget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        CurrentPlayingSongImage = new QLabel(CurrentPlayingSongImageWidget);
        CurrentPlayingSongImage->setObjectName("CurrentPlayingSongImage");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(CurrentPlayingSongImage->sizePolicy().hasHeightForWidth());
        CurrentPlayingSongImage->setSizePolicy(sizePolicy4);
        CurrentPlayingSongImage->setMaximumSize(QSize(290, 290));
        CurrentPlayingSongImage->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(CurrentPlayingSongImage);


        verticalLayout->addWidget(CurrentPlayingSongImageWidget);

        SongInfoWidget = new QWidget(CurrentPlayingWidgetSongs);
        SongInfoWidget->setObjectName("SongInfoWidget");
        verticalLayout_5 = new QVBoxLayout(SongInfoWidget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        SongNameInfo = new QLabel(SongInfoWidget);
        SongNameInfo->setObjectName("SongNameInfo");
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setKerning(true);
        SongNameInfo->setFont(font);
        SongNameInfo->setStyleSheet(QString::fromUtf8("font:26px;\n"
"font-weight:bold;"));
        SongNameInfo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(SongNameInfo);

        SongAuthorInfo = new QLabel(SongInfoWidget);
        SongAuthorInfo->setObjectName("SongAuthorInfo");
        SongAuthorInfo->setStyleSheet(QString::fromUtf8("height:fit-content;\n"
"width:fit-content;"));
        SongAuthorInfo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(SongAuthorInfo);


        verticalLayout->addWidget(SongInfoWidget);

        PlayingSongControlsAndInfoWidget = new QWidget(CurrentPlayingWidgetSongs);
        PlayingSongControlsAndInfoWidget->setObjectName("PlayingSongControlsAndInfoWidget");
        verticalLayout_4 = new QVBoxLayout(PlayingSongControlsAndInfoWidget);
        verticalLayout_4->setSpacing(4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        SongControlsWidget = new QWidget(PlayingSongControlsAndInfoWidget);
        SongControlsWidget->setObjectName("SongControlsWidget");
        sizePolicy2.setHeightForWidth(SongControlsWidget->sizePolicy().hasHeightForWidth());
        SongControlsWidget->setSizePolicy(sizePolicy2);
        horizontalLayout_3 = new QHBoxLayout(SongControlsWidget);
        horizontalLayout_3->setSpacing(4);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        PlayPreviousButton = new QPushButton(SongControlsWidget);
        PlayPreviousButton->setObjectName("PlayPreviousButton");
        PlayPreviousButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        PlayPreviousButton->setStyleSheet(QString::fromUtf8(""));
        PlayPreviousButton->setCheckable(true);

        horizontalLayout_3->addWidget(PlayPreviousButton);

        Play_PauseButton = new QPushButton(SongControlsWidget);
        Play_PauseButton->setObjectName("Play_PauseButton");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(Play_PauseButton->sizePolicy().hasHeightForWidth());
        Play_PauseButton->setSizePolicy(sizePolicy5);
        Play_PauseButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Play_PauseButton->setMouseTracking(false);
        Play_PauseButton->setStyleSheet(QString::fromUtf8(""));
        Play_PauseButton->setCheckable(true);

        horizontalLayout_3->addWidget(Play_PauseButton);

        PlayNextButton = new QPushButton(SongControlsWidget);
        PlayNextButton->setObjectName("PlayNextButton");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(PlayNextButton->sizePolicy().hasHeightForWidth());
        PlayNextButton->setSizePolicy(sizePolicy6);
        PlayNextButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        PlayNextButton->setStyleSheet(QString::fromUtf8(""));
        PlayNextButton->setCheckable(true);

        horizontalLayout_3->addWidget(PlayNextButton);

        horizontalSpacer_3 = new QSpacerItem(100, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_4->addWidget(SongControlsWidget);

        TimerSliderWidget = new QWidget(PlayingSongControlsAndInfoWidget);
        TimerSliderWidget->setObjectName("TimerSliderWidget");
        TimerSliderWidget->setStyleSheet(QString::fromUtf8("width: fit-content;\n"
"height:fit-content;\n"
""));
        verticalLayout_6 = new QVBoxLayout(TimerSliderWidget);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(10, 0, 10, 0);
        horizontalSlider = new QSlider(TimerSliderWidget);
        horizontalSlider->setObjectName("horizontalSlider");
        sizePolicy2.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy2);
        horizontalSlider->setStyleSheet(QString::fromUtf8("/* Groove - the track */\n"
"QSlider::groove:horizontal {\n"
"    height: 6px;\n"
"    background: #404040; /* Dark gray for the track background */\n"
"    border: none;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"/* Progress bar - before the handle */\n"
"QSlider::sub-page:horizontal {\n"
"    background: #1DB954; /* Spotify green for the progress */\n"
"    border: none;\n"
"    height: 6px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"/* Remaining bar - after the handle */\n"
"QSlider::add-page:horizontal {\n"
"    background: #404040; /* Dark gray for the remaining part */\n"
"    border: none;\n"
"    height: 6px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"/* Handle - the draggable knob */\n"
"QSlider::handle:horizontal {\n"
"    background: #FFF; /* White handle for elegance */\n"
"    border: 1px solid #1DB954; /* Subtle border for Spotify green */\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin: -6px 0; /* Align with the track */\n"
"    border-radius: 8px; /* Perfectly circular */\n"
"}\n"
"\n"
""
                        "/* Handle hover effect */\n"
"QSlider::handle:horizontal:hover {\n"
"    background: #1DB954; /* Spotify green on hover */\n"
"    border: 1px solid #FFF; /* Invert the border for contrast */\n"
"}\n"
"\n"
"/* Handle focus (for accessibility) */\n"
"QSlider::handle:horizontal:focus {\n"
"    border: 2px solid #1DB954; /* Stronger border on focus */\n"
"    background: #FFF; /* Keep the handle visible */\n"
"}\n"
""));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout_6->addWidget(horizontalSlider);

        widget_3 = new QWidget(TimerSliderWidget);
        widget_3->setObjectName("widget_3");
        widget_3->setStyleSheet(QString::fromUtf8("width: fit-content;\n"
"height:fit-content;\n"
""));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        CurrentSongTime = new QLabel(widget_3);
        CurrentSongTime->setObjectName("CurrentSongTime");
        CurrentSongTime->setStyleSheet(QString::fromUtf8("width: fit-content;\n"
"height:fit-content;\n"
"\n"
""));
        CurrentSongTime->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_4->addWidget(CurrentSongTime);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        FullSongTime = new QLabel(widget_3);
        FullSongTime->setObjectName("FullSongTime");
        FullSongTime->setStyleSheet(QString::fromUtf8("width: fit-content;\n"
"height:fit-content;"));
        FullSongTime->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(FullSongTime);


        verticalLayout_6->addWidget(widget_3);


        verticalLayout_4->addWidget(TimerSliderWidget);


        verticalLayout->addWidget(PlayingSongControlsAndInfoWidget);


        horizontalLayout_2->addWidget(CurrentPlayingWidgetSongs);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1143, 25));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen_file->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        CreatePlaylistButton->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Your Playlists ", nullptr));

        const bool __sortingEnabled = PlaylistsListWidget->isSortingEnabled();
        PlaylistsListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = PlaylistsListWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = PlaylistsListWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = PlaylistsListWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "New Item", nullptr));
        PlaylistsListWidget->setSortingEnabled(__sortingEnabled);

        label->setText(QCoreApplication::translate("MainWindow", "Most Played Songs", nullptr));

        const bool __sortingEnabled1 = MostPlayedSongsListWidget->isSortingEnabled();
        MostPlayedSongsListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem3 = MostPlayedSongsListWidget->item(0);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = MostPlayedSongsListWidget->item(1);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("MainWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = MostPlayedSongsListWidget->item(2);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("MainWindow", "New Item", nullptr));
        MostPlayedSongsListWidget->setSortingEnabled(__sortingEnabled1);

        CurrentPlayingPlaylistName->setText(QCoreApplication::translate("MainWindow", "All Songs", nullptr));
        Shrink_ResizeButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));

        const bool __sortingEnabled2 = NextSongsInQueueListWidget->isSortingEnabled();
        NextSongsInQueueListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem6 = NextSongsInQueueListWidget->item(0);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("MainWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = NextSongsInQueueListWidget->item(1);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("MainWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = NextSongsInQueueListWidget->item(2);
        ___qlistwidgetitem8->setText(QCoreApplication::translate("MainWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = NextSongsInQueueListWidget->item(3);
        ___qlistwidgetitem9->setText(QCoreApplication::translate("MainWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem10 = NextSongsInQueueListWidget->item(4);
        ___qlistwidgetitem10->setText(QCoreApplication::translate("MainWindow", "New Item", nullptr));
        NextSongsInQueueListWidget->setSortingEnabled(__sortingEnabled2);

        CurrentPlayingSongImage->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        SongNameInfo->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        SongAuthorInfo->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        PlayPreviousButton->setText(QString());
        Play_PauseButton->setText(QString());
        PlayNextButton->setText(QString());
        CurrentSongTime->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        FullSongTime->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
