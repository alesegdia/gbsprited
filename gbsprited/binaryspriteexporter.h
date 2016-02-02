#ifndef BINARYSPRITEEXPORTER_H
#define BINARYSPRITEEXPORTER_H

#include "spriteexporter.h"

#include <QFile>
#include <QDataStream>

class BinarySpriteExporter : public SpriteExporter
{
public:
	BinarySpriteExporter( QSharedPointer<Sprite> sprite, QString outfile );

	void bytesAdded(uint8_t first_byte, uint8_t second_byte)
	{
		m_stream << first_byte << second_byte;
	}

	void newTile()
	{

	}

private:
	QFile m_file;
	QDataStream m_stream;

};

#endif // BINARYSPRITEEXPORTER_H
