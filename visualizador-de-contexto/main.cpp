#include "visualizadordecontexto.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	visualizadordecontexto w;
	w.show();
	return a.exec();
}
