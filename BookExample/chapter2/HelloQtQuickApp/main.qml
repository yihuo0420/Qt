﻿import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    color: "blue";
    title: qsTr("Hello Qt Quick App")

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }
    }
}
