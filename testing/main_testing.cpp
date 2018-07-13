
// gtest
#include <gtest/gtest.h>

#ifdef DEBUG || _DEBUG

// vld
#include <vld.h>

#endif // DEBUG || _DEBUG

// scraping
#include <scraping/include/IAdministradorScraping.h>
#include <scraping/include/ConfiguracionScraping.h>

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

using namespace visualizador;

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);

    // INICIO APP

    //aplicacion::ConfiguracionAplicacion::leerConfiguracion("config_testing.json");

    //aplicacion::IAdministradorAplicacion::crearAdministradorAplicacionLocal();
    aplicacion::IAdministradorAplicacion::iniciar("config_testing.json");
    aplicacion::IAdministradorAplicacion::getInstanciaAdminEntidades()->abrirBD();

    // INICIO INFO SCRAPING

    // INIT INFO SCRAPING
    //scraping::ConfiguracionScraping::leerConfiguracion("config_scraping.json");

    //scraping::IAdministradorScraping::crearAdministradorScrapingLocal();

    scraping::IAdministradorScraping::iniciar("config_scraping.json");
    scraping::IAdministradorScraping::getInstanciaAdminResultadosDiarios()->abrirBD();
    //scraping::IAdministradorScraping::getInstanciaAdminInfo()->abrirBD();

	int result = RUN_ALL_TESTS();

    // CIERO INFO SCRAPING
    //scraping::IAdministradorScraping::getInstanciaAdminInfo()->cerrarBD();
    //scraping::IAdministradorScraping::getInstanciaAdminResultadosAnalisisDiario()->cerrarBD();
    scraping::IAdministradorScraping::getInstanciaAdminResultadosDiarios()->cerrarBD();

    // CIERRO APP

    aplicacion::IAdministradorAplicacion::getInstanciaAdminEntidades()->cerrarBD();
    aplicacion::IAdministradorAplicacion::getInstanciaAdminEntidades()->borrarBD();

    // LIBERO MEMORIA DE APP Y SCRAPING
    scraping::IAdministradorScraping::liberar();

    // 'aplicacion::IAdministradorAplicacion::liberar()' debe ir ULTIMO POR ES EL Q LIBERA TODOS LOS LOGGERS.
    aplicacion::IAdministradorAplicacion::liberar();

	std::getchar();

	return result;
}