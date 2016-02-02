#include "binaryspriteexporter.h"

BinarySpriteExporter::BinarySpriteExporter(QSharedPointer<Sprite> sprite, QString outfile)
	: GBSpriteExporter(sprite), m_file(outfile)
{
	if( m_file.open(QIODevice::ReadWrite) )
	{
		m_stream.setDevice(&m_file);
	}
}

void BinarySpriteExporter::notifyBytes(uint8_t first_byte, uint8_t second_byte)
{
	m_stream << first_byte << second_byte;
}

void BinarySpriteExporter::notifyNewTile()
{

}

