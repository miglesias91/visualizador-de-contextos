#pragma once

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

    virtual bool vincular(modelo::relaciones::RelacionesConcepto * relaciones_concepto, aplicacion::ID * id_concepto);
    virtual bool vincular(modelo::relaciones::RelacionesConsulta * relaciones_consulta, aplicacion::ID * id_consulta);
    virtual bool vincular(modelo::relaciones::RelacionesFecha * relaciones_fecha, aplicacion::ID * id_fecha);
    virtual bool vincular(modelo::relaciones::RelacionesMedio * relaciones_medio, aplicacion::ID * id_medio);
    virtual bool vincular(modelo::relaciones::RelacionesPeriodo * relaciones_periodo, aplicacion::ID * id_periodo);
    virtual bool vincular(modelo::relaciones::RelacionesReporte * relaciones_reporte, aplicacion::ID * id_reporte);
    virtual bool vincular(modelo::relaciones::RelacionesSeccion * relaciones_seccion, aplicacion::ID * id_seccion);
    virtual bool vincular(modelo::relaciones::RelacionesTermino * relaciones_termino, aplicacion::ID * id_termino);

    virtual bool desvincular(modelo::relaciones::RelacionesConcepto * relaciones_termino, aplicacion::ID * id_concepto);
    virtual bool desvincular(modelo::relaciones::RelacionesConsulta * relaciones_consulta, aplicacion::ID * id_consulta);
    virtual bool desvincular(modelo::relaciones::RelacionesFecha * relaciones_fecha, aplicacion::ID * id_fecha);
    virtual bool desvincular(modelo::relaciones::RelacionesMedio * relaciones_medio, aplicacion::ID * id_medio);
    virtual bool desvincular(modelo::relaciones::RelacionesPeriodo * relaciones_periodo, aplicacion::ID * id_periodo);
    virtual bool desvincular(modelo::relaciones::RelacionesReporte * relaciones_reporte, aplicacion::ID * id_reporte);
    virtual bool desvincular(modelo::relaciones::RelacionesSeccion * relaciones_seccion, aplicacion::ID * id_seccion);
    virtual bool desvincular(modelo::relaciones::RelacionesTermino * relaciones_termino, aplicacion::ID * id_termino);

private:

};

};
};


