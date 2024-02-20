#include "thread.h"
#include <QtCore>
Thread::Thread(const QString& processName,  long long score, QString user, QString title, QString password)
    :  m_processName(processName), m_score(score), m_user(user), m_title(title),m_password(password)
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

                qDebug() << m_processName << "is not running...";


                QString time_format = "MM-dd-yyyy";
                QString _datetime=QDateTime::currentDateTime().toString(time_format);
                QSqlQuery query(db);
                if (!m_title.isEmpty() &  !m_title.isEmpty() & !m_password.isEmpty()){

                    QString selectQueryStr = QString("SELECT s.Score "
                                                     "FROM scores s "
                                                     "JOIN utilisateurs u ON s.ID_utilisateur = u.ID_utilisateur "
                                                     "JOIN jeux j ON s.ID_jeu = j.ID_jeu "
                                                     "WHERE u.Pseudo = :User AND j.Nom_jeu = :Title;");

                    QSqlQuery selectQuery;
                    selectQuery.prepare(selectQueryStr);
                    selectQuery.bindValue(":User", m_user);
                    selectQuery.bindValue(":Title", m_title);

                    if (selectQuery.exec() && selectQuery.next()) {
                        qlonglong oldScore = selectQuery.value(0).toLongLong();

                        if (m_score > oldScore) {
                            // Mettre à jour l'enregistrement existant
                            QString updateQueryStr = QString("UPDATE scores s "
                                                             "JOIN utilisateurs u ON s.ID_utilisateur = u.ID_utilisateur "
                                                             "JOIN jeux j ON s.ID_jeu = j.ID_jeu "
                                                             "SET s.Score = :Score, s.Date_enregistrement = :Datetime "
                                                             "WHERE u.Pseudo = :User AND j.Nom_jeu = :Title;");
                            QSqlQuery updateQuery;
                            updateQuery.prepare(updateQueryStr);
                            updateQuery.bindValue(":Score", m_score);
                            updateQuery.bindValue(":Datetime", _datetime);
                            updateQuery.bindValue(":User", m_user);
                            updateQuery.bindValue(":Title", m_title);
                            qDebug() <<" MISE A JOUR OK";

                            if (!updateQuery.exec()) {
                                qDebug() << updateQuery.lastError() << "Erreur lors de la mise à jour de l'enregistrement";
                            }
                        }
                    } else {
                        // Insérer un nouvel enregistrement si l'ancien n'existe pas
                        QString insertQueryStr = QString("INSERT INTO scores (ID_utilisateur, ID_jeu, Score, Date_enregistrement) "
                                                         "VALUES ( "
                                                         "(SELECT ID_utilisateur FROM utilisateurs WHERE Pseudo = :User), "
                                                         "(SELECT ID_jeu FROM jeux WHERE Nom_jeu = :Title), :Score, :Datetime )");

                        QSqlQuery insertQuery;
                        insertQuery.prepare(insertQueryStr);
                        insertQuery.bindValue(":User", m_user);
                        insertQuery.bindValue(":Title", m_title);
                        insertQuery.bindValue(":Score", m_score);
                        insertQuery.bindValue(":Datetime", _datetime);
                        qDebug() <<"NOUVEL INSERTION THREAD";

                        if (!insertQuery.exec()) {
                            qDebug() << insertQuery.lastError() << "Erreur lors de l'insertion d'un nouvel enregistrement";
                        }
                    }

                }



                sgdb.closeDatabase();



                QString exePath = "Front.exe";

                // Créer un objet QProcess
                QProcess *process = new QProcess();

                // Démarrer le processus
                process->start(exePath);

                // Libérer la mémoire du QProcess
                delete process;

                QCoreApplication::quit();

                break;
            }
        }
        else
        {
            qDebug() << "Error running tasklist.";
        }


        sleep(10);
    }
}


void Thread::openDatabaseConnection()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("-");
    db.setPort(3306);
    db.setDatabaseName("-");
    db.setUserName("-");
    db.setPassword("-");
    if (db.open()) {
         qDebug() << "base de données thread ok :";
    } else {
        qDebug() << "Erreur de connexion à la base de données : " << db.lastError().text();

    }

}
