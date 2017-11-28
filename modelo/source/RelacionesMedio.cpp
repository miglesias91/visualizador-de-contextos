#include <modelo/include/RelacionesMedio.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

RelacionesMedio::RelacionesMedio(visualizador::aplicacion::ID* id_medio) : IRelaciones(id_medio, aplicacion::ConfiguracionAplicacion::prefijoRelacionesMedio()), relacion_con_consultas(new RelacionConGrupo())
{
}

RelacionesMedio::~RelacionesMedio()
{
    if (NULL != this->relacion_con_consultas)
    {
        delete this->relacion_con_consultas;
        this->relacion_con_consultas = NULL;
    }
}

// GETTERS

// getters de IAlmacenable

std::string RelacionesMedio::getValorAlmacenable()
{
    this->crearContenido();

    return this->getContenido()->jsonString();
}

// SETTERS

// METODOS

// metodos de IAlmacenable

void RelacionesMedio::parsearValorAlmacenable(std::string valor_almacenable)
{
    IJson json_almacenable(valor_almacenable);

    this->parsearContenido(&json_almacenable);
}

std::string RelacionesMedio::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesMedio();
}

unsigned int RelacionesMedio::hashcode()
{
    return this->relacion_con_consultas->hashcode();
}

// metodos de IContieneJson

void RelacionesMedio::crearContenido()
{
    //this->relacion_con_conceptos->crearContenido();
    //IJson* ids_conceptos = this->relacion_con_conceptos->getContenido();

    IJson * relaciones_medio = new IJson();

    relaciones_medio->agregarAtributoArray("ids_consultas", this->relacion_con_consultas->getIdsGrupoComoUint());
    
    IJson* contenido = this->getContenido();
    contenido->reset();

    contenido->agregarAtributoJson("relaciones_medio", relaciones_medio);
}

bool RelacionesMedio::parsearContenido(IJson * contenido)
{
    IJson * json_relaciones_medio = contenido->getAtributoValorJson("relaciones_medio");

    std::vector<unsigned long long int> ids_consultas = json_relaciones_medio->getAtributoArrayUint("ids_consultas");

    for (std::vector<unsigned long long int>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        this->relacion_con_consultas->agregarRelacion(*it);
    }

    return true;
}