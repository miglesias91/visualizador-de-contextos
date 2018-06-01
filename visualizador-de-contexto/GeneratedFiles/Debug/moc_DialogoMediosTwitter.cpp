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
    QByteArrayData data[7];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogoMediosTwitter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogoMediosTwitter_t qt_meta_stringdata_DialogoMediosTwitter = {
    {
QT_MOC_LITERAL(0, 0, 20), // "DialogoMediosTwitter"
QT_MOC_LITERAL(1, 21, 19), // "actualizar_y_cerrar"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 15), // "resetear_cuenta"
QT_MOC_LITERAL(4, 58, 15), // "eliminar_cuenta"
QT_MOC_LITERAL(5, 74, 19), // "estado_btn_eliminar"
QT_MOC_LITERAL(6, 94, 12) // "nueva_cuenta"

    },
    "DialogoMediosTwitter\0actualizar_y_cerrar\0"
    "\0resetear_cuenta\0eliminar_cuenta\0"
    "estado_btn_eliminar\0nueva_cuenta"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogoMediosTwitter[] = {

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

void DialogoMediosTwitter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogoMediosTwitter *_t = static_cast<DialogoMediosTwitter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->actualizar_y_cerrar(); break;
        case 1: _t->resetear_cuenta(); break;
        case 2: _t->eliminar_cuenta(); break;
        case 3: _t->estado_btn_eliminar(); break;
        case 4: _t->nueva_cuenta(); break;
        default: ;
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
