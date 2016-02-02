#ifndef GBSPRITEEXPORTER_H
#define GBSPRITEEXPORTER_H

#include <QString>
#include <QSharedPointer>

#include "sprite.h"

class GBSpriteExporter
{
public:
	GBSpriteExporter( QSharedPointer<Sprite> sprite );
	virtual ~GBSpriteExporter() = 0 ;

	void run();

	virtual void notifyBytes( uint8_t first_byte, uint8_t second_byte ) = 0;
	virtual void notifyNewTile() = 0;

private:
	QSharedPointer<Sprite> m_sprite;

};

#endif // GBSPRITEEXPORTER_H
