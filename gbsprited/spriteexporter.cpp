#include "spriteexporter.h"



SpriteExporter::SpriteExporter(QSharedPointer<Sprite> sprite)
{
	m_sprite = sprite;
}

void SpriteExporter::run()
{
	int width = m_sprite->width();
	int height = m_sprite->height();

	notifySize( width, height );

	for( int y = 0; y < m_sprite->height(); y++ )
	{
		for( int x = 0; x < m_sprite->width(); x++ )
		{
			uint8_t value = m_sprite->get(x, y);
			notifyValue(value);
		}
	}
}
