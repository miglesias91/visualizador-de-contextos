#include <modelo/include/Concepto.h>

using namespace visualizador::modelo;

// rapidjson
#include <rapidjson/document.h>
#include <rapidjson/allocators.h>

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

Concepto::Concepto() : IEntidad()
{
}

Concepto::Concepto(std::string etiqueta, std::vector<Termino*> terminos, ContenidoEntidad* contenido) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoConcepto(), contenido), terminos(terminos)
{
}

Concepto::Concepto(std::string etiqueta, std::vector<Termino*> terminos) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoConcepto()), terminos(terminos)
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
	rapidjson::Value* json_contenido = new rapidjson::Value(rapidjson::kObjectType);

	rapidjson::Value json_terminos(rapidjson::kArrayType);

	rapidjson::Document::AllocatorType* alocador = visualizador::aplicacion::ConfiguracionAplicacion::getAlocador();

	for (std::vector<Termino*>::iterator it = this->terminos.begin(); it != this->terminos.end(); it++)
	{
		unsigned long long int id_termino = (*it)->getId()->numero();
		json_terminos.PushBack(id_termino, *alocador);
	}

	rapidjson::Value tag_terminos("ids_terminos", *alocador);
	json_contenido->AddMember(tag_terminos, json_terminos, *alocador);

	this->getContenido()->setValor(json_contenido);
}
