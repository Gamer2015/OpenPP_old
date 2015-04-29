#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidgetItem>
#include <QMainWindow>
#include <QImage>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsPixmapItem>

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
	void paintEvent(QPaintEvent *);

	void on_spinBox_valueChanged(int arg1);

private:
	Ui::MainWindow *ui;

	std::vector<int> numbers;
	std::vector<QPixmap> images;
	int i;
};

#endif // MAINWINDOW_H
