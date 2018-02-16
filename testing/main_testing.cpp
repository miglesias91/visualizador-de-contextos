
// gtest
#include <gtest/gtest.h>

// vld
#include <vld.h>

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

using namespace visualizador;

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);

    aplicacion::ConfiguracionAplicacion::leerConfiguracion("config_testing.json");

    aplicacion::IAdministradorAplicacion::crearAdministradorAplicacionLocal();

    aplicacion::IAdministradorAplicacion::getInstanciaAdminEntidades()->abrirBD();

	int result = RUN_ALL_TESTS();

    aplicacion::IAdministradorAplicacion::getInstanciaAdminEntidades()->cerrarBD();

    aplicacion::IAdministradorAplicacion::liberar();

	std::getchar();

	return result;
}