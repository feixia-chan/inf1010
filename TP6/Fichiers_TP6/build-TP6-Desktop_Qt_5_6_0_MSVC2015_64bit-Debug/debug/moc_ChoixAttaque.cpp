/****************************************************************************
** Meta object code from reading C++ file 'ChoixAttaque.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TP6/ChoixAttaque.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChoixAttaque.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChoixAttaque_t {
    QByteArrayData data[6];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChoixAttaque_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChoixAttaque_t qt_meta_stringdata_ChoixAttaque = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ChoixAttaque"
QT_MOC_LITERAL(1, 13, 16), // "afficherAttaques"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 9), // "Creature*"
QT_MOC_LITERAL(4, 41, 8), // "creature"
QT_MOC_LITERAL(5, 50, 15) // "masquerAttaques"

    },
    "ChoixAttaque\0afficherAttaques\0\0Creature*\0"
    "creature\0masquerAttaques"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChoixAttaque[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       1,    1,   30,    2, 0x0a /* Public */,
       5,    0,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void ChoixAttaque::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChoixAttaque *_t = static_cast<ChoixAttaque *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->afficherAttaques(); break;
        case 1: _t->afficherAttaques((*reinterpret_cast< Creature*(*)>(_a[1]))); break;
        case 2: _t->masquerAttaques(); break;
        default: ;
        }
    }
}

const QMetaObject ChoixAttaque::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChoixAttaque.data,
      qt_meta_data_ChoixAttaque,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChoixAttaque::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChoixAttaque::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChoixAttaque.stringdata0))
        return static_cast<void*>(const_cast< ChoixAttaque*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChoixAttaque::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
