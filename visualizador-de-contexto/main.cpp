
#include <QtWidgets/qapplication.h>
#include <QtWidgets/qpushbutton.h>

int main(int argc, char **argv)
{
	QApplication a(argc, argv);

	//QPushButton hello("Hello world!", 0);
	//hello.resize(100, 30);

	//a.setActiveWindow(&hello);
	//hello.show();
	return a.exec();
}