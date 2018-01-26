import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import "../../QmlBase" as Base
Item{
signal goToSignup()
    Rectangle {
        id:root
        anchors.fill: parent
        color: "transparent"

        Rectangle{
            id:logo
            width: (parent.width/3)*2
            height: parent.height/2.5
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top:parent.top
            anchors.topMargin: 20
            color: "#00a2ff"


        }

        Base.ShadowTextField{
            id:userTextField
            anchors{
                top :logo.bottom
                horizontalCenter: parent.horizontalCenter
                topMargin: 30
            }
            placeholderText: "نام کاربری"
            width: root.width/2
            height: 50
        }

        Base.ShadowTextField{
            id:passTexeField
            placeholderText: "رمزعبور"
            width: root.width/2
            height: 50

            anchors{
                top :userTextField.bottom
                horizontalCenter: parent.horizontalCenter
                topMargin: 15
            }


        }

        Button{
            id:forgotButton

            anchors{
                top :passTexeField.bottom
                topMargin: 5
                right: passTexeField.right
            }

            background: Rectangle{
                color:"transparent"

            }
            contentItem: Text {
                // anchors.centerIn: parent
                text: qsTr("فراموشی رمز عبور")

                horizontalAlignment: Text.AlignRight
                color: "#90A4AE"
                font.pixelSize: 12
            }
            onClicked: {
                console.log("forgot")
            }
        }

        Base.ShadowButton{
            onClicked: {
                console.log("sign in")
            }

            id:loginButton
            width: root.width/2
            height: 50
            fText: "ورود"
            anchors{
                top :forgotButton.bottom
                horizontalCenter: parent.horizontalCenter
                topMargin: 30
            }
            background: Rectangle{
                anchors.fill: parent
                radius:width/2
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#2c7aff" }
                    GradientStop { position: 1.0; color: "#8d25ff" }
                }
            }

           }

        Row{
            anchors{
                bottom :root.bottom
                horizontalCenter: parent.horizontalCenter
                bottomMargin: 30
            }
            spacing: 10

            Text{
                text:"ثبت نام"
                color:"#00a2ff"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        console.log("sign up")
                        goToSignup()
                    }
                }
            }

            Text{
                text:"حساب کاربری ندارید ؟"
                color:"#666"
            }


        }


    }




}
