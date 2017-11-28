#pragma once

// stl
#include <functional>

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

// modelo
#include <modelo/include/IRelaciones.h>
#include <modelo/include/IRelacionConConceptos.h>

#include <modelo/include/RelacionConGrupo.h>

namespace visualizador
{
namespace modelo
{
namespace relaciones
{

class RelacionesConsulta : public IRelaciones, public IRelacionConConceptos, public IRelacionConMedios, public IRelacionConSecciones
{
public:
    RelacionesConsulta(visualizador::aplicacion::ID* id_consulta = NULL);
    virtual ~RelacionesConsulta();

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

    unsigned long long int relacion_con_periodo;
    unsigned long long int relacion_con_reporte;

    RelacionConGrupo * relacion_con_medios;
    RelacionConGrupo * relacion_con_secciones;
};

};
};
};
