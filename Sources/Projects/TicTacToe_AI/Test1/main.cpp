#include <QtWidgets/QApplication>
#include "Gui/mainwindow.h"
#include <ctime>

int main(int argc, char* argv[])
{
    srand(time(0));
	QApplication a(argc, argv);

	MainWindow w;
	w.show();

	return a.exec();
}
