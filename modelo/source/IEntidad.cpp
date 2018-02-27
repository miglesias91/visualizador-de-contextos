#include <modelo/include/IEntidad.h>

using namespace visualizador::modelo;

IEntidad::IEntidad() : IReferenciable(), IAlmacenable(), herramientas::utiles::IContieneJson(), IRelacionable(), esta_limpia(true)
{
}

IEntidad::IEntidad(std::string etiqueta, std::string grupo, relaciones::IRelaciones * relaciones, herramientas::utiles::Json * json)
    : IReferenciable(), IAlmacenable(grupo), herramientas::utiles::IContieneJson(json), IRelacionable(relaciones), etiqueta(etiqueta), esta_limpia(true)
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
    //this->armarJson();
    this->armarJson();
    
    herramientas::utiles::Json json_almacenable;

    // seteo la etiqueta
    json_almacenable.agregarAtributoValor("etiqueta", this->getEtiqueta());
    
    // seteo el contenido
    herramientas::utiles::Json* json_contenido = this->getJson();
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

void IEntidad::setId(herramientas::utiles::ID* id)
{
    if (NULL != this->getRelaciones())
    {
        this->getRelaciones()->setId(id->copia());

        herramientas::utiles::ID * id_viejo = this->getId();
        this->actualizarRelaciones(id, id_viejo);
    }

    IAlmacenable::setId(id);
}

void IEntidad::parsearValorAlmacenable(std::string valor_almacenable)
{
    herramientas::utiles::Json json_almacenable(valor_almacenable);

    // parseo etiqueta
	std::string etiqueta = json_almacenable.getAtributoValorString("etiqueta");
	this->setEtiqueta(etiqueta);

    // parseo contenido
    herramientas::utiles::Json* json_contenido = json_almacenable.getAtributoValorJson("contenido");

    this->setJson(json_contenido);
	this->esta_limpia = this->parsearJson();
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
