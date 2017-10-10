
// qt
#include <QtWidgets/qapplication.h>

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>
#include <aplicacion/include/IAdministradorAplicacion.h>

// interfaz usuario
#include <interfaz-qt/ventanaprincipal.h>

int main(int argc, char **argv)
{
	// INICIO APLICACION
	visualizador::aplicacion::ConfiguracionAplicacion::leerConfiguracion("configuracion_aplicacion.json");
	
	visualizador::aplicacion::IAdministradorAplicacion::crearAdministradorAplicacionLocal();

	// LANZAMIENTO INTERFAZ QT
	QApplication a(argc, argv);
	VentanaPrincipal w;
	w.show();

	int retorno = a.exec();

	// CIERRE APLICACION


}