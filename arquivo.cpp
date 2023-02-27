#include "arquivo.h"
#include "crialista.h"
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
#include <QStringList>
#include <QVector>

contato contact;


Arquivo::Arquivo(QObject *parent)
    : QObject(parent)
{

}

void Arquivo::setM_arquivo(QString new_word)
{
    if(new_word== __m_arquivo__)
        return;
    __m_arquivo__ = new_word;
    emit m_ArquivoChanged();
}

QString Arquivo::m_Arquivo()
{
    return this->__m_arquivo__;
}

QStringList Arquivo::leArquivo()
{
    QFile file;
    QStringList palavras;
    QVariantList teste;
    QStringList names;
    QStringList phones;
    QStringList mails;
    file.setFileName("./Lista.txt");

    if (file.open(QIODevice::ReadOnly)){
        QTextStream arquivo(&file);

        palavras << arquivo.readAll();
//        while(!arquivo.atEnd()){
//            contact.definirNome(arquivo.readLine(0));
//            contact.definirTelefone(arquivo.readLine(0));
//            contact.definirEmail(arquivo.readLine(0));
//        }

        file.close();

        return palavras;

    }
}

void Arquivo::writeFile(QString name,QString  phone,QString  mail)
{
    QFile file;
    QStringList palavras;
    file.setFileName("./Lista.txt");
    //file.setPermissions(QFileDevice::WriteOwner | QFileDevice::WriteUser | QFileDevice::WriteGroup | QFileDevice::WriteOther);
    qInfo()<<file.fileName();
    if (!file.open(QIODevice::ReadWrite)){
        qCritical()<<"Could not open file!";
        qCritical()<<file.errorString();
        return;
    }

    QTextStream out(&file);
    out << name + "\n";
    out << phone + "\n";
    out << mail + "\n";
    file.flush();//pushes the data to the device

    qInfo()<<"reading file....";
    file.seek(0);
    qInfo()<<file.readAll();
    file.close();
}


