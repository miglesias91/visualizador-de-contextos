#include "visualizadordecontexto.h"
#include <QtWidgets/QApplication>

// scraping
#include <scraping/include/IAdministradorScraping.h>
#include <scraping/include/ConfiguracionScraping.h>

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>
#include <aplicacion/include/GestorEntidades.h>
#include <aplicacion/include/Logger.h>

// vld
#ifdef DEBUG | _DEBUG
#include <vld.h>
#endif

using namespace visualizador;

int main(int argc, char *argv[])
{
    // INIT APP
    try
    {
        aplicacion::IAdministradorAplicacion::iniciar("config_aplicacion.json");
        aplicacion::IAdministradorAplicacion::getInstanciaAdminEntidades()->abrirBD();
        aplicacion::IAdministradorAplicacion::getInstanciaAdminEntidades()->recuperarIDActual();
    }
    catch (herramientas::utiles::excepciones::Excepcion & e)
    {
        throw;
    }

    // INIT INFO SCRAPING
    try
    {
        //scraping::IAdministradorScraping::iniciar("config_scraping.json");

        ////scraping::IAdministradorScraping::getInstanciaAdminInfo()->abrirBD();
        ////scraping::IAdministradorScraping::getInstanciaAdminInfo()->recuperarIDsActuales();

        //scraping::IAdministradorScraping::getInstanciaAdminResultadosDiarios()->abrirBD();
        //scraping::IAdministradorScraping::getInstanciaAdminResultadosDiarios()->recuperarIDsActuales();
    }
    catch (herramientas::utiles::excepciones::Excepcion & e)
    {
        throw;
    }

    // LANZAMIENTO INTERFAZ QT
	QApplication qt_app(argc, argv);
    visualizadordecontexto * visu = new visualizadordecontexto();
    visu->show();
	int retorno = qt_app.exec();

    delete visu;

    // CIERRE INFO SCRAPING
    //scraping::IAdministradorScraping::getInstanciaAdminResultadosDiarios()->cerrarBD();
    //scraping::IAdministradorScraping::getInstanciaAdminResultadosDiarios()->almacenarIDsActuales();

    //scraping::IAdministradorScraping::getInstanciaAdminInfo()->almacenarIDsActuales();
    //scraping::IAdministradorScraping::getInstanciaAdminInfo()->cerrarBD();

    //scraping::IAdministradorScraping::liberar();

	// CIERRE APP
    aplicacion::IAdministradorAplicacion::getInstanciaAdminEntidades()->cerrarBD();
	aplicacion::IAdministradorAplicacion::liberar();

	return retorno;
}
