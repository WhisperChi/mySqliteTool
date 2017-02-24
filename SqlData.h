#ifndef SQLDATA_H
#define SQLDATA_H

#include <QObject>
#include <QString>

class SqlData : public QObject
{
    Q_OBJECT

    //Q_PROPERTY(QStringList types READ types WRITE setTypes NOTIFY typesChanged)
    Q_PROPERTY(QStringList types READ types NOTIFY typesChanged)

public:
    Q_INVOKABLE QStringList getTypes();
    Q_INVOKABLE void insert(QString path,QString table);
    Q_INVOKABLE void print();

public:
    SqlData();
    ~SqlData();

public:
    QStringList types()const;

public slots:
    void update();


signals:
    void typesChanged();

private:
    int sqlInsert(std::string path,std::string table);


private:
    QStringList		m_types;
    QString			m_sqlPath;


};

#endif // SQLDATA_H
