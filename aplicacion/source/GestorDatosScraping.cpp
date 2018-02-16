#include <aplicacion/include/GestorDatosScraping.h>

using namespace visualizador::aplicacion;

GestorDatosScraping::GestorDatosScraping()
{
    this->admin_datos_scraping = IAdministradorAplicacion::getInstanciaAdminDatosScraping();
}

GestorDatosScraping::~GestorDatosScraping()
{
}
