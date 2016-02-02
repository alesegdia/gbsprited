#include "cppspriteexporter.h"

#include <QFile>
#include <QTextStream>

CppSpriteExporter::CppSpriteExporter( QSharedPointer<Sprite> sprite, QString outfile )
	: GBSpriteExporter(sprite), m_file(outfile)
{
	if( m_file.open(QIODevice::ReadWrite) )
	{
		m_stream.setDevice(&m_file);
	}
}

void CppSpriteExporter::notifyBytes(uint8_t first_byte, uint8_t second_byte)
{
	m_stream << "0x" << QString::number(first_byte, 16)  << ", ";
	m_stream << "0x" << QString::number(second_byte, 16) << ", ";
}

void CppSpriteExporter::notifyNewTile()
{
	m_stream << "\n";
}

