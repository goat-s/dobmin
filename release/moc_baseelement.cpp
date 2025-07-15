/****************************************************************************
** Meta object code from reading C++ file 'baseelement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../baseelement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'baseelement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BaseElement_t {
    QByteArrayData data[25];
    char stringdata0[286];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BaseElement_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BaseElement_t qt_meta_stringdata_BaseElement = {
    {
QT_MOC_LITERAL(0, 0, 11), // "BaseElement"
QT_MOC_LITERAL(1, 12, 11), // "rectChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "arg1"
QT_MOC_LITERAL(4, 30, 18), // "rotateAngleChanged"
QT_MOC_LITERAL(5, 49, 12), // "drawFinished"
QT_MOC_LITERAL(6, 62, 11), // "drawAborted"
QT_MOC_LITERAL(7, 74, 16), // "lockScaleChanged"
QT_MOC_LITERAL(8, 91, 9), // "lockScale"
QT_MOC_LITERAL(9, 101, 18), // "elementNameChanged"
QT_MOC_LITERAL(10, 120, 11), // "elementName"
QT_MOC_LITERAL(11, 132, 7), // "setRect"
QT_MOC_LITERAL(12, 140, 1), // "r"
QT_MOC_LITERAL(13, 142, 10), // "hidePicker"
QT_MOC_LITERAL(14, 153, 10), // "showPicker"
QT_MOC_LITERAL(15, 164, 14), // "setRotateAngle"
QT_MOC_LITERAL(16, 179, 6), // "center"
QT_MOC_LITERAL(17, 186, 12), // "setLockScale"
QT_MOC_LITERAL(18, 199, 14), // "setElementName"
QT_MOC_LITERAL(19, 214, 16), // "setParentElement"
QT_MOC_LITERAL(20, 231, 12), // "BaseElement*"
QT_MOC_LITERAL(21, 244, 13), // "parentElement"
QT_MOC_LITERAL(22, 258, 11), // "rotateAngle"
QT_MOC_LITERAL(23, 270, 10), // "scaleRatio"
QT_MOC_LITERAL(24, 281, 4) // "rect"

    },
    "BaseElement\0rectChanged\0\0arg1\0"
    "rotateAngleChanged\0drawFinished\0"
    "drawAborted\0lockScaleChanged\0lockScale\0"
    "elementNameChanged\0elementName\0setRect\0"
    "r\0hidePicker\0showPicker\0setRotateAngle\0"
    "center\0setLockScale\0setElementName\0"
    "setParentElement\0BaseElement*\0"
    "parentElement\0rotateAngle\0scaleRatio\0"
    "rect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaseElement[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       6,  120, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       5,    0,   90,    2, 0x06 /* Public */,
       6,    0,   91,    2, 0x06 /* Public */,
       7,    1,   92,    2, 0x06 /* Public */,
       9,    1,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   98,    2, 0x0a /* Public */,
      13,    0,  101,    2, 0x0a /* Public */,
      14,    0,  102,    2, 0x0a /* Public */,
      15,    2,  103,    2, 0x0a /* Public */,
      15,    1,  108,    2, 0x2a /* Public | MethodCloned */,
      17,    1,  111,    2, 0x0a /* Public */,
      18,    1,  114,    2, 0x0a /* Public */,
      19,    1,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QRectF,    3,
    QMetaType::Void, QMetaType::QReal,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::QString,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::QRectF,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal, QMetaType::QPointF,    3,   16,
    QMetaType::Void, QMetaType::QReal,    3,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, 0x80000000 | 20,   21,

 // properties: name, type, flags
      22, QMetaType::QReal, 0x00495103,
       8, QMetaType::Bool, 0x00495103,
      23, QMetaType::QReal, 0x00095001,
      24, QMetaType::QRectF, 0x00495103,
      10, QMetaType::QString, 0x00495103,
      21, 0x80000000 | 20, 0x0009510b,

 // properties: notify_signal_id
       1,
       4,
       0,
       0,
       5,
       0,

       0        // eod
};

void BaseElement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BaseElement *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rectChanged((*reinterpret_cast< const QRectF(*)>(_a[1]))); break;
        case 1: _t->rotateAngleChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 2: _t->drawFinished(); break;
        case 3: _t->drawAborted(); break;
        case 4: _t->lockScaleChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->elementNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setRect((*reinterpret_cast< const QRectF(*)>(_a[1]))); break;
        case 7: _t->hidePicker(); break;
        case 8: _t->showPicker(); break;
        case 9: _t->setRotateAngle((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< const QPointF(*)>(_a[2]))); break;
        case 10: _t->setRotateAngle((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 11: _t->setLockScale((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->setElementName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->setParentElement((*reinterpret_cast< BaseElement*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BaseElement* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BaseElement::*)(const QRectF & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseElement::rectChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BaseElement::*)(qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseElement::rotateAngleChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BaseElement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseElement::drawFinished)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BaseElement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseElement::drawAborted)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (BaseElement::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseElement::lockScaleChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (BaseElement::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseElement::elementNameChanged)) {
                *result = 5;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BaseElement* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<BaseElement *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->rotateAngle(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->lockScale(); break;
        case 2: *reinterpret_cast< qreal*>(_v) = _t->scaleRatio(); break;
        case 3: *reinterpret_cast< QRectF*>(_v) = _t->rect(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->elementName(); break;
        case 5: *reinterpret_cast< BaseElement**>(_v) = _t->parentElement(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<BaseElement *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRotateAngle(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->setLockScale(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setRect(*reinterpret_cast< QRectF*>(_v)); break;
        case 4: _t->setElementName(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setParentElement(*reinterpret_cast< BaseElement**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject BaseElement::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsObject::staticMetaObject>(),
    qt_meta_stringdata_BaseElement.data,
    qt_meta_data_BaseElement,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BaseElement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaseElement::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BaseElement.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsObject::qt_metacast(_clname);
}

int BaseElement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void BaseElement::rectChanged(const QRectF & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BaseElement::rotateAngleChanged(qreal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BaseElement::drawFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BaseElement::drawAborted()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void BaseElement::lockScaleChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void BaseElement::elementNameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
