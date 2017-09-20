#include <modelo/include/Termino.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorIDs.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

Termino::Termino() : IEntidad()
{
}

Termino::Termino(std::string termino) : IEntidad(termino, visualizador::aplicacion::ConfiguracionAplicacion::prefijoTermino()), valor(termino)
{
}

Termino::~Termino()
{
}

std::string Termino::getValor()
{
	return this->valor;
}

void Termino::setValor(std::string valor)
{
	this->valor = valor;
}

void Termino::crearContenido()
{
	rapidjson::Value* json_contenido = new rapidjson::Value(rapidjson::kObjectType);

	rapidjson::Document::AllocatorType* alocador = visualizador::aplicacion::ConfiguracionAplicacion::getAlocador();

	rapidjson::Value tag_valor("valor", *alocador);
	rapidjson::Value valor(this->getValor().c_str(), *alocador);
	json_contenido->AddMember(tag_valor, valor, *alocador);

	this->getContenido()->setValor(json_contenido);
}
