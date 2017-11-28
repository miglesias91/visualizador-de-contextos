#include <modelo/include/RelacionesSeccion.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

RelacionesSeccion::RelacionesSeccion(visualizador::aplicacion::ID* id_seccion) : IRelaciones(id_seccion, aplicacion::ConfiguracionAplicacion::prefijoRelacionesSeccion()), relacion_con_consultas(new RelacionConGrupo())
{
}

RelacionesSeccion::~RelacionesSeccion()
{
    if (NULL != this->relacion_con_consultas)
    {
        delete this->relacion_con_consultas;
        this->relacion_con_consultas = NULL;
    }
}

// GETTERS

// getters de IAlmacenable

std::string RelacionesSeccion::getValorAlmacenable()
{
    this->crearContenido();

    return this->getContenido()->jsonString();
}

// SETTERS

// METODOS

// metodos de IAlmacenable

void RelacionesSeccion::parsearValorAlmacenable(std::string valor_almacenable)
{
    IJson json_almacenable(valor_almacenable);

    this->parsearContenido(&json_almacenable);
}

std::string RelacionesSeccion::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesSeccion();
}

unsigned int RelacionesSeccion::hashcode()
{
    return this->relacion_con_consultas->hashcode();
}

// metodos de IContieneJson

void RelacionesSeccion::crearContenido()
{
    IJson * relaciones_termino = new IJson();

    relaciones_termino->agregarAtributoArray("ids_consultas", this->relacion_con_consultas->getIdsGrupoComoUint());

    IJson* contenido = this->getContenido();
    contenido->reset();

    contenido->agregarAtributoJson("relaciones_seccion", relaciones_termino);
}

bool RelacionesSeccion::parsearContenido(IJson * contenido)
{
    IJson * json_relaciones_termino = contenido->getAtributoValorJson("relaciones_seccion");

    std::vector<unsigned long long int> ids_consultas = json_relaciones_termino->getAtributoArrayUint("ids_consultas");

    for (std::vector<unsigned long long int>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        this->relacion_con_consultas->agregarRelacion(*it);
    }

    return true;
}