#ifndef CPPSPRITEEXPORTER_H
#define CPPSPRITEEXPORTER_H

#include <QString>
#include <QFile>
#include <QTextStream>

#include "spriteexporter.h"

class CppSpriteExporter : public SpriteExporter
{
public:
	CppSpriteExporter( QSharedPointer<Sprite> sprite, QString outfile );

	void bytesAdded(uint8_t first_byte, uint8_t second_byte) override;
	void newTile() override;

private:
	QFile m_file;
	QTextStream m_stream;

};

#endif // CPPSPRITEEXPORTER_H
