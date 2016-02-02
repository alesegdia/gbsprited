#ifndef SPRITE_H
#define SPRITE_H

#include <QVector>
#include <stdint.h>

class Sprite
{

public:

	friend class SpriteImporter;

	Sprite();

	/**
	 * @brief resets the sprite size with all pixels reset to zero
	 * @param width
	 * @param height
	 */
	void reset( int width, int height );

	/**
	 * @brief gets the pixel at specified position
	 * @param x coordinate
	 * @param y coordinate
	 * @return the pixel value
	 */
	uint8_t get( int x, int y );

	/**
	 * @brief plots a pixel at specified position
	 * @param x coordinate
	 * @param y coordinate
	 * @param the pixel value
	 */
	void plot( int x, int y, uint8_t value );

	int width();
	int height();

private:
	QVector<uint8_t> m_data;
	int m_width, m_height;

	int coordToIndex( int x, int y );

};

#endif // SPRITE_H
