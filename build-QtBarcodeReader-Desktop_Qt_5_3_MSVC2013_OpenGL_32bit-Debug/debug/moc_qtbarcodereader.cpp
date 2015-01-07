/****************************************************************************
** Meta object code from reading C++ file 'qtbarcodereader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtBarcodeReader/qtbarcodereader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtbarcodereader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QtBarcodeReader_t {
    QByteArrayData data[24];
    char stringdata[329];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtBarcodeReader_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtBarcodeReader_t qt_meta_stringdata_QtBarcodeReader = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 9),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 11),
QT_MOC_LITERAL(4, 39, 10),
QT_MOC_LITERAL(5, 50, 11),
QT_MOC_LITERAL(6, 62, 10),
QT_MOC_LITERAL(7, 73, 9),
QT_MOC_LITERAL(8, 83, 19),
QT_MOC_LITERAL(9, 103, 26),
QT_MOC_LITERAL(10, 130, 11),
QT_MOC_LITERAL(11, 142, 24),
QT_MOC_LITERAL(12, 167, 18),
QT_MOC_LITERAL(13, 186, 18),
QT_MOC_LITERAL(14, 205, 8),
QT_MOC_LITERAL(15, 214, 6),
QT_MOC_LITERAL(16, 221, 17),
QT_MOC_LITERAL(17, 239, 14),
QT_MOC_LITERAL(18, 254, 17),
QT_MOC_LITERAL(19, 272, 20),
QT_MOC_LITERAL(20, 293, 9),
QT_MOC_LITERAL(21, 303, 3),
QT_MOC_LITERAL(22, 307, 15),
QT_MOC_LITERAL(23, 323, 5)
    },
    "QtBarcodeReader\0setCamera\0\0QCameraInfo\0"
    "cameraInfo\0startCamera\0stopCamera\0"
    "takeImage\0displayCaptureError\0"
    "QCameraImageCapture::Error\0errorString\0"
    "configureCaptureSettings\0displayCameraError\0"
    "updateCameraDevice\0QAction*\0action\0"
    "updateCameraState\0QCamera::State\0"
    "updateCaptureMode\0processCapturedImage\0"
    "requestId\0img\0readyForCapture\0ready"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtBarcodeReader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    3,   80,    2, 0x08 /* Private */,
      11,    0,   87,    2, 0x08 /* Private */,
      12,    0,   88,    2, 0x08 /* Private */,
      13,    1,   89,    2, 0x08 /* Private */,
      16,    1,   92,    2, 0x08 /* Private */,
      18,    0,   95,    2, 0x08 /* Private */,
      19,    2,   96,    2, 0x08 /* Private */,
      22,    1,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9, QMetaType::QString,    2,    2,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QImage,   20,   21,
    QMetaType::Void, QMetaType::Bool,   23,

       0        // eod
};

void QtBarcodeReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtBarcodeReader *_t = static_cast<QtBarcodeReader *>(_o);
        switch (_id) {
        case 0: _t->setCamera((*reinterpret_cast< const QCameraInfo(*)>(_a[1]))); break;
        case 1: _t->startCamera(); break;
        case 2: _t->stopCamera(); break;
        case 3: _t->takeImage(); break;
        case 4: _t->displayCaptureError((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QCameraImageCapture::Error(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 5: _t->configureCaptureSettings(); break;
        case 6: _t->displayCameraError(); break;
        case 7: _t->updateCameraDevice((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 8: _t->updateCameraState((*reinterpret_cast< QCamera::State(*)>(_a[1]))); break;
        case 9: _t->updateCaptureMode(); break;
        case 10: _t->processCapturedImage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QImage(*)>(_a[2]))); break;
        case 11: _t->readyForCapture((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCameraImageCapture::Error >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCamera::State >(); break;
            }
            break;
        }
    }
}

const QMetaObject QtBarcodeReader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtBarcodeReader.data,
      qt_meta_data_QtBarcodeReader,  qt_static_metacall, 0, 0}
};


const QMetaObject *QtBarcodeReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtBarcodeReader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtBarcodeReader.stringdata))
        return static_cast<void*>(const_cast< QtBarcodeReader*>(this));
    return QObject::qt_metacast(_clname);
}

int QtBarcodeReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
