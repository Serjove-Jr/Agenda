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

class StateMachine :public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList someVar READ someVar WRITE setSomeVar NOTIFY someVarChanged)
    Q_PROPERTY(QStringList phone READ phone WRITE setPhone NOTIFY phoneChanged)
    Q_PROPERTY(QStringList mail READ mail WRITE setMail NOTIFY mailChanged)

public:
    explicit StateMachine(QObject *parent = nullptr);
    QStringList sendValues();
    QStringList sendValues2();
    QStringList sendValues3();

    QStringList someVar();
    QStringList phone();
    QString singlePhone(int i);
    QStringList mail();
    QString singleMail(int i);
signals:
    void someVarChanged();
    void phoneChanged();

    void mailChanged();

public slots:
    void setSomeVar(QStringList);
    void setPhone(QStringList);
    void setMail(QStringList);

private:

    QStringList m_someVar;
    QStringList m_phone;
    QStringList m_mail;
};

#endif // STATEMACHINE_H
