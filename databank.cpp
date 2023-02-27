#include "databank.h"

databank::databank()
{

}

void databank::addValues(QString name, QString phone, QString mail)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sergi/Desktop/QT/Agenda/Agenda/db.sqlite");

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
    db.close();

}

QMap<int,contato> databank::readValues()
{
    contato conta;
    QSqlDatabase db;

    QMap<int,contato> map;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sergi/Desktop/QT/Agenda/Agenda/db.sqlite");

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

void databank::deleteValue(QString name)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sergi/Desktop/QT/Agenda/Agenda/db.sqlite");

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
    db.close();
}

