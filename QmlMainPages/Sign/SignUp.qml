import QtQuick 2.9
import "../../QmlBase" as Base

Item{
    id:root
    signal goToSignin()
    signal signUp();

    anchors.fill: parent
    Rectangle {
        id:topSingup
        anchors.bottom: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.height
        height: width
        radius:width/2
        anchors.bottomMargin: -160
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#2c7aff" }
            GradientStop { position: 1.0; color: "#8d25ff" }
        }
    }
    Text{
        text: "ثبت نام"
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 60
        color: "white"
        font.pixelSize: 25
    }

    Text{
        text: "<"
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 30
        anchors.leftMargin: 10
        color: "white"
        font.pixelSize: 25
        MouseArea{
            anchors.fill: parent
            onClicked: {
                console.log("go to login")
                goToSignin()
            }
        }
    }
    Column{
        anchors.top:topSingup.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 15
        topPadding: 20

        /**
    std::string username{""};
    std::string name{""};
    std::string family{""};
    std::string sex{""};
    std::string email{""};
    std::string phoneNumber{""};
    std::vector<std::string> favoriteTags;
    DateTime berthday;
    */
        Base.ShadowTextField{
            id:userTextField
            placeholderText: "نام کاربری"
            width: root.width/2
            height: 50
        }

        Base.ShadowTextField{
            id:nameTextField
            placeholderText: "نام"
            width: root.width/2
            height: 50
        }

        Base.ShadowTextField{
            id:familyTextField
            placeholderText: "نام خانوادگی"
            width: root.width/2
            height: 50
        }


        Base.ShadowTextField{
            id:emailTextField
            placeholderText: "ایمیل"
            width: root.width/2
            height: 50
        }

        Base.ShadowTextField{
            id:phoneTextField
            placeholderText: "شماره موبایل"
            width: root.width/2
            height: 50
        }

        Base.ShadowTextField{
            id:firstPassTextField
            placeholderText: "رمزعبور"
            width: root.width/2
            height: 50
        }
        Base.ShadowTextField{
            id:secondPassTextField
            placeholderText: "تکرار رمزعبور"
            width: root.width/2
            height: 50
        }

        Base.ShadowButton{
            onClicked: {
                console.log("sign up")
                signUp();
            }

            id:loginButton
            width: root.width/2
            height: 50
            fText: "ثبت نام"
            anchors{
                horizontalCenter: parent.horizontalCenter
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


    }

}
