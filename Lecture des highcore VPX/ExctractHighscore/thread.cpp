#include "thread.h"
#include <QtCore>
Thread::Thread(const QString& processName, QString score, QString user, QString title)
    :  m_processName(processName), m_score(score), m_user(user), m_title(title)
{}




void Thread::run()
{
    while (!isInterruptionRequested())
    {
        QProcess process;
        process.start("tasklist", QStringList() << "/FI" << "IMAGENAME eq " + m_processName);

        if (process.waitForFinished())
        {
            QByteArray output = process.readAllStandardOutput();

            QString outputStr(output);
            if (outputStr.contains(m_processName))
            {

                qDebug() << m_processName << "is running.";
            }
            else
            {

                openDatabaseConnection();
                qDebug() << m_processName << "is not running.";


                QString time_format = "MM-dd-yyyy";
                QString _datetime=QDateTime::currentDateTime().toString(time_format);
                QSqlQuery query(db);
                query.prepare("INSERT INTO score (user, highscore, datetime,titre) VALUES (:user, :highscore, :_datetime, :titre )");

                query.bindValue(":titre",m_title);
                query.bindValue(":user",m_user);
                query.bindValue(":highscore",m_score);
                query.bindValue(":_datetime",_datetime);

                if (query.exec()){
                    qDebug() << "Les highscore sont inséré";

                } else {

                    qDebug() << "Echec de l'insertion";

             }





                sgdb.closeDatabase();
                break;
            }
        }
        else
        {
            qDebug() << "Error running tasklist.";
        }

        // Wait for a few seconds before checking again
        sleep(10);
    }
}


void Thread::openDatabaseConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Database/Pinball/Scoreboard.db");

    if (!db.open())
    {
        qDebug() << "Impossible d'ouvrir la base de données.";
    }
    else{
        qDebug() << "Ouverture de la base de données.";

    }
}
