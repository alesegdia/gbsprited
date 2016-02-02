#include "spriteexporter.h"

SpriteExporter::SpriteExporter(QSharedPointer<Sprite> sprite)
{
	m_sprite = sprite;
}

void SpriteExporter::run()
{
	for( int tx = 0; tx < m_sprite->width() / 8; tx++ )
	{
		for( int ty = 0; ty < m_sprite->height() / 8; ty++ )
		{
			for( int y = 0; y < 8; y++ )
			{
				uint8_t row_first = 0;
				uint8_t row_second = 0;
				for( int x = 0; x < 8; x++ )
				{
					int rx = tx * 8 + x;
					int ry = ty * 8 + y;
					uint8_t value = m_sprite->get(rx, ry);
					uint8_t bit_first  = value & 0b01;
					uint8_t bit_second = (value & 0b10) >> 1;

					row_first  |= bit_first  << (x + 1);
					row_second |= bit_second << (x + 1);
				}
				bytesAdded( row_first, row_second );
			}
			newTile();
		}
	}
}

SpriteExporter::~SpriteExporter()
{

}

