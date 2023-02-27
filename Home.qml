import QtQuick 2.15
import QtQuick.Controls 2.5


Page {

    width: 600
    height: 400

    title: qsTr("Home")

    Image {
        width: 130; height: 100
        fillMode: Image.PreserveAspectFit
        source: "qrc:/Images/Logo.png"
        anchors.centerIn: parent
    }

}
