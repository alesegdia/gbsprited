#ifndef DRAWINGCANVAS_H
#define DRAWINGCANVAS_H

#include <QWidget>
#include <QPainter>
#include <QColor>
#include <QSize>
#include <QSharedPointer>
#include <QMouseEvent>
#include <QDebug>

#include "sprite.h"

class DrawingCanvas : public QWidget
{
public:
	DrawingCanvas(QWidget* p);
	QSharedPointer<Sprite> getSprite();
	void setColor( uint8_t color );

protected:
	void paintEvent(QPaintEvent *event);

	void mousePressEvent(QMouseEvent *e) override;
	void mouseReleaseEvent(QMouseEvent *e) override;
	void mouseMoveEvent(QMouseEvent *e) override;

	void plotPixel( QVector2D click_pos );


private:
	QSharedPointer<Sprite> m_sprite;
	int m_scale = 20;

	//QColor m_bgColor = QColor(0x73, 0x00, 0x2e, 0xff);
	QColor m_bgColor = QColor(0, 0, 0, 0xff);
	QColor m_color0 = QColor(0xb2, 0xbd, 0x80, 0xff);
	QColor m_color1 = QColor(0x8b, 0xac, 0x0f, 0xff);
	QColor m_color2 = QColor(0x30, 0x62, 0x30, 0xff);
	QColor m_color3 = QColor(0x0f, 0x38, 0x0f, 0xff);
	uint8_t m_selectedColor = 0;

	Qt::MouseButton m_lastButtonPressed = Qt::MouseButton::NoButton;
	QVector2D m_lastMousePos;

};

#endif // DRAWINGCANVAS_H
