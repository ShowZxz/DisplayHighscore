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


class Sgdb
{
public:
    Sgdb();
    ~Sgdb();

    bool databaseConnect();
    void closeDatabase();
    bool databaseRecordTitle(const QString& titre);
    bool databaseRecordHighscore(const QString& user, const QString& highscore,const QString& titre);
    void removeDuplicatesFromTable();

private:
    QSqlDatabase db;
    QDateTime * now;


};

#endif // SGDB_H
