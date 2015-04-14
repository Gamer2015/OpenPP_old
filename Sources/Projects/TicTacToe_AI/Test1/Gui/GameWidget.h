#ifndef GAME_WDIGET_H_
#define GAME_WDIGET_H_

#include <QPainter>
#include <QStyleOption>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QWidget>

class GameWidget : public QWidget
{
	Q_OBJECT

public:
	explicit GameWidget(QWidget *parent = 0);

protected:
	void mousePressEvent(QMouseEvent*);
	void paintEvent(QPaintEvent*);
};

#endif // GAME_WDIGET_H_
