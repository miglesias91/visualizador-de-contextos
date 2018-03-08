#pragma once

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>

// modelo
#include <modelo/include/RelacionesConcepto.h>
#include <modelo/include/RelacionesConsulta.h>
#include <modelo/include/RelacionesFecha.h>
#include <modelo/include/RelacionesMedio.h>
#include <modelo/include/RelacionesPeriodo.h>
#include <modelo/include/RelacionesReporte.h>
#include <modelo/include/RelacionesSeccion.h>
#include <modelo/include/RelacionesTermino.h>

using namespace visualizador;

namespace visualizador
{
namespace aplicacion
{

class GestorRelaciones
{
public:
    GestorRelaciones();
    virtual ~GestorRelaciones();

    // GETTERS

    // SETTERS

    // METODOS

    virtual bool vincular(modelo::relaciones::RelacionesConcepto * relaciones_concepto, herramientas::utiles::ID * id_concepto);
    virtual bool vincular(modelo::relaciones::RelacionesConsulta * relaciones_consulta, herramientas::utiles::ID * id_consulta);
    virtual bool vincular(modelo::relaciones::RelacionesFecha * relaciones_fecha, herramientas::utiles::ID * id_fecha);
    virtual bool vincular(modelo::relaciones::RelacionesPeriodo * relaciones_periodo, herramientas::utiles::ID * id_periodo);
    virtual bool vincular(modelo::relaciones::RelacionesReporte * relaciones_reporte, herramientas::utiles::ID * id_reporte);
    virtual bool vincular(modelo::relaciones::RelacionesSeccion * relaciones_seccion, herramientas::utiles::ID * id_seccion);
    virtual bool vincular(modelo::relaciones::RelacionesTermino * relaciones_termino, herramientas::utiles::ID * id_termino);

    virtual bool vincularMedioTwitter(modelo::relaciones::RelacionesMedio * relaciones_medio, herramientas::utiles::ID * id_medio);
    virtual bool vincularMedioFacebook(modelo::relaciones::RelacionesMedio * relaciones_medio, herramientas::utiles::ID * id_medio);

    virtual bool desvincular(modelo::relaciones::RelacionesConcepto * relaciones_termino, herramientas::utiles::ID * id_concepto);
    virtual bool desvincular(modelo::relaciones::RelacionesConsulta * relaciones_consulta, herramientas::utiles::ID * id_consulta);
    virtual bool desvincular(modelo::relaciones::RelacionesFecha * relaciones_fecha, herramientas::utiles::ID * id_fecha);
    virtual bool desvincular(modelo::relaciones::RelacionesPeriodo * relaciones_periodo, herramientas::utiles::ID * id_periodo);
    virtual bool desvincular(modelo::relaciones::RelacionesReporte * relaciones_reporte, herramientas::utiles::ID * id_reporte);
    virtual bool desvincular(modelo::relaciones::RelacionesSeccion * relaciones_seccion, herramientas::utiles::ID * id_seccion);
    virtual bool desvincular(modelo::relaciones::RelacionesTermino * relaciones_termino, herramientas::utiles::ID * id_termino);

    virtual bool desvincularMedioTwitter(modelo::relaciones::RelacionesMedio * relaciones_medio, herramientas::utiles::ID * id_medio);
    virtual bool desvincularMedioFacebook(modelo::relaciones::RelacionesMedio * relaciones_medio, herramientas::utiles::ID * id_medio);

    // clona la entidad devolviendo un puntero de la clase especifica de la entidad.
    // Similar al metodo "clonar" de cada entidad, solo que agrega el tipo de entidad indicado en <ENTIDAD>.
    template <class RELACIONES>
    RELACIONES* clonar(visualizador::modelo::relaciones::IRelaciones * relaciones_a_clonar);

private:

    IAdministradorAplicacion * admin_app;

};


template <class RELACIONES>
RELACIONES* GestorRelaciones::clonar(visualizador::modelo::relaciones::IRelaciones * relaciones_a_clonar)
{
    visualizador::modelo::relaciones::IRelaciones * relaciones_clonada = relaciones_a_clonar->clonar();
    return static_cast<RELACIONES*>(relaciones_clonada);
}

};
};