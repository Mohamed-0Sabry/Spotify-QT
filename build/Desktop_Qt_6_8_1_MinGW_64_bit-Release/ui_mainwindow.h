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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_file;
    QWidget *centralwidget;
    QLabel *label;
    QLabel *FILE_NAME;
    QPushButton *pushButton_PlayPause;
    QPushButton *pushButton_Mute;
    QSlider *horizontalSlider_Volume;
    QSlider *horizontalSlider_Progress;
    QLabel *label_CurrentTime;
    QLabel *label_2;
    QLabel *label_TotalTime;
    QMenuBar *menubar;
    QMenu *menuopen;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(584, 260);
        actionOpen_file = new QAction(MainWindow);
        actionOpen_file->setObjectName("actionOpen_file");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setEnabled(true);
        label->setGeometry(QRect(30, 40, 60, 40));
        FILE_NAME = new QLabel(centralwidget);
        FILE_NAME->setObjectName("FILE_NAME");
        FILE_NAME->setGeometry(QRect(110, 40, 460, 40));
        pushButton_PlayPause = new QPushButton(centralwidget);
        pushButton_PlayPause->setObjectName("pushButton_PlayPause");
        pushButton_PlayPause->setGeometry(QRect(10, 120, 80, 41));
        pushButton_Mute = new QPushButton(centralwidget);
        pushButton_Mute->setObjectName("pushButton_Mute");
        pushButton_Mute->setGeometry(QRect(110, 120, 80, 41));
        horizontalSlider_Volume = new QSlider(centralwidget);
        horizontalSlider_Volume->setObjectName("horizontalSlider_Volume");
        horizontalSlider_Volume->setGeometry(QRect(210, 90, 331, 41));
        horizontalSlider_Volume->setValue(99);
        horizontalSlider_Volume->setOrientation(Qt::Orientation::Horizontal);
        horizontalSlider_Progress = new QSlider(centralwidget);
        horizontalSlider_Progress->setObjectName("horizontalSlider_Progress");
        horizontalSlider_Progress->setGeometry(QRect(210, 150, 331, 41));
        horizontalSlider_Progress->setOrientation(Qt::Orientation::Horizontal);
        label_CurrentTime = new QLabel(centralwidget);
        label_CurrentTime->setObjectName("label_CurrentTime");
        label_CurrentTime->setGeometry(QRect(203, 130, 41, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(250, 130, 16, 21));
        label_TotalTime = new QLabel(centralwidget);
        label_TotalTime->setObjectName("label_TotalTime");
        label_TotalTime->setGeometry(QRect(260, 130, 37, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 584, 17));
        menuopen = new QMenu(menubar);
        menuopen->setObjectName("menuopen");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuopen->menuAction());
        menuopen->addAction(actionOpen_file);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen_file->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Song Name", nullptr));
        FILE_NAME->setText(QCoreApplication::translate("MainWindow", "FILE_NAME", nullptr));
        pushButton_PlayPause->setText(QString());
        pushButton_Mute->setText(QString());
        label_CurrentTime->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        label_TotalTime->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menuopen->setTitle(QCoreApplication::translate("MainWindow", "open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
