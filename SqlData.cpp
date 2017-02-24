#include "SqlData.h"

#include <iostream>

#include <QDir>
#include <QFileInfo>
#include <QCoreApplication>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sstream>

#include "sqlite3.h"

typedef struct _tableData{
    std::string codeex;
    std::string path;
    std::string name;

}tableData;

void myWriteIntoFile(std::vector<tableData> data,std::string tableName,std::string path = "./")
{
    std::string filePath = path + "/";
    filePath += tableName;

    std::cout << "Write path :" << filePath << std::endl;

    FILE *fp = fopen(filePath.c_str(),"w");

    std::cout << "Start to write ......" << data.size() << std::endl;

    for(int i = 0; i < data.size();i++)
    {
        fprintf(fp,"%s	%s	%s\n",data[i].codeex.c_str(),data[i].name.c_str(),data[i].path.c_str());
    }

    std::cout <<"End Write." << std::endl;

    fclose(fp);
}

static int _callback_exec(void * notused,int argc, char ** argv, char ** aszColName)
{
    int i;
    for ( i=0; i<argc; i++  )
    {
        }
    return 0;
}

int SqlData::sqlInsert(std::string path,std::string table)
{
    QFileInfo fileInfo(QString::fromLocal8Bit(path.c_str()));
    std::string fileName = fileInfo.fileName().toStdString();

    //Todo: 名字为空或者路径为空时，提醒
    //Over:20170225 05:52
    if(path == "" || fileName == "")
        return -3;



    //! [sqlite]
    sqlite3_stmt* stat;
    sqlite3* db = NULL;

    int rc = sqlite3_open(m_sqlPath.toStdString().c_str(),&db);

    //Todo:	这边发现相对路径有点问题
    //int rc = sqlite3_open("/Users/whisperchi/work/MySqlTool/testData.sqlite3",&db);

    if(rc != 0)
    {
        return -1;
    }

    char* zErrmsg = 0;
    std::string maxRowidCmd = "select MAX(rowid) from " + table;
    maxRowidCmd += ";";

    sqlite3_prepare(db,maxRowidCmd.c_str(),-1,&stat,0);
    sqlite3_step(stat);

    if(stat == NULL)
    {
        std::cout << "Operation failed.\n";
        return -2;
    }

    int maxRowid = sqlite3_column_int(stat,0);

    std::string maxCodeCmd = "select MAX(code) from " + table;
    maxCodeCmd += ";";

    sqlite3_prepare(db,maxCodeCmd.c_str(),-1,&stat,0);
    sqlite3_step(stat);

    if(stat == NULL)
    {
        std::cout << "Operation failed.\n";
        return -2;
    }

    int maxCode = sqlite3_column_int(stat,0);

    std::cout << "maxRowid:" << maxRowid << std::endl;
    std::cout << "maxCode:" << maxCode << std::endl;

    //1. 先存入 table 表
    // insert into <table> (rowid,code,path,name) values (maxRowid+1,maxCode+1,path,fileName);

    std::string rowidS;
    std::stringstream ss;
    ss << (maxRowid + 1);
    ss >> rowidS;

    std::string codeS;
    std::stringstream sss;
    sss << (maxCode + 1);
    sss >> codeS;

    //Todo:根据path获得name，现在name为空
    //Over 20170225 03:21

    std::string codeex = table + codeS;
    std::string insertTableCmd = "insert into " + table;
    insertTableCmd += "(rowid,code,path,name,codeex) values(";
    insertTableCmd += rowidS;
    insertTableCmd += ",";
    insertTableCmd += codeS;
    insertTableCmd += ",\"";
    insertTableCmd += path;
    insertTableCmd += "\",";
    insertTableCmd += "\"";
    insertTableCmd += fileName;
    insertTableCmd += "\",";
    insertTableCmd += "\"";
    insertTableCmd += codeex;
    insertTableCmd += "\");";

    std::cout << "insert cmd : " << insertTableCmd << std::endl;

    sqlite3_prepare(db,insertTableCmd.c_str(),-1,&stat,0);
    sqlite3_step(stat);
    if(stat == NULL)
    {
        std::cout << "Operation failed.\n";
        return -2;
    }

    //2. 写入modeltype表
    // insert into modeltype(rowid,code,tablename) values(maxModeltypeRowid+1,maxCode+1,table);

    std::string maxModeltypeRowidCmd = "select MAX(rowid) from modeltype;";
    sqlite3_prepare(db,maxModeltypeRowidCmd.c_str(),-1,&stat,0);
    sqlite3_step(stat);
    if(stat == NULL)
    {
        std::cout << "Operation failed.\n";
        return -2;
    }
    int maxModeltypeRowid = sqlite3_column_int(stat,0);
    std::cout << "maxModeltypeRowid : " << maxModeltypeRowid << std::endl;

    std::string tmp;
    std::stringstream ssss;
    ssss << (maxModeltypeRowid + 1);
    ssss >> tmp;

    std::string modeltypeCmd = "insert into modeltype(rowid,code,tablename) values(";
    modeltypeCmd += tmp;
    modeltypeCmd += ",";
    modeltypeCmd += codeS;
    modeltypeCmd += ",\"";
    modeltypeCmd += table;
    modeltypeCmd += "\");";

    std::cout << "modeltype cmd: " << modeltypeCmd << std::endl;

    sqlite3_prepare(db,modeltypeCmd.c_str(),-1,&stat,0);
    sqlite3_step(stat);
    if(stat == NULL)
    {
        std::cout << "Operation failed.\n";
        return -2;
    }

    // 释放内存
    sqlite3_finalize(stat);
     sqlite3_close(db);
    //! [sqlite]

    return 0;
}

