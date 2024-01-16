#include "mainwindow.h"
#include "highscore.h"
#include "ui_mainwindow.h"
#include "sgdb.h"
#include "thread.h"
#include "scoreboardmanager.h"
#include "QLabel"

#include <QApplication>
#include <QDir>
#include <QTextEdit>
#include <QFileInfoList>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QStringList>
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

Sgdb sgdb;
ScoreboardManager scoreboardManager;



QString vpinball = "VPinballX.exe";






                                                             //ini File
//############################################################################################################################################################









    int numToperScreen =high.getToperScreen();
    int toperSizeScreen;

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


            // Déplacez la fenêtre vers le deuxième écran
            w.move(toperScreen->geometry().x(), toperScreen->geometry().y());

        }







                                                                 //CONFIGURATION OF LABEL
//#############################################################################################################################################################

         /*
        QLabel *label_RankForward2 = new QLabel("Mon highscore", &w);
        label_RankForward2->setGeometry(350, 95, 250, 100);


        QLabel *label_RankForward3 = new QLabel(" Top 1", &w);
        label_RankForward3->setGeometry(850, 95, 250, 100);
        */

        QLabel *myBestScoreLabel = new QLabel("Votre texte ici", &w);
        myBestScoreLabel->setGeometry(490, 420, 400, 110);
        myBestScoreLabel->setAlignment(Qt::AlignCenter);

        QLabel *worldRecordLabel = new QLabel("Votre texte ici", &w);
        worldRecordLabel->setGeometry(490, 550, 400, 110);
        worldRecordLabel->setAlignment(Qt::AlignCenter);

        QLabel *topUserLabel = new QLabel("Votre texte ici", &w);
        topUserLabel->setGeometry(1100, 425, 400, 110);
        topUserLabel->setAlignment(Qt::AlignCenter);

        QLabel *midUserLabel = new QLabel("Votre texte ici", &w);
        midUserLabel->setGeometry(1100, 490, 400, 110);
        midUserLabel->setAlignment(Qt::AlignCenter);

        QLabel *botUserLabel = new QLabel("Votre texte ici", &w);
        botUserLabel->setGeometry(1100, 555, 400, 110);
        botUserLabel->setAlignment(Qt::AlignCenter);

        QLabel *botRankLabel = new QLabel("100", &w);
        botRankLabel->setGeometry(1490, 555, 50, 110);
        botRankLabel->setAlignment(Qt::AlignCenter);

        QLabel *midRankLabel = new QLabel("100", &w);
        midRankLabel->setGeometry(1490, 485, 50, 110);
        midRankLabel->setAlignment(Qt::AlignCenter);

        QLabel *topRankLabel = new QLabel("100", &w);
        topRankLabel->setGeometry(1490, 425, 50, 110);
        topRankLabel->setAlignment(Qt::AlignCenter);

        QLabel *myRankLabel = new QLabel("100", &w);
        myRankLabel->setGeometry(870, 415, 50, 110);
        myRankLabel->setAlignment(Qt::AlignCenter);

        QLabel *worldRankLabel = new QLabel("1", &w);
        worldRankLabel->setGeometry(870, 550, 50, 110);
        worldRankLabel->setAlignment(Qt::AlignCenter);










QString styleSheet = "font-size: 30px; color: red; font-weight: bold; background: transparent;";
QString styleSheet2 = "font-size: 35px; color: red; font-weight: bold; background: transparent;";



//label_RankForward2->setStyleSheet(styleSheet);
//label_RankForward3->setStyleSheet(styleSheet);

//label_RankForward2->setFont(QFont("Gotham Medium"));
//label_RankForward3->setFont(QFont("Gotham Medium"));





                                                    //GET ARGV
