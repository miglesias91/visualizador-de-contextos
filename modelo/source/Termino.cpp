#include <modelo/include/Termino.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorIDs.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

std::hash<std::string> Termino::hasher;

Termino::Termino() : IEntidad("", visualizador::aplicacion::ConfiguracionAplicacion::prefijoTermino(), NULL), valor("")
{
    this->relaciones_termino = new relaciones::RelacionesTermino();
    this->setRelaciones(this->relaciones_termino);
}

Termino::Termino(std::string termino, std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoTermino(), NULL), valor(termino)
{
    this->relaciones_termino = new relaciones::RelacionesTermino();
    this->setRelaciones(this->relaciones_termino);
}

Termino::~Termino()
{
    //if (NULL != this->relaciones)
    //{
    //    delete this->relaciones;
    //    this->relaciones = NULL;
    //}
}

// GETTERS

std::string Termino::getValor()
{
	return this->valor;
}

// SETTERS

void Termino::setValor(std::string valor)
{
	this->valor = valor;
}

void Termino::relacionarConConcepto(Concepto * concepto)
{
    this->relaciones_termino->agregarRelacionConConcepto(concepto->getId());
}

// METODOS

// metodos de IContieneJson

void Termino::crearContenido()
{
	IJson* contenido = this->getContenido();
	contenido->reset();

	contenido->agregarAtributoValor("valor", this->getValor());
}

bool Termino::parsearContenido(IJson* contenido)
{
	std::string valor = contenido->getAtributoValorString("valor");

	this->setValor(valor);

    return true;
}

// metodos de IAlmacenable

std::string Termino::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoTermino();
}

unsigned int Termino::hashcode()
{
	return hasher(this->getValor());
}

// metodos de IEntidad

IEntidad * Termino::clonar()
{
    Termino * clon = new Termino(this->valor, this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setContenido(this->getContenido()->clonar());
    return clon;
}