QStringList SqlData::getTypes()
{
    return m_types;
}

/// 将目录和名字存入数据库
/// \brief SqlData::insert
/// \param path
/// \param table
///
void SqlData::insert(QString path, QString table)
{
    QString curPath = QDir::cleanPath(QCoreApplication::applicationDirPath());
    QString filePath = QDir::cleanPath(path);

    QDir dir(curPath);

    QString relPath = dir.relativeFilePath(filePath);

    std::cout << "current path:" << curPath.toStdString() << std::endl;
    std::cout << "file path:" << filePath.toStdString() << std::endl;
    std::cout << "relative path:" << relPath.toStdString() << std::endl;


    sqlInsert(relPath.toStdString(),table.toStdString());

}

void SqlData::print()
{
    std::string path = QCoreApplication::applicationDirPath().toStdString();
    std::cout << "func print() current path: " << path << std::endl;

    std::string dbPath = path + "/testData.sqlite3";

    sqlite3_stmt* stat;
    sqlite3* db = NULL;

    //Todo:	这边发现相对路径有点问题

    int rc = sqlite3_open(dbPath.c_str(),&db);
    //int rc = sqlite3_open("/Users/whisperchi/work/MySqlTool/testData.sqlite3",&db);

    if(rc != 0)
    {
        std::cout << "Can not open" << std::endl;
        return;
    }

    // 读取modeltype，得到tables
    // select tablename from modeltype group by tablename;
    std::vector<std::string> tables;

    std::string tablesCmd = "select tablename from modeltype group by tablename";

    sqlite3_prepare(db,tablesCmd.c_str(),-1,&stat,0);
    while(sqlite3_step(stat) == SQLITE_ROW)
    {
        char* total = (char*)sqlite3_column_blob(stat,0);
        tables.push_back(std::string(total));
        std::cout << std::string(total) << std::endl;
    }

    // 将tables打印出来
    for(int i = 0; i < tables.size();i++)
    {
        //myPrint(path,tables[i]);
        std::cout << "Current table" << tables[i] << std::endl;
        std::string cmd = "select * from " + tables[i];
        cmd += ";";

        std::cout << "cmd :" << cmd << std::endl;
        std::cout << "tables num:" << tables.size() << std::endl;

        sqlite3_prepare(db,cmd.c_str(),-1,&stat,0);

        std::vector<tableData> dataOut;
        dataOut.clear();
        while(sqlite3_step(stat) == SQLITE_ROW)
        {
            char *codeex = (char*)sqlite3_column_blob(stat,4);
            char *path = (char*) sqlite3_column_blob(stat,2);
            char *name = (char*)sqlite3_column_blob(stat,3);
            tableData tmp;
            tmp.codeex = std::string(codeex);
            tmp.name = std::string(name);
            tmp.path = std::string(path);
            dataOut.push_back(tmp);

            std::cout << tmp.codeex << " " << tmp.name << " " << tmp.path << std::endl;

        }
        std::cout << "Current table" << tables[i] << std::endl;
        myWriteIntoFile(dataOut,tables[i],QCoreApplication::applicationDirPath().toStdString());
    }

    //Release resource
    sqlite3_finalize(stat);
    sqlite3_close(db);

}

SqlData::SqlData()
{
    m_types.append("DD");
    m_types.append("HJ");
    m_types.append("LJ");
    m_types.append("KJ");

    m_sqlPath = "./testData.sqlite3";
}

SqlData::~SqlData()
{

}

QStringList SqlData::types() const
{
    std::cout<< m_types.size() << std::endl;
    return m_types;
}

///	读取数据库，读取modeltype表中typename这列，存入列表中
/// \brief SqlData::update
///
void SqlData::update()
{
    std::cout << "update func\n";
    emit typesChanged();
}


