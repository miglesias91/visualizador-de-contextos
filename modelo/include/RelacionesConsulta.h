#pragma once

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

// modelo
#include <modelo/include/IRelaciones.h>
#include <modelo/include/IRelacionConConceptos.h>
#include <modelo/include/IRelacionConMedios.h>
#include <modelo/include/IRelacionConSecciones.h>

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
    
    unsigned long long int getRelacionConPeriodo();
    
    unsigned long long int getRelacionConReporte();

    // getters de IAlmacenable

    virtual std::string getValorAlmacenable();

    // SETTERS

    void setRelacionConPeriodo(unsigned long long int id_periodo);

    void setRelacionConReporte(unsigned long long int id_reporte);

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

    unsigned long long int relacion_con_periodo;
    unsigned long long int relacion_con_reporte;
};

};
};
};
