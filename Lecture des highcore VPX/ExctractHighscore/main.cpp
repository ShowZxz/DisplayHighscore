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



        QString styleSheetNumber = "font-size: 30px; color: red; font-weight: bold; background: transparent; border: none;";
        QString styleSheetName = "font-size: 15px; color: red; font-weight: bold; background: transparent; border: none;";
        QString styleSheetRank = "font-size: 15px; color: red; font-weight: bold; background: transparent; border: none;";
        //if (high.getSizeScreen = "toper")
        QLabel *myBestScoreLabel = new QLabel("100000000000", &w);
        myBestScoreLabel->setGeometry(530, 420, 400, 110);
        myBestScoreLabel->setAlignment(Qt::AlignCenter);

        QLabel *worldRecordLabel = new QLabel("100000000000", &w);
        worldRecordLabel->setGeometry(530, 550, 400, 110);
        worldRecordLabel->setAlignment(Qt::AlignCenter);

        QLabel *topScoreLabel = new QLabel("100000000000", &w);
        topScoreLabel->setGeometry(1150, 420, 400, 110);
        topScoreLabel->setAlignment(Qt::AlignCenter);

        QLabel *midScoreLabel = new QLabel("100000000000", &w);
        midScoreLabel->setGeometry(1150, 490, 400, 110);
        midScoreLabel->setAlignment(Qt::AlignCenter);

        QLabel *botScoreLabel = new QLabel("100000000000", &w);
        botScoreLabel->setGeometry(1150, 555, 400, 110);
        botScoreLabel->setAlignment(Qt::AlignCenter);

        QLabel *botRankLabel = new QLabel("100", &w);
        botRankLabel->setGeometry(1480, 550, 50, 110);
        botRankLabel->setAlignment(Qt::AlignCenter);

        QLabel *midRankLabel = new QLabel("100", &w);
        midRankLabel->setGeometry(1480, 490, 50, 110);
        midRankLabel->setAlignment(Qt::AlignCenter);

        QLabel *topRankLabel = new QLabel("100", &w);
        topRankLabel->setGeometry(1480, 420, 50, 110);
        topRankLabel->setAlignment(Qt::AlignCenter);

        QLabel *myRankLabel = new QLabel("100", &w);
        myRankLabel->setGeometry(870, 415, 50, 110);
        myRankLabel->setAlignment(Qt::AlignCenter);

        QLabel *worldRankLabel = new QLabel("1", &w);
        worldRankLabel->setGeometry(870, 550, 50, 110);
        worldRankLabel->setAlignment(Qt::AlignCenter);

        QLabel *myName = new QLabel("COUCOU C MOI", &w);
        myName->setGeometry(350, 410, 400, 110);
        myName->setAlignment(Qt::AlignCenter);

        QLabel *worldName = new QLabel("LE MEILLEUR", &w);
        worldName->setGeometry(380, 530, 400, 110);
        worldName->setAlignment(Qt::AlignCenter);

        QLabel *topName = new QLabel("C++ QTCREATOR", &w);
        topName->setGeometry(960, 415, 400, 110);
        topName->setAlignment(Qt::AlignCenter);

        QLabel *midName = new QLabel( &w);
        midName->setGeometry(960, 480, 400, 110);
        midName->setAlignment(Qt::AlignCenter);

        QLabel *botName = new QLabel("THE MONSTER", &w);
        botName->setGeometry(960, 540, 400, 110);
        botName->setAlignment(Qt::AlignCenter);

        myBestScoreLabel->setStyleSheet(styleSheetNumber);
        worldRecordLabel->setStyleSheet(styleSheetNumber);
        topScoreLabel->setStyleSheet(styleSheetNumber);
        midScoreLabel->setStyleSheet(styleSheetNumber);
        botScoreLabel->setStyleSheet(styleSheetNumber);

        myRankLabel->setStyleSheet(styleSheetRank);
        botRankLabel->setStyleSheet(styleSheetRank);
        midRankLabel->setStyleSheet(styleSheetRank);
        topRankLabel->setStyleSheet(styleSheetRank);
        worldRankLabel->setStyleSheet(styleSheetRank);

        myName->setStyleSheet(styleSheetName);
        worldName->setStyleSheet(styleSheetName);
        botName->setStyleSheet(styleSheetName);
        midName->setStyleSheet(styleSheetName);
        topName->setStyleSheet(styleSheetName);




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
               bestScore = high.formatStringWithSpaces(bestScore);
               //qDebug() << bestScore << "Le best Score ";

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
                       strPosBottom = QString::number(rank);
                       rank= rank - 2;
                       strPosTop = QString::number(rank);

                       //Stock des ranks dans la class highscore
                       high.settopRank(strPosTop);
                       high.setmidRank(strPosMid);
                       high.setbotRank(strPosBottom);

                       qDebug() << strPosBottom <<"bot";
                       qDebug() <<strPosMid << "mid";
                       qDebug() << strPosTop << "top";



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
            topScoreLabel->setText(high.getfrontPosScore());
            botScoreLabel->setText(high.getbehindPosScore());
            midScoreLabel->setText(bestScore);

            worldName->setText(high.getworldPosUser());
            myName->setText(high.getUsernameFromConfig());
            topName->setText(high.getfrontPosUser());
            midName->setText(high.getUsernameFromConfig());
            botName->setText(high.getbehindPosUser());


            botRankLabel->setText(high.getbotRank());
            midRankLabel->setText(high.getmidRank());
            topRankLabel->setText(high.gettopRank());
            myRankLabel->setText(high.getmidRank());
            worldRankLabel->setText("1");




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


w.showFullScreen();

return a.exec();
}


