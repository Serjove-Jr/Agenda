#ifndef DATABANK_H
#define DATABANK_H

#include <QObject>
#include <QDebug>
#include <QVariant>
#include <QStringList>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <QMap>
#include <QVariantMap>

//Headers
#include "contato.h"
#include "statemachine.h"
//Database
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
//Json
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>

//contato conta;

class databank
{
public:
    databank();
    void addValues(QString name, QString phone, QString mail);
    QMap<int,contato> readValues();

    void deleteValue(QString name);

};

#endif // DATABANK_H
