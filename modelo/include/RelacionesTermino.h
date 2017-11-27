#pragma once

// stl
#include <functional>

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

// modelo
#include <modelo/include/IRelaciones.h>
#include <modelo/include/RelacionConConceptos.h>

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

    RelacionesTermino(visualizador::aplicacion::ID* id_termino = NULL);
    virtual ~RelacionesTermino();

    // GETTERS

    virtual RelacionConConceptos * getRelacionConConceptos();

    // getters de IAlmacenable

    virtual std::string getValorAlmacenable();

    // SETTERS

    virtual void setRelacionConConceptos(RelacionConConceptos * relacion_con_conceptos);

    // METODOS

    bool vincularConceptos();

    bool desvincularConceptos();

    void agregarRelacionConConcepto(visualizador::aplicacion::ID* id_concepto);

    // IAlmacenable::

    virtual void parsearValorAlmacenable(std::string valor_almacenable);

    virtual std::string prefijoGrupo();

    virtual unsigned int hashcode();

    // IContieneJson::

    virtual void crearContenido();

    virtual bool parsearContenido(IJson * contenido);

private:
    
    static std::hash<std::string> hasher;

    RelacionConConceptos * relacion_con_conceptos;
};

};
};
};

