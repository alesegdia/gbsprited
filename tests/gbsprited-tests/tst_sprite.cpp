#include <QString>
#include <QtTest>

#include "../../gbsprited/sprite.h"

class SpriteTest : public QObject
{
	Q_OBJECT

public:
	SpriteTest();

private Q_SLOTS:
	void sizeTest();
	void resetPixelsTest();
	void pixelPlotResetTest();

};

SpriteTest::SpriteTest()
{
}

void SpriteTest::sizeTest()
{
	Sprite spr;
	spr.reset(123, 321);
	QVERIFY2(spr.width() == 123, "width mismatch");
	QVERIFY2(spr.height() == 321, "height mismatch");
}

void SpriteTest::resetPixelsTest()
{
	Sprite spr;
	spr.reset(123, 321);
	for( int y = 0; y < spr.height(); y++ )
	{
		for( int x = 0; x < spr.width(); x++ )
		{
			QVERIFY2(spr.get(x, y) == 0, "data not correctly reset");
		}
	}
}

void SpriteTest::pixelPlotResetTest()
{
	Sprite spr;

	const int NUM_ITERS = 500;
	const int MIN_SIZE = 100;
	const int MAX_SIZE = 300;

	for( int i = 0; i < NUM_ITERS; i++ )
	{
		spr.reset(
			MIN_SIZE + qrand() % (MAX_SIZE - MIN_SIZE),
			MIN_SIZE + qrand() % (MAX_SIZE - MIN_SIZE)
		);

		int px = qrand() % spr.width();
		int py = qrand() % spr.height();

		uint8_t plottedValue = qrand() % 256;

		spr.plot(px, py, plottedValue);

		for( int x = 0; x < spr.width(); x++ )
		{
			for( int y = 0; y < spr.height(); y++ )
			{
				uint8_t storedValue = spr.get(x, y);
				if( px == x && py == y )
				{
					QVERIFY2( storedValue == plottedValue, "plotted pixel value mismatch" );
				}
				else
				{
					QVERIFY2( storedValue == 0, "non plotted pixel is non zero");
				}
			}
		}
	}
}


QTEST_APPLESS_MAIN(SpriteTest)

#include "tst_sprite.moc"
