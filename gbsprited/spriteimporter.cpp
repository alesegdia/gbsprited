#include "spriteimporter.h"

SpriteImporter::SpriteImporter(QSharedPointer<Sprite> sprite, QString infile)
	: m_sprite(sprite), m_file(infile)
{
	if( m_file.open(QIODevice::ReadWrite) )
	{
		m_stream.setDevice(&m_file);
	}
}

void SpriteImporter::run()
{
	uint8_t width_in_tiles = 0;
	m_stream >> width_in_tiles;
	QVector<uint8_t> pixel_data;

	while( !m_stream.atEnd() )
	{
		uint8_t byte;
		m_stream >> byte;
		pixel_data.append(byte);
	}

	int total_tiles = pixel_data.size() / 8;
	int height_in_tiles = total_tiles / width_in_tiles;

	m_sprite->m_height = height_in_tiles;
	m_sprite->m_width = width_in_tiles * 8;

	m_sprite->m_data = pixel_data;
}

