#ifndef ISPRITEEXPORTER_H
#define ISPRITEEXPORTER_H

#include <QString>

class ISpriteExporter
{
public:
	ISpriteExporter();
	virtual ~ISpriteExporter() = 0 ;

	virtual void xport(QString outfile) = 0 ;
};

#endif // ISPRITEEXPORTER_H
