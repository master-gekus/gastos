#include <QString>
#include <QtTest>

#include "GAsn1Object.h"

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

void GastosTest::testSimpleConstrutor()
{
  GAsn1Object g1;
  QVERIFY(g1.objectType() == GAsn1Object::Null);
  QVERIFY(g1.objectTag() == static_cast<GAsn1Object::Tag>(GAsn1Object::Null));
  QVERIFY(g1.objectClass() == GAsn1Object::Universal);
  QVERIFY(!g1.isConstructed());
  QVERIFY(g1.isPrimitive());

  GAsn1Object g2(g1);
  QVERIFY(g2.objectType() == GAsn1Object::Null);
  QVERIFY(g2.objectTag() == static_cast<GAsn1Object::Tag>(GAsn1Object::Null));
  QVERIFY(g2.objectClass() == GAsn1Object::Universal);
  QVERIFY(!g2.isConstructed());
  QVERIFY(g2.isPrimitive());

  GAsn1Object* pg = new GAsn1Object();
  QVERIFY(pg->objectType() == GAsn1Object::Null);
  QVERIFY(pg->objectTag() == static_cast<GAsn1Object::Tag>(GAsn1Object::Null));
  QVERIFY(pg->objectClass() == GAsn1Object::Universal);
  QVERIFY(!pg->isConstructed());
  QVERIFY(pg->isPrimitive());

  GAsn1Object g3(*pg);
  delete pg;
  QVERIFY(g3.objectType() == GAsn1Object::Null);
  QVERIFY(g3.objectTag() == static_cast<GAsn1Object::Tag>(GAsn1Object::Null));
  QVERIFY(g3.objectClass() == GAsn1Object::Universal);
  QVERIFY(!g3.isConstructed());
  QVERIFY(g3.isPrimitive());

  GAsn1Object g4;
  g4 = g1;
  QVERIFY(g4.objectType() == GAsn1Object::Null);
  QVERIFY(g4.objectTag() == static_cast<GAsn1Object::Tag>(GAsn1Object::Null));
  QVERIFY(g4.objectClass() == GAsn1Object::Universal);
  QVERIFY(!g4.isConstructed());
  QVERIFY(g4.isPrimitive());
}

QTEST_APPLESS_MAIN(GastosTest)

#include "libgastos-test.moc"
