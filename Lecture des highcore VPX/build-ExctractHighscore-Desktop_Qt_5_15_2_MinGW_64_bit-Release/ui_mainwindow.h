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
#include <QtWidgets/QGridLayout>
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
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *label_RankForward2;
    QLabel *label_Title;
    QLabel *label_ScoreUser;
    QLabel *label_ScoreForward1;
    QLabel *label_UserForward1;
    QLabel *label_RankForward1;
    QLabel *label_UserPseudo;
    QLabel *label_UserForward2;
    QLabel *label_ScoreForward2;
    QLabel *label_RankUser;
    QLabel *label_RankForward3;
    QLabel *label_UserForward3;
    QLabel *label_ScoreForward3;
    QMenuBar *menubar;
    QMenu *menuHighscore;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1020, 651);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-image: url(C:/From Future app/Image/blackbackground.jpg);\n"
"background-repeat: no-repeat;\n"
"background-attachment: fixed; \n"
"background-size: cover;\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_RankForward2 = new QLabel(widget_2);
        label_RankForward2->setObjectName(QString::fromUtf8("label_RankForward2"));

        gridLayout->addWidget(label_RankForward2, 3, 0, 1, 1);

        label_Title = new QLabel(widget_2);
        label_Title->setObjectName(QString::fromUtf8("label_Title"));

        gridLayout->addWidget(label_Title, 0, 1, 1, 1);

        label_ScoreUser = new QLabel(widget_2);
        label_ScoreUser->setObjectName(QString::fromUtf8("label_ScoreUser"));

        gridLayout->addWidget(label_ScoreUser, 1, 2, 1, 1);

        label_ScoreForward1 = new QLabel(widget_2);
        label_ScoreForward1->setObjectName(QString::fromUtf8("label_ScoreForward1"));

        gridLayout->addWidget(label_ScoreForward1, 2, 2, 1, 1);

        label_UserForward1 = new QLabel(widget_2);
        label_UserForward1->setObjectName(QString::fromUtf8("label_UserForward1"));

        gridLayout->addWidget(label_UserForward1, 2, 1, 1, 1);

        label_RankForward1 = new QLabel(widget_2);
        label_RankForward1->setObjectName(QString::fromUtf8("label_RankForward1"));

        gridLayout->addWidget(label_RankForward1, 2, 0, 1, 1);

        label_UserPseudo = new QLabel(widget_2);
        label_UserPseudo->setObjectName(QString::fromUtf8("label_UserPseudo"));

        gridLayout->addWidget(label_UserPseudo, 1, 1, 1, 1);

        label_UserForward2 = new QLabel(widget_2);
        label_UserForward2->setObjectName(QString::fromUtf8("label_UserForward2"));

        gridLayout->addWidget(label_UserForward2, 3, 1, 1, 1);

        label_ScoreForward2 = new QLabel(widget_2);
        label_ScoreForward2->setObjectName(QString::fromUtf8("label_ScoreForward2"));

        gridLayout->addWidget(label_ScoreForward2, 3, 2, 1, 1);

        label_RankUser = new QLabel(widget_2);
        label_RankUser->setObjectName(QString::fromUtf8("label_RankUser"));

        gridLayout->addWidget(label_RankUser, 1, 0, 1, 1);

        label_RankForward3 = new QLabel(widget_2);
        label_RankForward3->setObjectName(QString::fromUtf8("label_RankForward3"));

        gridLayout->addWidget(label_RankForward3, 4, 0, 1, 1);

        label_UserForward3 = new QLabel(widget_2);
        label_UserForward3->setObjectName(QString::fromUtf8("label_UserForward3"));

        gridLayout->addWidget(label_UserForward3, 4, 1, 1, 1);

        label_ScoreForward3 = new QLabel(widget_2);
        label_ScoreForward3->setObjectName(QString::fromUtf8("label_ScoreForward3"));

        gridLayout->addWidget(label_ScoreForward3, 4, 2, 1, 1);


        verticalLayout->addWidget(widget_2);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1020, 21));
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
        label_RankForward2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_Title->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_ScoreUser->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_ScoreForward1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_UserForward1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_RankForward1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_UserPseudo->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_UserForward2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_ScoreForward2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_RankUser->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_RankForward3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_UserForward3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_ScoreForward3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menuHighscore->setTitle(QCoreApplication::translate("MainWindow", "Highscore", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
