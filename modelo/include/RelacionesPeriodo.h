#pragma once

// stl
#include <functional>

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

// modelo
#include <modelo/include/IRelaciones.h>
#include <modelo/include/IRelacionConConsultas.h>

namespace visualizador
{
namespace modelo
{
namespace relaciones
{

class RelacionesPeriodo : public IRelaciones, IRelacionConConsultas
{
public:
    RelacionesPeriodo(visualizador::aplicacion::ID* id_periodo = NULL);
    virtual ~RelacionesPeriodo();

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

    unsigned long long int relacion_con_fecha_desde;
    unsigned long long int relacion_con_fecha_hasta;

    // RelacionConGrupo * relacion_con_consultas;

};

};
};
};
