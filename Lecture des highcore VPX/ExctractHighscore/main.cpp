#include "mainwindow.h"
#include "highscore.h"
#include "thread.h"
#include "ui_mainwindow.h"
#include "sgdb.h"

#include "QLabel"

#include <QCoreApplication>
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

QString vpinball = "VPinballX.exe";






                                                             //ini File
//############################################################################################################################################################









    int numToperScreen =high.getToperScreen();
    QString typeOfScreen = high.getTypeOfScreen();

    QString pinemhi_worldpath = high.getLeaderboardPath();
    QString pinemhi_userpath= high.getUserScorePath();
    QString username = high.getUsernameFromConfig();
    QString password = high.getPasswordFromConfig();
    qDebug()<< numToperScreen;
    qDebug()<< password +" //// "+username +" W "+pinemhi_userpath+" W "+pinemhi_worldpath;


    //VERIFY PASSWORD AND USERNAME HERE

    if (!username.isEmpty() || !password.isEmpty()) {
        QList<LoginUser> resultLogin = sgdb.getLoginUser(username, password);

        if (resultLogin.isEmpty()) {
            QMessageBox::critical(nullptr, "Erreur", "Nom d'utilisateur ou mot de passe différent que celui de l'inscription.");
                return 1;
        }

        qDebug() << "PSEUDO : " << resultLogin[0].pseudo << "CODE : " << resultLogin[0].code;

        if (resultLogin[0].pseudo != username || resultLogin[0].code != password) {
            QMessageBox::critical(nullptr, "Erreur", "Nom d'utilisateur ou mot de passe différent que celui de l'inscription.");
                return 1;
        }
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

        QString processName = "Front.exe";


        QProcess *process = new QProcess();


        QStringList processList = process->systemEnvironment();
        processList << "tasklist";


        process->start("tasklist");

        process->waitForFinished(-1);


        QString tasklistOutput = process->readAllStandardOutput();

        if (tasklistOutput.contains(processName)) {

            QProcess::execute("taskkill", QStringList() << "/F" << "/IM" << processName);
        } else {

            qDebug() << "Le processus" << processName << "n'est pas en cours d'exécution.";
        }


        delete process;

                                                                 //CONFIGURATION OF LABEL
//#############################################################################################################################################################

        QString styleSheetNumber;
        QString styleSheetName;
        QString styleSheetRank;

        QLabel *myBestScoreLabel;
        QLabel *worldRecordLabel;
        QLabel *topScoreLabel;
        QLabel *midScoreLabel;
        QLabel *botScoreLabel;
        QLabel *midRankLabel;
        QLabel *botRankLabel;
        QLabel *topRankLabel;
        QLabel *myRankLabel;
        QLabel *worldRankLabel;
        QLabel *myName;
        QLabel *worldName;
        QLabel *topName;
        QLabel *botName;
        QLabel *midName;

        if (typeOfScreen == "toper") {
            styleSheetNumber = "font-size: 20px; color: red; font-weight: bold; background: transparent; border: none;";
            styleSheetName = "font-size: 10px; color: red; font-weight: bold; background: transparent; border: none;";
            styleSheetRank = "font-size: 15px; color: red; font-weight: bold; background: transparent; border: none;";

            myBestScoreLabel = new QLabel("100 000 000 000", &w);
            myBestScoreLabel->setGeometry(290, 260, 400, 110);
            myBestScoreLabel->setAlignment(Qt::AlignCenter);

            worldRecordLabel = new QLabel("100 000 000 000", &w);
            worldRecordLabel->setGeometry(290, 345, 400, 110);
            worldRecordLabel->setAlignment(Qt::AlignCenter);

            topScoreLabel = new QLabel("100 000 000 000", &w);
            topScoreLabel->setGeometry(700, 265, 400, 110);
            topScoreLabel->setAlignment(Qt::AlignCenter);

            midScoreLabel = new QLabel("100000000000", &w);
            midScoreLabel->setGeometry(700, 305, 400, 110);
            midScoreLabel->setAlignment(Qt::AlignCenter);

            botScoreLabel = new QLabel("100000000000", &w);
            botScoreLabel->setGeometry(700, 350, 400, 110);
            botScoreLabel->setAlignment(Qt::AlignCenter);

            botRankLabel = new QLabel("3", &w);
            botRankLabel->setGeometry(975, 350, 50, 110);
            botRankLabel->setAlignment(Qt::AlignCenter);

            midRankLabel = new QLabel("2", &w);
            midRankLabel->setGeometry(975, 305, 50, 110);
            midRankLabel->setAlignment(Qt::AlignCenter);

            topRankLabel = new QLabel("1", &w);
            topRankLabel->setGeometry(975, 265, 50, 110);
            topRankLabel->setAlignment(Qt::AlignCenter);

            myRankLabel = new QLabel("100", &w);
            myRankLabel->setGeometry(570, 260, 50, 110);
            myRankLabel->setAlignment(Qt::AlignCenter);

            worldRankLabel = new QLabel("1", &w);
            worldRankLabel->setGeometry(570, 345, 50, 110);
            worldRankLabel->setAlignment(Qt::AlignCenter);

            myName = new QLabel("COUCOU C MOI", &w);
            myName->setGeometry(170, 250, 400, 110);
            myName->setAlignment(Qt::AlignCenter);

            worldName = new QLabel("LE MEILLEUR", &w);
            worldName->setGeometry(170, 335, 400, 110);
            worldName->setAlignment(Qt::AlignCenter);

            topName = new QLabel("C++ QTCREATOR", &w);
            topName->setGeometry(550, 255, 400, 110);
            topName->setAlignment(Qt::AlignCenter);

            midName = new QLabel( "THE GRINDER",&w);
            midName->setGeometry(550, 300, 400, 110);
            midName->setAlignment(Qt::AlignCenter);

            botName = new QLabel("THE MONSTER", &w);
            botName->setGeometry(550, 340, 400, 110);
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

        } else {
            styleSheetNumber = "font-size: 30px; color: red; font-weight: bold; background: transparent; border: none;";
            styleSheetName = "font-size: 15px; color: red; font-weight: bold; background: transparent; border: none;";
            styleSheetRank = "font-size: 15px; color: red; font-weight: bold; background: transparent; border: none;";

            myBestScoreLabel = new QLabel("100000000000", &w);
            myBestScoreLabel->setGeometry(530, 420, 400, 110);
            myBestScoreLabel->setAlignment(Qt::AlignCenter);
            myBestScoreLabel->setStyleSheet(styleSheetNumber);

            worldRecordLabel = new QLabel("100000000000", &w);
            worldRecordLabel->setGeometry(530, 550, 400, 110);
            worldRecordLabel->setAlignment(Qt::AlignCenter);

            topScoreLabel = new QLabel("100000000000", &w);
            topScoreLabel->setGeometry(1150, 420, 400, 110);
            topScoreLabel->setAlignment(Qt::AlignCenter);

            midScoreLabel = new QLabel("100000000000", &w);
            midScoreLabel->setGeometry(1150, 490, 400, 110);
            midScoreLabel->setAlignment(Qt::AlignCenter);

            botScoreLabel = new QLabel("100000000000", &w);
            botScoreLabel->setGeometry(1150, 555, 400, 110);
            botScoreLabel->setAlignment(Qt::AlignCenter);

            botRankLabel = new QLabel("100", &w);
            botRankLabel->setGeometry(1480, 550, 50, 110);
            botRankLabel->setAlignment(Qt::AlignCenter);

            midRankLabel = new QLabel("100", &w);
            midRankLabel->setGeometry(1480, 490, 50, 110);
            midRankLabel->setAlignment(Qt::AlignCenter);

            topRankLabel = new QLabel("100", &w);
            topRankLabel->setGeometry(1480, 420, 50, 110);
            topRankLabel->setAlignment(Qt::AlignCenter);

            myRankLabel = new QLabel("100", &w);
            myRankLabel->setGeometry(870, 415, 50, 110);
            myRankLabel->setAlignment(Qt::AlignCenter);

            worldRankLabel = new QLabel("1", &w);
            worldRankLabel->setGeometry(870, 550, 50, 110);
            worldRankLabel->setAlignment(Qt::AlignCenter);

            myName = new QLabel("COUCOU C MOI", &w);
            myName->setGeometry(350, 410, 400, 110);
            myName->setAlignment(Qt::AlignCenter);

            worldName = new QLabel("LE MEILLEUR", &w);
            worldName->setGeometry(380, 530, 400, 110);
            worldName->setAlignment(Qt::AlignCenter);

            topName = new QLabel("C++ QTCREATOR", &w);
            topName->setGeometry(960, 415, 400, 110);
            topName->setAlignment(Qt::AlignCenter);

            midName = new QLabel( &w);
            midName->setGeometry(960, 480, 400, 110);
            midName->setAlignment(Qt::AlignCenter);

            botName = new QLabel("THE MONSTER", &w);
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
        }



//label_RankForward2->setFont(QFont("Gotham Medium"));
//label_RankForward3->setFont(QFont("Gotham Medium"));





                                                    //GET ARGV
//#############################################################################################################################################################



            //QString name_NVRAM = "afm_113b.nv";
            QString gameFullName = argv[1];
            QString name_NVRAM = argv[2];
            //gameFullName = "Attack from Mars (Bally 1995)";

            int pos = name_NVRAM.lastIndexOf(QChar('.'));
            QString nvram = name_NVRAM.left(pos)+".txt";
            qDebug() << nvram;



            //QString user = "Gold";
            //QString title = "Apex";




               QString bestScore = sgdb.getNewHighscore(username, gameFullName);
               //QString bestScore = sgdb.getNewHighscore(user, title);
               bestScore = high.formatStringWithSpaces(bestScore);
               //qDebug() << bestScore << "Le best Score ";

               if (!bestScore.isEmpty()) {
                   //qDebug() << "Meilleur score de l'utilisateur" << user << "pour le titre" << title << " : " << bestScore;
                   QString bestScoreWithSpaces = high.formatStringWithSpaces(bestScore);
                   high.setScore(bestScoreWithSpaces);

               } else {
                   qDebug() << "Aucun résultat trouvé. ( ## sgdb.getNewHighscore(user, title); ##) ";
               }

               QString scoreInfo = sgdb.getInfoRank(username,gameFullName);
               //QString scoreInfo = sgdb.getInfoRank(user, title);


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
                   //QString titleTest = "Apex";
                   //QString userTest = "Gold";

                   //QList<ScoreInfoTop> results_Front = sgdb.getTopScoresInFronUser(titleTest, userTest);

                   //QList<ScoreInfoTop> results_Behind = sgdb.getTopScoresBehindUser(titleTest, userTest);
                   //QList<ScoreInfoTop> results_WorldScore = sgdb.getWorldScoreInfo(titleTest);

                   QList<ScoreInfoTop> results_Front = sgdb.getTopScoresInFronUser(gameFullName, username);

                   QList<ScoreInfoTop> results_Behind = sgdb.getTopScoresBehindUser(gameFullName, username);
                   QList<ScoreInfoTop> results_WorldScore = sgdb.getWorldScoreInfo(gameFullName);


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
            myBestScoreLabel->setText(high.getScore());


            worldRecordLabel->setText(high.getworldPosScore());

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
//QFile file("pinemhi_userpath+nvram);
            //nvram = "totan_14.txt";
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


QString thread_score=high.getScore();
thread_score.replace(".","");
long long long_thread_score = thread_score.toLongLong();
//qDebug()<< long_thread_score << "  EEEEEEEEEEEEEEEEEEEEEEEEEEEEEE";
Thread thread(vpinball,long_thread_score,high.getUser(),gameFullName,high.getPasswordFromConfig());
//Thread thread(vpinball,myLongLong,u,g,p);

thread.start();


w.showFullScreen();

return a.exec();
}


