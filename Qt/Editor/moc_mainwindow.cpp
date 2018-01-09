/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
<<<<<<< HEAD
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
=======
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
>>>>>>> Aplicacion bolas
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
=======
>>>>>>> Aplicacion bolas
struct qt_meta_stringdata_VentanaPrincipal_t {
    QByteArrayData data[13];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VentanaPrincipal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VentanaPrincipal_t qt_meta_stringdata_VentanaPrincipal = {
    {
QT_MOC_LITERAL(0, 0, 16), // "VentanaPrincipal"
QT_MOC_LITERAL(1, 17, 25), // "slotActualizarBarraEstado"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 9), // "slotNuevo"
QT_MOC_LITERAL(4, 54, 9), // "slotAbrir"
QT_MOC_LITERAL(5, 64, 10), // "slotBuscar"
<<<<<<< HEAD
QT_MOC_LITERAL(6, 75, 12), // "slotDeshacer"
QT_MOC_LITERAL(7, 88, 24), // "slotAbrirFicheroReciente"
QT_MOC_LITERAL(8, 113, 14), // "slotBuscarNext"
QT_MOC_LITERAL(9, 128, 3), // "str"
QT_MOC_LITERAL(10, 132, 19), // "Qt::CaseSensitivity"
QT_MOC_LITERAL(11, 152, 2), // "cs"
QT_MOC_LITERAL(12, 155, 18) // "slotBuscarPrevious"
=======
QT_MOC_LITERAL(6, 75, 24), // "slotAbrirFicheroReciente"
QT_MOC_LITERAL(7, 100, 14), // "slotBuscarNext"
QT_MOC_LITERAL(8, 115, 3), // "str"
QT_MOC_LITERAL(9, 119, 19), // "Qt::CaseSensitivity"
QT_MOC_LITERAL(10, 139, 2), // "cs"
QT_MOC_LITERAL(11, 142, 18), // "slotBuscarPrevious"
QT_MOC_LITERAL(12, 161, 12) // "slotDeshacer"
>>>>>>> Aplicacion bolas

    },
    "VentanaPrincipal\0slotActualizarBarraEstado\0"
    "\0slotNuevo\0slotAbrir\0slotBuscar\0"
<<<<<<< HEAD
    "slotDeshacer\0slotAbrirFicheroReciente\0"
    "slotBuscarNext\0str\0Qt::CaseSensitivity\0"
    "cs\0slotBuscarPrevious"
=======
    "slotAbrirFicheroReciente\0slotBuscarNext\0"
    "str\0Qt::CaseSensitivity\0cs\0"
    "slotBuscarPrevious\0slotDeshacer"
>>>>>>> Aplicacion bolas
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VentanaPrincipal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
<<<<<<< HEAD
       7,    0,   59,    2, 0x08 /* Private */,
       8,    2,   60,    2, 0x08 /* Private */,
      12,    2,   65,    2, 0x08 /* Private */,
=======
       7,    2,   59,    2, 0x08 /* Private */,
      11,    2,   64,    2, 0x08 /* Private */,
      12,    0,   69,    2, 0x08 /* Private */,
>>>>>>> Aplicacion bolas

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
<<<<<<< HEAD
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 10,    9,   11,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 10,    9,   11,
=======
    QMetaType::Void, QMetaType::QString, 0x80000000 | 9,    8,   10,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 9,    8,   10,
    QMetaType::Void,
>>>>>>> Aplicacion bolas

       0        // eod
};

void VentanaPrincipal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VentanaPrincipal *_t = static_cast<VentanaPrincipal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotActualizarBarraEstado(); break;
        case 1: _t->slotNuevo(); break;
        case 2: _t->slotAbrir(); break;
        case 3: _t->slotBuscar(); break;
<<<<<<< HEAD
        case 4: _t->slotDeshacer(); break;
        case 5: _t->slotAbrirFicheroReciente(); break;
        case 6: _t->slotBuscarNext((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< Qt::CaseSensitivity(*)>(_a[2]))); break;
        case 7: _t->slotBuscarPrevious((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< Qt::CaseSensitivity(*)>(_a[2]))); break;
=======
        case 4: _t->slotAbrirFicheroReciente(); break;
        case 5: _t->slotBuscarNext((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< Qt::CaseSensitivity(*)>(_a[2]))); break;
        case 6: _t->slotBuscarPrevious((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< Qt::CaseSensitivity(*)>(_a[2]))); break;
        case 7: _t->slotDeshacer(); break;
>>>>>>> Aplicacion bolas
        default: ;
        }
    }
}

const QMetaObject VentanaPrincipal::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VentanaPrincipal.data,
<<<<<<< HEAD
      qt_meta_data_VentanaPrincipal,  qt_static_metacall, nullptr, nullptr}
=======
      qt_meta_data_VentanaPrincipal,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
>>>>>>> Aplicacion bolas
};


const QMetaObject *VentanaPrincipal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VentanaPrincipal::qt_metacast(const char *_clname)
{
<<<<<<< HEAD
    if (!_clname) return nullptr;
=======
    if (!_clname) return Q_NULLPTR;
>>>>>>> Aplicacion bolas
    if (!strcmp(_clname, qt_meta_stringdata_VentanaPrincipal.stringdata0))
        return static_cast<void*>(const_cast< VentanaPrincipal*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int VentanaPrincipal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
<<<<<<< HEAD
QT_WARNING_POP
=======
>>>>>>> Aplicacion bolas
QT_END_MOC_NAMESPACE
