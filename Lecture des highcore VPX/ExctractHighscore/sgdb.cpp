#include "sgdb.h"

#include <QDebug>

Sgdb::Sgdb(){

    openConnexion();

}



bool Sgdb::openConnexion(){
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("scoring_manager");
    db.setUserName("root");
    db.setPassword("");
    if (db.open()) {
        return true;
    } else {
        qDebug() << "Erreur de connexion à la base de données : " << db.lastError().text();
        return false;
    }
}

QList<LoginUser> Sgdb::getLoginUser(const QString &pseudo, const QString &code) {
    QList<LoginUser> result;

    if (!db.open()) {
        qDebug() << "Erreur lors de l'ouverture de la base de données";
        // Vous pourriez renvoyer une liste vide ou signaler l'erreur d'une autre manière.
        return result;
    }

    qDebug() << "Ouverture de la base de données SDGB.";

    QString queryStr = "SELECT Pseudo, Code FROM utilisateurs WHERE Pseudo = :pseudo AND Code = :code;";
    QSqlQuery query;

    query.prepare(queryStr);
    query.bindValue(":pseudo", pseudo);
    query.bindValue(":code", code);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError();
        // Vous pourriez renvoyer une liste vide ou signaler l'erreur d'une autre manière.
        return result;
    }

    if (query.next()) {
        LoginUser loginUser;
        loginUser.pseudo = query.value(0).toString();
        loginUser.code = query.value(1).toString();
        result.append(loginUser);
    }

    return result;
}



QString Sgdb::getInfoRank(const QString &user, const QString &title){
    QString result;
        if (!db.open()) {
                    qDebug() << "Erreur lors de l'ouverture de la base de données";
                    return result;
                }

                // Obtenir le meilleur score de l'utilisateur pour le titre donné
                QString queryStr = QString("SELECT s.Score AS Score,(SELECT COUNT(*) FROM scores s2 JOIN utilisateurs u ON s2.ID_utilisateur = u.ID_utilisateur JOIN jeux j ON s2.ID_jeu = j.ID_jeu WHERE j.Nom_jeu = '%1' AND s2.Score > s.Score) + 1 AS Rank FROM scores s JOIN utilisateurs u ON s.ID_utilisateur = u.ID_utilisateur JOIN jeux j ON s.ID_jeu = j.ID_jeu WHERE j.Nom_jeu = '%1' AND u.Pseudo = '%2';").arg(title).arg(user);


                QSqlQuery query;
                if (!query.exec(queryStr)) {
                    qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError();

                    return result;
                }

                if (query.next()) {
                    QString score = query.value("score").toString();
                    int rank = query.value("Rank").toInt();

                    result = "Meilleur score de l'utilisateur " + user + " pour le titre " + title + " : " + score +
                             "\nClassement : #" + QString::number(rank);
                }

                // Fermer la connexion à la base de données


                return result;
}

QList<ScoreInfoTop> Sgdb::getWorldScoreInfo(const QString &title){
                QList<ScoreInfoTop> worldScore;
                if (!db.open())
                {
                    qDebug() << "Impossible d'ouvrir la base de données. getWorldScoreInfo";
                }
                else{
                    qDebug() << "Ouverture de la base de données SDGB.";

                }
                QString queryStr = QString("SELECT u.Pseudo AS User, s.Score "
                                           "FROM scores s "
                                           "JOIN utilisateurs u ON s.ID_utilisateur = u.ID_utilisateur "
                                           "JOIN jeux j ON s.ID_jeu = j.ID_jeu "
                                           "WHERE j.Nom_jeu = 'Apex' AND s.Score = (SELECT MAX(s2.Score) "
                                           "FROM scores s2 "
                                           "JOIN jeux j2 ON s2.ID_jeu = j2.ID_jeu "
                                           "WHERE j2.Nom_jeu = '%1');")
                                       .arg(title);

                QSqlQuery query(queryStr);

                if (!query.exec()) {
                    qDebug() << query.lastError() << "Erreur lors de l'exécution de la requête getWorldScoreInfo";

                    return worldScore;
                }

                if (query.next()) {
                    ScoreInfoTop scoreInfo;
                    scoreInfo.username = query.value(0).toString();
                    scoreInfo.score = query.value(1).toLongLong();
                    worldScore.append(scoreInfo);
                }


                return worldScore;
}

