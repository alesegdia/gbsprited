#ifndef CUSTOMSPRITEEXPORTER_H
#define CUSTOMSPRITEEXPORTER_H

#include <QFile>
#include <QDataStream>

#include "spriteexporter.h"

class CustomSpriteExporter : public SpriteExporter
{
public:
	CustomSpriteExporter( QSharedPointer<Sprite> sprite, QString outfile );

	void notifySize(int width, int height);
	void notifyValue(uint8_t value);

private:
	QFile m_file;
	QDataStream m_stream;

};

#endif // CUSTOMSPRITEEXPORTER_H
