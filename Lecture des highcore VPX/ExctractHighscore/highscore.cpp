#include "highscore.h"

#include <QDir>
#include <QFileInfoList>
#include <QFileInfo>
#include <QDateTime>
#include <QTextStream>
#include <QDebug>

Highscore::Highscore(){

}




QString Highscore::getUsernameFromConfig() {
    QSettings settings("C:/From Futur Application/config/path.ini", QSettings::IniFormat);
    return settings.value("Credentials/username").toString();
    qDebug()<< settings.value("Credentials/username").toString();
}

QString Highscore::getPasswordFromConfig() {
    QSettings settings("C:/From Futur Application/config/path.ini", QSettings::IniFormat);
    return settings.value("Credentials/password").toString();
    qDebug()<< settings.value("Credentials/password").toString();
}

QString Highscore::getLeaderboardPath(){
    QSettings settings("C:/From Futur Application/config/path.ini", QSettings::IniFormat);
    return settings.value("DIR_PATH/user_scoreboard").toString();
    qDebug()<< settings.value("DIR_PATH/user_scoreboard").toString();
}
QString Highscore::getUserScorePath(){
    QSettings settings("C:/From Futur Application/config/path.ini", QSettings::IniFormat);
    return settings.value("DIR_PATH/leaderboard").toString();
    qDebug()<< settings.value("DIR_PATH/leaderboard").toString();

}
int Highscore::getToperScreen(){
    QSettings settings("C:/From Futur Application/config/path.ini", QSettings::IniFormat);
    return settings.value("Screen/toper").toInt();
    qDebug()<< settings.value("Screen/toper").toInt();

}

QString Highscore::getDatabasePath(){
    QSettings settings("C:/From Futur Application/config/path.ini", QSettings::IniFormat);
    return settings.value("Database/data_path").toString();
    qDebug()<< settings.value("Database/data_path").toString();

}
QString Highscore::formatStringWithSpaces(const QString &input){
    QString formattedString;
        int count = 0;

        for (int i = input.length() - 1; i >= 0; --i) {
            formattedString.prepend(input.at(i));
            count++;

            if (count == 3 && i != 0) {
                formattedString.prepend(" ");
                count = 0;
            }
        }

        return formattedString;
}

QString Highscore::getTypeOfScreen(){
        QSettings settings("C:/From Futur Application/config/path.ini", QSettings::IniFormat);
        return settings.value("SCALE/size_screen").toString();
        qDebug()<< settings.value("SCALE/size_screen").toString();

}
