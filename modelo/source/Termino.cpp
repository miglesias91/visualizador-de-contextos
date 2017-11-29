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

void Termino::setRelacionesTermino(relaciones::RelacionesTermino * relaciones_termino)
{
    this->relaciones_termino = relaciones_termino;
}

// METODOS

// metodos de IContieneJson

void Termino::crearJson()
{
	IJson* json = this->getJson();
    json->reset();

    json->agregarAtributoValor("valor", this->getValor());
}

bool Termino::parsearJson(IJson* json)
{
	std::string valor = json->getAtributoValorString("valor");

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
    clon->setJson(this->getJson()->clonar());
    return clon;
}

// metodos de IRelacionable

bool Termino::recuperarContenidoDeRelaciones()
{
    return true;
}

void Termino::actualizarRelaciones()
{
}

void Termino::vincular()
{    
    visualizador::aplicacion::GestorRelaciones gestor;
    gestor.vincular(this->relaciones_termino, this->getId());
}

void Termino::desvincular()
{
    visualizador::aplicacion::GestorRelaciones gestor;
    gestor.desvincular(this->relaciones_termino, this->getId());
}
