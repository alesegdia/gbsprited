#ifndef CPPSPRITEEXPORTER_H
#define CPPSPRITEEXPORTER_H

#include <QString>
#include <QFile>
#include <QTextStream>

#include "gbspriteexporter.h"

class CppSpriteExporter : public GBSpriteExporter
{
public:
	CppSpriteExporter( QSharedPointer<Sprite> sprite, QString outfile );

	void notifyBytes(uint8_t first_byte, uint8_t second_byte) override;
	void notifyNewTile() override;

private:
	QFile m_file;
	QTextStream m_stream;

};

#endif // CPPSPRITEEXPORTER_H
