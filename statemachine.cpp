#include "statemachine.h"
#include <QDebug>
#include "contato.h"
#include "database.h"



StateMachine::StateMachine(QObject *parent):QObject(parent)
{

}

QStringList StateMachine::someVar() // Função getNome
{
    //qDebug()<< "entrou no return";
    return m_someVar;
}
void StateMachine::setSomeVar(QStringList newVar) // Seta uma nova QstringList pro nome
{
    if(m_someVar != newVar)
    {
        m_someVar = newVar;
        emit someVarChanged();
    }
}

QStringList StateMachine::phone()// Função getPhone
{
    return m_phone;
}
void StateMachine::setPhone(QStringList newVar) // Seta uma nova QstringList pro telefone
{

    if(m_phone != newVar)
    {
        m_phone = newVar;
        emit phoneChanged();

    }
}

QStringList StateMachine::mail()// Função getMail
{
    return m_mail;
}
void StateMachine::setMail(QStringList newVar) // Seta uma nova QstringList pro E-mail
{
    if(m_mail != newVar)
    {
        m_mail = newVar;
        emit mailChanged();
    }
}


QString StateMachine::singlePhone(int i)
{
    qDebug()<< i;
    if(i >= 0){
    qDebug()<< "entrou";
    QStringList a = phone();
    qDebug()<<a.at(i);
    qDebug() << a.value(i);
    return a.value(i);
    }
    return "i";
}
QString StateMachine::singleMail(int i)
{
    qDebug()<< i;
    if(i >= 0){
    qDebug()<< "entrou";
    QStringList a = mail();
    qDebug()<<a.at(i);
    qDebug() << a.value(i);
    return a.value(i);
    }
    return "i";
}

QStringList StateMachine::sendValues()
{

    QMap<int,contato> map;
    map = Database::getInstance()->readValues();
    int count = 0;
    int last = map.size();
    QStringList teste;
    QStringList phone;
    QStringList mail;
    qDebug() << map.size();
    while( count <= last)
    {


       teste << map[count].recuperaNome();
       phone << map[count].recuperaTelefone();
       mail <<map[count].recuperaEmail();
       count++;

    }

 //   setPhone(phone);
//    setMail(mail);
    return teste;


}
QStringList StateMachine::sendValues2()
{

    QMap<int,contato> map;
    map = Database::getInstance()->readValues();
    int count = 0;
    int last = map.size();
    QStringList teste;
    QStringList phone;
    QStringList mail;
    qDebug() << map.size();
    while( count <= last)
    {


       teste << map[count].recuperaNome();
       phone << map[count].recuperaTelefone();
       mail <<map[count].recuperaEmail();
       count++;

    }

    //setPhone(phone);
//    setMail(mail);
    return phone;


}
QStringList StateMachine::sendValues3()
{

    QMap<int,contato> map;
    map = Database::getInstance()->readValues();
    int count = 0;
    int last = map.size();
    QStringList teste;
    QStringList phone;
    QStringList mail;
    qDebug() << map.size();
    while( count <= last)
    {


       teste << map[count].recuperaNome();
       phone << map[count].recuperaTelefone();
       mail <<map[count].recuperaEmail();
       count++;

    }

    //setPhone(phone);
//    setMail(mail);
    return mail;


}
