#include "visualizadordecontexto.h"
#include <QtWidgets/QApplication>

// utiles
#include <log/include/AdministradorLog.h>

// medios
#include <noticias/include/config.h>

// scraping
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
    aplicacion::Logger::iniciar("log_aplicacion.json");
    aplicacion::Logger::info("INICIO APP");

    // INIT APP
    try
    {
        aplicacion::IAdministradorAplicacion::iniciar("config_aplicacion.json");
        aplicacion::IAdministradorAplicacion::getInstanciaAdminEntidades()->abrirBD();
        aplicacion::IAdministradorAplicacion::getInstanciaAdminEntidades()->recuperarIDActual();

        aplicacion::IAdministradorAplicacion::getInstanciaAdminResultados()->abrirBD();
    }
    catch (herramientas::utiles::excepciones::Excepcion & e)
    {
        throw;
    }

    // INIT INFO SCRAPING
    try
    {
        scraping::ConfiguracionScraping::leerConfiguracion(aplicacion::ConfiguracionAplicacion::pathConfiguracionScraping());
        medios::noticias::config::levantar(aplicacion::ConfiguracionAplicacion::pathConfiguracionNoticias());
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

	// CIERRE APP
    aplicacion::IAdministradorAplicacion::getInstanciaAdminEntidades()->almacenarIDActual();
    aplicacion::IAdministradorAplicacion::getInstanciaAdminEntidades()->cerrarBD();

    aplicacion::IAdministradorAplicacion::getInstanciaAdminResultados()->cerrarBD();
	aplicacion::IAdministradorAplicacion::liberar();

	return retorno;
}
