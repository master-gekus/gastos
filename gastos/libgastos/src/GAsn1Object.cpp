#include <QSharedData>

#include "GAsn1Object.h"

// ///////////////////////////////////////////////////////////////////////////
// The GAsn1ObjectPrivate class
class GAsn1ObjectPrivate : public QSharedData
{
private:
  GAsn1ObjectPrivate();
  virtual ~GAsn1ObjectPrivate();

private:
  GAsn1Object::Tag tag_;
  GAsn1Object::Class class_;
  bool is_constructed_;

  friend class GAsn1Object;
  friend class QSharedDataPointer<GAsn1ObjectPrivate>;
};

GAsn1ObjectPrivate::GAsn1ObjectPrivate() :
  tag_(static_cast<GAsn1Object::Tag>(GAsn1Object::Null)),
  class_(GAsn1Object::Universal),
  is_constructed_(false)
{
}

GAsn1ObjectPrivate::~GAsn1ObjectPrivate()
{

}

// ///////////////////////////////////////////////////////////////////////////
// The GAsn1Object class
GAsn1Object::GAsn1Object() :
  d(new GAsn1ObjectPrivate())
{
}

GAsn1Object::GAsn1Object(const GAsn1Object &other) :
  d(other.d)
{
}

GAsn1Object&
GAsn1Object::operator=(const GAsn1Object &other)
{
  if (this != &other)
    d.operator=(other.d);
  return *this;
}

GAsn1Object::~GAsn1Object()
{
}

GAsn1Object::Type
GAsn1Object::objectType() const
{
  Q_ASSERT(Universal == d->class_);
  Q_ASSERT(static_cast<Tag>(MaxUniversalType) >= d->tag_);
  return static_cast<Type>(d->tag_);
}

GAsn1Object::Tag
GAsn1Object::objectTag() const
{
  return d->tag_;
}

GAsn1Object::Class
GAsn1Object::objectClass() const
{
  return d->class_;
}

bool
GAsn1Object::isConstructed() const
{
  return d->is_constructed_;
}

#define ENUM_CASE(e) case e: return QStringLiteral(#e)

QString
GAsn1Object::typeToString(Type object_type)
{
  switch (object_type)
    {
      ENUM_CASE(EndOfContent);
      ENUM_CASE(Boolean);
      ENUM_CASE(Integer);
      ENUM_CASE(BitString);
      ENUM_CASE(OctetString);
      ENUM_CASE(Null);
      ENUM_CASE(ObjectIdentifier);
      ENUM_CASE(ObjectDescriptor);
      ENUM_CASE(External);
      ENUM_CASE(Real);
      ENUM_CASE(Enumerated);
      ENUM_CASE(EmbeddedPDV);
      ENUM_CASE(Utf8String);
      ENUM_CASE(RelativeOID);
      ENUM_CASE(Reserved1);
      ENUM_CASE(Reserved2);
      ENUM_CASE(Sequence);
      ENUM_CASE(Set);
      ENUM_CASE(NumericString);
      ENUM_CASE(PrintableString);
      ENUM_CASE(T61String);
      ENUM_CASE(VideotexString);
      ENUM_CASE(IA5String);
      ENUM_CASE(UTCTime);
      ENUM_CASE(GeneralizedTime);
      ENUM_CASE(GraphicString);
      ENUM_CASE(VisibleString);
      ENUM_CASE(GeneralString);
      ENUM_CASE(UniversalString);
      ENUM_CASE(CharacterString);
      ENUM_CASE(BMPString);
      default: return QStringLiteral("<invalid-type>");
    }
}

QString
GAsn1Object::classToString(Class object_class)
{
  switch (object_class)
    {
      ENUM_CASE(Universal);
      ENUM_CASE(Application);
      ENUM_CASE(ContextSpecific);
      ENUM_CASE(Private);
      default: return QStringLiteral("<invalid-class>");
    }
}
