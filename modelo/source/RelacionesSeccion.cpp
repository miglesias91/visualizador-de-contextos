#include <modelo/include/RelacionesSeccion.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

RelacionesSeccion::RelacionesSeccion(visualizador::aplicacion::ID* id_seccion) :
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
    this->crearJson();

    return this->getJson()->jsonString();
}

// SETTERS

// METODOS

// metodos de IAlmacenable

void RelacionesSeccion::parsearValorAlmacenable(std::string valor_almacenable)
{
    IJson json_almacenable(valor_almacenable);

    this->parsearJson(&json_almacenable);
}

std::string RelacionesSeccion::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesSeccion();
}

unsigned int RelacionesSeccion::hashcode()
{
    return this->getRelacionConConsultas()->hashcode();
}

// metodos de IContieneJson

void RelacionesSeccion::crearJson()
{
    IJson * relaciones_termino = new IJson();

    relaciones_termino->agregarAtributoArray("ids_consultas", this->getRelacionConConsultas()->getIdsGrupoComoUint());

    IJson* json = this->getJson();
    json->reset();

    json->agregarAtributoJson("relaciones_seccion", relaciones_termino);
}

bool RelacionesSeccion::parsearJson(IJson * json)
{
    IJson * json_relaciones_termino = json->getAtributoValorJson("relaciones_seccion");

    std::vector<unsigned long long int> ids_consultas = json_relaciones_termino->getAtributoArrayUint("ids_consultas");

    for (std::vector<unsigned long long int>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        this->getRelacionConConsultas()->agregarRelacion(*it);
    }

    return true;
}