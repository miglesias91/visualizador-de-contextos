#include <modelo/include/IEntidad.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorIDs.h>

IEntidad::IEntidad() : IReferenciable(), IAlmacenable(), IContieneJson(), IRelacionable(), esta_limpia(true)
{
}

IEntidad::IEntidad(std::string etiqueta, std::string grupo, relaciones::IRelaciones * relaciones, IJson * json)
    : IReferenciable(), IAlmacenable(grupo), IContieneJson(json), IRelacionable(relaciones), etiqueta(etiqueta), esta_limpia(true)
{
}

IEntidad::~IEntidad()
{
}

// GETTERS

std::string IEntidad::getEtiqueta()
{
	return this->etiqueta;
}

// metodos IAlmacenable

std::string IEntidad::getValorAlmacenable()
{
	this->crearJson();
    
    IJson json_almacenable;

    // seteo la etiqueta
	json_almacenable.agregarAtributoValor("etiqueta", this->getEtiqueta());
    
    // seteo el contenido
    IJson* json_contenido = this->getJson();
	json_almacenable.agregarAtributoJson("contenido", json_contenido);

	std::string string_almacenable = json_almacenable.jsonString();

	return string_almacenable;
}

// SETTERS

void IEntidad::setEtiqueta(std::string etiqueta)
{
	this->etiqueta = etiqueta;
}

// metodos de IAlmacenable

void IEntidad::setId(visualizador::aplicacion::ID* id)
{
    if (NULL != this->getRelaciones())
    {
        this->getRelaciones()->setId(id->copia());

        visualizador::aplicacion::ID * id_viejo = this->getId();
        this->actualizarRelaciones(id, id_viejo);
    }

    IAlmacenable::setId(id);
}

void IEntidad::parsearValorAlmacenable(std::string valor_almacenable)
{
	IJson json_almacenable(valor_almacenable);

    // parseo etiqueta
	std::string etiqueta = json_almacenable.getAtributoValorString("etiqueta");
	this->setEtiqueta(etiqueta);

    // parseo contenido
	IJson* json_contenido = json_almacenable.getAtributoValorJson("contenido");

	this->esta_limpia = this->parsearJson(json_contenido);

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
