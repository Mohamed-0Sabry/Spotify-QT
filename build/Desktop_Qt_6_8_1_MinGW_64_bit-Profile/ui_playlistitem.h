/********************************************************************************
** Form generated from reading UI file 'playlistitem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLISTITEM_H
#define UI_PLAYLISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlaylistItem
{
public:
    QHBoxLayout *horizontalLayout;
    QCheckBox *AddSongCheckBox;
    QLabel *pictureLabel;
    QWidget *middleWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *nameLabel;
    QLabel *authorLabel;
    QLabel *lengthLabel;

    void setupUi(QWidget *PlaylistItem)
    {
        if (PlaylistItem->objectName().isEmpty())
            PlaylistItem->setObjectName("PlaylistItem");
        PlaylistItem->resize(499, 64);
        PlaylistItem->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        horizontalLayout = new QHBoxLayout(PlaylistItem);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        AddSongCheckBox = new QCheckBox(PlaylistItem);
        AddSongCheckBox->setObjectName("AddSongCheckBox");

        horizontalLayout->addWidget(AddSongCheckBox);

        pictureLabel = new QLabel(PlaylistItem);
        pictureLabel->setObjectName("pictureLabel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pictureLabel->sizePolicy().hasHeightForWidth());
        pictureLabel->setSizePolicy(sizePolicy);
        pictureLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(pictureLabel);

        middleWidget = new QWidget(PlaylistItem);
        middleWidget->setObjectName("middleWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(3);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(middleWidget->sizePolicy().hasHeightForWidth());
        middleWidget->setSizePolicy(sizePolicy1);
        middleWidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_3 = new QHBoxLayout(middleWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        nameLabel = new QLabel(middleWidget);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(nameLabel);

        authorLabel = new QLabel(middleWidget);
        authorLabel->setObjectName("authorLabel");
        authorLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(authorLabel);


        horizontalLayout->addWidget(middleWidget);

        lengthLabel = new QLabel(PlaylistItem);
        lengthLabel->setObjectName("lengthLabel");
        sizePolicy.setHeightForWidth(lengthLabel->sizePolicy().hasHeightForWidth());
        lengthLabel->setSizePolicy(sizePolicy);
        lengthLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(lengthLabel);


        retranslateUi(PlaylistItem);

        QMetaObject::connectSlotsByName(PlaylistItem);
    } // setupUi

    void retranslateUi(QWidget *PlaylistItem)
    {
        PlaylistItem->setWindowTitle(QCoreApplication::translate("PlaylistItem", "Form", nullptr));
        AddSongCheckBox->setText(QString());
        pictureLabel->setText(QCoreApplication::translate("PlaylistItem", "TextLabel", nullptr));
        nameLabel->setText(QCoreApplication::translate("PlaylistItem", "lable", nullptr));
        authorLabel->setText(QCoreApplication::translate("PlaylistItem", "TextLabel", nullptr));
        lengthLabel->setText(QCoreApplication::translate("PlaylistItem", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlaylistItem: public Ui_PlaylistItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLISTITEM_H
