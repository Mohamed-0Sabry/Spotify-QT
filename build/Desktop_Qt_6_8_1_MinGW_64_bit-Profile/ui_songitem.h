/********************************************************************************
** Form generated from reading UI file 'songitem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONGITEM_H
#define UI_SONGITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SongItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *pictureLabel;
    QWidget *middleWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *nameLabel;
    QLabel *authorLabel;
    QLabel *lengthLabel;
    QPushButton *favoriteButton;

    void setupUi(QWidget *SongItem)
    {
        if (SongItem->objectName().isEmpty())
            SongItem->setObjectName("SongItem");
        SongItem->resize(400, 64);
        SongItem->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        horizontalLayout = new QHBoxLayout(SongItem);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, -1, 14, -1);
        pictureLabel = new QLabel(SongItem);
        pictureLabel->setObjectName("pictureLabel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pictureLabel->sizePolicy().hasHeightForWidth());
        pictureLabel->setSizePolicy(sizePolicy);
        pictureLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(pictureLabel);

        middleWidget = new QWidget(SongItem);
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

        lengthLabel = new QLabel(SongItem);
        lengthLabel->setObjectName("lengthLabel");
        sizePolicy.setHeightForWidth(lengthLabel->sizePolicy().hasHeightForWidth());
        lengthLabel->setSizePolicy(sizePolicy);
        lengthLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(lengthLabel);

        favoriteButton = new QPushButton(SongItem);
        favoriteButton->setObjectName("favoriteButton");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(favoriteButton->sizePolicy().hasHeightForWidth());
        favoriteButton->setSizePolicy(sizePolicy2);
        favoriteButton->setMaximumSize(QSize(20, 20));
        favoriteButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        favoriteButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        qproperty-icon: url(./icons/AddFavSong.svg);\n"
"    }\n"
""));
        favoriteButton->setCheckable(true);
        favoriteButton->setChecked(false);

        horizontalLayout->addWidget(favoriteButton);


        retranslateUi(SongItem);

        QMetaObject::connectSlotsByName(SongItem);
    } // setupUi

    void retranslateUi(QWidget *SongItem)
    {
        SongItem->setWindowTitle(QCoreApplication::translate("SongItem", "Form", nullptr));
        pictureLabel->setText(QCoreApplication::translate("SongItem", "TextLabel", nullptr));
        nameLabel->setText(QCoreApplication::translate("SongItem", "TextLabel", nullptr));
        authorLabel->setText(QCoreApplication::translate("SongItem", "TextLabel", nullptr));
        lengthLabel->setText(QCoreApplication::translate("SongItem", "TextLabel", nullptr));
        favoriteButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SongItem: public Ui_SongItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONGITEM_H
