#ifndef BINARYSPRITEEXPORTER_H
#define BINARYSPRITEEXPORTER_H

#include "gbspriteexporter.h"

#include <QFile>
#include <QDataStream>

class BinarySpriteExporter : public GBSpriteExporter
{
public:
	BinarySpriteExporter( QSharedPointer<Sprite> sprite, QString outfile );

	void notifyBytes(uint8_t first_byte, uint8_t second_byte);
	void notifyNewTile();

private:
	QFile m_file;
	QDataStream m_stream;

};

#endif // BINARYSPRITEEXPORTER_H
