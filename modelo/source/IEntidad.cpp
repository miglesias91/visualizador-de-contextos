#include <modelo/include/IEntidad.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorIDs.h>

IEntidad::IEntidad() : IReferenciable(), IAlmacenable(), IContieneJson(), esta_limpia(true)
{
}

IEntidad::IEntidad(std::string etiqueta, std::string grupo, IJson * contenido)
    : IReferenciable(), IAlmacenable(grupo), IContieneJson(contenido), etiqueta(etiqueta), esta_limpia(true)
{
}

IEntidad::~IEntidad()
{
}

std::string IEntidad::getEtiqueta()
{
	return this->etiqueta;
}

std::string IEntidad::getValorAlmacenable()
{
	this->crearContenido();

	IJson* json_contenido = this->getContenido();
	IJson json_almacenable;

	json_almacenable.agregarAtributoValor("etiqueta", this->getEtiqueta());
	json_almacenable.agregarAtributoJson("contenido", json_contenido);

	std::string string_almacenable = json_almacenable.jsonString();

	return string_almacenable;
}

void IEntidad::setEtiqueta(std::string etiqueta)
{
	this->etiqueta = etiqueta;
}

void IEntidad::parsearValorAlmacenable(std::string valor_almacenable)
{
	IJson json_almacenable(valor_almacenable);

	std::string etiqueta = json_almacenable.getAtributoValorString("etiqueta");
	this->setEtiqueta(etiqueta);

	IJson* json_contenido = json_almacenable.getAtributoValorJson("contenido");

	this->esta_limpia = this->parsearContenido(json_contenido);

	delete json_contenido;
}

std::vector<IAlmacenable*> IEntidad::comoAlmacenables(std::vector<IEntidad*> entidades)
{
    std::vector<IAlmacenable*> almacenables;

    for (std::vector<IEntidad*>::iterator it = entidades.begin(); it != entidades.end(); it++)
    {
        IEntidad* entidad = *it;
        almacenables.push_back(entidad);
    }

    return almacenables;
}

bool IEntidad::estaSucia()
{
    return !this->estaLimpia();
}

bool IEntidad::estaLimpia()
{
    return this->esta_limpia;
}
