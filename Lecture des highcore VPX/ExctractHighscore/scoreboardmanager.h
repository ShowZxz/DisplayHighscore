#ifndef SCOREBOARDMANAGER_H
#define SCOREBOARDMANAGER_H
#include <QString>
#include <QDebug>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>

#include "highscore.h"

class ScoreboardManager
{
private:

public:
    ScoreboardManager();


    QString getScoreInfoForUserAndTitle(const QString &user, const QString &title,const QString &databasePath) {
        QString result;

        // Établir une connexion à la base de données SQLite
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(databasePath);

        if (!db.open()) {
                    qDebug() << "Erreur lors de l'ouverture de la base de données";
                    return result;
                }

                // Obtenir le meilleur score de l'utilisateur pour le titre donné
                QString queryStr = QString("SELECT score, (SELECT COUNT(*) FROM scoreboard WHERE Title = '%1' AND score > s.score) + 1 AS Rank "
                                          "FROM scoreboard s WHERE title = '%1' AND user = '%2'")
                                          .arg(title).arg(user);

                QSqlQuery query;
                if (!query.exec(queryStr)) {
                    qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError();
                    db.close();
                    return result;
                }

                if (query.next()) {
                    QString score = query.value("Score").toString();
                    int rank = query.value("Rank").toInt();

                    result = "Meilleur score de l'utilisateur " + user + " pour le titre " + title + " : " + score +
                             "\nClassement : #" + QString::number(rank);
                }

                // Fermer la connexion à la base de données
                db.close();

                return result;
            }
};

#endif // SCOREBOARDMANAGER_H
