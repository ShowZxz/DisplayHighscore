#ifndef THREAD_H
#define THREAD_H

#include "sgdb.h"
#include "highscore.h"
#include <QThread>




class Thread : public QThread
{
public:
    Thread(const QString& processName, QString score, QString user,QString title);
    void run();
    void openDatabaseConnection();

    Thread();


private:


    Sgdb sgdb;
    Highscore highscore;
    QSqlDatabase db;
    QDateTime * now;
    QString m_score;
    QString m_user;
    QString m_processName;
    QString m_title;
};

#endif // THREAD_H
