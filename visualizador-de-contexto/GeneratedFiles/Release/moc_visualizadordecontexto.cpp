/****************************************************************************
** Meta object code from reading C++ file 'visualizadordecontexto.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../visualizadordecontexto.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'visualizadordecontexto.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_visualizadordecontexto_t {
    QByteArrayData data[12];
    char stringdata0[371];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_visualizadordecontexto_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_visualizadordecontexto_t qt_meta_stringdata_visualizadordecontexto = {
    {
QT_MOC_LITERAL(0, 0, 22), // "visualizadordecontexto"
QT_MOC_LITERAL(1, 23, 25), // "senialProgresoAnalisisCTX"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 34), // "on_action_abrir_terminos_trig..."
QT_MOC_LITERAL(4, 85, 35), // "on_action_abrir_conceptos_tri..."
QT_MOC_LITERAL(5, 121, 32), // "on_action_abrir_fechas_triggered"
QT_MOC_LITERAL(6, 154, 34), // "on_action_abrir_periodos_trig..."
QT_MOC_LITERAL(7, 189, 34), // "on_action_abrir_consulta_trig..."
QT_MOC_LITERAL(8, 224, 40), // "on_action_abrir_medios_twitte..."
QT_MOC_LITERAL(9, 265, 32), // "on_action_analizar_ctx_triggered"
QT_MOC_LITERAL(10, 298, 37), // "on_action_deshabilitar_menu_t..."
QT_MOC_LITERAL(11, 336, 34) // "on_action_habilitar_menu_trig..."

    },
    "visualizadordecontexto\0senialProgresoAnalisisCTX\0"
    "\0on_action_abrir_terminos_triggered\0"
    "on_action_abrir_conceptos_triggered\0"
    "on_action_abrir_fechas_triggered\0"
    "on_action_abrir_periodos_triggered\0"
    "on_action_abrir_consulta_triggered\0"
    "on_action_abrir_medios_twitter_triggered\0"
    "on_action_analizar_ctx_triggered\0"
    "on_action_deshabilitar_menu_triggered\0"
    "on_action_habilitar_menu_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_visualizadordecontexto[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   67,    2, 0x08 /* Private */,
       4,    0,   68,    2, 0x08 /* Private */,
       5,    0,   69,    2, 0x08 /* Private */,
       6,    0,   70,    2, 0x08 /* Private */,
       7,    0,   71,    2, 0x08 /* Private */,
       8,    0,   72,    2, 0x08 /* Private */,
       9,    0,   73,    2, 0x08 /* Private */,
      10,    0,   74,    2, 0x08 /* Private */,
      11,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void visualizadordecontexto::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        visualizadordecontexto *_t = static_cast<visualizadordecontexto *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->senialProgresoAnalisisCTX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_action_abrir_terminos_triggered(); break;
        case 2: _t->on_action_abrir_conceptos_triggered(); break;
        case 3: _t->on_action_abrir_fechas_triggered(); break;
        case 4: _t->on_action_abrir_periodos_triggered(); break;
        case 5: _t->on_action_abrir_consulta_triggered(); break;
        case 6: _t->on_action_abrir_medios_twitter_triggered(); break;
        case 7: _t->on_action_analizar_ctx_triggered(); break;
        case 8: _t->on_action_deshabilitar_menu_triggered(); break;
        case 9: _t->on_action_habilitar_menu_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (visualizadordecontexto::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&visualizadordecontexto::senialProgresoAnalisisCTX)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject visualizadordecontexto::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_visualizadordecontexto.data,
      qt_meta_data_visualizadordecontexto,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *visualizadordecontexto::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *visualizadordecontexto::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_visualizadordecontexto.stringdata0))
        return static_cast<void*>(const_cast< visualizadordecontexto*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int visualizadordecontexto::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void visualizadordecontexto::senialProgresoAnalisisCTX(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
