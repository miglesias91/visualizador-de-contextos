#include <modelo/include/RelacionesSeccion.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

RelacionesSeccion::RelacionesSeccion(herramientas::utiles::ID* id_seccion) :
    IRelaciones(id_seccion, aplicacion::ConfiguracionAplicacion::prefijoRelacionesSeccion()),
    IRelacionConConsultas(new RelacionConGrupo())
{
}

RelacionesSeccion::~RelacionesSeccion()
{
}

// GETTERS

// getters de IAlmacenable

std::string RelacionesSeccion::getValorAlmacenable()
{
    this->armarJson();

    return this->getJson()->jsonString();
}

// SETTERS

// METODOS

// metodos de IAlmacenable

void RelacionesSeccion::parsearValorAlmacenable(std::string valor_almacenable)
{
    herramientas::utiles::Json * json_almacenable = new herramientas::utiles::Json(valor_almacenable);

    this->setJson(json_almacenable);
    this->parsearJson();
}

std::string RelacionesSeccion::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesSeccion();
}

unsigned long long int RelacionesSeccion::hashcode()
{
    return this->getRelacionConConsultas()->hashcode();
}

// metodos de IContieneJson

bool RelacionesSeccion::armarJson()
{
    herramientas::utiles::Json * relaciones_termino = new herramientas::utiles::Json();

    relaciones_termino->agregarAtributoArray("ids_consultas", this->getRelacionConConsultas()->getIdsGrupoComoUint());

    this->getJson()->reset();

    this->getJson()->agregarAtributoJson("relaciones_seccion", relaciones_termino);

    delete relaciones_termino;

    return true;
}

bool RelacionesSeccion::parsearJson()
{
    herramientas::utiles::Json * json_relaciones_seccion = this->getJson()->getAtributoValorJson("relaciones_seccion");

    std::vector<unsigned long long int> ids_consultas = json_relaciones_seccion->getAtributoArrayUint("ids_consultas");

    for (std::vector<unsigned long long int>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        this->getRelacionConConsultas()->agregarRelacion(*it);
    }

    delete json_relaciones_seccion;

    return true;
}

IRelaciones * RelacionesSeccion::clonar()
{
    RelacionesSeccion * clon = new RelacionesSeccion(this->getId()->copia());

    std::vector<herramientas::utiles::ID*> ids_consultas = this->getRelacionConConsultas()->getIdsGrupo();
    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        clon->agregarRelacionConConsulta(*it);
    }

    return clon;
}
