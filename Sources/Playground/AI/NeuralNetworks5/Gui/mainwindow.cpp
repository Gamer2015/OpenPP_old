#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	i(0)
{
	ui->setupUi(this);

	const int width = 28;
	const int height = 28 * 60000;
	const int area = width * height;

	std::ifstream file("t10k-images.idx3-ubyte", std::ios::binary);
	if(file.is_open())
	{
		file.seekg(0, std::ios::end);
		int count = file.tellg();
		file.seekg(0, std::ios::beg);
		char* picture = new char[area];

		file.seekg(16, std::ios::beg); // offset
		while(file.tellg() < count)
		{
			file.read(picture, area);
			images.push_back(QPixmap::fromImage(QImage((uchar*)picture, width, height, QImage::Format_Indexed8, nullptr, nullptr )));
		}
	}
	file.close();
	std::cout << images.size() << std::endl;

	file.open("t10k-labels.idx1-ubyte", std::ios::binary);
	if(file.is_open())
	{
		file.seekg(0, std::ios::end);
		int count = file.tellg();
		file.seekg(0, std::ios::beg);
		char number;

		file.seekg(8, std::ios::beg); // offset
		while(file.tellg() < count)
		{
			file.read(&number, 1);
			numbers.push_back(number);
		}
	}
	file.close();
	std::cout << numbers.size() << std::endl;
	ui->lblNumber->setText(QString(std::to_string(numbers[i]).c_str()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
	std::cout << "painting " << i << std::endl;
	QPainter painter(this);
	painter.drawPixmap(5, 5, 28, 28, images[i]);
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
	i = arg1;
	if(i >= images.size())
		i = images.size() - 1;
	ui->lblNumber->setText(QString(std::to_string(numbers[i]).c_str()));
	update();
}
