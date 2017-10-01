
// qt
#include <QtWidgets/qapplication.h>

// interfaz usuario
#include <interfaz-usuario/ventanaprincipal.h>

int main(int argc, char **argv)
{
	QApplication a(argc, argv);
	VentanaPrincipal w;
	w.show();

	return a.exec();
}