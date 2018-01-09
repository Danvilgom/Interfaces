/****************************************************************************
** Meta object code from reading C++ file 'dialogodeshacer.h'
**
<<<<<<< HEAD
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
=======
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
>>>>>>> Aplicacion bolas
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dialogodeshacer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogodeshacer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
<<<<<<< HEAD
#error "This file was generated using the moc from 5.9.1. It"
=======
#error "This file was generated using the moc from 5.7.1. It"
>>>>>>> Aplicacion bolas
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
<<<<<<< HEAD
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogoDeshacer_t {
    QByteArrayData data[5];
    char stringdata0[71];
=======
struct qt_meta_stringdata_DialogoDeshacer_t {
    QByteArrayData data[5];
    char stringdata0[69];
>>>>>>> Aplicacion bolas
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogoDeshacer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogoDeshacer_t qt_meta_stringdata_DialogoDeshacer = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DialogoDeshacer"
QT_MOC_LITERAL(1, 16, 12), // "DeshacerSlot"
QT_MOC_LITERAL(2, 29, 0), // ""
<<<<<<< HEAD
QT_MOC_LITERAL(3, 30, 20), // "slotDisabledDeshacer"
QT_MOC_LITERAL(4, 51, 19) // "slotDisabledRehacer"

    },
    "DialogoDeshacer\0DeshacerSlot\0\0"
    "slotDisabledDeshacer\0slotDisabledRehacer"
=======
QT_MOC_LITERAL(3, 30, 19), // "slotDisableDeshacer"
QT_MOC_LITERAL(4, 50, 18) // "slotDisableRehacer"

    },
    "DialogoDeshacer\0DeshacerSlot\0\0"
    "slotDisableDeshacer\0slotDisableRehacer"
>>>>>>> Aplicacion bolas
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogoDeshacer[] = {

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
       1,    0,   29,    2, 0x08 /* Private */,
       3,    1,   30,    2, 0x08 /* Private */,
       4,    1,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void DialogoDeshacer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogoDeshacer *_t = static_cast<DialogoDeshacer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DeshacerSlot(); break;
<<<<<<< HEAD
        case 1: _t->slotDisabledDeshacer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->slotDisabledRehacer((*reinterpret_cast< bool(*)>(_a[1]))); break;
=======
        case 1: _t->slotDisableDeshacer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->slotDisableRehacer((*reinterpret_cast< bool(*)>(_a[1]))); break;
>>>>>>> Aplicacion bolas
        default: ;
        }
    }
}

const QMetaObject DialogoDeshacer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogoDeshacer.data,
<<<<<<< HEAD
      qt_meta_data_DialogoDeshacer,  qt_static_metacall, nullptr, nullptr}
=======
      qt_meta_data_DialogoDeshacer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
>>>>>>> Aplicacion bolas
};


const QMetaObject *DialogoDeshacer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogoDeshacer::qt_metacast(const char *_clname)
{
<<<<<<< HEAD
    if (!_clname) return nullptr;
=======
    if (!_clname) return Q_NULLPTR;
>>>>>>> Aplicacion bolas
    if (!strcmp(_clname, qt_meta_stringdata_DialogoDeshacer.stringdata0))
        return static_cast<void*>(const_cast< DialogoDeshacer*>(this));
    if (!strcmp(_clname, "Ui::DialogoDeshacer"))
        return static_cast< Ui::DialogoDeshacer*>(const_cast< DialogoDeshacer*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogoDeshacer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
<<<<<<< HEAD
QT_WARNING_POP
=======
>>>>>>> Aplicacion bolas
QT_END_MOC_NAMESPACE
