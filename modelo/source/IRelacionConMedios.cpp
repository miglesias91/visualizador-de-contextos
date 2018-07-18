#include <modelo/include/IRelacionConMedios.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

IRelacionConMedios::IRelacionConMedios(RelacionConGrupo * relacion_con_medios, RelacionConGrupo * relacion_con_medios_facebook)
    : relacion_con_medios_twitter(relacion_con_medios), relacion_con_medios_facebook(relacion_con_medios_facebook)
{
}

IRelacionConMedios::~IRelacionConMedios()
{
    if (NULL != this->relacion_con_medios_twitter)
    {
        delete this->relacion_con_medios_twitter;
        this->relacion_con_medios_twitter = NULL;
    }
    
    if (NULL != this->relacion_con_medios_facebook)
    {
        delete this->relacion_con_medios_facebook;
        this->relacion_con_medios_facebook = NULL;
    }
}

// GETTERS

RelacionConGrupo * IRelacionConMedios::getRelacionConMediosTwitter()
{
    return this->relacion_con_medios_twitter;
}

RelacionConGrupo * IRelacionConMedios::getRelacionConMediosFacebook()
{
    return this->relacion_con_medios_facebook;
}

RelacionConGrupo * IRelacionConMedios::getRelacionConMediosPortalNoticias()
{
    return this->relacion_con_medios_portal_noticias;
}

// SETTERS

void IRelacionConMedios::setRelacionConMediosTwitter(RelacionConGrupo * relacion_con_medios_twitter)
{
    this->relacion_con_medios_twitter = relacion_con_medios_twitter;
}

void IRelacionConMedios::setRelacionConMediosFacebook(RelacionConGrupo * relacion_con_medios_facebook)
{
    this->relacion_con_medios_facebook = relacion_con_medios_facebook;
}

void IRelacionConMedios::setRelacionConMediosPortalNoticias(RelacionConGrupo * relacion_con_medios)
{
    this->relacion_con_medios_portal_noticias = relacion_con_medios_facebook;
}

// METODOS

void IRelacionConMedios::agregarRelacionConMedioTwitter(herramientas::utiles::ID * id_medio)
{
    this->relacion_con_medios_twitter->agregarRelacion(id_medio);
}

void IRelacionConMedios::eliminarRelacionConMedioTwitter(herramientas::utiles::ID * id_medio)
{
    this->relacion_con_medios_twitter->eliminarRelacion(id_medio);
}

void IRelacionConMedios::actualizarRelacionConMedioTwitter(herramientas::utiles::ID * id_medio_nuevo, herramientas::utiles::ID * id_medio_viejo)
{
    this->relacion_con_medios_twitter->actualizarRelacion(id_medio_nuevo, id_medio_viejo);
}

void IRelacionConMedios::agregarRelacionConMedioFacebook(herramientas::utiles::ID * id_medio)
{
    this->relacion_con_medios_facebook->agregarRelacion(id_medio);
}

void IRelacionConMedios::eliminarRelacionConMedioFacebook(herramientas::utiles::ID * id_medio)
{
    this->relacion_con_medios_facebook->eliminarRelacion(id_medio);
}

void IRelacionConMedios::actualizarRelacionConMedioFacebook(herramientas::utiles::ID * id_medio_nuevo, herramientas::utiles::ID * id_medio_viejo)
{
    this->relacion_con_medios_facebook->actualizarRelacion(id_medio_nuevo, id_medio_viejo);
}

void IRelacionConMedios::agregarRelacionConMedioPortalNoticias(herramientas::utiles::ID * id_medio)
{
    this->relacion_con_medios_portal_noticias->agregarRelacion(id_medio);
}

void IRelacionConMedios::eliminarRelacionConMedioPortalNoticias(herramientas::utiles::ID * id_medio)
{
    this->relacion_con_medios_portal_noticias->eliminarRelacion(id_medio);
}

void IRelacionConMedios::actualizarRelacionConMedioPortalNoticias(herramientas::utiles::ID * id_medio_nuevo, herramientas::utiles::ID * id_medio_viejo)
{
    this->relacion_con_medios_portal_noticias->actualizarRelacion(id_medio_nuevo, id_medio_viejo);
}