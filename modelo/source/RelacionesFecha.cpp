#include <modelo/include/RelacionesFecha.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

RelacionesFecha::RelacionesFecha(visualizador::aplicacion::ID* id_fecha) : IRelaciones(id_fecha, aplicacion::ConfiguracionAplicacion::prefijoRelacionesFecha()), relacion_con_periodos(new RelacionConGrupo())
{
}

RelacionesFecha::~RelacionesFecha()
{
    if (NULL != this->relacion_con_periodos)
    {
        delete this->relacion_con_periodos;
        this->relacion_con_periodos = NULL;
    }
}

// GETTERS

// getters de IAlmacenable

std::string RelacionesFecha::getValorAlmacenable()
{
    this->crearContenido();

    return this->getContenido()->jsonString();
}

// SETTERS

// METODOS

// metodos de IAlmacenable

void RelacionesFecha::parsearValorAlmacenable(std::string valor_almacenable)
{
    IJson json_almacenable(valor_almacenable);

    this->parsearContenido(&json_almacenable);
}

std::string RelacionesFecha::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesFecha();
}

unsigned int RelacionesFecha::hashcode()
{
    return this->relacion_con_periodos->hashcode();
}

// metodos de IContieneJson

void RelacionesFecha::crearContenido()
{
    IJson * relaciones_fecha = new IJson();

    relaciones_fecha->agregarAtributoArray("ids_periodos", this->relacion_con_periodos->getIdsGrupoComoUint());

    IJson* contenido = this->getContenido();
    contenido->reset();

    contenido->agregarAtributoJson("relaciones_fecha", relaciones_fecha);
}

bool RelacionesFecha::parsearContenido(IJson * contenido)
{
    IJson * json_relaciones_fecha = contenido->getAtributoValorJson("relaciones_fecha");

    std::vector<unsigned long long int> ids_periodos = json_relaciones_fecha->getAtributoArrayUint("ids_periodos");

    for (std::vector<unsigned long long int>::iterator it = ids_periodos.begin(); it != ids_periodos.end(); it++)
    {
        this->relacion_con_periodos->agregarRelacion(*it);
    }

    return true;
}