#ifndef SQLDATA_H
#define SQLDATA_H

#include <QObject>
#include <QString>

class SqlData : public QObject
{
    Q_OBJECT

    //Q_PROPERTY(QStringList types READ types WRITE setTypes NOTIFY typesChanged)
    Q_PROPERTY(QStringList types READ types NOTIFY typesChanged)
    Q_PROPERTY(QString dbUrl READ dbUrl WRITE setDbUrl NOTIFY dbUrlChanged)

public:
    Q_INVOKABLE QStringList getTypes();
    Q_INVOKABLE void insert(const QString path,const QString table);
    Q_INVOKABLE void print()const;
    Q_INVOKABLE void update();

public:
    SqlData();
    ~SqlData();

    QStringList types()const;

    QString dbUrl()const;

    void setDbUrl(const QString url);



signals:
    void typesChanged();
    void dbUrlChanged();

    void warning(const QString msg);

private:
    int sqlInsert(std::string path,std::string table);
    void print();


private:
    QStringList		m_types;

    QString			m_curPath;
    QString 		m_dbUrl;


};

#endif // SQLDATA_H
