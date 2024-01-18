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
       void setfrontPosUser(QString frontPosUser){
           this->frontPosUser =frontPosUser;
       }
       void setbehindPosUser(QString behindPosUser){
           this->behindPosUser =behindPosUser;
       }
       void setfrontPosScore(QString frontPosScore){
           this->frontPosScore =frontPosScore;
       }
       void setbehindPosScore(QString behindPosScore){
           this->behindPosScore =behindPosScore;
       }
       void setworldPosScore(QString worldPosScore){
           this->worldPosScore =worldPosScore;
       }
       void setworldPosUser(QString worldPosUser){
           this->worldPosUser =worldPosUser;
       }
       void setmidPosScore(QString midPosScore){
           this->midPosScore =midPosScore;
       }
       void setmidPosUser(QString midPosUser){
           this->midPosUser =midPosUser;
       }
       void settopRank(QString topRank){
           this->topRank =topRank;
       }
       void setmidRank(QString midRank){
           this->midRank =midRank;
       }
       void setbotRank(QString botRank){
           this->botRank =botRank;
       }




       QString getPasswordFromConfig();
       QString getUsernameFromConfig();
       QString getDatabasePath();
       QString getLeaderboardPath();
       QString getUserScorePath();

       int getToperScreen();

       QString getScore(){return score;}
       QString getTitle(){return titre;}
       QString getUser(){return user;}

       QString getfrontPosUser(){return frontPosUser;}
       QString getbehindPosUser(){return behindPosUser;}
       QString getworldPosUser(){return worldPosUser;}
       QString getmidPosUser(){return midPosUser;}

       QString getmidPosScore(){return midPosScore;}
       QString getworldPosScore(){return worldPosScore;}
       QString getfrontPosScore(){return frontPosScore;}
       QString getbehindPosScore(){return behindPosScore;}

       QString gettopRank(){return topRank;}
       QString getmidRank(){return midRank;}
       QString getbotRank(){return botRank;}

       QString formatStringWithSpaces(const QString &input);


private:
       QString titre;
       QString score;
       QString user;

       QString frontPosUser;
       QString frontPosScore;
       QString behindPosUser;
       QString behindPosScore;
       QString worldPosScore;
       QString worldPosUser;

       QString midPosScore;
       QString midPosUser;

       QString topRank;
       QString midRank;
       QString botRank;

       QString myName;
       QString topNameUser;
       QString midNameUser;
       QString botNameUser;

};

#endif // HIGHSCORE_H
