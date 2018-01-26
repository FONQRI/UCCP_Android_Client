import QtQuick 2.9
import QtQuick.Controls 2.2
import user 1.0

Rectangle {
    anchors.fill: parent
    color  :"#fff"
    Component.onCompleted: signLoader.sourceComponent = signUpComonnent
    User{
        id:myUser
        username: "FONQRI"
        password: "password"
        name: "behnam"
        family: "sabaghi"
        sex:"male"
        email: "behnamsabaghi@gmail.com"
        phoneNumber: "+989384797401"
        berthdayDay: 4
        berthdayMonth: 10
        berthdayYear: 1995
    }
    Loader{
        id:signLoader
        anchors.fill: parent


    }
    Component{
        id:signUpComonnent
        SignUp {
            onGoToSignin:{ signLoader.sourceComponent = signInComonnent}
            onSignUp:{
                myUser.signUp()
            }
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
