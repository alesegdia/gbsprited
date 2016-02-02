#include "customspriteexporter.h"

CustomSpriteExporter::CustomSpriteExporter(QSharedPointer<Sprite> sprite, QString outfile)
	: SpriteExporter(sprite), m_file(outfile)
{
	if( m_file.open(QIODevice::ReadWrite) )
	{
		m_stream.setDevice(&m_file);
	}
}

void CustomSpriteExporter::notifySize(int width, int height)
{
	uint8_t w = width / 8;
	m_stream << w;
}

void CustomSpriteExporter::notifyValue(uint8_t value)
{
	m_stream << value;
}

