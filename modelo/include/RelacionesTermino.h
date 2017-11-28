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

class RelacionesTermino : public IRelaciones
{
public:

    // CONSTRUCTORES

    RelacionesTermino(visualizador::aplicacion::ID* id_termino = NULL);
    virtual ~RelacionesTermino();

    // GETTERS

    virtual RelacionConGrupo * getRelacionConConceptos();

    // getters de IAlmacenable

    virtual std::string getValorAlmacenable();

    // SETTERS

    virtual void setRelacionConConceptos(RelacionConGrupo * relacion_con_conceptos);

    // METODOS

    void agregarRelacionConConcepto(visualizador::aplicacion::ID* id_concepto);

    void eliminarRelacionConConcepto(visualizador::aplicacion::ID* id_concepto);

    // metodos de IAlmacenable

    virtual void parsearValorAlmacenable(std::string valor_almacenable);

    virtual std::string prefijoGrupo();

    virtual unsigned int hashcode();

    // metodos de IContieneJson

    virtual void crearContenido();

    virtual bool parsearContenido(IJson * contenido);

private:
    
    static std::hash<std::string> hasher;

    RelacionConGrupo * relacion_con_conceptos;
};

};
};
};

