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
    QByteArrayData data[9];
    char stringdata0[286];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogoConceptos_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogoConceptos_t qt_meta_stringdata_DialogoConceptos = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DialogoConceptos"
QT_MOC_LITERAL(1, 17, 39), // "on_action_actualizar_y_cerrar..."
QT_MOC_LITERAL(2, 57, 0), // ""
QT_MOC_LITERAL(3, 58, 37), // "on_action_resetear_concepto_t..."
QT_MOC_LITERAL(4, 96, 37), // "on_action_eliminar_concepto_t..."
QT_MOC_LITERAL(5, 134, 36), // "on_action_guardar_concepto_tr..."
QT_MOC_LITERAL(6, 171, 39), // "on_action_estado_btn_eliminar..."
QT_MOC_LITERAL(7, 211, 38), // "on_action_estado_btn_agregar_..."
QT_MOC_LITERAL(8, 250, 35) // "on_action_editar_concepto_tri..."

    },
    "DialogoConceptos\0"
    "on_action_actualizar_y_cerrar_triggered\0"
    "\0on_action_resetear_concepto_triggered\0"
    "on_action_eliminar_concepto_triggered\0"
    "on_action_guardar_concepto_triggered\0"
    "on_action_estado_btn_eliminar_triggered\0"
    "on_action_estado_btn_agregar_triggered\0"
    "on_action_editar_concepto_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogoConceptos[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogoConceptos::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogoConceptos *_t = static_cast<DialogoConceptos *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_action_actualizar_y_cerrar_triggered(); break;
        case 1: _t->on_action_resetear_concepto_triggered(); break;
        case 2: _t->on_action_eliminar_concepto_triggered(); break;
        case 3: _t->on_action_guardar_concepto_triggered(); break;
        case 4: _t->on_action_estado_btn_eliminar_triggered(); break;
        case 5: _t->on_action_estado_btn_agregar_triggered(); break;
        case 6: _t->on_action_editar_concepto_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
