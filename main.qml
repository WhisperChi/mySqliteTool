import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import QtQuick.Window 2.0

import SqlData 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("数据库录入程序")

    Item{
         id:menu
         anchors.fill:parent.fill
         width:parent.width
         height:parent.height



       Item{
            id:model
            x:0
            width:parent.width / 2
            height: parent.height

            Button{
                id:modelBt
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                width:100
                height:100
                text:"模型"
                onClicked:{
                    modelUI.visible = true
                    menu.visible = false
                }
            }
        }

       Item{
            id:type
            x:parent.width / 2
            width:parent.width / 2
            height: parent.height

            Button{
                id:typeBt
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                width:100
                height:100
                text:"类型"

                onClicked:{
                    typeUI.visible = true
                    menu.visible = false
                }
            }

        }
    }

    Item{
        id:funcUI
        anchors.fill:parent.fill
        width:parent.width
        height:parent.height

        Item{
            /*
                modelUI
                    -backMenu0
                    -modelFunc
                        -fileOpen
                            -Text
                            -But
                        -sqlType
                            -type0
                            -type1
                            ...
                            -typen
                        -submit

            */
                id:modelUI
                anchors.fill: parent.fill
                width:parent.width
                height: parent.height

                visible: false

                Item{
                    id:backMenu0
                    //Test code
                    width:30
                    height: 30

                    Image{
                        width:parent.width
                        height:parent.height
                        source:"arrowLeft.png"
                    }

                    MouseArea{
                        anchors.fill: backMenu0
                        onClicked: {
                            modelUI.visible = false
                            menu.visible = true
                        }
                    }
                }

                Item{
                    id:modelFunc
                    y:backMenu0.height + 5
                    width:parent.width
                    Rectangle{
                        width:modelUI.width
                        height:modelUI.height

                        Item{
                            id:fileOpen
                            width:parent.width
                            height: 30
                            Rectangle{
                                id:bgRec
                                color:"gray"
                                width:parent.width / 4 * 3
                                height: 30
                            }
                            Rectangle{
                                color:"white"
                                x:1
                                y:1
                                width:bgRec.width - 2
                                height:bgRec.height -2
                            }

                            TextEdit{
                                id:fileText
                                width:parent.width / 4 * 3
                                height: 30
                                readOnly: true
                            }
                            Button{
                                id:fileOpenBt
                                x:fileText.x + fileText.width
                                width:80
                                height:30
                                text:"打开文件"
                                onClicked: {
                                     fileDialog.open()
                                }
                            }
                        }

                    }

                    Rectangle{
                        id:sqlType
                        y:fileOpen.y + fileOpen.height + 2
                        width:parent.width / 2
                        height: modelUI.height

                        color:"#d0d0d0"

                        ExclusiveGroup { id: tabPositionGroup }
                        ListView{
                            id:radioBts
                            anchors.fill: parent
                            model: sql.types

                            delegate:
                                RadioButton {
                                    id: bottomButton

                                    anchors.leftMargin: 20

                                    text: modelData
                                    style:radioStyle
                                    exclusiveGroup: tabPositionGroup
                                    Layout.minimumWidth: 100
                                    checked: false
                                    activeFocusOnPress: true
                                }

                        }

                    }

                    Button{
                        id:update
                        text:"更新"
                        anchors.top: sqlType.top
                        anchors.topMargin: 20
                        anchors.right: sqlType.right
                        anchors.rightMargin: 80
                        onClicked: {
                            sql.update()
                        }
                    }

                    Button{
                        id:submit
                        text:"提交"

                        anchors.top: update.bottom
                        anchors.topMargin: 20
                        anchors.right: sqlType.right
                        anchors.rightMargin: 80
                        onClicked: {
                            //console.log(tabPositionGroup.current.text)
                            sql.update()
                            sql.insert(fileText.text,tabPositionGroup.current.text)
                            console.log(tabPositionGroup.current.text)
                        }
                    }
                    Button{
                        id:myPrint
                        text:"打印"

                        anchors.top: submit.bottom
                        anchors.topMargin: 20
                        anchors.right: sqlType.right
                        anchors.rightMargin: 80

                        onClicked: {
                            sql.print()
                        }
                    }
                }



         }//End modelUI

        Item{
            id:typeUI
            anchors.fill:parent.fill
            width:parent.width
            height: parent.height
            visible: false

            Item{
                id:backMenu1
                //Test code
                width:30
                height: 30
                Image{
                    width:parent.width
                    height:parent.height
                    source:"arrowLeft.png"
                }

                MouseArea{
                    anchors.fill: backMenu1
                    onClicked: {
                        typeUI.visible = false
                        menu.visible = true
                    }
                }
            }

            Item{
                id:typeFunc
            }

        }//End typeUI
       }


    //! [filedialog]
    FileDialog{
        id: fileDialog

        //visible: fileDialogVisible.checked
        //modality: fileDialogModal.checked ? Qt.WindowModal : Qt.NonModal
        //title: fileDialogSelectFolder.checked ? "Choose a folder" :
         //   (fileDialogSelectMultiple.checked ? "Choose some files" : "Choose a file")
        //selectExisting: fileDialogSelectExisting.checked
        //selectMultiple: fileDialogSelectMultiple.checked
        //selectFolder: fileDialogSelectFolder.checked
        nameFilters: [ "Image files (*.png *.jpg)", "All files (*)" ]
        selectedNameFilter: "All files (*)"
        //sidebarVisible: fileDialogSidebarVisible.checked

        onAccepted: {
            console.log("Accepted: " + fileUrls)
            //if (fileDialogOpenFiles.checked)
                for (var i = 0; i < fileUrls.length; ++i)
                    console.log(fileUrls[i])

                var path = fileDialog.fileUrl.toString();
                        // remove prefixed "file:///"
                        path = path.replace(/^(file:\/{2})/,"");
                        // unescape html codes like '%23' for '#'
                        var cPath = decodeURIComponent(path);
                        fileText.text = cPath

                    //Qt.openUrlExternally(fileUrls[i])
        }
        onRejected: { console.log("Rejected") }
    }
    //! [filedialog]


    //! [ListView]



    //! [ListVie]

    //! [RadioButtonStyle]
    // 单选框框风格组件
    Component{

        id: radioStyle;
        RadioButtonStyle{

            indicator: Rectangle{
                implicitHeight: 12;
                implicitWidth: 16;

                radius: 6;
                border.color: control.hovered? "darkblue":"gray";
                border.width: 3;

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
    //! [RadioButtonStyle]

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

    SqlData{
        id:sql

        onTypesChanged: {
            radioBts.update()
        }
    }
}
