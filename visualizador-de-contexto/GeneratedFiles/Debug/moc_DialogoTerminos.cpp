/****************************************************************************
** Meta object code from reading C++ file 'DialogoTerminos.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DialogoTerminos.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogoTerminos.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogoTerminos_t {
    QByteArrayData data[7];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogoTerminos_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogoTerminos_t qt_meta_stringdata_DialogoTerminos = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DialogoTerminos"
QT_MOC_LITERAL(1, 16, 37), // "on_action_actualizarYCerrar_t..."
QT_MOC_LITERAL(2, 54, 0), // ""
QT_MOC_LITERAL(3, 55, 36), // "on_action_resetear_termino_tr..."
QT_MOC_LITERAL(4, 92, 35), // "on_action_guardar_termino_tri..."
QT_MOC_LITERAL(5, 128, 36), // "on_action_eliminar_termino_tr..."
QT_MOC_LITERAL(6, 165, 39) // "on_action_estado_btn_eliminar..."

    },
    "DialogoTerminos\0on_action_actualizarYCerrar_triggered\0"
    "\0on_action_resetear_termino_triggered\0"
    "on_action_guardar_termino_triggered\0"
    "on_action_eliminar_termino_triggered\0"
    "on_action_estado_btn_eliminar_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogoTerminos[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogoTerminos::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogoTerminos *_t = static_cast<DialogoTerminos *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_action_actualizarYCerrar_triggered(); break;
        case 1: _t->on_action_resetear_termino_triggered(); break;
        case 2: _t->on_action_guardar_termino_triggered(); break;
        case 3: _t->on_action_eliminar_termino_triggered(); break;
        case 4: _t->on_action_estado_btn_eliminar_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DialogoTerminos::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DialogoTerminos.data,
      qt_meta_data_DialogoTerminos,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DialogoTerminos::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogoTerminos::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogoTerminos.stringdata0))
        return static_cast<void*>(const_cast< DialogoTerminos*>(this));
    return QWidget::qt_metacast(_clname);
}

int DialogoTerminos::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
