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
  void testCase1();
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

void GastosTest::testCase1()
{
  GAsn1Object g;
  printf("GastosTest::testCase1()\n");
  QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(GastosTest)

#include "libgastos-test.moc"
