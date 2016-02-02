#ifndef SPRITEEXPORTER_H
#define SPRITEEXPORTER_H

#include <QSharedPointer>
#include "sprite.h"

class SpriteExporter
{
public:
	SpriteExporter(QSharedPointer<Sprite> sprite);

	void run();
	virtual void notifySize( int width, int height ) = 0;
	virtual void notifyValue( uint8_t value ) = 0;

private:
	QSharedPointer<Sprite> m_sprite;

};

#endif // SPRITEEXPORTER_H
