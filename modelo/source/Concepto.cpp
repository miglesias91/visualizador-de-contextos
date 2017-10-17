#include <modelo/include/Concepto.h>

using namespace visualizador::modelo;
using namespace visualizador;

// stl
#include <algorithm>

// rapidjson
#include <rapidjson/document.h>
#include <rapidjson/allocators.h>

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

Concepto::Concepto(std::string etiqueta) : IEntidad(etiqueta, aplicacion::ConfiguracionAplicacion::prefijoConcepto())
{
}

Concepto::Concepto(std::vector<Termino*> terminos, ContenidoEntidad* contenido, std::string etiqueta) : IEntidad(etiqueta, aplicacion::ConfiguracionAplicacion::prefijoConcepto(), contenido), terminos(terminos)
{
}

Concepto::Concepto(std::vector<Termino*> terminos, std::string etiqueta) : IEntidad(etiqueta, aplicacion::ConfiguracionAplicacion::prefijoConcepto()), terminos(terminos)
{
}

Concepto::~Concepto()
{
}

std::vector<Termino*> Concepto::getTerminos()
{
	return this->terminos;
}

void Concepto::agregarTermino(Termino* termino_nuevo)
{
	this->terminos.push_back(termino_nuevo);
}

void Concepto::crearContenido()
{
	std::vector<unsigned long long int> ids_terminos;
	for (std::vector<Termino*>::iterator it = this->terminos.begin(); it != this->terminos.end(); it++)
	{
		unsigned long long int id = (*it)->getId()->numero();
		ids_terminos.push_back(id);
	}

	ContenidoEntidad* contenido = this->getContenido();
	contenido->reset();

	contenido->agregarAtributoArray("ids_terminos", ids_terminos);
}

void Concepto::parsearContenido(IJson* contenido)
{
	std::vector<unsigned long long int> ids_terminos = contenido->getAtributoArrayUint("ids_terminos");

	Termino* termino_nuevo = NULL;
	for (std::vector<unsigned long long int>::iterator it = ids_terminos.begin(); it != ids_terminos.end(); it++)
	{
		termino_nuevo = new Termino();
		termino_nuevo->setId(new aplicacion::ID(*it));
		aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(termino_nuevo);
		this->terminos.push_back(termino_nuevo);
	}
}

std::string Concepto::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoConcepto();
}

unsigned int Concepto::hashcode()
{
	std::vector<Termino*> terminos = this->getTerminos();

	std::sort(terminos.begin(), terminos.end(), IEntidad::comparador);

	unsigned long long int hashcode_terminos = 0;
	for (std::vector<Termino*>::iterator it = terminos.begin(); it != terminos.end(); it++)
	{
		hashcode_terminos += (*it)->hashcode();
	}

	return hashcode_terminos;
}
