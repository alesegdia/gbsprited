#include "drawingcanvas.h"
#include <QDebug>

DrawingCanvas::DrawingCanvas(QWidget* p)
	: QWidget(p)
{
	m_sprite.reset(new Sprite());
	m_sprite->reset(8, 8);
}

DrawingCanvas::~DrawingCanvas()
{

}

QSharedPointer<Sprite> DrawingCanvas::getSprite()
{
	return m_sprite;
}

void DrawingCanvas::setColor(uint8_t color)
{
	m_selectedColor = color;
}

void DrawingCanvas::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.fillRect( 0, 0, this->width(), this->height(), m_bgColor );

	for( int x = 0; x < m_sprite->width(); x++ )
	{
		for( int y = 0; y < m_sprite->height(); y++ )
		{
			uint8_t pixel = m_sprite->get(x, y);
			QColor pixelColor;

			switch( pixel )
			{
			case 0: pixelColor = m_color0; break;
			case 1: pixelColor = m_color1; break;
			case 2: pixelColor = m_color2; break;
			case 3: pixelColor = m_color3; break;
			}

			painter.fillRect( x * m_scale, y * m_scale,
							  m_scale, m_scale, pixelColor );
		}
	}
}

void DrawingCanvas::mousePressEvent(QMouseEvent *e)
{
	m_lastMousePos = QVector2D( e->localPos().x(), e->localPos().y() );
	m_lastButtonPressed = e->button();

	if( Qt::MouseButton::LeftButton == m_lastButtonPressed )
	{
		plotPixel( m_lastMousePos );
	}

}

void DrawingCanvas::mouseReleaseEvent(QMouseEvent *e)
{
	Q_UNUSED(e)
	m_lastButtonPressed = Qt::MouseButton::NoButton;
}

void DrawingCanvas::mouseMoveEvent(QMouseEvent *e)
{
	QVector2D new_mouse_position = QVector2D( e->localPos().x(), e->localPos().y() );
	QVector2D delta = new_mouse_position - m_lastMousePos;

	if( Qt::MouseButton::LeftButton == m_lastButtonPressed )
	{
		plotPixel( new_mouse_position );
	}

	m_lastMousePos = new_mouse_position;
}

void DrawingCanvas::plotPixel(QVector2D click_pos)
{
	float mx, my, rx, ry;
	mx = click_pos.x();
	my = click_pos.y();
	rx = mx / m_scale;
	ry = my / m_scale;

	if( rx < m_sprite->width() && ry < m_sprite->height() && rx >= 0 && ry >= 0 )
	{
		m_sprite->plot(rx, ry, m_selectedColor);
		repaint();
	}
}

void DrawingCanvas::scaleChanged(int new_scale)
{
	m_scale = new_scale;
	repaint();
}

void DrawingCanvas::setColor0()
{
	setColor(0);
}

void DrawingCanvas::setColor1()
{
	setColor(1);
}

void DrawingCanvas::setColor2()
{
	setColor(2);
}

void DrawingCanvas::setColor3()
{
	setColor(3);
}


