#ifndef GASN1OBJECT_H
#define GASN1OBJECT_H

#include <QSharedDataPointer>
#include <QMetaType>

#include "gastos.h"

class GAsn1ObjectPrivate;

class GASTOSSHARED_EXPORT GAsn1Object
{
public:
  typedef quint64 Tag;

  enum Type
  {
    EndOfContent = 0x00,
    Boolean = 0x01,
    Integer = 0x02,
    BitString = 0x03,
    OctetString = 0x04,
    Null = 0x05,
    ObjectIdentifier = 0x06,
    ObjectDescriptor = 0x07,
    External = 0x08,
    Real = 0x09,
    Enumerated = 0x0A,
    EmbeddedPDV = 0x0B,
    Utf8String = 0x0C,
    RelativeOID = 0x0D,
    Reserved1 = 0x0E,
    Reserved2 = 0x0F,
    Sequence = 0x10,
    Set = 0x11,
    NumericString = 0x12,
    PrintableString = 0x13,
    T61String= 0x14,
    VideotexString = 0x15,
    IA5String = 0x16,
    UTCTime = 0x17,
    GeneralizedTime = 0x18,
    GraphicString = 0x19,
    VisibleString = 0x1A,
    GeneralString = 0x1B,
    UniversalString = 0x1C,
    CharacterString = 0x1D,
    BMPString = 0x1E,

    MaxUniversalType = 0x1E,
  };

  enum Class
  {
    Universal = 0x0,
    Application = 0x1,
    ContextSpecific = 0x2,
    Private = 0x3,
  };

public:
  GAsn1Object();
  GAsn1Object(const GAsn1Object& other);
  virtual ~GAsn1Object();

public:
  GAsn1Object& operator =(const GAsn1Object& other);

public:
  GAsn1Object(Type object_type);

public:
  Type objectType() const;
  Tag objectTag() const;
  Class objectClass() const;
  bool isConstructed() const;
  bool isPrimitive() const;
  bool canBeConstructed() const;
  bool canBePrimitive() const;
  static bool canBeConstructed(Tag tag);
  static bool canBePrimitive(Tag tag);
  static bool canBeConstructed(Type type);
  static bool canBePrimitive(Type type);

public:
  static QString typeToString(Type object_type);
  static QString classToString(Class object_class);

private:
  QSharedDataPointer<GAsn1ObjectPrivate> d;
};

Q_DECLARE_METATYPE(GAsn1Object)
Q_DECLARE_TYPEINFO(GAsn1Object, Q_MOVABLE_TYPE);

Q_DECLARE_METATYPE(GAsn1Object::Type)
Q_DECLARE_METATYPE(GAsn1Object::Class)

inline bool GAsn1Object::isPrimitive() const
{
  return !isConstructed();
}


#endif // GASN1OBJECT_H
