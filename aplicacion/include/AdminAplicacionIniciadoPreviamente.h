#pragma once

// utiles
#include <utiles/include/Excepcion.h>

namespace visualizador
{
namespace aplicacion
{
namespace excepciones
{

class AdminAplicacionIniciadoPreviamente : public herramientas::utiles::excepciones::Excepcion
{
public:
    AdminAplicacionIniciadoPreviamente(std::string mensaje = "AdminAplicacion iniciado previamente.");
    virtual ~AdminAplicacionIniciadoPreviamente();
};

};
};
};

