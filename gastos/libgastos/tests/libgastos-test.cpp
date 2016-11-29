#include <QString>
#include <QtTest>

#include "GAsn1Object.h"

namespace QTest
{
  template <>
  char* toString(const GAsn1Object::Type& object_type)
  {
    return qstrdup(GAsn1Object::typeToString(object_type).toUtf8().constData());
  }

  template <>
  char* toString(const GAsn1Object::Class& object_class)
  {
    return qstrdup(GAsn1Object::classToString(object_class).toUtf8().constData());
  }
}

class GastosTest : public QObject
{
  Q_OBJECT

public:
  GastosTest();

private Q_SLOTS:
  void initTestCase();
  void cleanupTestCase();
  void testSimpleConstrutor();
};

GastosTest::GastosTest()
{
}

void GastosTest::initTestCase()
{
}

void GastosTest::cleanupTestCase()
{
}

#define VERIFY_ASN1_OBJECT(object, type, tag, cls, constucted) \
do {\
  auto const& o = (object); \
  QCOMPARE(o.objectClass(), cls); \
  QCOMPARE(o.objectTag(), static_cast<GAsn1Object::Tag>(tag)); \
  if (GAsn1Object::Universal == o.objectClass()) \
    { \
      QCOMPARE(o.objectType(), static_cast<GAsn1Object::Type>(type)); \
    } \
  QCOMPARE(o.isConstructed(), constucted); \
  QCOMPARE(o.isPrimitive(), !constucted); \
} while (false)

#define VERIFY_UNIVERSAL(object, tag, constucted) \
  VERIFY_ASN1_OBJECT(object, tag, tag, GAsn1Object::Universal, constucted)

#define VERIFY_ASN1OBJECT_COPYING(object) \
do {\
  const GAsn1Object& o = (object); \
  GAsn1Object::Tag tag = o.objectTag(); \
  GAsn1Object::Type type = static_cast<GAsn1Object::Type>(tag); \
  GAsn1Object::Class cls = o.objectClass(); \
  if (GAsn1Object::Universal == cls) \
    type = o.objectType(); \
\
  GAsn1Object o1(o), o2; \
  VERIFY_ASN1_OBJECT(o1, tag, type, cls, o.isConstructed()); \
\
  o2 = o; \
  VERIFY_ASN1_OBJECT(o2, tag, type, cls, o.isConstructed()); \
\
} while(false)

void GastosTest::testSimpleConstrutor()
{
  GAsn1Object g1;
  VERIFY_UNIVERSAL(g1, GAsn1Object::Null, false);
  VERIFY_ASN1OBJECT_COPYING(g1);
}

QTEST_APPLESS_MAIN(GastosTest)

#include "libgastos-test.moc"
