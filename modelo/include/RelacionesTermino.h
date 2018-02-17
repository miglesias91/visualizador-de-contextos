#pragma once

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

// modelo
#include <modelo/include/IRelaciones.h>
#include <modelo/include/IRelacionConConceptos.h>

namespace visualizador
{
namespace modelo
{
namespace relaciones
{

class RelacionesTermino : public IRelaciones, public IRelacionConConceptos
{
public:

    // CONSTRUCTORES

    RelacionesTermino(herramientas::utiles::ID* id_termino = NULL);
    virtual ~RelacionesTermino();

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

