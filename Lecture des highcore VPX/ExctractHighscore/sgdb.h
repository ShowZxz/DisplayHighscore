#ifndef SGDB_H
#define SGDB_H

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

struct ScoreInfoTop {
    QString username;
    long long score;
};

struct LoginUser{
    QString pseudo;
    QString code;
};



class Sgdb
{
public:
    Sgdb();
    ~Sgdb();

    bool databaseConnect();
    bool openConnexion();
    void closeDatabase();




    QString getInfoRank(const QString &user, const QString &title);
    QString getNewHighscore(QString userName,QString title);
    QList<LoginUser> getLoginUser(const QString &pseudo, const QString &code);
    QList<ScoreInfoTop> getTopScoresInFronUser(const QString &title, const QString &user);
    QList<ScoreInfoTop> getTopScoresBehindUser(const QString &title, const QString &user);
    QList<ScoreInfoTop> getWorldScoreInfo(const QString &title);



private:
    QSqlDatabase db;
    QDateTime * now;
    Highscore highscore;


};

#endif // SGDB_H
