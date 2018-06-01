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
    QByteArrayData data[6];
    char stringdata0[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogoTerminos_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogoTerminos_t qt_meta_stringdata_DialogoTerminos = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DialogoTerminos"
QT_MOC_LITERAL(1, 16, 8), // "se_cerro"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "se_abrio"
QT_MOC_LITERAL(4, 35, 7), // "guardar"
QT_MOC_LITERAL(5, 43, 6) // "cerrar"

    },
    "DialogoTerminos\0se_cerro\0\0se_abrio\0"
    "guardar\0cerrar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogoTerminos[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
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
        case 0: _t->se_cerro(); break;
        case 1: _t->se_abrio(); break;
        case 2: _t->guardar(); break;
        case 3: _t->cerrar(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DialogoTerminos::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogoTerminos::se_cerro)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DialogoTerminos::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogoTerminos::se_abrio)) {
                *result = 1;
                return;
            }
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DialogoTerminos::se_cerro()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DialogoTerminos::se_abrio()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
