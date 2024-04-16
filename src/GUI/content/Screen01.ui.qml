

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.5
import QtQuick.Controls 6.5
import UntitledProject

Rectangle {
    id: rectangle
    width: 250
    height: 400
    color: "#feece2"

    Rectangle {
        id: rectangle1
        x: 0
        y: 0
        width: 250
        height: 100
        color: "#e2bfb3"

        Button {
            id: button
            x: 12
            y: 340
            width: 50
            height: 50
            opacity: 1
            text: "0"
            rotation: 0
            scale: 1
            font.pointSize: 12
            display: AbstractButton.TextOnly
            icon.color: "#607181"
            font.family: "Arial"
        }

        Button {
            id: button1
            x: 132
            y: 340
            width: 50
            height: 50
            text: qsTr("x10")
            rotation: 0
            scale: 1
            font.pointSize: 12
            icon.color: "#607181"
            font.family: "Arial"
        }

        Button {
            id: button2
            x: 72
            y: 340
            width: 50
            height: 50
            text: qsTr(".")
            rotation: 0
            scale: 1
            font.pointSize: 12
            icon.color: "#607181"
            font.family: "Arial"
        }

        Button {
            id: button3
            x: 192
            y: 340
            width: 50
            height: 50
            text: qsTr("=")
            rotation: 0
            scale: 1
            font.pointSize: 12
            icon.color: "#607181"
            font.family: "Arial"
        }

        Rectangle {
            id: rectangle2
            x: 19
            y: 19
            width: 213
            height: 63
            color: "#feece2"
            radius: 10
        }

        Button {
            id: button4
            x: 12
            y: 284
            width: 50
            height: 50
            opacity: 1
            text: "1"
            rotation: 0
            scale: 1
            font.pointSize: 12
            icon.color: "#607181"
            font.family: "Arial"
            display: AbstractButton.TextOnly
        }

        Button {
            id: button5
            x: 12
            y: 172
            width: 50
            height: 50
            opacity: 1
            text: "7"
            rotation: 0
            scale: 1
            font.pointSize: 12
            icon.color: "#607181"
            font.family: "Arial"
            display: AbstractButton.TextOnly
        }

        Button {
            id: button6
            x: 12
            y: 228
            width: 50
            height: 50
            opacity: 1
            text: "4"
            rotation: 0
            scale: 1
            font.pointSize: 12
            icon.color: "#607181"
            font.family: "Arial"
            display: AbstractButton.TextOnly
        }

        Button {
            id: button7
            x: 72
            y: 284
            width: 50
            height: 50
            opacity: 1
            text: "2"
            rotation: 0
            scale: 1
            font.pointSize: 12
            icon.color: "#607181"
            font.family: "Arial"
            display: AbstractButton.TextOnly
        }

        Button {
            id: button8
            x: 192
            y: 228
            width: 50
            height: 50
            opacity: 1
            text: "-"
            scale: 1
            font.pointSize: 12
            rotation: 0
            icon.color: "#607181"
            font.family: "Arial"
            display: AbstractButton.TextOnly
        }

        Button {
            id: button9
            x: 192
            y: 284
            width: 50
            height: 50
            text: qsTr("+")
            scale: 1
            font.pointSize: 12
            rotation: 0
            icon.color: "#607181"
            font.family: "Arial"
        }

        Button {
            id: button10
            x: 192
            y: 172
            width: 50
            height: 50
            opacity: 1
            text: "/"
            scale: 1
            font.pointSize: 12
            rotation: 0
            icon.color: "#607181"
            font.family: "Arial"
            display: AbstractButton.TextOnly
        }

        Button {
            id: button11
            x: 132
            y: 284
            width: 50
            height: 50
            opacity: 1
            text: "3"
            scale: 1
            font.pointSize: 12
            rotation: 0
            icon.color: "#607181"
            font.family: "Arial"
            display: AbstractButton.TextOnly
        }

        Button {
            id: button12
            x: 72
            y: 228
            width: 50
            height: 50
            opacity: 1
            text: "1"
            rotation: 0
            scale: 1
            icon.color: "#607181"
            font.family: "Arial"
            display: AbstractButton.TextOnly
        }

        Button {
            id: button13
            x: 132
            y: 228
            width: 50
            height: 50
            text: qsTr("Button")
            rotation: 0
            scale: 1
            icon.color: "#607181"
            font.family: "Arial"
        }

        Button {
            id: button14
            x: 72
            y: 172
            width: 50
            height: 50
            opacity: 1
            text: "1"
            rotation: 0
            scale: 1
            icon.color: "#607181"
            font.family: "Arial"
            display: AbstractButton.TextOnly
        }

        Button {
            id: button15
            x: 132
            y: 172
            width: 50
            height: 50
            opacity: 1
            text: "1"
            rotation: 0
            scale: 1
            icon.color: "#607181"
            font.family: "Arial"
            display: AbstractButton.TextOnly
        }

        Button {
            id: button16
            x: 72
            y: 228
            width: 50
            height: 50
            opacity: 1
            text: "5"
            scale: 1
            font.pointSize: 12
            rotation: 0
            icon.color: "#607181"
            font.family: "Arial"
            display: AbstractButton.TextOnly
        }

        Button {
            id: button17
            x: 132
            y: 228
            width: 50
            height: 50
            text: qsTr("6")
            scale: 1
            font.pointSize: 12
            rotation: 0
            icon.color: "#607181"
            font.family: "Arial"
        }

        Button {
            id: button18
            x: 72
            y: 172
            width: 50
            height: 50
            opacity: 1
            text: "8"
            scale: 1
            font.pointSize: 12
            rotation: 0
            icon.color: "#607181"
            font.family: "Arial"
            display: AbstractButton.TextOnly
        }

        Button {
            id: button19
            x: 132
            y: 172
            width: 50
            height: 50
            opacity: 1
            text: "9"
            scale: 1
            font.pointSize: 12
            rotation: 0
            icon.color: "#607181"
            font.family: "Arial"
            display: AbstractButton.TextOnly
        }

        Button {
            id: button20
            x: 12
            y: 116
            width: 50
            height: 50
            opacity: 1
            text: "\u221a"
            rotation: 0
            scale: 1
            font.pointSize: 12
            icon.color: "#607181"
            font.family: "Arial"
            display: AbstractButton.TextOnly
        }

        Button {
            id: button21
            x: 192
            y: 116
            width: 50
            height: 50
            opacity: 1
            text: "*"
            scale: 1
            font.pointSize: 12
            rotation: 0
            icon.color: "#607181"
            font.family: "Arial"
            display: AbstractButton.TextOnly
        }

        Button {
            id: button22
            x: 72
            y: 116
            width: 50
            height: 50
            opacity: 1
            text: "1"
            rotation: 0
            scale: 1
            icon.color: "#607181"
            font.family: "Arial"
            display: AbstractButton.TextOnly
        }

        Button {
            id: button23
            x: 132
            y: 116
            width: 50
            height: 50
            opacity: 1
            text: "1"
            rotation: 0
            scale: 1
            icon.color: "#607181"
            font.family: "Arial"
            display: AbstractButton.TextOnly
        }

        Button {
            id: button24
            x: 72
            y: 116
            width: 50
            height: 50
            opacity: 1
            text: "DEF"
            scale: 1
            font.pointSize: 12
            rotation: 0
            icon.color: "#607181"
            font.family: "Arial"
            display: AbstractButton.TextOnly
        }

        Button {
            id: button25
            x: 132
            y: 116
            width: 50
            height: 50
            opacity: 1
            text: "AC"
            scale: 1
            font.pointSize: 12
            rotation: 0
            icon.color: "#607181"
            font.family: "Arial"
            display: AbstractButton.TextOnly
        }
    }
    states: [
        State {
            name: "clicked"
        }
    ]
}
