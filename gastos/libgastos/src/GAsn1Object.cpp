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

GAsn1Object &GAsn1Object::operator=(const GAsn1Object &other)
{
  if (this != &other)
    d.operator=(other.d);
  return *this;
}

GAsn1Object::~GAsn1Object()
{
}

GAsn1Object::Type GAsn1Object::objectType() const
{
  Q_ASSERT(Universal == d->class_);
  Q_ASSERT(static_cast<Tag>(MaxUniversalType) >= d->tag_);
  return static_cast<Type>(d->tag_);
}

GAsn1Object::Tag GAsn1Object::objectTag() const
{
  return d->tag_;
}

GAsn1Object::Class GAsn1Object::objectClass() const
{
  return d->class_;
}

bool GAsn1Object::isConstructed() const
{
  return d->is_constructed_;
}
