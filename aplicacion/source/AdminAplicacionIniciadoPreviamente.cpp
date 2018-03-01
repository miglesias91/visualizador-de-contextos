#include <aplicacion/include/AdminAplicacionIniciadoPreviamente.h>

using namespace visualizador::aplicacion::excepciones;

AdminAplicacionIniciadoPreviamente::AdminAplicacionIniciadoPreviamente(std::string mensaje) : herramientas::utiles::excepciones::Excepcion(mensaje)
{
}

AdminAplicacionIniciadoPreviamente::~AdminAplicacionIniciadoPreviamente()
{
}
