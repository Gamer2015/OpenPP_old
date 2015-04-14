#include "GameWidget.h"
#include "../TicTacToe.h"
#include <iostream>

GameWidget::GameWidget(QWidget *parent) :
	QWidget(parent)
{
	this->setStyleSheet("background-color:white;");
}

void GameWidget::mousePressEvent(QMouseEvent *event)
{
	int x = 3.0 * event->x() / this->size().width();
	int y = 3.0 * event->y() / this->size().height();

    static int tile = TicTacToe::TILE_X;

    int p1move;
    int p2move;
    int* last_move = &p1move;

    p1move = TicTacToe::set(x, y, tile);

    if(p1move) {
        p2move = TicTacToe::learn_move();
        if(p2move == true)
            last_move = &p2move;
    }

    if(p1move)
    {
        int winner = TicTacToe::check_winner();

        if(winner != 0)
        {
            if(winner < 2)
                std::cout << "player " << winner << " wins!" << std::endl;
            else
                std::cout << "draw" << std::endl;
            TicTacToe::save_game();
        }
    }

    TicTacToe::print();

    update();
}

void GameWidget::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter painter(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

	painter.setPen(QPen(Qt::black, 3, Qt::SolidLine));

	int width = this->size().width();
	int height = this->size().height();
	int width_3 = width / 3;
	int height_3 = height / 3;

	for(int x = 1; x < 3; ++x)
		painter.drawLine(x * width_3, 0, x * width_3, height);
	for(int y = 1; y < 3; ++y)
		painter.drawLine(0, y * height_3, width, y * height_3);

	for(int x = 0; x < 3; ++x)
		for(int y = 0; y < 3; ++y)
		{
            if(TicTacToe::game_data()[3*x + y] == 0)
				continue;

            else if(TicTacToe::game_data()[3*x + y] == TicTacToe::TILE_O)
				painter.drawEllipse(QPoint(width_3 * x + width_3 / 2, height_3 * y + height_3 / 2), height_3 / 2 - 10, width_3 / 2 - 10);

            else if(TicTacToe::game_data()[3*x + y] == TicTacToe::TILE_X)
			{
				painter.drawLine(QPoint(width_3 * x + 10, height_3 * y + 10), QPoint(width_3 * (x+1) - 10, height_3 * (y+1) - 10));
				painter.drawLine(QPoint(width_3 * (x+1) - 10, height_3 * y + 10), QPoint(width_3 * x + 10, height_3 * (y+1) - 10));
			}
		}
}
