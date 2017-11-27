#include <modelo/include/RelacionesTermino.h>

// stl
#include <algorithm>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;

// CONSTRUCTORES

RelacionesTermino::RelacionesTermino() : IRelaciones(), relacion_con_conceptos(NULL)
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

