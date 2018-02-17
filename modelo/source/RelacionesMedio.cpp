#include <modelo/include/RelacionesMedio.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

RelacionesMedio::RelacionesMedio(herramientas::utiles::ID* id_medio) :
    IRelaciones(id_medio, aplicacion::ConfiguracionAplicacion::prefijoRelacionesMedio()),
    IRelacionConConsultas(new RelacionConGrupo())
{
}

RelacionesMedio::~RelacionesMedio()
{
}

// GETTERS

// getters de IAlmacenable

std::string RelacionesMedio::getValorAlmacenable()
{
    this->crearJson();

    return this->getJson()->jsonString();
}

// SETTERS

// METODOS

// metodos de IAlmacenable

void RelacionesMedio::parsearValorAlmacenable(std::string valor_almacenable)
{
    IJson json_almacenable(valor_almacenable);

    this->parsearJson(&json_almacenable);
}

std::string RelacionesMedio::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesMedio();
}

unsigned int RelacionesMedio::hashcode()
{
    return this->getRelacionConConsultas()->hashcode();
}

// metodos de IContieneJson

void RelacionesMedio::crearJson()
{
    //this->relacion_con_conceptos->crearJson();
    //IJson* ids_conceptos = this->relacion_con_conceptos->getJson();

    IJson * relaciones_medio = new IJson();

    relaciones_medio->agregarAtributoArray("ids_consultas", this->getRelacionConConsultas()->getIdsGrupoComoUint());
    
    IJson* json = this->getJson();
    json->reset();

    json->agregarAtributoJson("relaciones_medio", relaciones_medio);
    
    delete relaciones_medio;
}

bool RelacionesMedio::parsearJson(IJson * json)
{
    IJson * json_relaciones_medio = json->getAtributoValorJson("relaciones_medio");

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

    return clon;
}
