#ifndef ARQUIVO_H
#define ARQUIVO_H

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

//#include "contato.h"


class Arquivo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString Arquivo READ m_Arquivo NOTIFY m_ArquivoChanged)
public:

    explicit Arquivo(QObject *parent = nullptr);
    void setM_arquivo(QString new_arquivo);
    QString m_Arquivo();
private:
    QString __m_arquivo__ = {""};

signals:
    void status(QVariant data);
    void m_ArquivoChanged();

public slots:

    QStringList leArquivo();
    void writeFile(QString name,QString  phone,QString  mail);
   // void saveContact();

};

#endif // ARQUIVO_H
