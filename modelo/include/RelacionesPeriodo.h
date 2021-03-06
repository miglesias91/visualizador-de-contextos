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

class RelacionesPeriodo : public IRelaciones, public IRelacionConConsultas
{
public:
    RelacionesPeriodo(herramientas::utiles::ID* id_periodo = NULL);
    virtual ~RelacionesPeriodo();

    // GETTERS

    unsigned long long int getRelacionConFechaDesde();

    unsigned long long int getRelacionConFechaHasta();

    // getters de IAlmacenable

    virtual std::string getValorAlmacenable();

    // SETTERS

    void setRelacionConFechaDesde(unsigned long long int id_fecha_desde);

    void setRelacionConFechaHasta(unsigned long long int id_fecha_hasta);

    // METODOS

    // metodos de IAlmacenable

    virtual void parsearValorAlmacenable(std::string valor_almacenable);

    virtual std::string prefijoGrupo();

    virtual unsigned long long int hashcode();

    // metodos de IContieneJson

    virtual bool armarJson();

    virtual bool parsearJson();

    // metodos de IRelaciones

    virtual IRelaciones * clonar();

    // CONSULTAS

private:

    unsigned long long int relacion_con_fecha_desde;
    unsigned long long int relacion_con_fecha_hasta;

};

};
};
};
