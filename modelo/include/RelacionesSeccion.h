#pragma once

// stl
#include <functional>

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

// modelo
#include <modelo/include/IRelaciones.h>
#include <modelo/include/RelacionConGrupo.h>

namespace visualizador
{
namespace modelo
{
namespace relaciones
{

class RelacionesSeccion : public IRelaciones
{
public:
    RelacionesSeccion(visualizador::aplicacion::ID* id_seccion = NULL);
    virtual ~RelacionesSeccion();

    // GETTERS

    // getters de IAlmacenable

    virtual std::string getValorAlmacenable();

    // SETTERS

    // METODOS

    // IAlmacenable::

    virtual void parsearValorAlmacenable(std::string valor_almacenable);

    virtual std::string prefijoGrupo();

    virtual unsigned int hashcode();

    // IContieneJson::

    virtual void crearContenido();

    virtual bool parsearContenido(IJson * contenido);

private:

    RelacionConGrupo * relacion_con_consultas;
};

};
};
};
