/****************************************************************************
** Meta object code from reading C++ file 'Menu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TP6/Menu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Menu_t {
    QByteArrayData data[22];
    char stringdata0[392];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Menu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Menu_t qt_meta_stringdata_Menu = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Menu"
QT_MOC_LITERAL(1, 5, 14), // "masquerBoutons"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 15), // "afficherBoutons"
QT_MOC_LITERAL(4, 37, 13), // "gestionDuMenu"
QT_MOC_LITERAL(5, 51, 30), // "afficherListeCreaturesDresseur"
QT_MOC_LITERAL(6, 82, 9), // "Dresseur&"
QT_MOC_LITERAL(7, 92, 8), // "dresseur"
QT_MOC_LITERAL(8, 101, 22), // "afficherListeCreatures"
QT_MOC_LITERAL(9, 124, 20), // "std::list<Creature*>"
QT_MOC_LITERAL(10, 145, 9), // "creatures"
QT_MOC_LITERAL(11, 155, 23), // "affichierListeDresseurs"
QT_MOC_LITERAL(12, 179, 20), // "std::list<Dresseur*>"
QT_MOC_LITERAL(13, 200, 9), // "dresseurs"
QT_MOC_LITERAL(14, 210, 18), // "afficherInventaire"
QT_MOC_LITERAL(15, 229, 9), // "Dresseur*"
QT_MOC_LITERAL(16, 239, 34), // "obtenirCreatureDresseurSelect..."
QT_MOC_LITERAL(17, 274, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(18, 291, 26), // "obtenirCreatureSelectionne"
QT_MOC_LITERAL(19, 318, 26), // "obtenirDresseurSelectionne"
QT_MOC_LITERAL(20, 345, 30), // "obtenirObjetMagiqueSelectionne"
QT_MOC_LITERAL(21, 376, 15) // "afficherAttaque"

    },
    "Menu\0masquerBoutons\0\0afficherBoutons\0"
    "gestionDuMenu\0afficherListeCreaturesDresseur\0"
    "Dresseur&\0dresseur\0afficherListeCreatures\0"
    "std::list<Creature*>\0creatures\0"
    "affichierListeDresseurs\0std::list<Dresseur*>\0"
    "dresseurs\0afficherInventaire\0Dresseur*\0"
    "obtenirCreatureDresseurSelectionne\0"
    "QListWidgetItem*\0obtenirCreatureSelectionne\0"
    "obtenirDresseurSelectionne\0"
    "obtenirObjetMagiqueSelectionne\0"
    "afficherAttaque"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Menu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    1,   77,    2, 0x0a /* Public */,
       8,    1,   80,    2, 0x0a /* Public */,
      11,    1,   83,    2, 0x0a /* Public */,
      14,    1,   86,    2, 0x0a /* Public */,
      16,    0,   89,    2, 0x0a /* Public */,
      18,    0,   90,    2, 0x0a /* Public */,
      19,    0,   91,    2, 0x0a /* Public */,
      20,    0,   92,    2, 0x0a /* Public */,
      21,    0,   93,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,    7,
    0x80000000 | 17,
    0x80000000 | 17,
    0x80000000 | 17,
    0x80000000 | 17,
    QMetaType::Void,

       0        // eod
};

void Menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Menu *_t = static_cast<Menu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->masquerBoutons(); break;
        case 1: _t->afficherBoutons(); break;
        case 2: _t->gestionDuMenu(); break;
        case 3: _t->afficherListeCreaturesDresseur((*reinterpret_cast< Dresseur(*)>(_a[1]))); break;
        case 4: _t->afficherListeCreatures((*reinterpret_cast< std::list<Creature*>(*)>(_a[1]))); break;
        case 5: _t->affichierListeDresseurs((*reinterpret_cast< std::list<Dresseur*>(*)>(_a[1]))); break;
        case 6: _t->afficherInventaire((*reinterpret_cast< Dresseur*(*)>(_a[1]))); break;
        case 7: { QListWidgetItem* _r = _t->obtenirCreatureDresseurSelectionne();
            if (_a[0]) *reinterpret_cast< QListWidgetItem**>(_a[0]) = _r; }  break;
        case 8: { QListWidgetItem* _r = _t->obtenirCreatureSelectionne();
            if (_a[0]) *reinterpret_cast< QListWidgetItem**>(_a[0]) = _r; }  break;
        case 9: { QListWidgetItem* _r = _t->obtenirDresseurSelectionne();
            if (_a[0]) *reinterpret_cast< QListWidgetItem**>(_a[0]) = _r; }  break;
        case 10: { QListWidgetItem* _r = _t->obtenirObjetMagiqueSelectionne();
            if (_a[0]) *reinterpret_cast< QListWidgetItem**>(_a[0]) = _r; }  break;
        case 11: _t->afficherAttaque(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Dresseur* >(); break;
            }
            break;
        }
    }
}

const QMetaObject Menu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Menu.data,
      qt_meta_data_Menu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Menu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Menu.stringdata0))
        return static_cast<void*>(const_cast< Menu*>(this));
    return QWidget::qt_metacast(_clname);
}

int Menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
