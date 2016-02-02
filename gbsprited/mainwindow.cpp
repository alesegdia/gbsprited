#include <QTime>
#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "drawingcanvas.h"
#include "cppspriteexporter.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	qsrand(QTime::currentTime().msec());

	this->m_newImageDialog = new NewImageDialog();
	this->m_newImageDialog->setSprite(ui->canvasWidget->getSprite());

	QWidget::connect(m_newImageDialog, SIGNAL(spriteSizeChanged()), ui->canvasWidget, SLOT(repaint()));

	QWidget::connect(ui->color0btn, SIGNAL(pressed()), this, SLOT(setColor0()));
	QWidget::connect(ui->color1btn, SIGNAL(pressed()), this, SLOT(setColor1()));
	QWidget::connect(ui->color2btn, SIGNAL(pressed()), this, SLOT(setColor2()));
	QWidget::connect(ui->color3btn, SIGNAL(pressed()), this, SLOT(setColor3()));

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

void MainWindow::setColor0()
{
	ui->canvasWidget->setColor(0);
}

void MainWindow::setColor1()
{
	ui->canvasWidget->setColor(1);
}

void MainWindow::setColor2()
{
	ui->canvasWidget->setColor(2);
}

void MainWindow::setColor3()
{
	ui->canvasWidget->setColor(3);
}

