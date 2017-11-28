#include <modelo/include/RelacionesTermino.h>

// stl
#include <algorithm>

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

// CONSTRUCTORES

RelacionesTermino::RelacionesTermino(visualizador::aplicacion::ID* id_termino) : IRelaciones(id_termino, aplicacion::ConfiguracionAplicacion::prefijoRelacionesTermino()), relacion_con_conceptos(new RelacionConGrupo())
{
}

RelacionesTermino::~RelacionesTermino()
{
    if (NULL != this->relacion_con_conceptos)
    {
        delete this->relacion_con_conceptos;
        this->relacion_con_conceptos = NULL;
    }
}

// GETTERS

RelacionConGrupo * RelacionesTermino::getRelacionConConceptos()
{
    return this->relacion_con_conceptos;;
}

// getters de IAlmacenable

std::string RelacionesTermino::getValorAlmacenable()
{
    this->crearContenido();

    return this->getContenido()->jsonString();
}

// SETTERS

void RelacionesTermino::setRelacionConConceptos(RelacionConGrupo * relacion_con_conceptos)
{
    this->relacion_con_conceptos = relacion_con_conceptos;
}

// METODOS

void RelacionesTermino::agregarRelacionConConcepto(visualizador::aplicacion::ID * id_concepto)
{
    visualizador::aplicacion::ID * id_concepto_copia = id_concepto->copia();
    if (false == this->relacion_con_conceptos->agregarRelacion(id_concepto_copia))
    {// si no lo agrego, entonces destruyo la copia.
        delete id_concepto_copia;
    }
}

void RelacionesTermino::eliminarRelacionConConcepto(visualizador::aplicacion::ID * id_concepto)
{
}

// metodos de IAlmacenable

void RelacionesTermino::parsearValorAlmacenable(std::string valor_almacenable)
{
    IJson json_almacenable(valor_almacenable);

    this->parsearContenido(&json_almacenable);
}

std::string RelacionesTermino::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesTermino();
}

unsigned int RelacionesTermino::hashcode()
{
    return this->relacion_con_conceptos->hashcode();
}

// metodos de IContieneJson

void RelacionesTermino::crearContenido()
{
    IJson * relaciones_termino = new IJson();

    relaciones_termino->agregarAtributoArray("ids_conceptos", this->relacion_con_conceptos->getIdsGrupoComoUint());
    
    IJson* contenido = this->getContenido();
    contenido->reset();

    contenido->agregarAtributoJson("relaciones_termino", relaciones_termino);
}

bool RelacionesTermino::parsearContenido(IJson * contenido)
{
    IJson * json_relaciones_termino = contenido->getAtributoValorJson("relaciones_termino");

    std::vector<unsigned long long int> ids_conceptos = json_relaciones_termino->getAtributoArrayUint("ids_conceptos");

    for (std::vector<unsigned long long int>::iterator it = ids_conceptos.begin(); it != ids_conceptos.end(); it++)
    {
        this->relacion_con_conceptos->agregarRelacion(*it);
    }

    return true;
}