//#############################################################################################################################################################



            QString name_NVRAM = "afm_113b.nv";
            QString gameFullName = argv[1];
            //QString name_NVRAM = argv[2];
            gameFullName = "Attack from Mars (Bally 1995)";

            int pos = name_NVRAM.lastIndexOf(QChar('.'));
            QString nvram = name_NVRAM.left(pos)+".txt";
            qDebug() << nvram;



            QString user = "Gold";  // Remplacez par l'utilisateur que vous recherchez
            QString title = "Apex";  // Remplacez par le titre que vous recherchez




               //QString bestScore = sgdb.getNewHighscore(username, gameFullName);

               QString bestScore = sgdb.getNewHighscore(user, title);

               if (!bestScore.isEmpty()) {
                   qDebug() << "Meilleur score de l'utilisateur" << user << "pour le titre" << title << " : " << bestScore;
                   QString bestScoreWithSpaces = high.formatStringWithSpaces(bestScore);
                   high.setScore(bestScoreWithSpaces);

               } else {
                   qDebug() << "Aucun résultat trouvé. ( ## sgdb.getNewHighscore(user, title); ##) ";
               }


               QString scoreInfo = sgdb.getInfoRank(user, title);


               if (!scoreInfo.isEmpty()) {
                   qDebug() << "Score info str"<<scoreInfo;
                   if (scoreInfo.length() >= 2) {

                       QString strPosTop;
                       QString strPosMid;
                       QString strPosBottom;

                       QString lastFirstChars= scoreInfo.right(1);
                       int rank;
                       rank = lastFirstChars.toInt();
                       strPosMid = QString::number(rank);
                       rank++;
                       strPosTop = QString::number(rank);
                       rank= rank - 2;
                       strPosBottom = QString::number(rank);

                       //Stock des ranks dans la class highscore
                       high.settopRank(strPosTop);
                       high.setmidRank(strPosMid);
                       high.setbotRank(strPosBottom);



                   } else {
                       qDebug() << "La chaîne est trop courte pour avoir deux caractères.";
                   }

               } else {
                   qDebug() << "Aucun résultat trouvé.";
               }


                   // USELESSS
                   QString titleTest = "Apex";
                   QString userTest = "Gold";

                   QList<ScoreInfoTop> results_Front = sgdb.getTopScoresInFronUser(titleTest, userTest);

                   QList<ScoreInfoTop> results_Behind = sgdb.getTopScoresBehindUser(titleTest, userTest);
                   QList<ScoreInfoTop> results_WorldScore = sgdb.getWorldScoreInfo(titleTest);


                       for (const ScoreInfoTop &results_Behind : results_Behind) {

                           qDebug() << "Utilisateur:" << results_Behind.username << "Score:" << results_Behind.score;
                       }
                       for (const ScoreInfoTop &results_Front : results_Front) {

                           qDebug() << "Utilisateur:" << results_Front.username << "Score:" << results_Front.score;
                       }
                       for (const ScoreInfoTop &results_WorldScore : results_WorldScore) {

                           qDebug() << "Utilisateur:" << results_WorldScore.username << "Score:" << results_WorldScore.score;
                       }
                       if (results_Behind.size() >= 1) {
                           QString frontPosUser;

                           QString behindPosUser;

                           QString frontPosScore;

                           QString behindPosScore;

                           QString worldPosScore;

                           QString worldPosUser;

                           worldPosUser=results_WorldScore[0].username;
                           frontPosUser=results_Front[0].username;
                           behindPosUser=results_Behind[0].username;
                           worldPosScore= high.formatStringWithSpaces(QString::number(results_WorldScore[0].score));
                           frontPosScore= high.formatStringWithSpaces(QString::number(results_Behind[0].score));
                           behindPosScore= high.formatStringWithSpaces(QString::number(results_Front[0].score));


                           high.setworldPosScore(worldPosScore);
                           high.setworldPosUser(worldPosUser);

                           high.setfrontPosUser(frontPosUser);
                           high.setfrontPosScore(frontPosScore);

                           high.setbehindPosScore(behindPosScore);
                           high.setbehindPosUser(behindPosUser);

                           qDebug() << "Utilisateur:" <<frontPosUser;
                           qDebug() << "Utilisateur:" <<behindPosUser;
                           qDebug() << "Utilisateur:" <<worldPosUser;
                           qDebug() << "Score:" << frontPosScore;
                           qDebug() << "Score:" << behindPosScore;
                           qDebug() << "Score:" << worldPosScore;
                           }


                                               // SETUP TEXT LABEL
//######################################################################################################################################################

            worldRecordLabel->setText(high.getworldPosScore());
            myBestScoreLabel->setText(high.getScore());
            topUserLabel->setText(high.getfrontPosScore());
            botUserLabel->setText(high.getbehindPosScore());
            midUserLabel->setText(high.getmidPosScore());


            botRankLabel->setText(high.getbotRank());
            midRankLabel->setText(high.getmidRank());
            topRankLabel->setText(high.gettopRank());
            myRankLabel->setText(high.getmidRank());




            //LECTURE FICHIER HIGHSCORE DE L'USER
//######################################################################################################################################################
//QFile file2("C:/PINemHi/PINemHi LeaderBoard/TOP10_Personal/"+nvram);
            nvram = "totan_14.txt";
QFile file(pinemhi_userpath+nvram);

if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString line;


            // Recherche du highscore et de l'utilisateur à la ligne 7
            int lineNumber = 0;
            while (!in.atEnd()) {
                QString line = in.readLine();


                lineNumber++;
                //qDebug()<<lineNumber;
                if (lineNumber == 7) {
                    QStringList parts = line.split(" ", Qt::SkipEmptyParts);
                    //qDebug()<<line;

                    if (parts.size() >= 5) {

                        QString highscore = parts.at(1);
                        high.setScore(highscore);

                        qDebug() << "Highscore:" << highscore;

                    }

                }


            file.close();
}

}
            else {
            qDebug() << "Erreur lors de l'ouverture du fichier";
}





                                                            //Record highscore when end
//#############################################################################################################################################################





//long long y = 856833300;
QString s="345.455.600";
s.replace(".","");
long long myLongLong = s.toLongLong();


qDebug()<< myLongLong << "  EEEEEEEEEEEEEEEEEEEEEEEEEEEEEE";
QString u="Gold";
QString g="Apex";
QString p="lol";
//Thread thread(vpinball,high.getScore(),high.getUser(),gameFullName,high.getPasswordFromConfig());
Thread thread(vpinball,myLongLong,u,g,p);

thread.start();


//w.showFullScreen();
w.showMaximized();
return a.exec();
}


