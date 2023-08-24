/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_8;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_title;
    QLabel *label_namecab;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_user1;
    QLabel *label_high_user1;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_user2;
    QLabel *label_high_user2;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_user3;
    QLabel *label_high_user3;
    QFrame *line_8;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_title_world;
    QLabel *label_world_namecab;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_world1;
    QLabel *label_world_score1;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_world2;
    QLabel *label_world_score2;
    QFrame *line_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_world3;
    QLabel *label_world_score3;
    QMenuBar *menubar;
    QMenu *menuHighscore;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1111, 475);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"background-image: url(C:/From Future app/Image/blackbackground.jpg);\n"
"background-repeat: no-repeat;\n"
"background-attachment: fixed; \n"
"background-size: cover;\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"background-image: url(C:/From Future app/Image/comics.jpeg);\n"
"border-radius: 50px;\n"
"background-attachment: fixed; \n"
"\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_title = new QLabel(frame);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setStyleSheet(QString::fromUtf8("background: transparent;"));

        verticalLayout->addWidget(label_title);

        label_namecab = new QLabel(frame);
        label_namecab->setObjectName(QString::fromUtf8("label_namecab"));
        label_namecab->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 57 15pt \"Gotham Medium\";\n"
"\n"
"\n"
""));
        label_namecab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_namecab);


        verticalLayout_2->addLayout(verticalLayout);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_user1 = new QLabel(frame);
        label_user1->setObjectName(QString::fromUtf8("label_user1"));
        label_user1->setStyleSheet(QString::fromUtf8("background: transparent;"));

        horizontalLayout_2->addWidget(label_user1);

        label_high_user1 = new QLabel(frame);
        label_high_user1->setObjectName(QString::fromUtf8("label_high_user1"));
        label_high_user1->setEnabled(true);
        QFont font;
        font.setFamily(QString::fromUtf8("Gotham Medium"));
        label_high_user1->setFont(font);
        label_high_user1->setAutoFillBackground(false);
        label_high_user1->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"\n"
