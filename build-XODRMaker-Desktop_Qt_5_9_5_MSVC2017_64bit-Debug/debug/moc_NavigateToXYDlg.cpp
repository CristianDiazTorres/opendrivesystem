/****************************************************************************
** Meta object code from reading C++ file 'NavigateToXYDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source/_XODRMaker/Main/NavigateToXYDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NavigateToXYDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NavigateToXYDlg_t {
    QByteArrayData data[10];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NavigateToXYDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NavigateToXYDlg_t qt_meta_stringdata_NavigateToXYDlg = {
    {
QT_MOC_LITERAL(0, 0, 15), // "NavigateToXYDlg"
QT_MOC_LITERAL(1, 16, 10), // "doNavigate"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 3), // "lat"
QT_MOC_LITERAL(4, 32, 3), // "lon"
QT_MOC_LITERAL(5, 36, 22), // "on_navigateBtn_clicked"
QT_MOC_LITERAL(6, 59, 19), // "on_closeBtn_clicked"
QT_MOC_LITERAL(7, 79, 20), // "on_xyEdt_textChanged"
QT_MOC_LITERAL(8, 100, 4), // "arg1"
QT_MOC_LITERAL(9, 105, 22) // "on_xyEdt_returnPressed"

    },
    "NavigateToXYDlg\0doNavigate\0\0lat\0lon\0"
    "on_navigateBtn_clicked\0on_closeBtn_clicked\0"
    "on_xyEdt_textChanged\0arg1\0"
    "on_xyEdt_returnPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NavigateToXYDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   44,    2, 0x08 /* Private */,
       6,    0,   45,    2, 0x08 /* Private */,
       7,    1,   46,    2, 0x08 /* Private */,
       9,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

       0        // eod
};

void NavigateToXYDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NavigateToXYDlg *_t = static_cast<NavigateToXYDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doNavigate((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->on_navigateBtn_clicked(); break;
        case 2: _t->on_closeBtn_clicked(); break;
        case 3: _t->on_xyEdt_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_xyEdt_returnPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (NavigateToXYDlg::*_t)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavigateToXYDlg::doNavigate)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject NavigateToXYDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NavigateToXYDlg.data,
      qt_meta_data_NavigateToXYDlg,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *NavigateToXYDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NavigateToXYDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NavigateToXYDlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int NavigateToXYDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void NavigateToXYDlg::doNavigate(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
