import QtQuick 2.3
import QtQuick.Controls 1.2

import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import QtQuick.Window 2.0

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

         //TestCode
        MyRadioButton{

        }


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
                text:"分类"

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

                        //color:"red"  //Test
                    }

                    Item{
                        id:sqlType
                        y:fileOpen.y + fileOpen.height + 2
                        width:parent.width
                        height: 100

                        ExclusiveGroup { id: tabPositionGroup }
                        ListView{
                            anchors.fill: parent
                            model:myModel

                            delegate:
                                      RowLayout {
                                          RadioButton {
                                              id: bottomButton
                                              text: modelData
                                              exclusiveGroup: tabPositionGroup
                                              Layout.minimumWidth: 100
                                          }
                                      }

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
                    console.log("current url :" + fileDialog.fileUrl)
                    fileText.text = fileDialog.fileUrl
                    //Qt.openUrlExternally(fileUrls[i])
        }
        onRejected: { console.log("Rejected") }
    }
    //! [filedialog]


    //! [ListView]



    //! [ListView]


}
