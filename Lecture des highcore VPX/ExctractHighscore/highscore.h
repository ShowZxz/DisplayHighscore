#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <stdio.h>
#include <QString>
#include <QSettings>

class Highscore
{
public:


       Highscore();
       void setScore (QString score ){
           this->score = score;
       }
       void setTitle(QString titre){
           this->titre = titre;

       }

       void setUser ( QString user){
           this->user = user;

       }
       QString extractString(QString string_);

       QString extractSubstring(const QString& str, QChar startChar, QChar endChar);
       QString extractSubstring(const QString& str);

       QString getPasswordFromConfig();
       QString getUsernameFromConfig();
       QString getScore (){return score;}
       QString getTitle(){return titre;}
       QString getUser(){return user;}
private:
       QString titre;
       QString score;
       QString user;
};

#endif // HIGHSCORE_H
