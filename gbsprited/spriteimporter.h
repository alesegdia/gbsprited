#ifndef SPRITEIMPORTER_H
#define SPRITEIMPORTER_H

#include <QSharedPointer>
#include <QFile>
#include <QDataStream>
#include <QDebug>

#include "sprite.h"

class SpriteImporter
{
public:
	SpriteImporter( QSharedPointer<Sprite> sprite, QString infile );
	void run();

private:
	QSharedPointer<Sprite> m_sprite;
	QFile m_file;
	QDataStream m_stream;

};

#endif // SPRITEIMPORTER_H