"border-radius: 25% 10%;"));
        label_high_user1->setTextFormat(Qt::AutoText);
        label_high_user1->setScaledContents(false);
        label_high_user1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_high_user1->setWordWrap(false);

        horizontalLayout_2->addWidget(label_high_user1);


        verticalLayout_2->addLayout(horizontalLayout_2);

        line_2 = new QFrame(frame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_user2 = new QLabel(frame);
        label_user2->setObjectName(QString::fromUtf8("label_user2"));
        label_user2->setStyleSheet(QString::fromUtf8("background: transparent;"));

        horizontalLayout_3->addWidget(label_user2);

        label_high_user2 = new QLabel(frame);
        label_high_user2->setObjectName(QString::fromUtf8("label_high_user2"));
        label_high_user2->setStyleSheet(QString::fromUtf8("background: transparent;"));
        label_high_user2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_high_user2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        line_3 = new QFrame(frame);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_user3 = new QLabel(frame);
        label_user3->setObjectName(QString::fromUtf8("label_user3"));
        label_user3->setStyleSheet(QString::fromUtf8("background: transparent;"));

        horizontalLayout_4->addWidget(label_user3);

        label_high_user3 = new QLabel(frame);
        label_high_user3->setObjectName(QString::fromUtf8("label_high_user3"));
        label_high_user3->setStyleSheet(QString::fromUtf8("background: transparent;"));
        label_high_user3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_high_user3);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_8->addWidget(frame);

        line_8 = new QFrame(centralwidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        horizontalLayout_8->addWidget(line_8);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"background-image: url(C:/From Future app/Image/comics_right.jpeg);\n"
"background-repeat: no-repeat;\n"
"border-radius: 50px;\n"
"background-attachment: fixed; \n"
"background-size: cover;\n"
"\n"
""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_title_world = new QLabel(frame_2);
        label_title_world->setObjectName(QString::fromUtf8("label_title_world"));
        label_title_world->setStyleSheet(QString::fromUtf8("background: transparent;"));

        verticalLayout_3->addWidget(label_title_world);

        label_world_namecab = new QLabel(frame_2);
        label_world_namecab->setObjectName(QString::fromUtf8("label_world_namecab"));
        label_world_namecab->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 57 15pt \"Gotham Medium\";"));
        label_world_namecab->setScaledContents(true);
        label_world_namecab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_world_namecab->setWordWrap(false);

        verticalLayout_3->addWidget(label_world_namecab);


        verticalLayout_4->addLayout(verticalLayout_3);

        line_4 = new QFrame(frame_2);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_world1 = new QLabel(frame_2);
        label_world1->setObjectName(QString::fromUtf8("label_world1"));
        label_world1->setStyleSheet(QString::fromUtf8("background: transparent;"));

        horizontalLayout_5->addWidget(label_world1);

        label_world_score1 = new QLabel(frame_2);
        label_world_score1->setObjectName(QString::fromUtf8("label_world_score1"));
        label_world_score1->setStyleSheet(QString::fromUtf8("background: transparent;"));
        label_world_score1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_world_score1);


        verticalLayout_4->addLayout(horizontalLayout_5);

        line_5 = new QFrame(frame_2);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_world2 = new QLabel(frame_2);
        label_world2->setObjectName(QString::fromUtf8("label_world2"));
        label_world2->setStyleSheet(QString::fromUtf8("background: transparent;"));

        horizontalLayout_6->addWidget(label_world2);

        label_world_score2 = new QLabel(frame_2);
        label_world_score2->setObjectName(QString::fromUtf8("label_world_score2"));
        label_world_score2->setStyleSheet(QString::fromUtf8("background: transparent;"));
        label_world_score2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_world_score2);


        verticalLayout_4->addLayout(horizontalLayout_6);

        line_6 = new QFrame(frame_2);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_world3 = new QLabel(frame_2);
        label_world3->setObjectName(QString::fromUtf8("label_world3"));
        label_world3->setStyleSheet(QString::fromUtf8("background: transparent;"));

        horizontalLayout_7->addWidget(label_world3);

        label_world_score3 = new QLabel(frame_2);
        label_world_score3->setObjectName(QString::fromUtf8("label_world_score3"));
        label_world_score3->setStyleSheet(QString::fromUtf8("background: transparent;"));
        label_world_score3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_world_score3);


        verticalLayout_4->addLayout(horizontalLayout_7);


        horizontalLayout_8->addWidget(frame_2);


        gridLayout->addLayout(horizontalLayout_8, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1111, 21));
        menuHighscore = new QMenu(menubar);
        menuHighscore->setObjectName(QString::fromUtf8("menuHighscore"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuHighscore->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_title->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">Title</span></p><p><br/></p></body></html>", nullptr));
        label_namecab->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; color:#ffffff;\">YOUR HIGHSCORE</span></p></body></html>", nullptr));
        label_user1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>not supported</p></body></html>", nullptr));
        label_high_user1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>not supported</p></body></html>", nullptr));
        label_user2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>not supported</p></body></html>", nullptr));
        label_high_user2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>not supported</p></body></html>", nullptr));
        label_user3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>not supported</p></body></html>", nullptr));
        label_high_user3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>not supported</p></body></html>", nullptr));
        label_title_world->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Title</p><p><br/></p></body></html>", nullptr));
        label_world_namecab->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">WORLD WIDE HIGHSCORE</span></p></body></html>", nullptr));
        label_world1->setText(QCoreApplication::translate("MainWindow", "not supported", nullptr));
        label_world_score1->setText(QCoreApplication::translate("MainWindow", "not supported", nullptr));
        label_world2->setText(QCoreApplication::translate("MainWindow", "not supported", nullptr));
        label_world_score2->setText(QCoreApplication::translate("MainWindow", "not supported", nullptr));
        label_world3->setText(QCoreApplication::translate("MainWindow", "not supported", nullptr));
        label_world_score3->setText(QCoreApplication::translate("MainWindow", "not supported", nullptr));
        menuHighscore->setTitle(QCoreApplication::translate("MainWindow", "Highscore", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
