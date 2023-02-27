import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.3
//Created classes
import Controller 1.0



Page {
    Controller{
        id: controller
    }
    Rectangle{
        id: errorMessage
        width: 200
        height: 100
        color: "lightgray"
        visible: false
        z:1
        Text{
            x: 10
            y: 0
            id: errorText
            text: ""

        }
        Button{
            x: errorMessage.width/2 - 50
            y: 50
            text: "Ok"
            onClicked: {
                errorMessage.visible = false
            }
        }


    }
    Item{
        id: variable
        property string name: ""
        property string phone: ""
        property string mail: ""

    }


    function verifyData(){
        //console.log(variable.name.length)
        if(variable.name.length < 1 ){
            errorMessage.visible = true
            errorText.text = "O Nome informado está vazio"
            return
        }else if(variable.phone.length < 1 ){
            errorMessage.visible = true
            errorText.text = "O Telefone informado está vazio"
            return
        }else if(variable.mail.length < 1 ){
            errorMessage.visible = true
            errorText.text = "O E-mail informado está vazio"
            return
        }

        controller.addcontact(variable.name, variable.phone, variable.mail)
        telefone.text = ""
        nome.text = ""
        email.text = ""
    }
    function getData(name, phone, mail){

        var params = {};
    }

    width: 600
    height: 400

    title: qsTr("Cadastro")
    Column{
        anchors.centerIn: parent
        spacing: 5

        Grid{

            spacing: 5
            columns: 2


            Rectangle{
                width: 50; height: 20
                Text {
                    anchors.fill: parent
                    font.bold: true
                    text: qsTr("Nome: ")
                }
            }
            Rectangle{
                border.color: "black"
                width: 200; height: 20
                TextInput{
                    id: nome
                    anchors.fill: parent
                    cursorVisible: true
                    text: " "
                    onAccepted: {
                        variable.name = getText(0,100)

                    }
                }
            }
            Rectangle{
                width: 50; height: 20
                Text {
                    anchors.fill: parent
                    font.bold: true
                    text: qsTr("Telefone: ")
                }
            }
            Rectangle{
                border.color: "black"
                width: 200; height: 20
                TextInput{
                    id: telefone
                    anchors.fill: parent
                    cursorVisible: true
                    text: " "
                    onAccepted: {
                        variable.phone = getText(0,100)

                    }
                }
            }
            Rectangle{
                width: 50; height: 20
                Text {
                    anchors.fill: parent
                    font.bold: true
                    text: qsTr("E-mail: ")
                }
            }
            Rectangle{
                border.color: "black"
                width: 200; height: 20
                TextInput{
                    id: email
                    anchors.fill: parent
                    cursorVisible: true
                    text: " "

                    onAccepted: {
                        variable.mail = getText(0,100)

                    }
                }
            }

        }
        Button{
            id: record

            text: "Gravar"
            onClicked: {
                verifyData()
            }
        }
    }


}
