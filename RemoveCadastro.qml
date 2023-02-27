import QtQuick 2.15
import QtQuick.Controls 2.5

Page {

    width: 600
    height: 400

    title: qsTr("Remover Cadastro")


    ScrollView{
        anchors.fill: parent

        ListView{
            width: parent.width
            model: 21 //numero de itens
            delegate: ItemDelegate{
                text: "Item" + (index +1) //exibição dos itens
                width: parent.width
            }
        }
    }

}
