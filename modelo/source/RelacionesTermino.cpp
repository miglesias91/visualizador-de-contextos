#include <modelo/include/RelacionesTermino.h>

using namespace visualizador::modelo::relaciones;

// CONSTRUCTORES

RelacionesTermino::RelacionesTermino() : IRelaciones()
{
}

RelacionesTermino::~RelacionesTermino()
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
    IJson* contenido = this->getContenido();
    contenido->reset();

    contenido->agregarAtributoArray("ids_terminos", this->);
}

bool RelacionesTermino::parsearContenido(IJson * contenido)
{

}

