#ifndef THREAD_H
#define THREAD_H

#include "sgdb.h"
#include "highscore.h"
#include <QThread>




class Thread : public QThread
{
public:
    Thread(const QString& processName, long long score, QString user,QString title,QString password);
    void run();
    void openDatabaseConnection();
    void closeDatabaseConnection();

    Thread();


private:


    Sgdb sgdb;
    Highscore highscore;
    QSqlDatabase db;
    QDateTime * now;
    long long m_score;
    QString m_user;
    QString m_processName;
    QString m_title;
    QString m_password;
};

#endif // THREAD_H
