import QtQuick 2.9
import QtQuick.Controls 2.2

Rectangle {
    anchors.fill: parent
    color  :"#fff"
    Component.onCompleted: signLoader.sourceComponent = signUpComonnent
    Loader{
        id:signLoader
        anchors.fill: parent


    }
    Component{
        id:signUpComonnent
        SignUp {
            onGoToSignin: signLoader.sourceComponent = signInComonnent
        }
    }
    Component{
        id:signInComonnent
        SignIn {
            id: signIn
            onGoToSignup: signLoader.sourceComponent = signUpComonnent

        }
    }




}
