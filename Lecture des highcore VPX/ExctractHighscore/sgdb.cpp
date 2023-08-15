#include "sgdb.h"

#include <QDebug>

Sgdb::Sgdb(){

            //db= QSqlDatabase::addDatabase("QSQLITE");
            //db.setHostName("127.0.0.1");
            //db.setPort(3306);
            //db.setDatabaseName("C:/Database/Pinball/Scoreboard.db");
            //db.setUserName("root");
            //db.setPassword("");
            //databaseConnect();

}




bool Sgdb::databaseConnect(){

if(QSqlDatabase::isDriverAvailable("QSQLITE")){


      if(db.open())
      {
           qDebug() << "Connexion à la base de données établie";
          return true;
      }
    else
    {

          qDebug() << "Échec de la connexion à la base de données :" << db.lastError().text();




     return false;
    }

  }
}





bool Sgdb::databaseRecordHighscore(const QString& user, const QString& highscore,const QString& titre){
    if (!db.isOpen()){
        qDebug() << "La base est pas ouverte";
    }

    QString time_format = "MM-dd-yyyy";
    QString _datetime=QDateTime::currentDateTime().toString(time_format);
    QSqlQuery query(db);
    query.prepare("INSERT INTO score (user, highscore, datetime,titre) VALUES (:user, :highscore, :_datetime, :titre )");

    query.bindValue(":titre",titre);
    query.bindValue(":user",user);
    query.bindValue(":highscore",highscore);
    query.bindValue(":_datetime",_datetime);

    if (query.exec()){
        qDebug() << "Les highscore sont inséré";
        return true;
    } else {

        qDebug() << "Echec de l'insertion";
        return false;
 }

}


void Sgdb::removeDuplicatesFromTable() {

}


void Sgdb::closeDatabase(){

    db.close();
    qDebug() << "Connexion à la base de données fermée";

}



Sgdb::~Sgdb()
{

}
