#ifndef SPRITEEXPORTER_H
#define SPRITEEXPORTER_H

#include <QString>
#include <QSharedPointer>

#include "sprite.h"

class SpriteExporter
{
public:
	SpriteExporter( QSharedPointer<Sprite> sprite );
	virtual ~SpriteExporter() = 0 ;

	void run();

	virtual void bytesAdded( uint8_t first_byte, uint8_t second_byte ) = 0;
	virtual void newTile() = 0;

private:
	QSharedPointer<Sprite> m_sprite;

};

#endif // SPRITEEXPORTER_H
