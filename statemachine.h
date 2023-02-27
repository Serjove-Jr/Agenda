#ifndef STATEMACHINE_H
#define STATEMACHINE_H

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
//Database
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
//Json
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>

class StateMachine
{
    Q_OBJECT
    //Q_PROPERTY(QMap map READ map WRITE setMap NOTIFY mapChanged)

public:
    StateMachine();
    //static void sendValues(QMap<int,contato>);
    //QMap<int,contato> map();
signals:
    //void mapChanged();

public slots:
    //void setMap(QMap<int,contato>);
    //static void sendValues(QMap<int,contato>);

private:
   //QMap<int,contato> m_map;
};

#endif // STATEMACHINE_H
