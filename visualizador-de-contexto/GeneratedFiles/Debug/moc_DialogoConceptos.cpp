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
    QByteArrayData data[14];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogoConceptos_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogoConceptos_t qt_meta_stringdata_DialogoConceptos = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DialogoConceptos"
QT_MOC_LITERAL(1, 17, 8), // "se_cerro"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "se_abrio"
QT_MOC_LITERAL(4, 36, 19), // "actualizar_y_cerrar"
QT_MOC_LITERAL(5, 56, 17), // "resetear_concepto"
QT_MOC_LITERAL(6, 74, 17), // "eliminar_concepto"
QT_MOC_LITERAL(7, 92, 19), // "estado_btn_eliminar"
QT_MOC_LITERAL(8, 112, 22), // "concepto_dobleclikeado"
QT_MOC_LITERAL(9, 135, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(10, 152, 18), // "item_dobleclikeado"
QT_MOC_LITERAL(11, 171, 14), // "nuevo_concepto"
QT_MOC_LITERAL(12, 186, 7), // "guardar"
QT_MOC_LITERAL(13, 194, 6) // "cerrar"

    },
    "DialogoConceptos\0se_cerro\0\0se_abrio\0"
    "actualizar_y_cerrar\0resetear_concepto\0"
    "eliminar_concepto\0estado_btn_eliminar\0"
    "concepto_dobleclikeado\0QListWidgetItem*\0"
    "item_dobleclikeado\0nuevo_concepto\0"
    "guardar\0cerrar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogoConceptos[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    1,   70,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,
      12,    0,   74,    2, 0x08 /* Private */,
      13,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
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
        case 0: _t->se_cerro(); break;
        case 1: _t->se_abrio(); break;
        case 2: _t->actualizar_y_cerrar(); break;
        case 3: _t->resetear_concepto(); break;
        case 4: _t->eliminar_concepto(); break;
        case 5: _t->estado_btn_eliminar(); break;
        case 6: _t->concepto_dobleclikeado((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 7: _t->nuevo_concepto(); break;
        case 8: _t->guardar(); break;
        case 9: _t->cerrar(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DialogoConceptos::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogoConceptos::se_cerro)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DialogoConceptos::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogoConceptos::se_abrio)) {
                *result = 1;
                return;
            }
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void DialogoConceptos::se_cerro()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DialogoConceptos::se_abrio()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
