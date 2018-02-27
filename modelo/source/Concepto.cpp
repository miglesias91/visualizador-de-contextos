#include <modelo/include/Concepto.h>

using namespace visualizador::modelo;
using namespace visualizador;

// stl
#include <algorithm>

// rapidjson
#include <rapidjson/document.h>
#include <rapidjson/allocators.h>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>
#include <aplicacion/include/GestorRelaciones.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

Concepto::Concepto(std::string etiqueta) : IEntidad(etiqueta, aplicacion::ConfiguracionAplicacion::prefijoConcepto(), NULL), relaciones_concepto(NULL)
{
    this->relaciones_concepto = new relaciones::RelacionesConcepto();
    this->setRelaciones(this->relaciones_concepto);
}

Concepto::Concepto(std::vector<Termino*> terminos, IJson* contenido, std::string etiqueta) : IEntidad(etiqueta, aplicacion::ConfiguracionAplicacion::prefijoConcepto(), NULL, contenido), relaciones_concepto(NULL)
{
    this->relaciones_concepto = new relaciones::RelacionesConcepto();
    this->setRelaciones(this->relaciones_concepto);

    for (std::vector<Termino*>::iterator it = terminos.begin(); it != terminos.end(); it++)
    {
        this->agregarTermino(*it);
    }
}

Concepto::Concepto(std::vector<Termino*> terminos, std::string etiqueta) : IEntidad(etiqueta, aplicacion::ConfiguracionAplicacion::prefijoConcepto(), NULL), relaciones_concepto(NULL)
{
    this->relaciones_concepto = new relaciones::RelacionesConcepto();
    this->setRelaciones(this->relaciones_concepto);

    for (std::vector<Termino*>::iterator it = terminos.begin(); it != terminos.end(); it++)
    {
        this->agregarTermino(*it);
    }
}

Concepto::~Concepto()
{
	for (std::vector<Termino*>::iterator it = this->terminos.begin(); it != this->terminos.end(); it++)
	{
        if (0 == (*it)->restarReferencia())
        {
            delete (*it);
            (*it) = NULL;
        }
	}
	this->terminos.clear();
}

// GETTERS

relaciones::RelacionesConcepto * Concepto::getRelacionesConcepto()
{
    return this->relaciones_concepto;
}

std::vector<Termino*> Concepto::getTerminos()
{
	return this->terminos;
}

// SETTERS

void Concepto::setRelacionesConcepto(relaciones::RelacionesConcepto * relaciones_concepto)
{
    if (NULL != this->relaciones_concepto)
    {
        delete this->relaciones_concepto;
    }

    this->relaciones_concepto = relaciones_concepto;
    this->setRelaciones(this->relaciones_concepto);
}

// METODOS

void Concepto::agregarTermino(Termino* termino_nuevo)
{
	this->terminos.push_back(termino_nuevo);
    termino_nuevo->sumarReferencia();

    if (NULL != this->getId())
    {
        termino_nuevo->getRelacionesTermino()->agregarRelacionConConcepto(this->getId());
    }

    if (NULL != termino_nuevo->getId())
    {
        this->relaciones_concepto->agregarRelacionConTermino(termino_nuevo->getId());
    }

}

// metodos IContieneJson

bool Concepto::armarJson()
{
}

bool Concepto::parsearJson()
{
    return true;
}

// metodos IAlmacenable

std::string Concepto::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoConcepto();
}

unsigned long long int Concepto::hashcode()
{
    return this->getRelacionesConcepto()->getRelacionConTerminos()->hashcode();
}

// metodos IEntidad

IEntidad * Concepto::clonar()
{
    aplicacion::GestorEntidades gestor;

    std::vector<Termino*> clon_terminos;
    for (std::vector<Termino*>::iterator it = this->terminos.begin(); it != this->terminos.end(); it++)
    {
        Termino * clon_termino = gestor.clonar<Termino>((*it));
        clon_terminos.push_back(clon_termino);
    }

    Concepto* clon = new Concepto(clon_terminos, this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setJson(this->getJson()->clonar());

    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    relaciones::RelacionesConcepto * relaciones_clon = gestor_relaciones.clonar<relaciones::RelacionesConcepto>(this->getRelacionesConcepto());

    clon->setRelacionesConcepto(relaciones_clon);

    return clon;
}

// metodos de IRelacionable

bool Concepto::recuperarContenidoDeRelaciones()
{
    visualizador::aplicacion::GestorEntidades gestor_entidades;

    std::vector<unsigned long long int> ids_terminos = this->relaciones_concepto->getRelacionConTerminos()->getIdsGrupoComoUint();

    Termino* termino_nuevo = NULL;
    bool contenido_limpio = true;
    for (std::vector<unsigned long long int>::iterator it = ids_terminos.begin(); it != ids_terminos.end(); it++)
    {
        termino_nuevo = new Termino();
        termino_nuevo->setId(new herramientas::utiles::ID(*it));
        if (gestor_entidades.recuperar(termino_nuevo))
        { // si el termino existe, lo agrego a la lista de terminos
            this->agregarTermino(termino_nuevo);
        }
        else
        { // si el termino no existe, entonces no lo agrego, lo elimino y seteo el 'concepto' como "entidad sucia" 
            delete termino_nuevo;
            contenido_limpio = false;
        }
    }
    return contenido_limpio;
}

void Concepto::actualizarRelaciones(herramientas::utiles::ID * id_nuevo, herramientas::utiles::ID * id_viejo)
{
    //for (std::vector<Termino*>::iterator it = this->terminos.begin(); it != this->terminos.end(); it++)
    //{
    //    (*it)->getRelacionesTermino()->agregarRelacionConConcepto(this->getId());
    //    this->relaciones_concepto->agregarRelacionConTermino((*it)->getId());
    //}

    for (std::vector<Termino*>::iterator it = this->terminos.begin(); it != this->terminos.end(); it++)
    {
        (*it)->getRelacionesTermino()->actualizarRelacionConConcepto(id_nuevo, id_viejo);
        this->relaciones_concepto->agregarRelacionConTermino((*it)->getId());
    }
}

void Concepto::vincular()
{
    visualizador::aplicacion::GestorRelaciones gestor;
    gestor.vincular(this->relaciones_concepto, this->getId());
}

void Concepto::desvincular()
{
    visualizador::aplicacion::GestorRelaciones gestor;
    gestor.desvincular(this->relaciones_concepto, this->getId());
}

bool Concepto::tieneRelacionesDependientes()
{
    return 0 != this->relaciones_concepto->getRelacionConConsultas()->getIdsGrupo().size();
}
