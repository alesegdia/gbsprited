#include "sprite.h"

Sprite::Sprite()
{

}

void Sprite::reset(int width, int height)
{
	m_data.clear();
	m_data.fill(0, width * height);
	m_width = width;
	m_height = height;

	for( int x = 0; x < width; x++ )
	{
		for( int y = 0; y < height; y++ )
		{
			plot(x, y, qrand() % 4);
		}
	}
}

uint8_t Sprite::get(int x, int y)
{
	Q_ASSERT(x >= 0 && x < m_width);
	Q_ASSERT(y >= 0 && y < m_height);

	return m_data[coordToIndex(x, y)];
}

void Sprite::plot(int x, int y, uint8_t value)
{
	Q_ASSERT(x >= 0 && x < m_width);
	Q_ASSERT(y >= 0 && y < m_height);

	m_data[coordToIndex(x, y)] = value;
}

int Sprite::width()
{
	return m_width;
}

int Sprite::height()
{
	return m_height;
}

int Sprite::coordToIndex(int x, int y)
{
	return y * m_width + x;
}

