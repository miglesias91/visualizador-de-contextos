#include "visualizadordecontexto.h"
#include <QtWidgets/QApplication>

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>
#include <aplicacion/include/GestorEntidades.h>
#include <aplicacion/include/GestorIDs.h>

// vld
#include <vld.h>

using namespace visualizador;

int main(int argc, char *argv[])
{
	// INIT APP
	aplicacion::ConfiguracionAplicacion::leerConfiguracion("configuracion_aplicacion.json");
	aplicacion::IAdministradorAplicacion::crearAdministradorAplicacionLocal();

	// LANZAMIENTO INTERFAZ QT
	QApplication a(argc, argv);
	visualizadordecontexto w;
	w.show();
	int retorno = a.exec();

	// CIERRE APP
	aplicacion::IAdministradorAplicacion::liberar();

	return retorno;
}
