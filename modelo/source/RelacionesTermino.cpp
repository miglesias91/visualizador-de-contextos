#include <modelo/include/RelacionesTermino.h>

using namespace visualizador::modelo::relaciones;

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

std::string RelacionesTermino::getValorAlmacenable()
{

}

// SETTERS

// METODOS

// IAlmacenable::

void RelacionesTermino::parsearValorAlmacenable(std::string valor_almacenable)
{

}

std::string RelacionesTermino::prefijoGrupo()
{

}

unsigned int RelacionesTermino::hashcode()
{

}

// GETTERS

std::string RelacionesTermino::getValorAlmacenable()
{

}

// SETTERS

// METODOS

// IAlmacenable::

void RelacionesTermino::parsearValorAlmacenable(std::string valor_almacenable)
{
    IJson json_almacenable(valor_almacenable);

    this->parsearContenido(&json_almacenable);

}

std::string RelacionesTermino::prefijoGrupo()
{

}

unsigned int RelacionesTermino::hashcode()
{

}

// IContieneJson::

void RelacionesTermino::crearContenido()
{
    this->relacion_con_conceptos->crearContenido();
    IJson* ids_conceptos = this->relacion_con_conceptos->getContenido());

    IJson* contenido = this->getContenido();
    contenido->reset();

    contenido->agregarAtributoJson("relaciones_termino", ids_conceptos);
}

bool RelacionesTermino::parsearContenido(IJson * contenido)
{
    IJson * json_relaciones_termino = contenido->getAtributoValorJson("relaciones_termino");
}

