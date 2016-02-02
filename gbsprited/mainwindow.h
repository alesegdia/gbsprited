#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include "newimagedialog.h"
#include "sprite.h"
#include "drawingcanvas.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_actionNew_triggered();
	void on_actionC_triggered();
	void on_actionBinary_triggered();
	void setColor0();
	void setColor1();
	void setColor2();
	void setColor3();

private:
	Ui::MainWindow *ui;
	NewImageDialog* m_newImageDialog;
	QSharedPointer<Sprite> m_sprite;

};

#endif // MAINWINDOW_H
