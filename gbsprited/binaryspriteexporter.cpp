#include "binaryspriteexporter.h"

BinarySpriteExporter::BinarySpriteExporter(QSharedPointer<Sprite> sprite, QString outfile)
	: SpriteExporter(sprite), m_file(outfile)
{
	if( m_file.open(QIODevice::ReadWrite) )
	{
		m_stream.setDevice(&m_file);
	}
}

