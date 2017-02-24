///
/// 数据库导入程序
/// 池晓焱
/// 2017-02-23
/// 注意点
///     1.重写关闭函数，在关闭的时候释放资源；
///     2.支持批量导入模型文件
///     3.
///
///


#include <QApplication>
#include <QQmlApplicationEngine>

#include <QStringList>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

#include <QQmlContext>

#include "SqlData.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<SqlData>("SqlData", 1, 0, "SqlData");

    SqlData data;

    QStringList dataList;
    dataList.append("DD");
    dataList.append("HJ");
    dataList.append("LJ");
    dataList.append("KJ");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QQmlContext* ctx = engine.rootContext();
    ctx->setContextProperty("myModel",QVariant::fromValue(dataList));


    return app.exec();
}












