#include "databank.h"
#include "statemachine.h"

QSqlDatabase db;
databank::databank()
{

}
databank::~databank()
{

}

databank* databank::m_Instance = nullptr;
databank* databank::getInstance()
{
    if(m_Instance==NULL)
    {
        m_Instance=new databank();
    }
    return m_Instance;

}


void databank::openBase()
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sergi/Desktop/QT/Agenda/Agenda/db.sqlite");
    qDebug()<< "opened";

}


StateMachine machine;
void databank::addValues(QString name, QString phone, QString mail)
{

    if(!db.open())
    {
        qDebug()<<"problem opening database";
    }
    QSqlQuery qry;
    qry.prepare("INSERT INTO contatcs(Name,Phone,mail)"
                "VALUES (?,?,?);");
    //qry.addBindValue(id);
    qry.addBindValue(name);
    qry.addBindValue(phone);
    qry.addBindValue(mail);

    if(!qry.exec())
    {
        qDebug()<< "error adding values into database";
    }
 //   db.close();
}
void databank::editValues(QString data, QString Collunm, int index)
{

    if(!db.open())
    {
        qDebug()<<"problem opening database";
    }
    QSqlQuery qry;
    //aqui vai a mensagem pronta

    qry.prepare("UPDATE contatcs SET Collunm=:coluna = "+data+" WHERE id=:id");

    //-------------------------
    if(!qry.exec())
    {
        qDebug()<< "error updating values into database";
    }

}
QMap<int,contato> databank::readValues()
{
    contato conta;


    QMap<int,contato> map;


    if(!db.open())
    {
        qDebug()<<"problem opening database";
    }
    QSqlQuery qry;
    qry.prepare("SELECT * FROM contatcs");
    if(qry.exec())
    {
//        int idName = qry.record().indexOf("Name");
//        int idPhone = qry.record().indexOf("Phone");
//        int idMail = qry.record().indexOf("Mail");
        int count = 0;
        while (qry.next()) {
            conta.definirNome(qry.value(qry.record().indexOf("Name")).toString());
            conta.definirTelefone(qry.value(qry.record().indexOf("Phone")).toString());
            conta.definirEmail(qry.value(qry.record().indexOf("Mail")).toString());
            map.insert(count,conta);
            count++;

        }
     }else qDebug()<< "não consegue";
    db.close();
    //StateMachine::sendValues(map);
    return map;
}

QStringList databank::readoValos()
{
    contato conta;


    QStringList lista;
    QStringList phone;
    QStringList mail;


    if(!db.open())
    {
        qDebug()<<"problem opening database";
    }
    QSqlQuery qry;
    qry.prepare("SELECT * FROM contatcs");
    if(qry.exec())
    {
//        int idName = qry.record().indexOf("Name");
//        int idPhone = qry.record().indexOf("Phone");
//        int idMail = qry.record().indexOf("Mail");
        int count = 0;
        while (qry.next() != qry.last()) {
            lista.append(qry.value(qry.record().indexOf("Name")).toString());
           // qDebug()<<lista;
            phone.append(qry.value(qry.record().indexOf("Phone")).toString());
          //  qDebug()<<phone;
            mail.append(qry.value(qry.record().indexOf("Mail")).toString());
        //    qDebug()<<mail;
            count++;

        }
     }else qDebug()<< "não consegue";

    //StateMachine::sendValues(map);
    machine.setPhone(phone);
    machine.setMail(mail);
    machine.setSomeVar(lista);
    return lista;
}

void databank::deleteValue(QString name)
{

    if(!db.open())
    {
        qDebug()<<"problem opening database";
    }
    QSqlQuery qry;
    qry.prepare("DELETE FROM contatcs WHERE name = (:name)");
    qry.bindValue(":name",name);
    if(!qry.exec())
    {
        qDebug()<< "removePerson error";
    }

}

