#include <modelo/include/Fecha.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorRelaciones.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

// CONSTRUCTORES

Fecha::Fecha(std::string etiqueta) : herramientas::utiles::Fecha(etiqueta), IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoFecha(), NULL), relaciones_fecha(NULL)
{
    this->relaciones_fecha = new relaciones::RelacionesFecha();
    this->setRelaciones(this->relaciones_fecha);
}

Fecha::Fecha(unsigned int dia, unsigned int mes, unsigned int anio, std::string etiqueta) : herramientas::utiles::Fecha(dia, mes, anio, etiqueta), IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoFecha(), NULL), relaciones_fecha(NULL)
{
    this->relaciones_fecha = new relaciones::RelacionesFecha();
    this->setRelaciones(this->relaciones_fecha);
}

Fecha::~Fecha()
{
}

// GETTERS

relaciones::RelacionesFecha * Fecha::getRelacionesFecha()
{
    return this->relaciones_fecha;;
}

// SETTERS

void Fecha::setRelacionesFecha(relaciones::RelacionesFecha * relaciones_fecha)
{
    if (NULL != this->relaciones_fecha)
    {
        delete this->relaciones_fecha;
    }

    this->relaciones_fecha = relaciones_fecha;
    this->setRelaciones(this->relaciones_fecha);
}

// METODOS

// metodos de IContieneJson

bool Fecha::armarJson()
{
    this->getJson()->reset();

    this->getJson()->agregarAtributoValor("dia", this->getDia());
    this->getJson()->agregarAtributoValor("mes", this->getMes());
    this->getJson()->agregarAtributoValor("anio", this->getAnio());

    return true;
}

bool Fecha::parsearJson()
{
    unsigned long long int dia = this->getJson()->getAtributoValorUint("dia");
    unsigned long long int mes = this->getJson()->getAtributoValorUint("mes");
    unsigned long long int anio = this->getJson()->getAtributoValorUint("anio");

    this->setDia(dia);
    this->setMes(mes);
    this->setAnio(anio);

    return true;
}

// metodos de IAlmacenable

std::string Fecha::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoFecha();
}

unsigned long long int Fecha::hashcode()
{
    return IHashable::hashear(this->getDia()) + IHashable::hashear(this->getMes()) + IHashable::hashear(this->getAnio());
}

// metodos de IEntidad

IEntidad * Fecha::clonar()
{
    Fecha * clon = new Fecha(this->getDia(), this->getMes(), this->getAnio(), this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setJson(this->getJson()->clonar());
    
    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    relaciones::RelacionesFecha * relaciones_clon = gestor_relaciones.clonar<relaciones::RelacionesFecha>(this->getRelacionesFecha());

    clon->setRelacionesFecha(relaciones_clon);
    
    return clon;
}

// metodos de IRelacionable

bool Fecha::recuperarContenidoDeRelaciones()
{
    return true;
}

void Fecha::actualizarRelaciones(herramientas::utiles::ID * id_nuevo, herramientas::utiles::ID * id_viejo)
{
    // this->relaciones_fecha
}

void Fecha::vincular()
{
    visualizador::aplicacion::GestorRelaciones gestor;
    gestor.vincular(this->relaciones_fecha, this->getId());
}

void Fecha::desvincular()
{
    visualizador::aplicacion::GestorRelaciones gestor;
    gestor.desvincular(this->relaciones_fecha, this->getId());
}

bool Fecha::tieneRelacionesDependientes()
{
    return 0 != this->relaciones_fecha->getRelacionConPeriodos()->getIdsGrupo().size();
}
