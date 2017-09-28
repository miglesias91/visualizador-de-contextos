
// qt
#include <QtWidgets/qapplication.h>

// interfaz usuario
#include <interfaz-usuario/DialogoPrincipal.h>

int main(int argc, char **argv)
{
	QApplication a(argc, argv);

	DialogoPrincipal* ppal = new DialogoPrincipal();

	a.setActiveWindow(ppal);
	ppal->show();
	return a.exec();
}