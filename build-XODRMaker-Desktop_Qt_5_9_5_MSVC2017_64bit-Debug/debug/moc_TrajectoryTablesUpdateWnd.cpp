/****************************************************************************
** Meta object code from reading C++ file 'TrajectoryTablesUpdateWnd.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source/_XODRMaker/Trajectory/TrajectoryTablesUpdateWnd.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TrajectoryTablesUpdateWnd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TrajectoryTablesUpdateWnd_t {
    QByteArrayData data[8];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TrajectoryTablesUpdateWnd_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TrajectoryTablesUpdateWnd_t qt_meta_stringdata_TrajectoryTablesUpdateWnd = {
    {
QT_MOC_LITERAL(0, 0, 25), // "TrajectoryTablesUpdateWnd"
QT_MOC_LITERAL(1, 26, 8), // "onAddLog"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 16), // "_NDebug::LogInfo"
QT_MOC_LITERAL(4, 53, 7), // "logInfo"
QT_MOC_LITERAL(5, 61, 17), // "onProgressUpdated"
QT_MOC_LITERAL(6, 79, 8), // "progress"
QT_MOC_LITERAL(7, 88, 24) // "onThreadPostLoopFinished"

    },
    "TrajectoryTablesUpdateWnd\0onAddLog\0\0"
    "_NDebug::LogInfo\0logInfo\0onProgressUpdated\0"
    "progress\0onThreadPostLoopFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrajectoryTablesUpdateWnd[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       5,    1,   32,    2, 0x0a /* Public */,
       7,    0,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,

       0        // eod
};

void TrajectoryTablesUpdateWnd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TrajectoryTablesUpdateWnd *_t = static_cast<TrajectoryTablesUpdateWnd *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onAddLog((*reinterpret_cast< _NDebug::LogInfo(*)>(_a[1]))); break;
        case 1: _t->onProgressUpdated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onThreadPostLoopFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< _NDebug::LogInfo >(); break;
            }
            break;
        }
    }
}

const QMetaObject TrajectoryTablesUpdateWnd::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TrajectoryTablesUpdateWnd.data,
      qt_meta_data_TrajectoryTablesUpdateWnd,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TrajectoryTablesUpdateWnd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrajectoryTablesUpdateWnd::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrajectoryTablesUpdateWnd.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TrajectoryTablesUpdateWnd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE