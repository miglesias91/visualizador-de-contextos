#include "visualizadordecontexto.h"
#include <QtWidgets/QApplication>

// scraping
#include <scraping/include/IAdministradorScraping.h>
#include <scraping/include/ConfiguracionScraping.h>

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>
#include <aplicacion/include/GestorEntidades.h>

// vld

#ifdef DEBUG | _DEBUG
#include <vld.h>
#endif

using namespace visualizador;

int main(int argc, char *argv[])
{
	// INIT APP
	aplicacion::IAdministradorAplicacion::iniciar("config_visualizador-de-contexto.json");
	aplicacion::IAdministradorAplicacion::getInstanciaAdminEntidades()->abrirBD();
	aplicacion::IAdministradorAplicacion::getInstanciaAdminEntidades()->recuperarIDActual();

    // INIT INFO SCRAPING
    scraping::ConfiguracionScraping::leerConfiguracion("config_scraping.json");

    scraping::IAdministradorScraping::crearAdministradorScrapingLocal();

    scraping::IAdministradorScraping::getInstanciaAdminInfo()->abrirBD();
    scraping::IAdministradorScraping::getInstanciaAdminInfo()->recuperarIDsActuales();

    scraping::IAdministradorScraping::getInstanciaAdminResultadosAnalisisDiario()->abrirBD();

    // LANZAMIENTO INTERFAZ QT
	QApplication a(argc, argv);
	visualizadordecontexto w;
	w.show();
	int retorno = a.exec();

    // CIERRE INFO SCRAPING
    scraping::IAdministradorScraping::getInstanciaAdminResultadosAnalisisDiario()->cerrarBD();

    scraping::IAdministradorScraping::getInstanciaAdminInfo()->almacenarIDsActuales();
    scraping::IAdministradorScraping::getInstanciaAdminInfo()->cerrarBD();

    scraping::IAdministradorScraping::liberar();

	// CIERRE APP
    aplicacion::IAdministradorAplicacion::getInstanciaAdminEntidades()->cerrarBD();
	aplicacion::IAdministradorAplicacion::liberar();

	return retorno;
}
