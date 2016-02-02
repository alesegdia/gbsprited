#include <QTime>
#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "drawingcanvas.h"
#include "cppspriteexporter.h"
#include "binaryspriteexporter.h"
#include "customspriteexporter.h"
#include "spriteimporter.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	qsrand(QTime::currentTime().msec());

	this->m_newImageDialog = new NewImageDialog();
	this->m_newImageDialog->setSprite(ui->canvasWidget->getSprite());

	QWidget::connect(m_newImageDialog, SIGNAL(spriteSizeChanged()), ui->canvasWidget, SLOT(repaint()));
	QWidget::connect(ui->verticalSlider, SIGNAL(valueChanged(int)), ui->canvasWidget, SLOT(scaleChanged(int)));

	QWidget::connect(ui->color0btn, SIGNAL(pressed()), ui->canvasWidget, SLOT(setColor0()));
	QWidget::connect(ui->color1btn, SIGNAL(pressed()), ui->canvasWidget, SLOT(setColor1()));
	QWidget::connect(ui->color2btn, SIGNAL(pressed()), ui->canvasWidget, SLOT(setColor2()));
	QWidget::connect(ui->color3btn, SIGNAL(pressed()), ui->canvasWidget, SLOT(setColor3()));

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_actionNew_triggered()
{
	this->m_newImageDialog->show();
}

void MainWindow::on_actionC_triggered()
{
	QString str = QFileDialog::getSaveFileName();
	CppSpriteExporter cse( ui->canvasWidget->getSprite(), str );
	cse.run();
}

void MainWindow::on_actionBinary_triggered()
{
	QString str = QFileDialog::getSaveFileName();
	BinarySpriteExporter bse( ui->canvasWidget->getSprite(), str );
	bse.run();
}

void MainWindow::on_actionGBSpritedExport_triggered()
{
	QString str = QFileDialog::getSaveFileName();
	CustomSpriteExporter cse( ui->canvasWidget->getSprite(), str );
	cse.run();
}

void MainWindow::on_actionGBSpritedImport_triggered()
{
	QString str = QFileDialog::getOpenFileName();
	SpriteImporter si( ui->canvasWidget->getSprite(), str );
	si.run();
}

