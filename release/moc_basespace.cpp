/****************************************************************************
** Meta object code from reading C++ file 'basespace.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../basespace.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'basespace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BaseSpaceScene_t {
    QByteArrayData data[10];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BaseSpaceScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BaseSpaceScene_t qt_meta_stringdata_BaseSpaceScene = {
    {
QT_MOC_LITERAL(0, 0, 14), // "BaseSpaceScene"
QT_MOC_LITERAL(1, 15, 19), // "physicalSizeChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 12), // "PhysicalSize"
QT_MOC_LITERAL(4, 49, 12), // "physicalSize"
QT_MOC_LITERAL(5, 62, 15), // "elementUnpicked"
QT_MOC_LITERAL(6, 78, 13), // "elementPicked"
QT_MOC_LITERAL(7, 92, 12), // "BaseElement*"
QT_MOC_LITERAL(8, 105, 7), // "element"
QT_MOC_LITERAL(9, 113, 15) // "setPhysicalSize"

    },
    "BaseSpaceScene\0physicalSizeChanged\0\0"
    "PhysicalSize\0physicalSize\0elementUnpicked\0"
    "elementPicked\0BaseElement*\0element\0"
    "setPhysicalSize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaseSpaceScene[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       1,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,
       6,    1,   38,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // properties: name, type, flags
       4, 0x80000000 | 3, 0x0049510b,

 // properties: notify_signal_id
       0,

       0        // eod
};

void BaseSpaceScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BaseSpaceScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->physicalSizeChanged((*reinterpret_cast< PhysicalSize(*)>(_a[1]))); break;
        case 1: _t->elementUnpicked(); break;
        case 2: _t->elementPicked((*reinterpret_cast< BaseElement*(*)>(_a[1]))); break;
        case 3: _t->setPhysicalSize((*reinterpret_cast< PhysicalSize(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BaseSpaceScene::*)(PhysicalSize );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseSpaceScene::physicalSizeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BaseSpaceScene::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseSpaceScene::elementUnpicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BaseSpaceScene::*)(BaseElement * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseSpaceScene::elementPicked)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<BaseSpaceScene *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< PhysicalSize*>(_v) = _t->physicalSize(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<BaseSpaceScene *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPhysicalSize(*reinterpret_cast< PhysicalSize*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject BaseSpaceScene::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_BaseSpaceScene.data,
    qt_meta_data_BaseSpaceScene,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BaseSpaceScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaseSpaceScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BaseSpaceScene.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int BaseSpaceScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void BaseSpaceScene::physicalSizeChanged(PhysicalSize _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BaseSpaceScene::elementUnpicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BaseSpaceScene::elementPicked(BaseElement * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_BaseSpace_t {
    QByteArrayData data[14];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BaseSpace_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BaseSpace_t qt_meta_stringdata_BaseSpace = {
    {
QT_MOC_LITERAL(0, 0, 9), // "BaseSpace"
QT_MOC_LITERAL(1, 10, 6), // "scaled"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 14), // "elementCreated"
QT_MOC_LITERAL(4, 33, 12), // "BaseElement*"
QT_MOC_LITERAL(5, 46, 7), // "element"
QT_MOC_LITERAL(6, 54, 19), // "originalSizeChanged"
QT_MOC_LITERAL(7, 74, 12), // "originalSize"
QT_MOC_LITERAL(8, 87, 4), // "zoom"
QT_MOC_LITERAL(9, 92, 6), // "factor"
QT_MOC_LITERAL(10, 99, 9), // "zoomToFit"
QT_MOC_LITERAL(11, 109, 12), // "pickElements"
QT_MOC_LITERAL(12, 122, 20), // "QList<BaseElement*>&"
QT_MOC_LITERAL(13, 143, 8) // "elements"

    },
    "BaseSpace\0scaled\0\0elementCreated\0"
    "BaseElement*\0element\0originalSizeChanged\0"
    "originalSize\0zoom\0factor\0zoomToFit\0"
    "pickElements\0QList<BaseElement*>&\0"
    "elements"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaseSpace[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       6,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   51,    2, 0x0a /* Public */,
      10,    0,   54,    2, 0x0a /* Public */,
      11,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QSize,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QReal,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void BaseSpace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BaseSpace *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->scaled(); break;
        case 1: _t->elementCreated((*reinterpret_cast< BaseElement*(*)>(_a[1]))); break;
        case 2: _t->originalSizeChanged((*reinterpret_cast< QSize(*)>(_a[1]))); break;
        case 3: _t->zoom((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 4: _t->zoomToFit(); break;
        case 5: _t->pickElements((*reinterpret_cast< QList<BaseElement*>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BaseSpace::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseSpace::scaled)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BaseSpace::*)(BaseElement * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseSpace::elementCreated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BaseSpace::*)(QSize );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseSpace::originalSizeChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BaseSpace::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_BaseSpace.data,
    qt_meta_data_BaseSpace,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BaseSpace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaseSpace::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BaseSpace.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int BaseSpace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
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
void BaseSpace::scaled()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BaseSpace::elementCreated(BaseElement * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BaseSpace::originalSizeChanged(QSize _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
