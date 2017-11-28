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
            
class RelacionesConcepto : public IRelaciones
{
public:
    RelacionesConcepto(visualizador::aplicacion::ID* id_concepto = NULL);
    virtual ~RelacionesConcepto();

    // GETTERS

    virtual RelacionConGrupo * getRelacionConTerminos();

    virtual RelacionConGrupo * getRelacionConConsultas();

    // getters de IAlmacenable

    virtual std::string getValorAlmacenable();

    // SETTERS

    // METODOS

    virtual void agregarRelacionConTermino(visualizador::aplicacion::ID * id_termino);

    virtual void agregarRelacionConConsulta(visualizador::aplicacion::ID * id_consulta);

    virtual void eliminarRelacionConTermino(visualizador::aplicacion::ID * id_termino);

    virtual void eliminarRelacionConConsulta(visualizador::aplicacion::ID * id_consulta);

    // IAlmacenable::

    virtual void parsearValorAlmacenable(std::string valor_almacenable);

    virtual std::string prefijoGrupo();

    virtual unsigned int hashcode();

    // IContieneJson::

    virtual void crearContenido();

    virtual bool parsearContenido(IJson * contenido);

private:

    RelacionConGrupo * relacion_con_terminos;
    RelacionConGrupo * relacion_con_consultas;
};

};
};
};

