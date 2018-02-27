#include <modelo/include/RelacionesTermino.h>

// stl
#include <algorithm>

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

// CONSTRUCTORES

RelacionesTermino::RelacionesTermino(herramientas::utiles::ID* id_termino) :
    IRelaciones(id_termino, aplicacion::ConfiguracionAplicacion::prefijoRelacionesTermino()),
    IRelacionConConceptos(new RelacionConGrupo())
{
}

RelacionesTermino::~RelacionesTermino()
{
}

// GETTERS

// getters de IAlmacenable

std::string RelacionesTermino::getValorAlmacenable()
{
    this->armarJson();

    return this->getJson()->jsonString();
}

// SETTERS

// metodos de IAlmacenable

void RelacionesTermino::parsearValorAlmacenable(std::string valor_almacenable)
{
    herramientas::utiles::Json * json_almacenable = new herramientas::utiles::Json(valor_almacenable);

    this->setJson(json_almacenable);
    this->parsearJson();
}

std::string RelacionesTermino::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesTermino();
}

unsigned long long int RelacionesTermino::hashcode()
{
    return this->getRelacionConConceptos()->hashcode();
}

// metodos de IContieneJson

bool RelacionesTermino::armarJson()
{
    herramientas::utiles::Json * relaciones_termino = new herramientas::utiles::Json();

    relaciones_termino->agregarAtributoArray("ids_conceptos", this->getRelacionConConceptos()->getIdsGrupoComoUint());
    
    this->getJson()->reset();

    this->getJson()->agregarAtributoJson("relaciones_termino", relaciones_termino);

    delete relaciones_termino;

    return true;
}

bool RelacionesTermino::parsearJson()
{
    herramientas::utiles::Json * json_relaciones_termino = this->getJson()->getAtributoValorJson("relaciones_termino");

    std::vector<unsigned long long int> ids_conceptos = json_relaciones_termino->getAtributoArrayUint("ids_conceptos");

    for (std::vector<unsigned long long int>::iterator it = ids_conceptos.begin(); it != ids_conceptos.end(); it++)
    {
        this->getRelacionConConceptos()->agregarRelacion(*it);
    }

    delete json_relaciones_termino;

    return true;
}

IRelaciones * RelacionesTermino::clonar()
{
    RelacionesTermino * clon = new RelacionesTermino(this->getId()->copia());

    std::vector<herramientas::utiles::ID*> ids_conceptos = this->getRelacionConConceptos()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_conceptos.begin(); it != ids_conceptos.end(); it++)
    {
        clon->agregarRelacionConConcepto(*it);
    }

    return clon;
}
