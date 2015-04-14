#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../TicTacToe.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_actionRestart_triggered()
{
    TicTacToe::reset();
    TicTacToe::print();
    update();
}
