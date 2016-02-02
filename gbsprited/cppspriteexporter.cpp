#include "cppspriteexporter.h"

#include <QFile>
#include <QTextStream>

CppSpriteExporter::CppSpriteExporter( QSharedPointer<Sprite> sprite )
{
	m_sprite = sprite;
}

void CppSpriteExporter::xport(QString outfile)
{
	QFile file(outfile);
	if( file.open(QIODevice::ReadWrite) )
	{
		QTextStream stream(&file);
		stream << "mehhh";
	}
}

