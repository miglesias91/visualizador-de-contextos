#include <modelo/include/RelacionesPeriodo.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

RelacionesPeriodo::RelacionesPeriodo(visualizador::aplicacion::ID* id_periodo) : IRelaciones(id_periodo, aplicacion::ConfiguracionAplicacion::prefijoRelacionesPeriodo()),
    relacion_con_consultas(new RelacionConGrupo()), relacion_con_fecha_desde(0), relacion_con_fecha_hasta(0)
{
}

RelacionesPeriodo::~RelacionesPeriodo()
{
    if (NULL != this->relacion_con_consultas)
    {
        delete this->relacion_con_consultas;
        this->relacion_con_consultas = NULL;
    }
}

// GETTERS

// getters de IAlmacenable

std::string RelacionesPeriodo::getValorAlmacenable()
{
    this->crearContenido();

    return this->getContenido()->jsonString();
}

// SETTERS

// METODOS

// metodos de IAlmacenable

void RelacionesPeriodo::parsearValorAlmacenable(std::string valor_almacenable)
{
    IJson json_almacenable(valor_almacenable);

    this->parsearContenido(&json_almacenable);
}

std::string RelacionesPeriodo::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesPeriodo();
}

unsigned int RelacionesPeriodo::hashcode()
{
    return this->relacion_con_fecha_desde + this->relacion_con_fecha_hasta + this->relacion_con_consultas->hashcode();
}

// metodos de IContieneJson

void RelacionesPeriodo::crearContenido()
{
    IJson * relaciones_periodo = new IJson();

    relaciones_periodo->agregarAtributoValor("id_fecha_desde", this->relacion_con_fecha_desde);
    relaciones_periodo->agregarAtributoValor("id_fecha_hasta", this->relacion_con_fecha_desde);

    relaciones_periodo->agregarAtributoArray("ids_consultas", this->relacion_con_consultas->getIdsGrupoComoUint());

    IJson* contenido = this->getContenido();
    contenido->reset();

    contenido->agregarAtributoJson("relaciones_periodo", relaciones_periodo);
}

bool RelacionesPeriodo::parsearContenido(IJson * contenido)
{
    IJson * json_relaciones_periodo = contenido->getAtributoValorJson("relaciones_periodo");

    std::vector<unsigned long long int> ids_consultas = json_relaciones_periodo->getAtributoArrayUint("ids_consultas");

    for (std::vector<unsigned long long int>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        this->relacion_con_consultas->agregarRelacion(*it);
    }

    this->relacion_con_fecha_desde = json_relaciones_periodo->getAtributoValorUint("id_fecha_desde");
    this->relacion_con_fecha_hasta = json_relaciones_periodo->getAtributoValorUint("id_fecha_hasta");

    return true;
}