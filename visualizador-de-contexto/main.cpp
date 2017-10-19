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
	aplicacion::IAdministradorAplicacion::iniciar("configuracion_aplicacion.json");
	aplicacion::IAdministradorAplicacion::getInstancia()->abrirBD();
	aplicacion::IAdministradorAplicacion::getInstancia()->recuperarIDActual();

	// LANZAMIENTO INTERFAZ QT
	QApplication a(argc, argv);
	visualizadordecontexto w;
	w.show();
	int retorno = a.exec();

	// CIERRE APP
	aplicacion::IAdministradorAplicacion::getInstancia()->cerrarBD();
	aplicacion::IAdministradorAplicacion::liberar();

	return retorno;
}
