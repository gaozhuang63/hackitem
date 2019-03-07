/****************************************************************************
** Meta object code from reading C++ file 'tcpsocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcpsocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpsocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpSocket_t {
    QByteArrayData data[13];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpSocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpSocket_t qt_meta_stringdata_TcpSocket = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TcpSocket"
QT_MOC_LITERAL(1, 10, 11), // "readDataSig"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "sockDisConnect"
QT_MOC_LITERAL(4, 38, 8), // "QThread*"
QT_MOC_LITERAL(5, 47, 8), // "send_sig"
QT_MOC_LITERAL(6, 56, 8), // "sentData"
QT_MOC_LITERAL(7, 65, 13), // "disConTcpSlot"
QT_MOC_LITERAL(8, 79, 1), // "i"
QT_MOC_LITERAL(9, 81, 18), // "OnSendFileDataSlot"
QT_MOC_LITERAL(10, 100, 12), // "readDataSlot"
QT_MOC_LITERAL(11, 113, 9), // "startNext"
QT_MOC_LITERAL(12, 123, 7) // "passevt"

    },
    "TcpSocket\0readDataSig\0\0sockDisConnect\0"
    "QThread*\0send_sig\0sentData\0disConTcpSlot\0"
    "i\0OnSendFileDataSlot\0readDataSlot\0"
    "startNext\0passevt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpSocket[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   59,    2, 0x06 /* Public */,
       3,    4,   68,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   78,    2, 0x0a /* Public */,
       7,    1,   83,    2, 0x0a /* Public */,
       9,    1,   86,    2, 0x0a /* Public */,
      10,    0,   89,    2, 0x09 /* Protected */,
      11,    0,   90,    2, 0x09 /* Protected */,
      12,    0,   91,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::UShort, QMetaType::QByteArray,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::UShort, 0x80000000 | 4,    2,    2,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TcpSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpSocket *_t = static_cast<TcpSocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readDataSig((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const quint16(*)>(_a[3])),(*reinterpret_cast< const QByteArray(*)>(_a[4]))); break;
        case 1: _t->sockDisConnect((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const quint16(*)>(_a[3])),(*reinterpret_cast< QThread*(*)>(_a[4]))); break;
        case 2: _t->send_sig(); break;
        case 3: _t->sentData((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 4: _t->disConTcpSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->OnSendFileDataSlot((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 6: _t->readDataSlot(); break;
        case 7: _t->startNext(); break;
        case 8: _t->passevt(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpSocket::*)(const int , const QString & , const quint16 , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpSocket::readDataSig)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpSocket::*)(const int , const QString & , const quint16 , QThread * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpSocket::sockDisConnect)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TcpSocket::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpSocket::send_sig)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TcpSocket::staticMetaObject = { {
    &QTcpSocket::staticMetaObject,
    qt_meta_stringdata_TcpSocket.data,
    qt_meta_data_TcpSocket,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TcpSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpSocket.stringdata0))
        return static_cast<void*>(this);
    return QTcpSocket::qt_metacast(_clname);
}

int TcpSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void TcpSocket::readDataSig(const int _t1, const QString & _t2, const quint16 _t3, const QByteArray & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpSocket::sockDisConnect(const int _t1, const QString & _t2, const quint16 _t3, QThread * _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpSocket::send_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
