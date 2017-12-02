#pragma once

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

class RelacionesReporte : public IRelaciones, public IRelacionConConsultas
{
public:
    RelacionesReporte(visualizador::aplicacion::ID* id_reporte = NULL);
    virtual ~RelacionesReporte();

    // GETTERS

    // getters de IAlmacenable

    virtual std::string getValorAlmacenable();

    // SETTERS

    // METODOS

    // metodos de IAlmacenable

    virtual void parsearValorAlmacenable(std::string valor_almacenable);

    virtual std::string prefijoGrupo();

    virtual unsigned int hashcode();

    // metodos de IContieneJson

    virtual void crearJson();

    virtual bool parsearJson(IJson * json);

    // metodos de IRelaciones

    virtual IRelaciones * clonar();

    // CONSULTAS

private:

};

};
};
};
