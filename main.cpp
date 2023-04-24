#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
//#include "arquivo.h"
//#include "contato.h"
//#include "crialista.h"
#include "database.h"
#include "statemachine.h"
#include "controller.h"
#include <QStringList>
#include <QMap>

//Database
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>


//Entry point of the application
int main(int argc, char *argv[])
{

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    //Application attributes
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif


    //The application Class
    QGuiApplication app(argc, argv);

    //The QML Engine
    QQmlApplicationEngine engine;


    //Register type QML


    qmlRegisterType<Controller>("Controller",1,0,"Controller");
    Controller controller;
    //engine.rootContext()->setContextProperty("Controller",&controller);

    StateMachine machine;
    engine.rootContext()->setContextProperty("Machine",&machine);

    qmlRegisterType<Controller>("StateMachine",1,0,"StateMachine");



    Database::getInstance()->openBase();
    //qDebug()<< "iniciar leitura";
    Database::getInstance()->readoValos();





   //engine.rootContext() -> setContextProperty("StateMachine", &machine);






    //The URL of the QML file, notice this is a compiled resource
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    //Coneccting a signal and slot - making sure the object and url match
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    //The engine loading the QML File
    engine.load(url);

    //the application entering an event loop that keeps the application open
    return app.exec();
}


