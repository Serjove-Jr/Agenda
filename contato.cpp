#include "contato.h"
#include "crialista.h"

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

contato::contato()
{

}

QString contato::recuperaNome()
{
    return nome;
}

QString contato::recuperaTelefone()
{
    return telefone;
}

QString contato::recuperaEmail()
{
    return email;
}

void contato::definirNome(QString nome)
{
    this->nome = nome;
}

void contato::definirTelefone(QString telefone)
{
    this->telefone = telefone;
}

void contato::definirEmail(QString email)
{
    this->email = email;
}
