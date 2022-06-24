/****************************************************************************
** Meta object code from reading C++ file 'qtelepathy.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../qtelepathy.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtelepathy.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qtelepathy__Socket_t {
    QByteArrayData data[12];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qtelepathy__Socket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qtelepathy__Socket_t qt_meta_stringdata_qtelepathy__Socket = {
    {
QT_MOC_LITERAL(0, 0, 18), // "qtelepathy::Socket"
QT_MOC_LITERAL(1, 19, 8), // "received"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "topic"
QT_MOC_LITERAL(4, 35, 7), // "payload"
QT_MOC_LITERAL(5, 43, 12), // "disconnected"
QT_MOC_LITERAL(6, 56, 8), // "transmit"
QT_MOC_LITERAL(7, 65, 12), // "transmitData"
QT_MOC_LITERAL(8, 78, 3), // "arr"
QT_MOC_LITERAL(9, 82, 15), // "connectToServer"
QT_MOC_LITERAL(10, 98, 10), // "serverName"
QT_MOC_LITERAL(11, 109, 4) // "read"

    },
    "qtelepathy::Socket\0received\0\0topic\0"
    "payload\0disconnected\0transmit\0"
    "transmitData\0arr\0connectToServer\0"
    "serverName\0read"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qtelepathy__Socket[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   50,    2, 0x0a /* Public */,
       7,    1,   55,    2, 0x0a /* Public */,
       9,    1,   58,    2, 0x0a /* Public */,
      11,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject,    3,    4,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,

       0        // eod
};

void qtelepathy::Socket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Socket *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->received((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 1: _t->disconnected(); break;
        case 2: _t->transmit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 3: _t->transmitData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->connectToServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->read(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Socket::*)(QString , QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Socket::received)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Socket::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Socket::disconnected)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject qtelepathy::Socket::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_qtelepathy__Socket.data,
    qt_meta_data_qtelepathy__Socket,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qtelepathy::Socket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qtelepathy::Socket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qtelepathy__Socket.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qtelepathy::Socket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void qtelepathy::Socket::received(QString _t1, QJsonObject _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void qtelepathy::Socket::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_qtelepathy__Server_t {
    QByteArrayData data[5];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qtelepathy__Server_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qtelepathy__Server_t qt_meta_stringdata_qtelepathy__Server = {
    {
QT_MOC_LITERAL(0, 0, 18), // "qtelepathy::Server"
QT_MOC_LITERAL(1, 19, 13), // "newConnection"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 23), // "std::shared_ptr<Socket>"
QT_MOC_LITERAL(4, 58, 10) // "connection"

    },
    "qtelepathy::Server\0newConnection\0\0"
    "std::shared_ptr<Socket>\0connection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qtelepathy__Server[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void qtelepathy::Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Server *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newConnection((*reinterpret_cast< std::shared_ptr<Socket>(*)>(_a[1]))); break;
        case 1: _t->connection(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Server::*)(std::shared_ptr<Socket> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::newConnection)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject qtelepathy::Server::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_qtelepathy__Server.data,
    qt_meta_data_qtelepathy__Server,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qtelepathy::Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qtelepathy::Server::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qtelepathy__Server.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qtelepathy::Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void qtelepathy::Server::newConnection(std::shared_ptr<Socket> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
