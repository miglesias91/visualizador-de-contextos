#pragma once

// modelo
#include <modelo/include/IRelaciones.h>

namespace visualizador
{
namespace modelo
{
namespace relaciones
{

class RelacionesTermino : public IRelaciones
{
public:

    // CONSTRUCTORES

    RelacionesTermino();
    virtual ~RelacionesTermino();

    // GETTERS

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

    RelacionConConsultas * relacion_con_consultas;
};

};
};
};

