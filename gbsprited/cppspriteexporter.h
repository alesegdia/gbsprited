#ifndef CPPSPRITEEXPORTER_H
#define CPPSPRITEEXPORTER_H

#include <QSharedPointer>
#include <QString>

#include "sprite.h"
#include "ispriteexporter.h"

class CppSpriteExporter : public ISpriteExporter
{
public:
	CppSpriteExporter( QSharedPointer<Sprite> sprite );

	void xport( QString outfile ) override;

private:
	QSharedPointer<Sprite> m_sprite;

};

#endif // CPPSPRITEEXPORTER_H
