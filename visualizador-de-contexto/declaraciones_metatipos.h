#pragma once

#include <QWidget>

// modelo
#include <modelo/include/Concepto.h>
#include <modelo/include/Consulta.h>
#include <modelo/include/Fecha.h>
#include <modelo/include/Periodo.h>
#include <modelo/include/Termino.h>
#include <modelo/include/Reporte.h>
#include <modelo/include/Seccion.h>
#include <modelo/include/Medio.h>
#include <modelo/include/MedioTwitter.h>
#include <modelo/include/MedioFacebook.h>
#include <modelo/include/MedioPortalNoticias.h>

Q_DECLARE_METATYPE(visualizador::modelo::Concepto*)
Q_DECLARE_METATYPE(visualizador::modelo::Consulta*)
Q_DECLARE_METATYPE(visualizador::modelo::Fecha*)
Q_DECLARE_METATYPE(visualizador::modelo::Periodo*)
Q_DECLARE_METATYPE(visualizador::modelo::Termino*)
Q_DECLARE_METATYPE(visualizador::modelo::Reporte*)
Q_DECLARE_METATYPE(visualizador::modelo::Seccion*)
Q_DECLARE_METATYPE(visualizador::modelo::Medio*)
Q_DECLARE_METATYPE(visualizador::modelo::MedioTwitter*)
Q_DECLARE_METATYPE(visualizador::modelo::MedioFacebook*)
Q_DECLARE_METATYPE(visualizador::modelo::MedioPortalNoticias*)
Q_DECLARE_METATYPE(visualizador::modelo::subseccion*)
