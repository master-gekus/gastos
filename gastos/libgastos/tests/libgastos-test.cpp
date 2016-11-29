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

  void testTypeConstructor_data();
  void testTypeConstructor();
};

GastosTest::GastosTest()
{
}

void
GastosTest::initTestCase()
{
}

void
GastosTest::cleanupTestCase()
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

void
GastosTest::testSimpleConstrutor()
{
  GAsn1Object g1;
  VERIFY_UNIVERSAL(g1, GAsn1Object::Null, false);
  VERIFY_ASN1OBJECT_COPYING(g1);
}

#define TESTTYPEC_ROW(type)\
  QTest::newRow(#type) \
    << GAsn1Object(GAsn1Object::type) \
    << GAsn1Object::type

void
GastosTest::testTypeConstructor_data()
{
  QTest::addColumn<GAsn1Object>("object");
  QTest::addColumn<GAsn1Object::Type>("type");
  QTest::addColumn<bool>("constructed");
  QTest::addColumn<bool>("can_be_constructed");
  QTest::addColumn<bool>("can_be_primitive");

  TESTTYPEC_ROW(EndOfContent) << false << false << true;
  TESTTYPEC_ROW(Boolean) << false << false << true;
  TESTTYPEC_ROW(Integer) << false << false << true;
  TESTTYPEC_ROW(BitString) << false << true << true;
  TESTTYPEC_ROW(OctetString) << false << true << true;
  TESTTYPEC_ROW(Null) << false << false << true;
  TESTTYPEC_ROW(ObjectIdentifier) << false << false << true;
  TESTTYPEC_ROW(ObjectDescriptor) << false << true << true;
  TESTTYPEC_ROW(External) << true << true << false;
  TESTTYPEC_ROW(Real) << false << false << true;
  TESTTYPEC_ROW(Enumerated) << false << false << true;
  TESTTYPEC_ROW(EmbeddedPDV) << true << true << false;
  TESTTYPEC_ROW(Utf8String) << false << true << true;
  TESTTYPEC_ROW(RelativeOID) << false << false << true;
  TESTTYPEC_ROW(Reserved1) << false << true << true;
  TESTTYPEC_ROW(Reserved2) << false << true << true;
  TESTTYPEC_ROW(Sequence) << true << true << false;
  TESTTYPEC_ROW(Set) << true << true << false;
  TESTTYPEC_ROW(NumericString) << false << true << true;
  TESTTYPEC_ROW(PrintableString) << false << true << true;
  TESTTYPEC_ROW(T61String) << false << true << true;
  TESTTYPEC_ROW(VideotexString) << false << true << true;
  TESTTYPEC_ROW(IA5String) << false << true << true;
  TESTTYPEC_ROW(UTCTime) << false << true << true;
  TESTTYPEC_ROW(GeneralizedTime) << false << true << true;
  TESTTYPEC_ROW(GraphicString) << false << true << true;
  TESTTYPEC_ROW(VisibleString) << false << true << true;
  TESTTYPEC_ROW(GeneralString) << false << true << true;
  TESTTYPEC_ROW(UniversalString) << false << true << true;
  TESTTYPEC_ROW(CharacterString) << false << true << true;
  TESTTYPEC_ROW(BMPString) << false << true << true;
}

void
GastosTest::testTypeConstructor()
{
  QFETCH(GAsn1Object, object);
  QFETCH(GAsn1Object::Type, type);
  QFETCH(bool, constructed);
  QFETCH(bool, can_be_constructed);
  QFETCH(bool, can_be_primitive);

  VERIFY_UNIVERSAL(object, type, constructed);
  VERIFY_ASN1OBJECT_COPYING(object);
  QCOMPARE(object.canBeConstructed(), can_be_constructed);
  QCOMPARE(object.canBePrimitive(), can_be_primitive);
}

QTEST_APPLESS_MAIN(GastosTest)

#include "libgastos-test.moc"
