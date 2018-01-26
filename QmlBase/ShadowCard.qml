import QtQuick 2.7
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0

Label {
    id:root
    property color  fBorderColor: "#03A9F4"
    property color  ffirstBackGroundColor: "#2196F3"
    property color  fSecondBackGroundColor: "#fff"
    property color  ffirstTextColor: "#fff"
    property color  fSecondTextColor: "#03A9F4"
    property string fContentText: "content"


            Label{
                id:shadowLabel
                height:root.height -30
                padding: 6
                y:30
                width: root.width
                color: fSecondTextColor
                text:fContentText
                background: Rectangle{
                    color: fSecondBackGroundColor
                    radius: 3
                }

        }
        DropShadow {
            z: -1
            anchors.fill: shadowLabel
            horizontalOffset: 0
            verticalOffset: 0
            radius: 8.0
            samples: 17
            color: "#2196F3"
            source: shadowLabel
        }

}
