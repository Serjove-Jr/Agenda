import QtQuick 2.15
import QtQuick.Controls 2.5

//imported classes
import Controller 1.0
import StateMachine 1.0



Page {

    width: 600
    height: 400

    title: qsTr("Consulta")

    ScrollView{
        anchors.fill: parent

        ListView{
            width: parent.width

            model: 21 //numero de itens
            delegate: ItemDelegate{
                Rectangle{
                    color: "lightgray"
                    width: parent.width
                    height: 30
                    Text{
                        font.bold: true
                        anchors.centerIn: parent
                        text: "Item" + (index +1) //exibição dos itens
                    }
                }
                //text: "Item" + (index +1) //exibição dos itens
                width: parent.width
            }
        }
    }

}
