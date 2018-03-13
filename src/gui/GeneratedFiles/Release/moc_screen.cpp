/****************************************************************************
** Meta object code from reading C++ file 'screen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../screen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_screen_t {
    QByteArrayData data[8];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_screen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_screen_t qt_meta_stringdata_screen = {
    {
QT_MOC_LITERAL(0, 0, 6), // "screen"
QT_MOC_LITERAL(1, 7, 10), // "getContext"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "getText"
QT_MOC_LITERAL(4, 27, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(5, 44, 13), // "handleResults"
QT_MOC_LITERAL(6, 58, 5), // "value"
QT_MOC_LITERAL(7, 64, 11) // "startThread"

    },
    "screen\0getContext\0\0getText\0QListWidgetItem*\0"
    "handleResults\0value\0startThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_screen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       5,    1,   38,    2, 0x0a /* Public */,
       7,    0,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,

       0        // eod
};

void screen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        screen *_t = static_cast<screen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getContext(); break;
        case 1: _t->getText((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->handleResults((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->startThread(); break;
        default: ;
        }
    }
}

const QMetaObject screen::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_screen.data,
      qt_meta_data_screen,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *screen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *screen::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_screen.stringdata0))
        return static_cast<void*>(const_cast< screen*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int screen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
