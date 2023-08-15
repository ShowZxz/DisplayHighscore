#include "highscore.h"

#include <QDir>
#include <QFileInfoList>
#include <QFileInfo>
#include <QDateTime>
#include <QTextStream>
#include <QDebug>

Highscore::Highscore(){

}

QString Highscore::extractString(QString string_){

}

QString Highscore::extractSubstring(const QString& str, QChar startChar, QChar endChar)
{
    int startPos = str.indexOf(startChar);
    int endPos = str.indexOf(endChar);

    if (startPos == -1 || endPos == -1)
        return QString(); // Les caractères de début ou de fin n'ont pas été trouvés

    int subStringStart = startPos + 2; // On commence après le caractère de début
    int subStringLength = endPos - subStringStart; // Calcul de la longueur de la sous-chaîne

    return str.mid(subStringStart, subStringLength);
}


QString Highscore::extractSubstring(const QString& str)
{
    QString startWord = "C:Visual PinballTables";
    QChar endChar = '.';

    int startPos = str.indexOf(startWord);
    int endPos = str.indexOf(endChar, startPos);

    if (startPos == -1 || endPos == -1)
        return QString(); // Le mot de début ou le caractère de fin n'ont pas été trouvés

    int subStringStart = startPos++ + startWord.length();
    int subStringLength = endPos - subStringStart;

    return str.mid(subStringStart, subStringLength);
}


QString Highscore::getUsernameFromConfig() {
    QSettings settings("C:/From Future app/config.ini", QSettings::IniFormat);
    return settings.value("Credentials/username").toString();
    qDebug()<< settings.value("Credentials/username").toString();
}

QString Highscore::getPasswordFromConfig() {
    QSettings settings("C:/From Future app/config.ini", QSettings::IniFormat);
    return settings.value("Credentials/password").toString();
    qDebug()<< settings.value("Credentials/password").toString();
}
