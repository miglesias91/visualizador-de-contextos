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
}

// GETTERS

std::string Termino::getValor()
{
	return this->valor;
}

relaciones::RelacionesTermino * Termino::getRelacionesTermino()
{
    return this->relaciones_termino;
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

// metodos de IRelacionable

void Termino::vincular()
{
    // DESDE ACA HACER Q LLAME AL "GestorRelaciones" y le paso el RelacionesTermino y le digo q vincule
    // los conceptos de "relacion_con_conceptos" con el id del termino (que esta almacenado en el id de RelacionesTermino).
    // --> con el GestorRelaciones evito clavar 'forward declaration' en todas las relaciones.
    
    visualizador::aplicacion::GestorRelaciones gestor;
    gestor.vincular(this->relaciones_termino, this->getId());
}

void Termino::desvincular()
{
    visualizador::aplicacion::GestorRelaciones gestor;
    gestor.desvincular(this->relaciones_termino, this->getId());
}
