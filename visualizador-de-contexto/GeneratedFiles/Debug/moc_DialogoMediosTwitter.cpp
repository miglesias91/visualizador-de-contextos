/****************************************************************************
** Meta object code from reading C++ file 'DialogoMediosTwitter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DialogoMediosTwitter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogoMediosTwitter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogoMediosTwitter_t {
    QByteArrayData data[11];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogoMediosTwitter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogoMediosTwitter_t qt_meta_stringdata_DialogoMediosTwitter = {
    {
QT_MOC_LITERAL(0, 0, 20), // "DialogoMediosTwitter"
QT_MOC_LITERAL(1, 21, 8), // "se_cerro"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "se_abrio"
QT_MOC_LITERAL(4, 40, 19), // "actualizar_y_cerrar"
QT_MOC_LITERAL(5, 60, 15), // "resetear_cuenta"
QT_MOC_LITERAL(6, 76, 15), // "eliminar_cuenta"
QT_MOC_LITERAL(7, 92, 19), // "estado_btn_eliminar"
QT_MOC_LITERAL(8, 112, 12), // "nueva_cuenta"
QT_MOC_LITERAL(9, 125, 7), // "guardar"
QT_MOC_LITERAL(10, 133, 6) // "cerrar"

    },
    "DialogoMediosTwitter\0se_cerro\0\0se_abrio\0"
    "actualizar_y_cerrar\0resetear_cuenta\0"
    "eliminar_cuenta\0estado_btn_eliminar\0"
    "nueva_cuenta\0guardar\0cerrar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogoMediosTwitter[] = {

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

void DialogoMediosTwitter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogoMediosTwitter *_t = static_cast<DialogoMediosTwitter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->se_cerro(); break;
        case 1: _t->se_abrio(); break;
        case 2: _t->actualizar_y_cerrar(); break;
        case 3: _t->resetear_cuenta(); break;
        case 4: _t->eliminar_cuenta(); break;
        case 5: _t->estado_btn_eliminar(); break;
        case 6: _t->nueva_cuenta(); break;
        case 7: _t->guardar(); break;
        case 8: _t->cerrar(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DialogoMediosTwitter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogoMediosTwitter::se_cerro)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DialogoMediosTwitter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogoMediosTwitter::se_abrio)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DialogoMediosTwitter::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DialogoMediosTwitter.data,
      qt_meta_data_DialogoMediosTwitter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DialogoMediosTwitter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogoMediosTwitter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogoMediosTwitter.stringdata0))
        return static_cast<void*>(const_cast< DialogoMediosTwitter*>(this));
    return QWidget::qt_metacast(_clname);
}

int DialogoMediosTwitter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void DialogoMediosTwitter::se_cerro()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DialogoMediosTwitter::se_abrio()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
