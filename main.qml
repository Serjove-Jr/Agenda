import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

//import Arquivo 1.0


ApplicationWindow {
    id: windown
    width: 600
    height: 400
    visible: true
    title: qsTr("Agenda")

    header: ToolBar{
        contentHeight: toolButton.implicitHeight

        ToolButton{
            id: toolButton
            text: stackView.depth > 1 ? "\u25C0" : "\u2630"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {
                if (stackView.depth > 1){
                    stackView.pop()
                }else{
                    drawer.open()
                }
            }
        }
        Label {
            text: stackView.currentItem.title
            anchors.centerIn: parent
        }
    }

    Drawer{
        id: drawer
        width: windown.width * 0.66
        height: windown.height


        Column{
            anchors.fill: parent

            ItemDelegate{
                text: qsTr("Consulta")
                width: parent.width
                onClicked: {
                    stackView.push("Consulta.qml")
                    drawer.close()
                }
            }
            ItemDelegate{
                text: qsTr("Cadastro")
                width: parent.width
                onClicked: {
                    stackView.push("Cadastro.qml")
                    drawer.close()
                }
            }
            ItemDelegate{
                text: qsTr("Remover Cadastro")
                width: parent.width
                onClicked: {
                    stackView.push("RemoveCadastro.qml")
                    drawer.close()
                }
            }
        }
    }
    StackView{
        id: stackView
        initialItem: "Home.qml"
        anchors.fill: parent
    }
}
