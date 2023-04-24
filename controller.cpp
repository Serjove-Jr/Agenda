#include "controller.h"
#include "contato.h"
#include "arquivo.h"
#include "database.h"
#include "statemachine.h"

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


Controller::Controller(QObject *parent):
    QObject(parent)
{

}
Arquivo arquivo;
Database database;
StateMachine machine1;

void Controller::setM_Controller(QString new_Controller)
{
    if(new_Controller== __m_Controller__)
        return;
    __m_Controller__ = new_Controller;
    emit m_ControllerChanged();
}

QString Controller::m_Controller()
{
    return this->__m_Controller__;
}

void Controller::createContact(QString name,QString phone,QString mail)
{
    qDebug()<<"Contato: "+name;
    qDebug()<<"Telefone: "+phone;
    qDebug()<<"E-mail: "+mail;

    arquivo.writeFile(name,phone,mail);
}
QStringList Controller::readFile()
{
    arquivo.leArquivo();
}

void Controller::addcontact(QString name, QString phone, QString mail)
{
    database.addValues(name, phone, mail);
    //qDebug() << "chegou";
    //machine1.setSomeVar(database.readoValos());
    //qDebug() << "chegou2";
    QStringList names;
    names << database.readoValos();
    machine1.setSomeVar(names);

    qDebug() << machine1.someVar();
}

void Controller::deleteContact(QString name)
{
    database.deleteValue(name);

}

void Controller::editContact(QString data, QString Collunm, int index)
{
    database.editValues(data, Collunm, index);
}


QStringList Controller::readValues()
{
    //database.readValues();
    database.readoValos();
}

QString Controller::singleP(int i)
{
   QString phone = machine1.singlePhone(i);
   return phone;
}
QString Controller::singleM(int i)
{
    QString mail = machine1.singleMail(i);
    return mail;
}

