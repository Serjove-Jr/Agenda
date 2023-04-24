#ifndef DATABASE_H
#define DATABASE_H

//-----------------------------------------------------------------
//tralha
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
//----------------------------------------------------------------
//Headers
#include "contato.h"
#include "statemachine.h"
#include "Singleton.h"
//----------------------------------------------------------------
//Database
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
//----------------------------------------------------------------

#include <QObject>

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);

    static Database* getInstance();
    void openBase();
    void addValues(QString name, QString phone, QString mail);
    void editValues(QString data, QString Collunm, int index);
    QMap<int,contato> readValues();
    QStringList readoValos();

    void deleteValue(QString name);



private:
    static Database* m_Instance;

signals:

};

#endif // DATABASE_H