QString Sgdb::getNewHighscore(QString userName,QString title){

    if (!db.open())
    {
        qDebug() << "Impossible d'ouvrir la base de données. getNewHighscore";
    }
    else{
        qDebug() << "Ouverture de la base de données SDGB.";

    }



        // Écrire la requête SQL pour récupérer le meilleur score d'un utilisateur pour un titre donné
        QString queryStr = QString("SELECT u.Pseudo AS Joueur, s.Score AS Meilleur_Score FROM scores s JOIN utilisateurs u ON s.ID_utilisateur = u.ID_utilisateur JOIN jeux j ON s.ID_jeu = j.ID_jeu WHERE j.Nom_jeu = '%1' AND u.Pseudo = '%2' ORDER BY s.Score DESC LIMIT 1;")
                              .arg(title).arg(userName);

        // Exécuter la requête
        QSqlQuery query;
        if (!query.exec(queryStr)) {
            qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError()<<"getNewHighscore";

        }

        // Récupérer le résultat (le meilleur score)
        if (query.next()) {
            QString bestScore = query.value("Meilleur_Score").toString();

            return bestScore;
        } else {

            qDebug()<<"FAILED INSERT";
        }
}


void Sgdb::closeDatabase(){

    db.close();
    qDebug() << "Connexion à la base de données fermée";

}



QList<ScoreInfoTop> Sgdb::getTopScoresBehindUser(const QString &title, const QString &user){
    QList<ScoreInfoTop> behindScores;


    if (!db.open()) {
            qDebug() << "Erreur de connexion à la base de données getTopScoresBehindUser";
            return behindScores;
    }

    QString queryStr = QString("SELECT u.Pseudo AS User, s.Score "
                               "FROM scores s "
                               "JOIN utilisateurs u ON s.ID_utilisateur = u.ID_utilisateur "
                               "JOIN jeux j ON s.ID_jeu = j.ID_jeu "
                               "WHERE j.Nom_jeu = '%1' AND s.Score < (SELECT s2.Score "
                               "FROM scores s2 "
                               "JOIN utilisateurs u2 ON s2.ID_utilisateur = u2.ID_utilisateur "
                               "JOIN jeux j2 ON s2.ID_jeu = j2.ID_jeu "
                               "WHERE j2.Nom_jeu = '%1' AND u2.Pseudo = '%2') "
                               "ORDER BY s.Score DESC "
                               "LIMIT 1;").arg(title).arg(user);

    QSqlQuery query(queryStr);

    if (!query.exec()) {
            qDebug() << "Erreur lors de l'exécution de la requête getTopScoresBehindUser " << query.lastError();

            return behindScores;
    }

    if (query.next()) {
            ScoreInfoTop scoreInfo;
            scoreInfo.username = query.value(0).toString();
            scoreInfo.score = query.value(1).toLongLong();
            behindScores.append(scoreInfo);
    }


    return behindScores;


}


QList<ScoreInfoTop> Sgdb::getTopScoresInFronUser(const QString &title, const QString &user) {
    QList<ScoreInfoTop> topScores;


    if (!db.open()) {
        qDebug() << "Erreur de connexion à la base de données getTopScoresInFronUse";
        return topScores;
    }

    QString queryStr = QString("SELECT u.Pseudo AS User, s.Score "
        "FROM scores s "
        "JOIN utilisateurs u ON s.ID_utilisateur = u.ID_utilisateur "
        "JOIN jeux j ON s.ID_jeu = j.ID_jeu "
        "WHERE j.Nom_jeu = '%1' AND u.Pseudo != '%2' "
        "ORDER BY s.Score ASC "
        "LIMIT 1;").arg(title).arg(user);
    QSqlQuery query(queryStr);

    if (!query.exec()) {
        qDebug() << query.lastError() << " Erreur lors de l'exécution de la requête getTopScoresInFronUser ";

        return topScores;
    }

    if (query.next()) {
        ScoreInfoTop scoreInfo;
        scoreInfo.username = query.value(0).toString();
        scoreInfo.score = query.value(1).toLongLong();
        topScores.append(scoreInfo);
    }


    return topScores;
}






Sgdb::~Sgdb()
{
    closeDatabase();
}
