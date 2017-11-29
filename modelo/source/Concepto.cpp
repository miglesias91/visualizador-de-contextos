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
#include <aplicacion/include/ConfiguracionAplicacion.h>

Concepto::Concepto(std::string etiqueta) : IEntidad(etiqueta, aplicacion::ConfiguracionAplicacion::prefijoConcepto(), NULL), relaciones_concepto(NULL)
{
    this->relaciones_concepto = new relaciones::RelacionesConcepto();
    this->setRelaciones(this->relaciones_concepto);
}

Concepto::Concepto(std::vector<Termino*> terminos, IJson* contenido, std::string etiqueta) : IEntidad(etiqueta, aplicacion::ConfiguracionAplicacion::prefijoConcepto(), NULL, contenido), /*terminos(terminos),*/ relaciones_concepto(NULL)
{
    this->relaciones_concepto = new relaciones::RelacionesConcepto();
    this->setRelaciones(this->relaciones_concepto);

    for (std::vector<Termino*>::iterator it = terminos.begin(); it != terminos.end(); it++)
    {
        //if (NULL != (*it)->getId())
        //{
        //    this->relaciones_concepto->agregarRelacionConTermino((*it)->getId());
        //}
        this->agregarTermino(*it);
        (*it)->sumarReferencia();
    }
}

Concepto::Concepto(std::vector<Termino*> terminos, std::string etiqueta) : IEntidad(etiqueta, aplicacion::ConfiguracionAplicacion::prefijoConcepto(), NULL), /*terminos(terminos),*/ relaciones_concepto(NULL)
{
    this->relaciones_concepto = new relaciones::RelacionesConcepto();
    this->setRelaciones(this->relaciones_concepto);

    for (std::vector<Termino*>::iterator it = terminos.begin(); it != terminos.end(); it++)
    {
        //if (NULL != (*it)->getId())
        //{
        //    this->relaciones_concepto->agregarRelacionConTermino((*it)->getId());
        //}
        this->agregarTermino(*it);
        (*it)->sumarReferencia();
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
    this->relaciones_concepto = relaciones_concepto;
}

// METODOS

void Concepto::agregarTermino(Termino* termino_nuevo)
{
	this->terminos.push_back(termino_nuevo);

    if (NULL != this->getId())
    {
        termino_nuevo->getRelacionesTermino()->agregarRelacionConConcepto(this->getId());
    }

    if (NULL != termino_nuevo->getId())
    {
        this->relaciones_concepto->agregarRelacionConTermino(termino_nuevo->getId());
    }

    termino_nuevo->sumarReferencia();
}

// metodos IContieneJson

void Concepto::crearJson()
{
	//std::vector<unsigned long long int> ids_terminos;
	//for (std::vector<Termino*>::iterator it = this->terminos.begin(); it != this->terminos.end(); it++)
	//{
	//	unsigned long long int id = (*it)->getId()->numero();
	//	ids_terminos.push_back(id);
	//}

	//IJson* contenido = this->getJson();
	//contenido->reset();

	// contenido->agregarAtributoArray("ids_terminos", ids_terminos);

    //this->relaciones_concepto->crearJson();
    //this->setJson(this->relaciones_concepto->getJson());
}

bool Concepto::parsearJson(IJson* json)
{
	// std::vector<unsigned long long int> ids_terminos = contenido->getAtributoArrayUint("ids_terminos");

//    this->relaciones_concepto->parsearJson(json);

 //   std::vector<unsigned long long int> ids_terminos = this->relaciones_concepto->getRelacionConTerminos()->getIdsGrupoComoUint();

	//Termino* termino_nuevo = NULL;
 //   bool contenido_limpio = true;
	//for (std::vector<unsigned long long int>::iterator it = ids_terminos.begin(); it != ids_terminos.end(); it++)
	//{
	//	termino_nuevo = new Termino();
	//	termino_nuevo->setId(new aplicacion::ID(*it));
 //       if (aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(termino_nuevo))
 //       { // si el termino existe, lo agrego a la lista de terminos
 //           this->agregarTermino(termino_nuevo);
 //       }
 //       else
 //       { // si el termino no existe, entonces no lo agrego, lo elimino y seteo el 'concepto' como "entidad sucia" 
 //           delete termino_nuevo;
 //           contenido_limpio = false;
 //       }
	//}
 //   return contenido_limpio;
    return true;
}

// metodos IAlmacenable

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
    return clon;
}

// metodos de IRelacionable

bool Concepto::recuperarContenidoDeRelaciones()
{
    std::vector<unsigned long long int> ids_terminos = this->relaciones_concepto->getRelacionConTerminos()->getIdsGrupoComoUint();

    Termino* termino_nuevo = NULL;
    bool contenido_limpio = true;
    for (std::vector<unsigned long long int>::iterator it = ids_terminos.begin(); it != ids_terminos.end(); it++)
    {
        termino_nuevo = new Termino();
        termino_nuevo->setId(new aplicacion::ID(*it));
        if (aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(termino_nuevo))
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

void Concepto::actualizarRelaciones()
{
    for (std::vector<Termino*>::iterator it = this->terminos.begin(); it != this->terminos.end(); it++)
    {
        (*it)->getRelacionesTermino()->agregarRelacionConConcepto(this->getId());
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
