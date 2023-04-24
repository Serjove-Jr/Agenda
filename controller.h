#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "contato.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <QFile>
#include <QFileInfo>
#include<QTextStream>
#include<QDebug>

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString m_Controller READ m_Controller NOTIFY m_ControllerChanged)
public:

    explicit Controller(QObject *parent = nullptr);
    void setM_Controller(QString new_Controller);
    QString m_Controller();
private:
    QString __m_Controller__ = "";

signals:
    void status(QVariant data);
    void m_ControllerChanged();

public slots:
    void createContact(QString name,QString phone,QString mail);
    QStringList readFile();
    void addcontact(QString name, QString phone, QString mail);
    void deleteContact(QString name);
    void editContact(QString data, QString Collunm, int index);

   QStringList readValues();
   QString singleP(int i);
   QString singleM(int i);


};

#endif // CONTROLLER_H
