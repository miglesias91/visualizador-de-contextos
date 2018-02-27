#include <modelo/include/RelacionesMedio.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

RelacionesMedio::RelacionesMedio(herramientas::utiles::ID* id_medio) :
    IRelaciones(id_medio, aplicacion::ConfiguracionAplicacion::prefijoRelacionesMedio()),
    IRelacionConConsultas(new RelacionConGrupo()),
    id_medio_a_scrapear(0)
{
}

RelacionesMedio::~RelacionesMedio()
{
}

// GETTERS

// getters de IAlmacenable

std::string RelacionesMedio::getValorAlmacenable()
{
    this->armarJson();

    return this->getJson()->jsonString();
}

unsigned long long int RelacionesMedio::getIDMedioAScrapear()
{
    return this->id_medio_a_scrapear;
}

// SETTERS

void RelacionesMedio::setIDMedioAScrapear(unsigned long long int id_medio_a_scrapear)
{
    this->id_medio_a_scrapear = id_medio_a_scrapear;
}

// METODOS

// metodos de IAlmacenable

void RelacionesMedio::parsearValorAlmacenable(std::string valor_almacenable)
{
    herramientas::utiles::Json * json_almacenable = new herramientas::utiles::Json(valor_almacenable);

    this->setJson(json_almacenable);
    this->parsearJson();
}

std::string RelacionesMedio::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesMedio();
}

unsigned long long int RelacionesMedio::hashcode()
{
    return this->getRelacionConConsultas()->hashcode();
}

// metodos de IContieneJson

bool RelacionesMedio::armarJson()
{
    herramientas::utiles::Json * relaciones_medio = new herramientas::utiles::Json();

    relaciones_medio->agregarAtributoArray("ids_consultas", this->getRelacionConConsultas()->getIdsGrupoComoUint());
    
    relaciones_medio->agregarAtributoValor("id_medio_a_scrapear", this->id_medio_a_scrapear);

    this->getJson()->reset();

    this->getJson()->agregarAtributoJson("relaciones_medio", relaciones_medio);

    delete relaciones_medio;

    return true;
}

bool RelacionesMedio::parsearJson()
{
    herramientas::utiles::Json * json_relaciones_medio = this->getJson()->getAtributoValorJson("relaciones_medio");
    
    unsigned long long int id_medio_a_scrapear = json_relaciones_medio->getAtributoValorUint("id_medio_a_scrapear");

    this->setIDMedioAScrapear(id_medio_a_scrapear);

    std::vector<unsigned long long int> ids_consultas = json_relaciones_medio->getAtributoArrayUint("ids_consultas");

    for (std::vector<unsigned long long int>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        this->getRelacionConConsultas()->agregarRelacion(*it);
    }

    delete json_relaciones_medio;

    return true;
}

IRelaciones * RelacionesMedio::clonar()
{
    RelacionesMedio * clon = new RelacionesMedio(this->getId()->copia());

    std::vector<herramientas::utiles::ID*> ids_consultas = this->getRelacionConConsultas()->getIdsGrupo();
    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        clon->agregarRelacionConConsulta(*it);
    }

    clon->setIDMedioAScrapear(this->id_medio_a_scrapear);

    return clon;
}
