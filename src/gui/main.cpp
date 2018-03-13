#include "screen.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	screen w;
	w.show();
	return a.exec();
}
