/****************************************************************************
** Meta object code from reading C++ file 'fileopener.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Code/fileopener.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fileopener.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FileOpener_t {
    QByteArrayData data[11];
    char stringdata[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_FileOpener_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_FileOpener_t qt_meta_stringdata_FileOpener = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 7),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 10),
QT_MOC_LITERAL(4, 31, 4),
QT_MOC_LITERAL(5, 36, 7),
QT_MOC_LITERAL(6, 44, 6),
QT_MOC_LITERAL(7, 51, 3),
QT_MOC_LITERAL(8, 55, 2),
QT_MOC_LITERAL(9, 58, 24),
QT_MOC_LITERAL(10, 83, 28)
    },
    "FileOpener\0getPath\0\0checkInput\0quit\0"
    "setText\0string\0pIn\0in\0changeDisplayedPage_next\0"
    "changeDisplayedPage_previous\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileOpener[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a,
       3,    0,   50,    2, 0x0a,
       4,    0,   51,    2, 0x08,
       5,    1,   52,    2, 0x08,
       5,    1,   55,    2, 0x08,
       9,    0,   58,    2, 0x08,
      10,    0,   59,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FileOpener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileOpener *_t = static_cast<FileOpener *>(_o);
        switch (_id) {
        case 0: _t->getPath(); break;
        case 1: _t->checkInput(); break;
        case 2: _t->quit(); break;
        case 3: _t->setText((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 4: _t->setText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->changeDisplayedPage_next(); break;
        case 6: _t->changeDisplayedPage_previous(); break;
        default: ;
        }
    }
}

const QMetaObject FileOpener::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FileOpener.data,
      qt_meta_data_FileOpener,  qt_static_metacall, 0, 0}
};


const QMetaObject *FileOpener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileOpener::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileOpener.stringdata))
        return static_cast<void*>(const_cast< FileOpener*>(this));
    return QWidget::qt_metacast(_clname);
}

int FileOpener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
