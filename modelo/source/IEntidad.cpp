#include <modelo/include/IEntidad.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorIDs.h>

IEntidad::IEntidad() : IReferenciable(), IAlmacenable(), IContieneJson(), relaciones(NULL), esta_limpia(true)
{
}

IEntidad::IEntidad(std::string etiqueta, std::string grupo, relaciones::IRelaciones * relaciones, IJson * contenido)
    : IReferenciable(), IAlmacenable(grupo), IContieneJson(contenido), etiqueta(etiqueta), relaciones(relaciones), esta_limpia(true)
{
}

IEntidad::~IEntidad()
{
    if (NULL != this->relaciones)
    {
        delete this->relaciones;
        this->relaciones = NULL;
    }
}

// GETTERS

std::string IEntidad::getEtiqueta()
{
	return this->etiqueta;
}

relaciones::IRelaciones * IEntidad::getRelaciones()
{
    return this->relaciones;
}

// metodos IAlmacenable

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

// SETTERS

void IEntidad::setEtiqueta(std::string etiqueta)
{
	this->etiqueta = etiqueta;
}

void IEntidad::setRelaciones(relaciones::IRelaciones * relaciones)
{
    this->relaciones = relaciones;
}


// metodos de IAlmacenable

void IEntidad::setId(visualizador::aplicacion::ID* id)
{
    if (NULL != this->relaciones)
    {
        this->relaciones->setId(id->copia());
    }

    IAlmacenable::setId(id);
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
