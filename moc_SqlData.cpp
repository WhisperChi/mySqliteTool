/****************************************************************************
** Meta object code from reading C++ file 'SqlData.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SqlData.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SqlData.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SqlData_t {
    QByteArrayData data[14];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SqlData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SqlData_t qt_meta_stringdata_SqlData = {
    {
QT_MOC_LITERAL(0, 0, 7), // "SqlData"
QT_MOC_LITERAL(1, 8, 12), // "typesChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "dbUrlChanged"
QT_MOC_LITERAL(4, 35, 7), // "warning"
QT_MOC_LITERAL(5, 43, 3), // "msg"
QT_MOC_LITERAL(6, 47, 6), // "update"
QT_MOC_LITERAL(7, 54, 8), // "getTypes"
QT_MOC_LITERAL(8, 63, 6), // "insert"
QT_MOC_LITERAL(9, 70, 4), // "path"
QT_MOC_LITERAL(10, 75, 5), // "table"
QT_MOC_LITERAL(11, 81, 5), // "print"
QT_MOC_LITERAL(12, 87, 5), // "types"
QT_MOC_LITERAL(13, 93, 5) // "dbUrl"

    },
    "SqlData\0typesChanged\0\0dbUrlChanged\0"
    "warning\0msg\0update\0getTypes\0insert\0"
    "path\0table\0print\0types\0dbUrl"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SqlData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       2,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   54,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       7,    0,   55,    2, 0x02 /* Public */,
       8,    2,   56,    2, 0x02 /* Public */,
      11,    0,   61,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void,

 // properties: name, type, flags
      12, QMetaType::QStringList, 0x00495001,
      13, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void SqlData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SqlData *_t = static_cast<SqlData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->typesChanged(); break;
        case 1: _t->dbUrlChanged(); break;
        case 2: _t->warning((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->update(); break;
        case 4: { QStringList _r = _t->getTypes();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 5: _t->insert((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->print(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SqlData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SqlData::typesChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SqlData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SqlData::dbUrlChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SqlData::*_t)(const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SqlData::warning)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        SqlData *_t = static_cast<SqlData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QStringList*>(_v) = _t->types(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->dbUrl(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        SqlData *_t = static_cast<SqlData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setDbUrl(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject SqlData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SqlData.data,
      qt_meta_data_SqlData,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SqlData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SqlData::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SqlData.stringdata0))
        return static_cast<void*>(const_cast< SqlData*>(this));
    return QObject::qt_metacast(_clname);
}

int SqlData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void SqlData::typesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void SqlData::dbUrlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void SqlData::warning(const QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
