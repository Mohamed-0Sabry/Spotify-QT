/********************************************************************************
** Form generated from reading UI file 'createplaylistdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPLAYLISTDIALOG_H
#define UI_CREATEPLAYLISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreatePlaylistDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *UpperSectionWidget;
    QVBoxLayout *verticalLayout;
    QLabel *UpperTitleLabel;
    QWidget *PlaylistNameAndInfoWidget;
    QHBoxLayout *horizontalLayout_5;
    QWidget *PlaylistNameWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *PlaylistNameLineEdit;
    QWidget *PlaylistInfoWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *PlaylistDescriptionLineEdit;
    QListWidget *AllSongsSelectionWidget;
    QWidget *ButtonsWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *SubmittionCreatePlaylistButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *CancelCreationPlaylistButton;

    void setupUi(QDialog *CreatePlaylistDialog)
    {
        if (CreatePlaylistDialog->objectName().isEmpty())
            CreatePlaylistDialog->setObjectName("CreatePlaylistDialog");
        CreatePlaylistDialog->resize(878, 372);
        verticalLayout_2 = new QVBoxLayout(CreatePlaylistDialog);
        verticalLayout_2->setObjectName("verticalLayout_2");
        UpperSectionWidget = new QWidget(CreatePlaylistDialog);
        UpperSectionWidget->setObjectName("UpperSectionWidget");
        verticalLayout = new QVBoxLayout(UpperSectionWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        UpperTitleLabel = new QLabel(UpperSectionWidget);
        UpperTitleLabel->setObjectName("UpperTitleLabel");
        QFont font;
        font.setPointSize(25);
        font.setBold(true);
        UpperTitleLabel->setFont(font);
        UpperTitleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(UpperTitleLabel);

        PlaylistNameAndInfoWidget = new QWidget(UpperSectionWidget);
        PlaylistNameAndInfoWidget->setObjectName("PlaylistNameAndInfoWidget");
        horizontalLayout_5 = new QHBoxLayout(PlaylistNameAndInfoWidget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        PlaylistNameWidget = new QWidget(PlaylistNameAndInfoWidget);
        PlaylistNameWidget->setObjectName("PlaylistNameWidget");
        horizontalLayout_4 = new QHBoxLayout(PlaylistNameWidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label = new QLabel(PlaylistNameWidget);
        label->setObjectName("label");

        horizontalLayout_4->addWidget(label);

        PlaylistNameLineEdit = new QLineEdit(PlaylistNameWidget);
        PlaylistNameLineEdit->setObjectName("PlaylistNameLineEdit");

        horizontalLayout_4->addWidget(PlaylistNameLineEdit);


        horizontalLayout_5->addWidget(PlaylistNameWidget);

        PlaylistInfoWidget = new QWidget(PlaylistNameAndInfoWidget);
        PlaylistInfoWidget->setObjectName("PlaylistInfoWidget");
        horizontalLayout_3 = new QHBoxLayout(PlaylistInfoWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(PlaylistInfoWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        PlaylistDescriptionLineEdit = new QLineEdit(PlaylistInfoWidget);
        PlaylistDescriptionLineEdit->setObjectName("PlaylistDescriptionLineEdit");

        horizontalLayout_3->addWidget(PlaylistDescriptionLineEdit);


        horizontalLayout_5->addWidget(PlaylistInfoWidget);


        verticalLayout->addWidget(PlaylistNameAndInfoWidget);


        verticalLayout_2->addWidget(UpperSectionWidget);

        AllSongsSelectionWidget = new QListWidget(CreatePlaylistDialog);
        AllSongsSelectionWidget->setObjectName("AllSongsSelectionWidget");

        verticalLayout_2->addWidget(AllSongsSelectionWidget);

        ButtonsWidget = new QWidget(CreatePlaylistDialog);
        ButtonsWidget->setObjectName("ButtonsWidget");
        horizontalLayout = new QHBoxLayout(ButtonsWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        SubmittionCreatePlaylistButton = new QPushButton(ButtonsWidget);
        SubmittionCreatePlaylistButton->setObjectName("SubmittionCreatePlaylistButton");

        horizontalLayout->addWidget(SubmittionCreatePlaylistButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        CancelCreationPlaylistButton = new QPushButton(ButtonsWidget);
        CancelCreationPlaylistButton->setObjectName("CancelCreationPlaylistButton");

        horizontalLayout->addWidget(CancelCreationPlaylistButton);


        verticalLayout_2->addWidget(ButtonsWidget);


        retranslateUi(CreatePlaylistDialog);

        QMetaObject::connectSlotsByName(CreatePlaylistDialog);
    } // setupUi

    void retranslateUi(QDialog *CreatePlaylistDialog)
    {
        CreatePlaylistDialog->setWindowTitle(QCoreApplication::translate("CreatePlaylistDialog", "Dialog", nullptr));
        UpperTitleLabel->setText(QCoreApplication::translate("CreatePlaylistDialog", "Create Your own Playlist ", nullptr));
        label->setText(QCoreApplication::translate("CreatePlaylistDialog", "PlayList Name : ", nullptr));
        PlaylistNameLineEdit->setText(QString());
        label_2->setText(QCoreApplication::translate("CreatePlaylistDialog", "Playlist Description : ", nullptr));
        SubmittionCreatePlaylistButton->setText(QCoreApplication::translate("CreatePlaylistDialog", "Create", nullptr));
        CancelCreationPlaylistButton->setText(QCoreApplication::translate("CreatePlaylistDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreatePlaylistDialog: public Ui_CreatePlaylistDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPLAYLISTDIALOG_H
