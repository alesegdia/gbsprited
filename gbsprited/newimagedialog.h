#ifndef NEWIMAGEDIALOG_H
#define NEWIMAGEDIALOG_H

#include <QDialog>
#include <QDebug>

#include "sprite.h"

namespace Ui {
class NewImageDialog;
}

class NewImageDialog : public QDialog
{
	Q_OBJECT

public:
	explicit NewImageDialog(QWidget *parent = 0);
	~NewImageDialog();

	void setSprite( QSharedPointer<Sprite> sprite );

signals:
	void spriteSizeChanged();

public slots:
	void accept() override;

private:
	Ui::NewImageDialog *ui;
	QSharedPointer<Sprite> m_sprite;

};

#endif // NEWIMAGEDIALOG_H
