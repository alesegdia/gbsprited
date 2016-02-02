#include <QMessageBox>

#include "newimagedialog.h"
#include "ui_newimagedialog.h"

NewImageDialog::NewImageDialog(QWidget *parent) :
	QDialog(parent), ui(new Ui::NewImageDialog)
{
	ui->setupUi(this);
}

NewImageDialog::~NewImageDialog()
{
	delete ui;
}

void NewImageDialog::setSprite(QSharedPointer<Sprite> sprite)
{
	m_sprite = sprite;
}

void NewImageDialog::accept()
{
	int width = ui->widthEdit->text().toInt();
	int height = ui->heightEdit->text().toInt();

	const int GB_MAX_TILE_SIZE = 8;
	m_sprite->reset( width * GB_MAX_TILE_SIZE, height * GB_MAX_TILE_SIZE );

	QDialog::accept();
	emit spriteSizeChanged();
}
