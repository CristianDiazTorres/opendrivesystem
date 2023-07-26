/****************************************************************************
** Meta object code from reading C++ file 'MapWnd.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source/_XODRMaker/Main/MapWnd.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MapWnd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MapWnd_t {
    QByteArrayData data[11];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MapWnd_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MapWnd_t qt_meta_stringdata_MapWnd = {
    {
QT_MOC_LITERAL(0, 0, 6), // "MapWnd"
QT_MOC_LITERAL(1, 7, 12), // "updateStatus"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "onDoNaviate"
QT_MOC_LITERAL(4, 33, 3), // "lat"
QT_MOC_LITERAL(5, 37, 3), // "lon"
QT_MOC_LITERAL(6, 41, 14), // "onShowGPSLayer"
QT_MOC_LITERAL(7, 56, 4), // "show"
QT_MOC_LITERAL(8, 61, 21), // "onShowTrajectoryLayer"
QT_MOC_LITERAL(9, 83, 17), // "onShowOSMWayLayer"
QT_MOC_LITERAL(10, 101, 24) // "onShowOpenDRIVERoadLayer"

    },
    "MapWnd\0updateStatus\0\0onDoNaviate\0lat\0"
    "lon\0onShowGPSLayer\0show\0onShowTrajectoryLayer\0"
    "onShowOSMWayLayer\0onShowOpenDRIVERoadLayer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MapWnd[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   45,    2, 0x0a /* Public */,
       6,    1,   50,    2, 0x0a /* Public */,
       8,    1,   53,    2, 0x0a /* Public */,
       9,    1,   56,    2, 0x0a /* Public */,
      10,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void MapWnd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MapWnd *_t = static_cast<MapWnd *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateStatus(); break;
        case 1: _t->onDoNaviate((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->onShowGPSLayer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onShowTrajectoryLayer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onShowOSMWayLayer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->onShowOpenDRIVERoadLayer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MapWnd::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapWnd::updateStatus)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MapWnd::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MapWnd.data,
      qt_meta_data_MapWnd,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MapWnd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MapWnd::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MapWnd.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MapWnd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void MapWnd::updateStatus()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
