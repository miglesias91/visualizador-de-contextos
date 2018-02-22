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

class RelacionesMedio : public IRelaciones, public IRelacionConConsultas
{
public:
    RelacionesMedio(herramientas::utiles::ID* id_medio = NULL);
    virtual ~RelacionesMedio();

    // GETTERS

    virtual unsigned long long int getIDMedioAScrapear();

    // getters de IAlmacenable

    virtual std::string getValorAlmacenable();

    // SETTERS

    virtual void setIDMedioAScrapear(unsigned long long int id_medio_a_scrapear);

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

    unsigned long long int id_medio_a_scrapear;

};

};
};
};
