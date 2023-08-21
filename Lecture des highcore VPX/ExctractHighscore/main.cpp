#include "mainwindow.h"
#include "highscore.h"
#include "ui_mainwindow.h"
#include "sgdb.h"
#include "thread.h"
#include <QApplication>
#include <QDir>
#include <QTextEdit>
#include <QFileInfoList>
#include <QFileInfo>
#include <QDebug>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <QGuiApplication>
#include <QScreen>
#include <QPixmap>
#include <QVBoxLayout>
#include <QSettings>
#include <QProcess>
#include <QFrame>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Ui::MainWindow ui;
    ui.setupUi(&w);

    //instanciation class Highscore
//#############################################################################################################################################################
Highscore high;
Highscore high1;
Highscore high2;
Highscore high_world;
Highscore high_world1;
Highscore high_world2;


QString vpinball = "VPinballX.exe";






                                                             //ini File
//############################################################################################################################################################









    int numToperScreen =high.getToperScreen();

    QString pinemhi_worldpath = high.getLeaderboardPath();
    QString pinemhi_userpath= high.getUserScorePath();
    QString username = high.getUsernameFromConfig();
    QString password = high.getPasswordFromConfig();
    qDebug()<< numToperScreen;
    qDebug()<< password +" //// "+username +"W "+pinemhi_userpath+" W "+pinemhi_worldpath;


    //VERIFY PASSWORD AND USERNAME HERE
    if (username.isEmpty() || password.isEmpty()) {
            QMessageBox::critical(nullptr, "Erreur", "Nom d'utilisateur ou mot de passe manquant dans le fichier de configuration.");
            return 1; // Quitter l'application avec un code d'erreur
        }

                                                           //CONFIGURATION OF SCREEN
//############################################################################################################################################################
    QList<QScreen*> screens = QGuiApplication::screens();

        // Vérifiez si le deuxième écran existe
        if (screens.size() > numToperScreen) {
            QScreen* toperScreen = screens.at(numToperScreen);

            // Afficher la fenêtre en plein écran sur le deuxième écran
            w.setWindowState(Qt::WindowFullScreen);


            // Déplacez la fenêtre vers le deuxième écran
            w.move(toperScreen->geometry().x(), toperScreen->geometry().y());
        }







                                                                 //CONFIGURATION OF LABEL
//#############################################################################################################################################################
    QLabel * label_high_user1= ui.label_high_user1;
    QLabel * label_high_user2= ui.label_high_user2;
    QLabel * label_high_user3= ui.label_high_user3;
    QLabel * label_user1= ui.label_user1;
    QLabel * label_user2= ui.label_user2;
    QLabel * label_user3= ui.label_user3;
    QLabel * label_world1 = ui.label_world1;
    QLabel * label_world2 = ui.label_world2;
    QLabel * label_world3 = ui.label_world3;
    QLabel * label_world_score1 = ui.label_world_score1;
    QLabel * label_world_score2 = ui.label_world_score2;
    QLabel * label_world_score3 = ui.label_world_score3;


    QLabel * label_namecab = ui.label_namecab;

    QLabel * label_title = ui.label_title;
    QLabel * label_title_world = ui.label_title_world;
    QFrame * frame=ui.frame;
    QFrame * frame_2=ui.frame_2;







QString styleSheet = "font-size: 30px; color: white; font-weight: bold; background: transparent;";
QString styleSheet2 = "font-size: 30px; color: white; font-weight: bold; background: transparent;";

label_high_user1->setStyleSheet(styleSheet);
label_high_user2->setStyleSheet(styleSheet);
label_high_user3->setStyleSheet(styleSheet);
label_user1->setStyleSheet(styleSheet2);
label_user2->setStyleSheet(styleSheet2);
label_user3->setStyleSheet(styleSheet2);
label_world1->setStyleSheet(styleSheet2);
label_world2->setStyleSheet(styleSheet2);
label_world3->setStyleSheet(styleSheet2);
label_world_score1->setStyleSheet(styleSheet);
label_world_score2->setStyleSheet(styleSheet);
label_world_score3->setStyleSheet(styleSheet);
label_title->setStyleSheet(styleSheet);
label_title_world->setStyleSheet(styleSheet);



label_title->setFont(QFont("Gotham Medium"));
label_title_world->setFont(QFont("Gotham Medium"));
label_high_user1->setFont(QFont("Swipe Race Demo"));
label_high_user2->setFont(QFont("Gotham Medium"));
label_high_user3->setFont(QFont("Gotham Medium"));
label_user1->setFont(QFont("Gotham Medium"));
label_user2->setFont(QFont("Gotham Medium"));
label_user3->setFont(QFont("Gotham Medium"));
label_world1->setFont(QFont("Gotham Medium"));
label_world2->setFont(QFont("Gotham Medium"));
label_world3->setFont(QFont("Gotham Medium"));
label_world_score1->setFont(QFont("Gotham Medium"));
label_world_score2->setFont(QFont("Gotham Medium"));
label_world_score3->setFont(QFont("Gotham Medium"));








                                                    //GET ARGV
//#############################################################################################################################################################



            QString name_NVRAM = "afm_113b.nv";
            QString gameFullName = argv[1];
            //QString name_NVRAM = argv[2];

            int pos = name_NVRAM.lastIndexOf(QChar('.'));
            QString nvram = name_NVRAM.left(pos)+".txt";
            qDebug() << nvram;
            label_title->setText(gameFullName);
            label_title_world->setText(gameFullName);






            //LECTURE FICHIER HIGHSCORE DE L'USER
