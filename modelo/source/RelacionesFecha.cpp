#include <modelo/include/RelacionesFecha.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

RelacionesFecha::RelacionesFecha(herramientas::utiles::ID* id_fecha) :
    IRelaciones(id_fecha, aplicacion::ConfiguracionAplicacion::prefijoRelacionesFecha()),
    IRelacionConPeriodos(new RelacionConGrupo())
{
}

RelacionesFecha::~RelacionesFecha()
{
}

// GETTERS

// getters de IAlmacenable

std::string RelacionesFecha::getValorAlmacenable()
{
    this->armarJson();

    return this->getJson()->jsonString();
}

// SETTERS

// METODOS

// metodos de IAlmacenable

void RelacionesFecha::parsearValorAlmacenable(std::string valor_almacenable)
{
    herramientas::utiles::Json * json_almacenable = new herramientas::utiles::Json(valor_almacenable);

    this->setJson(json_almacenable);
    this->parsearJson();
}

std::string RelacionesFecha::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesFecha();
}

unsigned long long int RelacionesFecha::hashcode()
{
    return this->getRelacionConPeriodos()->hashcode();
}

// metodos de IContieneJson

bool RelacionesFecha::armarJson()
{
    herramientas::utiles::Json * relaciones_fecha = new herramientas::utiles::Json();

    relaciones_fecha->agregarAtributoArray("ids_periodos", this->getRelacionConPeriodos()->getIdsGrupoComoUint());

    this->getJson()->reset();

    this->getJson()->agregarAtributoJson("relaciones_fecha", relaciones_fecha);
    
    delete relaciones_fecha;

    return true;
}

bool RelacionesFecha::parsearJson()
{
    herramientas::utiles::Json * json_relaciones_fecha = this->getJson()->getAtributoValorJson("relaciones_fecha");

    std::vector<unsigned long long int> ids_periodos = json_relaciones_fecha->getAtributoArrayUint("ids_periodos");

    for (std::vector<unsigned long long int>::iterator it = ids_periodos.begin(); it != ids_periodos.end(); it++)
    {
        this->getRelacionConPeriodos()->agregarRelacion(*it);
    }

    delete json_relaciones_fecha;

    return true;
}

IRelaciones * RelacionesFecha::clonar()
{
    RelacionesFecha * clon = new RelacionesFecha(this->getId()->copia());

    std::vector<herramientas::utiles::ID*> ids_periodos = this->getRelacionConPeriodos()->getIdsGrupo();
    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_periodos.begin(); it != ids_periodos.end(); it++)
    {
        clon->agregarRelacionConPeriodo(*it);
    }

    return clon;
}
