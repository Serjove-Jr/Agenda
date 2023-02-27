#ifndef CONTATO_H
#define CONTATO_H

#include <QObject>
#include <QObject>
#include <QDebug>
#include <QVariant>
#include <QStringList>
#include <iostream>

class contato
{

private:
    QString nome;
    QString telefone;
    QString email;

public:
    contato();
    QString recuperaNome();
    QString recuperaTelefone();
    QString recuperaEmail();

    void definirNome(QString nome);
    void definirTelefone(QString telefone);
    void definirEmail(QString email);
};

#endif // CONTATO_H