//######################################################################################################################################################
//QFile file2("C:/PINemHi/PINemHi LeaderBoard/TOP10_Personal/"+nvram);
QFile file2(pinemhi_userpath+nvram);



if (file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextStream in(&file2);
    QString line;



    // Recherche du highscore et de l'utilisateur à la ligne 7
    int lineNumber = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();


        lineNumber++;
        //qDebug()<<lineNumber;
        if (lineNumber == 7) {
            QStringList parts = line.split(" ", QString::SkipEmptyParts);
            //qDebug()<<line;

            if (parts.size() >= 5) {
                QString classement = parts.at(0);
                QString highscore = parts.at(1);
                QString user = parts.at(2);
                QString date = parts.at(3);
                QString heure = parts.at(4);

                //Stockage des variable dans la class Higscore
                high.setScore(highscore);
                high.setUser(user);

                //Affichage des variable sur les labels
                label_high_user1->setText(highscore);
                label_user1->setText(user);
                label_user2->setText(user);
                label_user3->setText(user);


                //sgdb.databaseRecordHighscore(user, highscore ,high.getTitle());


            }
        }
        if (lineNumber == 8) {
            QStringList parts = line.split(" ", QString::SkipEmptyParts);
            //qDebug()<<line;

            if (parts.size() >= 5) {
                QString classement = parts.at(0);
                QString highscore = parts.at(1);
                QString user = parts.at(2);
                QString date = parts.at(3);
                QString heure = parts.at(4);
                high1.setScore(highscore);
                high1.setUser(user);
                qDebug() << "Highscore:" << highscore;
                qDebug() << "USER: " << user;



                //Stockage des variable dans la class Highscore


                //Affichage des variable sur les text edit
                label_high_user2->setText(highscore);





            }
        }
        if (lineNumber == 9) {
            QStringList parts = line.split(" ", QString::SkipEmptyParts);
            //qDebug()<<line;

            if (parts.size() >= 5) {
                QString classement = parts.at(0);
                QString highscore = parts.at(1);
                QString user = parts.at(2);
                QString date = parts.at(3);
                QString heure = parts.at(4);
                qDebug() << "Highscore:" << highscore;
                qDebug() << "USER: " << user;
                high2.setScore(highscore);
                high2.setUser(user);


                //Stockage des variable dans la class Highscore


                //Affichage des variable sur les text edit
                label_high_user3->setText(highscore);



                break;
            }
        }
    }

    file2.close();
} else {
    qDebug() << "Erreur lors de l'ouverture du fichier";
}

                            //LECTURE HIGHSCORE WORLDWIDE
//######################################################################################################################################################################
  //QFile file3("C:/PINemHi/PINemHi LeaderBoard/TOP10_Best/"+nvram);
  QFile file3(pinemhi_worldpath+nvram);

  if (file3.open(QIODevice::ReadOnly | QIODevice::Text)) {
      QTextStream in(&file3);
      QString line;


      // Recherche du highscore et de l'utilisateur à la ligne 7
      int lineNumber = 0;
      while (!in.atEnd()) {
          QString line = in.readLine();


          lineNumber++;
          //qDebug()<<lineNumber;
          if (lineNumber == 7) {
              QStringList parts = line.split(" ", QString::SkipEmptyParts);
              //qDebug()<<line;

              if (parts.size() >= 5) {
                  QString classement = parts.at(0);
                  QString highscore = parts.at(1);
                  QString user = parts.at(2);
                  QString date = parts.at(3);
                  QString heure = parts.at(4);
                  label_world1->setText(user);
                  label_world_score1->setText(highscore);
                  high_world.setScore(highscore);
                  high_world.setScore(user);


                  qDebug() << "Highscore:" << highscore;
                  qDebug() << "USER: " << user;



              }

          }

          if (lineNumber == 8) {
              QStringList parts = line.split(" ", QString::SkipEmptyParts);
              //qDebug()<<line;

              if (parts.size() >= 5) {
                  QString classement = parts.at(0);
                  QString highscore = parts.at(1);
                  QString user = parts.at(2);
                  QString date = parts.at(3);
                  QString heure = parts.at(4);
                  qDebug() << "Highscore:" << highscore;
                  qDebug() << "USER: " << user;
                  high_world1.setScore(highscore);
                  high_world1.setScore(user);



                  //Stockage des variable dans la class Highscore


                  //Affichage des variable sur les text edit
                  label_world2->setText(user);
                  label_world_score2->setText(highscore);





              }
          }

          if (lineNumber == 9) {
              QStringList parts = line.split(" ", QString::SkipEmptyParts);
              //qDebug()<<line;

              if (parts.size() >= 5) {
                  QString classement = parts.at(0);
                  QString highscore = parts.at(1);
                  QString user = parts.at(2);
                  QString date = parts.at(3);
                  QString heure = parts.at(4);
                  high_world2.setScore(highscore);
                  high_world2.setScore(user);
                  qDebug() << "Highscore:" << highscore;
                  qDebug() << "USER: " << user;


                  //Stockage des variable dans la class Highscore


                  //Affichage des variable sur les text edit
                  label_world3->setText(user);
                  label_world_score3->setText(highscore);



                  break;
              }
          }


      }


      file3.close();
  } else {
      qDebug() << "Erreur lors de l'ouverture du fichier";
  }






w.show();

                                                            //Record highscore when end
//#############################################################################################################################################################


Thread thread(vpinball,high.getScore(),high.getUser(),gameFullName);

thread.start();












return a.exec();
}


