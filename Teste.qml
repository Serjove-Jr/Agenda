import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.3
import StateMachine 1.0

import Controller 1.0

Page {
    width: 600
    height: 400

    title: qsTr("teste")
    Controller{
        id: controller

    }

    Item{
        id: variable
        property string name: "0"


    }

    StateMachine{
        id: stateMachine
    }
    ListView {
        id : mListViewId
        anchors.fill: parent
        header: headerId
        footer : Rectangle{
            width: parent.width
            height: 50
            color: "dodgerblue"
        }
        highlight: Rectangle{
            width: parent.width
            color: "blue"
            radius: 14
            border.color: "lightblue"
            z : 3
            opacity: 0.1
        }

        model : Machine.someVar

         // Aqui entra o dado
        //delegate : delegateId
        delegate: Rectangle {
            id : rectangleId
            width: parent.width
            height: 50
            color: "beige"
            border.color: "Lightblue"
            radius: 10

            Text {
                id : textId
                anchors.centerIn: parent
                font.pointSize: 20
                text : modelData
            }

            MouseArea {
                id: selec
                anchors.fill: parent
                enabled: true
                z:1
                onClicked: {
                    console.log("Clicked on :"+ modelData)
                    variable.name = modelData
                    mListViewId.currentIndex = index
                    console.log("Index :"+ index)
                    contactInfo.visible = true

                }
            }
        }
    }

    Component {
        id : headerId
        Rectangle {
            id : headerRectId
            width: parent.width
            height: 50
            color: "lightblue"
            border {color: "#9EDDF2"; width: 2}

            Text {
                anchors.centerIn: parent
                text : "Contatos"
                font.pointSize: 20
            }

        }
    }
    Rectangle {
        id: contactInfo
        z: 4

        anchors.centerIn: parent
        width: parent.width/2
        height: parent.height/2
        color: "lightgreen"
        visible: false
        Column{
          anchors.centerIn: parent
            Grid{

                spacing:20
                columns: 2
                Rectangle{
                    width: 50; height: 20
                    Text {
                        id: phone
                        text: qsTr("Phone:")
                    }
                }
                Rectangle
                {
                    width: 150; height: 20
                    TextInput
                    {
                        id: phoneTxt
                        text:
                        {

                              controller.singleP(mListViewId.currentIndex)
                        }

                        onEditingFinished:
                        {

                            console.log("data: " + phoneTxt.text)
                            console.log(variable.name)
                            console.log(mListViewId.currentIndex)
                            console.log("Phone")

                            controller.editContact(phoneTxt.text,"Phone",mListViewId.currentIndex)
                        }
                    }
                }
                Rectangle{
                    width: 50; height: 20
                    Text {
                        id: mail
                        text: qsTr("E-mail:")
                    }
                }
                Rectangle{
                       width: 150; height: 20
                    TextInput {
                        id: mailTxt
                        text: {

                            controller.singleM(mListViewId.currentIndex)
                        }
                    }
                }
                Rectangle{
                    width: 50; height: 20
                    Text {
                        id: exit
                        text: qsTr("EXIT")

                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                           // selec.enabled = true
                            contactInfo.visible = false
                        }
                    }
                }
                Rectangle{
                    width: 50; height: 20
                    Text {
                        id: delete_contact
                        text: qsTr("Delete")

                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            controller.deleteContact(variable.name)
                            // selec.enabled = true
                            contactInfo.visible = false
                        }
                    }
                }
            }
        }
    }

}

