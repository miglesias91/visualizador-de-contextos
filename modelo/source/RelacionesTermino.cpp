#include <modelo/include/RelacionesTermino.h>

// stl
#include <algorithm>

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

// CONSTRUCTORES

RelacionesTermino::RelacionesTermino(visualizador::aplicacion::ID* id_termino) : IRelaciones(id_termino, aplicacion::ConfiguracionAplicacion::prefijoRelacionesTermino()), relacion_con_conceptos(new RelacionConConceptos())
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

// getters de IAlmacenable

std::string RelacionesTermino::getValorAlmacenable()
{
    this->crearContenido();

    return this->getContenido()->jsonString();
}

// SETTERS

// METODOS

void RelacionesTermino::agregarRelacionConConcepto(visualizador::aplicacion::ID * id_concepto)
{
    visualizador::aplicacion::ID * id_concepto_copia = id_concepto->copia();
    if (false == this->relacion_con_conceptos->agregarRelacion(id_concepto))
    {// si no lo agrego, entonces destruyo la copia.
        delete id_concepto_copia;
    }
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
    this->relacion_con_conceptos->crearContenido();
    IJson* ids_conceptos = this->relacion_con_conceptos->getContenido();

    IJson* contenido = this->getContenido();
    contenido->reset();

    contenido->agregarAtributoJson("relaciones_termino", ids_conceptos);
}

bool RelacionesTermino::parsearContenido(IJson * contenido)
{
    IJson * json_relaciones_termino = contenido->getAtributoValorJson("relaciones_termino");

    this->relacion_con_conceptos->parsearContenido(json_relaciones_termino);

    return true;
}

