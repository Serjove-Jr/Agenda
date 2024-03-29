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
#include "Singleton.h"
//Database
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
//Json
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QVariantMap>

//contato conta;

class databank: public QObject
{
    Q_OBJECT
public:
    databank();
    ~databank();
    databank* getInstance();
    void openBase();
    void addValues(QString name, QString phone, QString mail);
    void editValues(QString data, QString Collunm, int index);
    QMap<int,contato> readValues();
    QStringList readoValos();

    void deleteValue(QString name);

private:
    static databank* m_Instance;




};




#endif // DATABANK_H
