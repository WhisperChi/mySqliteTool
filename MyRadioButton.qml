import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

Rectangle{


    //主窗体的高宽，背景颜色
    width: 320;
    height: 300;
    color: "#d0d0d0";


    //结果提交的包围框和按钮
    Rectangle{
        id: resultHolder;
        color:"#a0a0a0";
        width: 200;
        height: 60;
        anchors.centerIn: parent;
        visible: false;
        z: 2;

        opacity: 0.8;

        border.width: 2;
        border.color: "#808080";

        Text{

            id:result;
            anchors.centerIn: parent;
            font.pixelSize: 20;
            color:"blue";
            font.bold: true;
        }
    }


    //定义的互斥分组
    ExclusiveGroup{

        id: mos;
    }


    // 单选框框风格组件
    Component{

        id: radioStyle;
        RadioButtonStyle{

            indicator: Rectangle{
                implicitHeight: 12;
                implicitWidth: 16;

                radius: 6;
                border.color: control.hovered? "darkblue":"gray";
                border.width: 1;

                Rectangle{
                    anchors.fill: parent;
                    visible: control.checked;
                    color:"#0000a0";
                    radius: 5;
                    anchors.margins: 3;
                }


            }



            label:Text{
                color: control.activeFocus?"blue":"black";
                text:control.text;
            }


        }

    }



    //具体标签
    Text{
        id: notation;
        text:"Please select the best mobile os:";
        anchors.top: parent.top;
        anchors.topMargin: 16;
        anchors.left: parent.left;
        anchors.leftMargin: 8;

    }

    //具体单选框


    //具体单选框
    RadioButton{

        id:android;
        text:"Android";
        exclusiveGroup: mos;
        anchors.top: notation.bottom;
        anchors.topMargin: 4;
        anchors.left: notation.left;
        anchors.leftMargin: 20;
        checked:  true;
        focus: true;
        activeFocusOnPress:  true;
        style:radioStyle;
        onClicked: resultHolder.visible = false;

    }

    RadioButton{

        id: ios;
        text:"IOS";
        exclusiveGroup: mos;
        anchors.top: android.bottom;
        anchors.topMargin: 4;
        anchors.left: notation.left;
        activeFocusOnPress: true;
        style:radioStyle;
        onClicked: resultHolder.visible = false;


    }



    RadioButton{

        id: wp;
        text:"wp_phone";
        exclusiveGroup: mos;
        anchors.top: ios.bottom;
        anchors.topMargin: 4;
        anchors.left: notation.left;
        activeFocusOnPress: true;
        style:radioStyle;
        onClicked: resultHolder.visible = false;


    }

    RadioButton{

        id: firefox;
        text:"firefox OS";
        exclusiveGroup: mos;
        anchors.top: wp.bottom;
        anchors.topMargin: 4;
        anchors.left: notation.left;
        activeFocusOnPress: true;
        style:radioStyle;
        onClicked: resultHolder.visible = false;

    }


    RadioButton{

        id: sailfish;
        text:"sailfish OS";
        exclusiveGroup: mos;
        anchors.top: firefox.bottom;
        anchors.topMargin: 4;
        anchors.left: notation.left;
        activeFocusOnPress: true;
        style:radioStyle;
        onClicked: resultHolder.visible = false;


    }



    //提交按钮
    Button{
        id: confirm;
        text:"Confirm";

        anchors.top: sailfish.bottom;
        anchors.topMargin: 4;
        anchors.left: notation.left;


        onClicked: {
            result.text = mos.current.text;
            resultHolder.visible = true;
        }

    }



}
