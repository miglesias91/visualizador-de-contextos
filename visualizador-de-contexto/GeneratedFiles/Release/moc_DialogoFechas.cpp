/****************************************************************************
** Meta object code from reading C++ file 'DialogoFechas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DialogoFechas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogoFechas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogoFechas_t {
    QByteArrayData data[11];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogoFechas_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogoFechas_t qt_meta_stringdata_DialogoFechas = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DialogoFechas"
QT_MOC_LITERAL(1, 14, 8), // "se_cerro"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "se_abrio"
QT_MOC_LITERAL(4, 33, 13), // "guardar_fecha"
QT_MOC_LITERAL(5, 47, 13), // "limpiar_fecha"
QT_MOC_LITERAL(6, 61, 14), // "eliminar_fecha"
QT_MOC_LITERAL(7, 76, 19), // "actualizar_y_cerrar"
QT_MOC_LITERAL(8, 96, 19), // "estado_btn_eliminar"
QT_MOC_LITERAL(9, 116, 7), // "guardar"
QT_MOC_LITERAL(10, 124, 6) // "cerrar"

    },
    "DialogoFechas\0se_cerro\0\0se_abrio\0"
    "guardar_fecha\0limpiar_fecha\0eliminar_fecha\0"
    "actualizar_y_cerrar\0estado_btn_eliminar\0"
    "guardar\0cerrar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogoFechas[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

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

void DialogoFechas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogoFechas *_t = static_cast<DialogoFechas *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->se_cerro(); break;
        case 1: _t->se_abrio(); break;
        case 2: _t->guardar_fecha(); break;
        case 3: _t->limpiar_fecha(); break;
        case 4: _t->eliminar_fecha(); break;
        case 5: _t->actualizar_y_cerrar(); break;
        case 6: _t->estado_btn_eliminar(); break;
        case 7: _t->guardar(); break;
        case 8: _t->cerrar(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DialogoFechas::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogoFechas::se_cerro)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DialogoFechas::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogoFechas::se_abrio)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DialogoFechas::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DialogoFechas.data,
      qt_meta_data_DialogoFechas,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DialogoFechas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogoFechas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogoFechas.stringdata0))
        return static_cast<void*>(const_cast< DialogoFechas*>(this));
    return QWidget::qt_metacast(_clname);
}

int DialogoFechas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void DialogoFechas::se_cerro()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DialogoFechas::se_abrio()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
