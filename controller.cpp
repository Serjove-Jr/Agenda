#include "controller.h"
#include "contato.h"
#include "arquivo.h"
#include "databank.h"

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
databank database;

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
}

QMap<int, contato> Controller::readValues()
{
    database.readValues();
}

