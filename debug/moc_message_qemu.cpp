/****************************************************************************
** Meta object code from reading C++ file 'message_qemu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../message_qemu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'message_qemu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_message_qemu_t {
    QByteArrayData data[16];
    char stringdata0[251];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_message_qemu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_message_qemu_t qt_meta_stringdata_message_qemu = {
    {
QT_MOC_LITERAL(0, 0, 12), // "message_qemu"
QT_MOC_LITERAL(1, 13, 11), // "send_signal"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "load_info"
QT_MOC_LITERAL(4, 36, 13), // "handleTimeout"
QT_MOC_LITERAL(5, 50, 14), // "handleTimeout1"
QT_MOC_LITERAL(6, 65, 14), // "handleTimeout2"
QT_MOC_LITERAL(7, 80, 14), // "handleTimeout3"
QT_MOC_LITERAL(8, 95, 14), // "handleTimeout4"
QT_MOC_LITERAL(9, 110, 14), // "handleTimeout5"
QT_MOC_LITERAL(10, 125, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(11, 147, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(12, 171, 19), // "OnConnectClientSlot"
QT_MOC_LITERAL(13, 191, 14), // "OnReadDataSlot"
QT_MOC_LITERAL(14, 206, 20), // "OnsockDisConnectSlot"
QT_MOC_LITERAL(15, 227, 23) // "on_pushButton_6_clicked"

    },
    "message_qemu\0send_signal\0\0load_info\0"
    "handleTimeout\0handleTimeout1\0"
    "handleTimeout2\0handleTimeout3\0"
    "handleTimeout4\0handleTimeout5\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "OnConnectClientSlot\0OnReadDataSlot\0"
    "OnsockDisConnectSlot\0on_pushButton_6_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_message_qemu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    3,   94,    2, 0x08 /* Private */,
      13,    4,  101,    2, 0x08 /* Private */,
      14,    3,  110,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::UShort,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::UShort, QMetaType::QByteArray,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::UShort,    2,    2,    2,
    QMetaType::Void,

       0        // eod
};

void message_qemu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        message_qemu *_t = static_cast<message_qemu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_signal(); break;
        case 1: _t->load_info(); break;
        case 2: _t->handleTimeout(); break;
        case 3: _t->handleTimeout1(); break;
        case 4: _t->handleTimeout2(); break;
        case 5: _t->handleTimeout3(); break;
        case 6: _t->handleTimeout4(); break;
        case 7: _t->handleTimeout5(); break;
        case 8: _t->on_pushButton_clicked(); break;
        case 9: _t->on_pushButton_2_clicked(); break;
        case 10: _t->OnConnectClientSlot((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const quint16(*)>(_a[3]))); break;
        case 11: _t->OnReadDataSlot((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3])),(*reinterpret_cast< const QByteArray(*)>(_a[4]))); break;
        case 12: _t->OnsockDisConnectSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 13: _t->on_pushButton_6_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (message_qemu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&message_qemu::send_signal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject message_qemu::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_message_qemu.data,
    qt_meta_data_message_qemu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *message_qemu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *message_qemu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_message_qemu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int message_qemu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void message_qemu::send_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
