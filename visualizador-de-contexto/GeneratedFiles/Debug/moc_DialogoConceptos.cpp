/****************************************************************************
** Meta object code from reading C++ file 'DialogoConceptos.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DialogoConceptos.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogoConceptos.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogoConceptos_t {
    QByteArrayData data[10];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogoConceptos_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogoConceptos_t qt_meta_stringdata_DialogoConceptos = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DialogoConceptos"
QT_MOC_LITERAL(1, 17, 19), // "actualizar_y_cerrar"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 17), // "resetear_concepto"
QT_MOC_LITERAL(4, 56, 17), // "eliminar_concepto"
QT_MOC_LITERAL(5, 74, 19), // "estado_btn_eliminar"
QT_MOC_LITERAL(6, 94, 22), // "concepto_dobleclikeado"
QT_MOC_LITERAL(7, 117, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(8, 134, 18), // "item_dobleclikeado"
QT_MOC_LITERAL(9, 153, 14) // "nuevo_concepto"

    },
    "DialogoConceptos\0actualizar_y_cerrar\0"
    "\0resetear_concepto\0eliminar_concepto\0"
    "estado_btn_eliminar\0concepto_dobleclikeado\0"
    "QListWidgetItem*\0item_dobleclikeado\0"
    "nuevo_concepto"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogoConceptos[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,

       0        // eod
};

void DialogoConceptos::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogoConceptos *_t = static_cast<DialogoConceptos *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->actualizar_y_cerrar(); break;
        case 1: _t->resetear_concepto(); break;
        case 2: _t->eliminar_concepto(); break;
        case 3: _t->estado_btn_eliminar(); break;
        case 4: _t->concepto_dobleclikeado((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->nuevo_concepto(); break;
        default: ;
        }
    }
}

const QMetaObject DialogoConceptos::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DialogoConceptos.data,
      qt_meta_data_DialogoConceptos,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DialogoConceptos::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogoConceptos::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogoConceptos.stringdata0))
        return static_cast<void*>(const_cast< DialogoConceptos*>(this));
    return QWidget::qt_metacast(_clname);
}

int DialogoConceptos::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
