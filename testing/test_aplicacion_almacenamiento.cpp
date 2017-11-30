// gtest
#include <gtest/gtest.h>

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>
#include <aplicacion/include/GestorEntidades.h>
#include <aplicacion/include/GestorIDs.h>

// modelo
#include <modelo/include/Concepto.h>
#include <modelo/include/Consulta.h>
#include <modelo/include/Fecha.h>
#include <modelo/include/Grafico.h>
#include <modelo/include/Medio.h>
#include <modelo/include/Periodo.h>

using namespace visualizador::modelo;
using namespace visualizador::aplicacion;

TEST(aplicacionAlmacenamiento, GuardarYCargarNuevoConcepto)
{
	Termino* termino_corrupcion = new Termino("corrupcion", "etiqueta_corurp");
	termino_corrupcion->asignarNuevoId();

	Termino* termino_irregularidad = new Termino("irregularidad","etiqueta_irregular");
	termino_irregularidad->asignarNuevoId();

	std::vector<Termino*> terminos_corrupcion;
	terminos_corrupcion.push_back(termino_corrupcion);
	terminos_corrupcion.push_back(termino_irregularidad);

	Concepto* concepto_corrupcion = new Concepto(terminos_corrupcion, "corrupcion");
	concepto_corrupcion->asignarNuevoId();

	unsigned int hashcode_irregularidad = termino_irregularidad->hashcode();
	unsigned int hashcode_corrupcion = termino_corrupcion->hashcode();
	unsigned int hashcode_concepto_corrupcion = concepto_corrupcion->hashcode();
    
    unsigned int hashcode_relaciones_irregularidad = termino_irregularidad->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_corrupcion = termino_corrupcion->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_concepto_corrupcion = concepto_corrupcion->getRelaciones()->hashcode();

    IAdministradorAplicacion::getInstancia()->almacenar(termino_irregularidad);
    IAdministradorAplicacion::getInstancia()->almacenar(termino_irregularidad->getRelaciones());

    IAdministradorAplicacion::getInstancia()->almacenar(termino_corrupcion);
    IAdministradorAplicacion::getInstancia()->almacenar(termino_corrupcion->getRelaciones());
    
    IAdministradorAplicacion::getInstancia()->almacenar(concepto_corrupcion);
    IAdministradorAplicacion::getInstancia()->almacenar(concepto_corrupcion->getRelaciones());

	Concepto* concepto_a_recuperar = new Concepto();
	concepto_a_recuperar->setId(new ID(*concepto_corrupcion->getId()));

    IAdministradorAplicacion::getInstancia()->recuperar(concepto_a_recuperar);
    IAdministradorAplicacion::getInstancia()->recuperar(concepto_a_recuperar->getRelaciones());
    concepto_a_recuperar->recuperarContenidoDeRelaciones();

	ASSERT_STREQ("corrupcion", concepto_a_recuperar->getEtiqueta().c_str());
    ASSERT_EQ(2, concepto_a_recuperar->getId()->numero());
    ASSERT_EQ(hashcode_concepto_corrupcion, concepto_a_recuperar->hashcode());

    ASSERT_EQ(hashcode_relaciones_concepto_corrupcion, concepto_a_recuperar->getRelaciones()->hashcode());
    ASSERT_EQ(2, concepto_a_recuperar->getRelaciones()->getId()->numero());
    ASSERT_EQ(0, concepto_a_recuperar->getRelacionesConcepto()->getRelacionConTerminos()->getIdsGrupoComoUint()[0]);
    ASSERT_EQ(1, concepto_a_recuperar->getRelacionesConcepto()->getRelacionConTerminos()->getIdsGrupoComoUint()[1]);

	ASSERT_STREQ("etiqueta_corurp", concepto_a_recuperar->getTerminos()[0]->getEtiqueta().c_str());
	ASSERT_EQ(0, concepto_a_recuperar->getTerminos()[0]->getId()->numero());
	ASSERT_STREQ("corrupcion", concepto_a_recuperar->getTerminos()[0]->getValor().c_str());
    ASSERT_EQ(hashcode_corrupcion, concepto_a_recuperar->getTerminos()[0]->hashcode());

    ASSERT_EQ(hashcode_relaciones_corrupcion, concepto_a_recuperar->getTerminos()[0]->getRelaciones()->hashcode());
    ASSERT_EQ(0, concepto_a_recuperar->getTerminos()[0]->getRelaciones()->getId()->numero());
    ASSERT_EQ(2, concepto_a_recuperar->getTerminos()[0]->getRelacionesTermino()->getRelacionConConceptos()->getIdsGrupoComoUint()[0]);

	ASSERT_STREQ("etiqueta_irregular", concepto_a_recuperar->getTerminos()[1]->getEtiqueta().c_str());
	ASSERT_EQ(1, concepto_a_recuperar->getTerminos()[1]->getId()->numero());
	ASSERT_STREQ("irregularidad", concepto_a_recuperar->getTerminos()[1]->getValor().c_str());
	ASSERT_EQ(hashcode_irregularidad, concepto_a_recuperar->getTerminos()[1]->hashcode());

    ASSERT_EQ(hashcode_relaciones_irregularidad, concepto_a_recuperar->getTerminos()[1]->getRelaciones()->hashcode());
    ASSERT_EQ(1, concepto_a_recuperar->getTerminos()[1]->getRelaciones()->getId()->numero());
    ASSERT_EQ(2, concepto_a_recuperar->getTerminos()[1]->getRelacionesTermino()->getRelacionConConceptos()->getIdsGrupoComoUint()[0]);

	delete concepto_a_recuperar;
	delete concepto_corrupcion;
}

TEST(aplicacionAlmacenamiento, GuardarYCargarNuevaConsulta)
{
	GestorIDs::setIdActual(0);

    // 1ero: armo el modelo
	Fecha* inicio_primavera_2017 = new Fecha(21, 9, 2017);
	inicio_primavera_2017->asignarNuevoId();

	Fecha* fin_primavera_2017 = new Fecha(21, 12, 2017);
	fin_primavera_2017->asignarNuevoId();

	Periodo* primavera_2017 = new Periodo(inicio_primavera_2017, fin_primavera_2017);
	primavera_2017->asignarNuevoId();

	Reporte* reporte = new Grafico("torta");
	reporte->asignarNuevoId();

	std::vector<Termino*> terminos_corrupcion;

	Termino* termino_corrupcion = new Termino("corrupcion");
	termino_corrupcion->asignarNuevoId();

	Termino* termino_irregularidad = new Termino("corrupcion");
	termino_irregularidad->asignarNuevoId();

	terminos_corrupcion.push_back(termino_corrupcion);
	terminos_corrupcion.push_back(termino_irregularidad);

	Concepto* concepto_corrupcion = new Concepto(terminos_corrupcion, "corrupcion");
	concepto_corrupcion->asignarNuevoId();

	Termino* termino_crisis = new Termino("crisis");
	termino_crisis->asignarNuevoId();

	Termino* termino_conflicto = new Termino("conflicto");
	termino_conflicto->asignarNuevoId();

	Termino* termino_desorden = new Termino("desorden");
	termino_desorden->asignarNuevoId();

	std::vector<Termino*> terminos_crisis;
	terminos_crisis.push_back(termino_crisis);
	terminos_crisis.push_back(termino_conflicto);
	terminos_crisis.push_back(termino_desorden);

	Concepto* concepto_crisis = new Concepto(terminos_crisis, "crisis");
	concepto_crisis->asignarNuevoId();

	Termino* termino_movilizacion = new Termino("movilizacion");
	termino_movilizacion->asignarNuevoId();

	Termino* termino_paro = new Termino("paro");
	termino_paro->asignarNuevoId();

	Termino* termino_marcha = new Termino("marcha");
	termino_marcha->asignarNuevoId();

	std::vector<Termino*> terminos_movilizacion;
	terminos_movilizacion.push_back(termino_movilizacion);
	terminos_movilizacion.push_back(termino_paro);
	terminos_movilizacion.push_back(termino_marcha);

	Concepto* concepto_movilizacion = new Concepto(terminos_movilizacion);
	concepto_movilizacion->asignarNuevoId();

	std::vector<Concepto*> conceptos;
	conceptos.push_back(concepto_corrupcion);
	conceptos.push_back(concepto_crisis);
	conceptos.push_back(concepto_movilizacion);

	// estos news de los medios en verdad no deberian usarse nunca. (PONER LOS NEW COMO METODOS PRIVADOS.
	Medio* medio_clarin = new Medio("clarin");
	medio_clarin->asignarNuevoId();

	Medio* medio_infobae = new Medio("infobae");
	medio_infobae->asignarNuevoId();

	std::vector<Medio*> medios;
	medios.push_back(medio_clarin);
	medios.push_back(medio_infobae);

	// estos news de las secciones en verdad no deberian usarse nunca. (PONER LOS NEW COMO METODOS PRIVADOS.
	Seccion* seccion_politica = new Seccion("politica");
	seccion_politica->asignarNuevoId();

	Seccion* seccion_economia = new Seccion("economia");
	seccion_economia->asignarNuevoId();

	std::vector<Seccion*> secciones;
	secciones.push_back(seccion_politica);
	secciones.push_back(seccion_economia);

	Consulta* consulta = new Consulta(primavera_2017, reporte, conceptos, medios, secciones, "primavera_2017");
	consulta->asignarNuevoId();

    // 3ero: recupero los hashcodes de las entidades.
    unsigned int hashcode_fecha_desde = inicio_primavera_2017->hashcode();
    unsigned int hashcode_fecha_hasta = fin_primavera_2017->hashcode();
    unsigned int hashcode_periodo = primavera_2017->hashcode();
    unsigned int hashcode_reporte = reporte->hashcode();
    unsigned int hashcode_termino_corrupcion = termino_corrupcion->hashcode();
    unsigned int hashcode_termino_irregularidad = termino_irregularidad->hashcode();
    unsigned int hashcode_concepto_corrupcion = concepto_corrupcion->hashcode();
    unsigned int hashcode_termino_crisis = termino_crisis->hashcode();
    unsigned int hashcode_termino_conflicto = termino_conflicto->hashcode();
    unsigned int hashcode_termino_desorden = termino_desorden->hashcode();
    unsigned int hashcode_concepto_crisis = concepto_crisis->hashcode();
    unsigned int hashcode_termino_movilizacion = termino_movilizacion->hashcode();
    unsigned int hashcode_termino_paro = termino_paro->hashcode();
    unsigned int hashcode_termino_marcha = termino_marcha->hashcode();
    unsigned int hashcode_concepto_movilizacion = concepto_movilizacion->hashcode();
    unsigned int hashcode_medio_clarin = medio_clarin->hashcode();
    unsigned int hashcode_medio_infobae = medio_infobae->hashcode();
    unsigned int hashcode_seccion_politica = seccion_politica->hashcode();
    unsigned int hashcode_seccion_economia = seccion_economia->hashcode();
    unsigned int hashcode_consulta = consulta->hashcode();
    unsigned int hashcode_relaciones_consulta = consulta->getRelaciones()->hashcode();
    
    // 3ero: ahora si recupero los hashcodes de las relaciones porque ya se agrego el id de 'consulta' a las relaciones de todos. (se agrego cuando le asigne un nuevo id a 'consulta': linea 205: "consulta->asignarNuevoId();").
    unsigned int hashcode_relaciones_fecha_desde = inicio_primavera_2017->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_fecha_hasta = fin_primavera_2017->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_periodo = primavera_2017->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_reporte = reporte->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_termino_corrupcion = termino_corrupcion->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_termino_irregularidad = termino_irregularidad->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_concepto_corrupcion = concepto_corrupcion->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_termino_crisis = termino_crisis->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_termino_desorden = termino_desorden->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_termino_conflicto = termino_conflicto->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_concepto_crisis = concepto_crisis->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_termino_movilizacion = termino_movilizacion->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_termino_paro = termino_paro->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_termino_marcha = termino_marcha->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_concepto_movilizacion = concepto_movilizacion->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_medio_clarin = medio_clarin->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_medio_infobae = medio_infobae->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_seccion_politica = seccion_politica->getRelaciones()->hashcode();
    unsigned int hashcode_relaciones_seccion_economia = seccion_economia->getRelaciones()->hashcode();

    // 4to: almaceno todo (con cada una de sus relaciones actualizadas y correctas.
    IAdministradorAplicacion::getInstancia()->almacenar(inicio_primavera_2017);
    IAdministradorAplicacion::getInstancia()->almacenar(inicio_primavera_2017->getRelaciones());
    IAdministradorAplicacion::getInstancia()->almacenar(fin_primavera_2017);
    IAdministradorAplicacion::getInstancia()->almacenar(fin_primavera_2017->getRelaciones());
    IAdministradorAplicacion::getInstancia()->almacenar(primavera_2017);
    IAdministradorAplicacion::getInstancia()->almacenar(primavera_2017->getRelaciones());
    IAdministradorAplicacion::getInstancia()->almacenar(reporte);
    IAdministradorAplicacion::getInstancia()->almacenar(reporte->getRelaciones());
    IAdministradorAplicacion::getInstancia()->almacenar(termino_corrupcion);
    IAdministradorAplicacion::getInstancia()->almacenar(termino_corrupcion->getRelaciones());
    IAdministradorAplicacion::getInstancia()->almacenar(termino_irregularidad);
    IAdministradorAplicacion::getInstancia()->almacenar(termino_irregularidad->getRelaciones());
    IAdministradorAplicacion::getInstancia()->almacenar(concepto_corrupcion);
    IAdministradorAplicacion::getInstancia()->almacenar(concepto_corrupcion->getRelaciones());
    IAdministradorAplicacion::getInstancia()->almacenar(termino_crisis);
    IAdministradorAplicacion::getInstancia()->almacenar(termino_crisis->getRelaciones());
    IAdministradorAplicacion::getInstancia()->almacenar(termino_conflicto);
    IAdministradorAplicacion::getInstancia()->almacenar(termino_conflicto->getRelaciones());
    IAdministradorAplicacion::getInstancia()->almacenar(termino_desorden);
    IAdministradorAplicacion::getInstancia()->almacenar(termino_desorden->getRelaciones());
    IAdministradorAplicacion::getInstancia()->almacenar(concepto_crisis);
    IAdministradorAplicacion::getInstancia()->almacenar(concepto_crisis->getRelaciones());
    IAdministradorAplicacion::getInstancia()->almacenar(termino_movilizacion);
    IAdministradorAplicacion::getInstancia()->almacenar(termino_movilizacion->getRelaciones());
    IAdministradorAplicacion::getInstancia()->almacenar(termino_paro);
    IAdministradorAplicacion::getInstancia()->almacenar(termino_paro->getRelaciones());
    IAdministradorAplicacion::getInstancia()->almacenar(termino_marcha);
    IAdministradorAplicacion::getInstancia()->almacenar(termino_marcha->getRelaciones());
    IAdministradorAplicacion::getInstancia()->almacenar(concepto_movilizacion);
    IAdministradorAplicacion::getInstancia()->almacenar(concepto_movilizacion->getRelaciones());
    IAdministradorAplicacion::getInstancia()->almacenar(medio_clarin);
    IAdministradorAplicacion::getInstancia()->almacenar(medio_clarin->getRelaciones());
    IAdministradorAplicacion::getInstancia()->almacenar(medio_infobae);
    IAdministradorAplicacion::getInstancia()->almacenar(medio_infobae->getRelaciones());
    IAdministradorAplicacion::getInstancia()->almacenar(seccion_politica);
    IAdministradorAplicacion::getInstancia()->almacenar(seccion_politica->getRelaciones());
    IAdministradorAplicacion::getInstancia()->almacenar(seccion_economia);
    IAdministradorAplicacion::getInstancia()->almacenar(seccion_economia->getRelaciones());
    IAdministradorAplicacion::getInstancia()->almacenar(consulta);
    IAdministradorAplicacion::getInstancia()->almacenar(consulta->getRelaciones());

	// 5to: AHORA RECUPERO TODO

	Consulta* consulta_a_recuperar = new Consulta();
	consulta_a_recuperar->setId(new ID(*consulta->getId()));

    IAdministradorAplicacion::getInstancia()->recuperar(consulta_a_recuperar);
    IAdministradorAplicacion::getInstancia()->recuperar(consulta_a_recuperar->getRelaciones());
    consulta_a_recuperar->recuperarContenidoDeRelaciones();

	// test consulta
	ASSERT_STREQ("primavera_2017", consulta_a_recuperar->getEtiqueta().c_str());
	ASSERT_EQ(19, consulta_a_recuperar->getId()->numero());
    ASSERT_EQ(hashcode_consulta, consulta_a_recuperar->hashcode());

    // test relaciones consulta
    ASSERT_EQ(hashcode_relaciones_consulta, consulta_a_recuperar->getRelaciones()->hashcode());

    ASSERT_EQ(17, consulta_a_recuperar->getRelacionesConsulta()->getRelacionConSecciones()->getIdsGrupoComoUint()[0]);
    ASSERT_EQ(18, consulta_a_recuperar->getRelacionesConsulta()->getRelacionConSecciones()->getIdsGrupoComoUint()[1]);

    ASSERT_EQ(15, consulta_a_recuperar->getRelacionesConsulta()->getRelacionConMedios()->getIdsGrupoComoUint()[0]);
    ASSERT_EQ(16, consulta_a_recuperar->getRelacionesConsulta()->getRelacionConMedios()->getIdsGrupoComoUint()[1]);

    ASSERT_EQ(6, consulta_a_recuperar->getRelacionesConsulta()->getRelacionConConceptos()->getIdsGrupoComoUint()[0]);
    ASSERT_EQ(10, consulta_a_recuperar->getRelacionesConsulta()->getRelacionConConceptos()->getIdsGrupoComoUint()[1]);
    ASSERT_EQ(14, consulta_a_recuperar->getRelacionesConsulta()->getRelacionConConceptos()->getIdsGrupoComoUint()[2]);

    ASSERT_EQ(3, consulta_a_recuperar->getRelacionesConsulta()->getRelacionConReporte());

    ASSERT_EQ(2, consulta_a_recuperar->getRelacionesConsulta()->getRelacionConPeriodo());

	// test secciones
	ASSERT_STREQ("politica", consulta_a_recuperar->getSecciones()[0]->getEtiqueta().c_str());
	ASSERT_EQ(17, consulta_a_recuperar->getSecciones()[0]->getId()->numero());
	ASSERT_EQ(hashcode_seccion_politica, consulta_a_recuperar->getSecciones()[0]->hashcode());

	ASSERT_STREQ("economia", consulta_a_recuperar->getSecciones()[1]->getEtiqueta().c_str());
	ASSERT_EQ(18, consulta_a_recuperar->getSecciones()[1]->getId()->numero());
	ASSERT_EQ(hashcode_seccion_economia, consulta_a_recuperar->getSecciones()[1]->hashcode());

    // test relaciones secciones
    ASSERT_EQ(19, consulta_a_recuperar->getSecciones()[0]->getRelacionesSeccion()->getRelacionConConsultas()->getIdsGrupoComoUint()[0]);
    ASSERT_EQ(hashcode_relaciones_seccion_politica, consulta_a_recuperar->getSecciones()[0]->getRelaciones()->hashcode());

    ASSERT_EQ(19, consulta_a_recuperar->getSecciones()[1]->getRelacionesSeccion()->getRelacionConConsultas()->getIdsGrupoComoUint()[0]);
    ASSERT_EQ(hashcode_relaciones_seccion_economia, consulta_a_recuperar->getSecciones()[1]->getRelaciones()->hashcode());

	// test medios
	ASSERT_STREQ("clarin", consulta_a_recuperar->getMedios()[0]->getEtiqueta().c_str());
	ASSERT_EQ(15, consulta_a_recuperar->getMedios()[0]->getId()->numero());
	ASSERT_EQ(hashcode_medio_clarin, consulta_a_recuperar->getMedios()[0]->hashcode());

	ASSERT_STREQ("infobae", consulta_a_recuperar->getMedios()[1]->getEtiqueta().c_str());
	ASSERT_EQ(16, consulta_a_recuperar->getMedios()[1]->getId()->numero());
	ASSERT_EQ(hashcode_medio_infobae, consulta_a_recuperar->getMedios()[1]->hashcode());

    // test relaciones medios
    ASSERT_EQ(19, consulta_a_recuperar->getMedios()[0]->getRelacionesMedio()->getRelacionConConsultas()->getIdsGrupoComoUint()[0]);
    ASSERT_EQ(hashcode_relaciones_medio_clarin, consulta_a_recuperar->getMedios()[0]->getRelaciones()->hashcode());

    ASSERT_EQ(19, consulta_a_recuperar->getMedios()[1]->getRelacionesMedio()->getRelacionConConsultas()->getIdsGrupoComoUint()[0]);
    ASSERT_EQ(hashcode_relaciones_medio_infobae, consulta_a_recuperar->getMedios()[1]->getRelaciones()->hashcode());

	// test concepto 0
	ASSERT_STREQ("corrupcion", consulta_a_recuperar->getConceptos()[0]->getEtiqueta().c_str());
	ASSERT_EQ(6, consulta_a_recuperar->getConceptos()[0]->getId()->numero());
	ASSERT_EQ(hashcode_concepto_corrupcion, consulta_a_recuperar->getConceptos()[0]->hashcode());

	ASSERT_STREQ("corrupcion", consulta_a_recuperar->getConceptos()[0]->getTerminos()[0]->getValor().c_str());
	ASSERT_STREQ("", consulta_a_recuperar->getConceptos()[0]->getTerminos()[0]->getEtiqueta().c_str());
	ASSERT_EQ(4, consulta_a_recuperar->getConceptos()[0]->getTerminos()[0]->getId()->numero());
	ASSERT_EQ(hashcode_termino_corrupcion, consulta_a_recuperar->getConceptos()[0]->getTerminos()[0]->hashcode());

	ASSERT_STREQ("corrupcion", consulta_a_recuperar->getConceptos()[0]->getTerminos()[1]->getValor().c_str());
	ASSERT_STREQ("", consulta_a_recuperar->getConceptos()[0]->getTerminos()[1]->getEtiqueta().c_str());
	ASSERT_EQ(5, consulta_a_recuperar->getConceptos()[0]->getTerminos()[1]->getId()->numero());
	ASSERT_EQ(hashcode_termino_irregularidad, consulta_a_recuperar->getConceptos()[0]->getTerminos()[1]->hashcode());

    // test relaciones concepto 0
    ASSERT_EQ(19, consulta_a_recuperar->getConceptos()[0]->getRelacionesConcepto()->getRelacionConConsultas()->getIdsGrupoComoUint()[0]);
    ASSERT_EQ(hashcode_relaciones_concepto_corrupcion, consulta_a_recuperar->getConceptos()[0]->getRelaciones()->hashcode());

	// test concepto 1
	ASSERT_STREQ("crisis", consulta_a_recuperar->getConceptos()[1]->getEtiqueta().c_str());
	ASSERT_EQ(10, consulta_a_recuperar->getConceptos()[1]->getId()->numero());
	ASSERT_EQ(hashcode_concepto_crisis, consulta_a_recuperar->getConceptos()[1]->hashcode());

	ASSERT_STREQ("crisis", consulta_a_recuperar->getConceptos()[1]->getTerminos()[0]->getValor().c_str());
	ASSERT_STREQ("", consulta_a_recuperar->getConceptos()[1]->getTerminos()[0]->getEtiqueta().c_str());
	ASSERT_EQ(7, consulta_a_recuperar->getConceptos()[1]->getTerminos()[0]->getId()->numero());
	ASSERT_EQ(hashcode_termino_crisis, consulta_a_recuperar->getConceptos()[1]->getTerminos()[0]->hashcode());

	ASSERT_STREQ("conflicto", consulta_a_recuperar->getConceptos()[1]->getTerminos()[1]->getValor().c_str());
	ASSERT_STREQ("", consulta_a_recuperar->getConceptos()[1]->getTerminos()[1]->getEtiqueta().c_str());
	ASSERT_EQ(8, consulta_a_recuperar->getConceptos()[1]->getTerminos()[1]->getId()->numero());
	ASSERT_EQ(hashcode_termino_conflicto, consulta_a_recuperar->getConceptos()[1]->getTerminos()[1]->hashcode());

	ASSERT_STREQ("desorden", consulta_a_recuperar->getConceptos()[1]->getTerminos()[2]->getValor().c_str());
	ASSERT_STREQ("", consulta_a_recuperar->getConceptos()[1]->getTerminos()[2]->getEtiqueta().c_str());
	ASSERT_EQ(9, consulta_a_recuperar->getConceptos()[1]->getTerminos()[2]->getId()->numero());
	ASSERT_EQ(hashcode_termino_desorden, consulta_a_recuperar->getConceptos()[1]->getTerminos()[2]->hashcode());

    // test relaciones concepto 1
    ASSERT_EQ(19, consulta_a_recuperar->getConceptos()[1]->getRelacionesConcepto()->getRelacionConConsultas()->getIdsGrupoComoUint()[0]);
    ASSERT_EQ(hashcode_relaciones_concepto_crisis, consulta_a_recuperar->getConceptos()[1]->getRelaciones()->hashcode());

	// test concepto 2
	ASSERT_STREQ("", consulta_a_recuperar->getConceptos()[2]->getEtiqueta().c_str());
	ASSERT_EQ(14, consulta_a_recuperar->getConceptos()[2]->getId()->numero());
	ASSERT_EQ(hashcode_concepto_movilizacion, consulta_a_recuperar->getConceptos()[2]->hashcode());

	ASSERT_STREQ("movilizacion", consulta_a_recuperar->getConceptos()[2]->getTerminos()[0]->getValor().c_str());
	ASSERT_STREQ("", consulta_a_recuperar->getConceptos()[2]->getTerminos()[0]->getEtiqueta().c_str());
	ASSERT_EQ(11, consulta_a_recuperar->getConceptos()[2]->getTerminos()[0]->getId()->numero());
	ASSERT_EQ(hashcode_termino_movilizacion, consulta_a_recuperar->getConceptos()[2]->getTerminos()[0]->hashcode());

	ASSERT_STREQ("paro", consulta_a_recuperar->getConceptos()[2]->getTerminos()[1]->getValor().c_str());
	ASSERT_STREQ("", consulta_a_recuperar->getConceptos()[2]->getTerminos()[1]->getEtiqueta().c_str());
	ASSERT_EQ(12, consulta_a_recuperar->getConceptos()[2]->getTerminos()[1]->getId()->numero());
	ASSERT_EQ(hashcode_termino_paro, consulta_a_recuperar->getConceptos()[2]->getTerminos()[1]->hashcode());

	ASSERT_STREQ("marcha", consulta_a_recuperar->getConceptos()[2]->getTerminos()[2]->getValor().c_str());
	ASSERT_STREQ("", consulta_a_recuperar->getConceptos()[2]->getTerminos()[2]->getEtiqueta().c_str());
	ASSERT_EQ(13, consulta_a_recuperar->getConceptos()[2]->getTerminos()[2]->getId()->numero());
	ASSERT_EQ(hashcode_termino_marcha, consulta_a_recuperar->getConceptos()[2]->getTerminos()[2]->hashcode());

    // test relaciones concepto 2
    ASSERT_EQ(19, consulta_a_recuperar->getConceptos()[2]->getRelacionesConcepto()->getRelacionConConsultas()->getIdsGrupoComoUint()[0]);
    ASSERT_EQ(hashcode_relaciones_concepto_movilizacion, consulta_a_recuperar->getConceptos()[2]->getRelaciones()->hashcode());

	// test reporte
	ASSERT_STREQ("torta", consulta_a_recuperar->getReporte()->getEtiqueta().c_str());
	ASSERT_EQ(3, consulta_a_recuperar->getReporte()->getId()->numero());
	ASSERT_EQ(hashcode_reporte, consulta_a_recuperar->getReporte()->hashcode());

    // test relaciones reporte
    ASSERT_EQ(19, consulta_a_recuperar->getReporte()->getRelacionesReporte()->getRelacionConConsultas()->getIdsGrupoComoUint()[0]);
    ASSERT_EQ(hashcode_relaciones_reporte, consulta_a_recuperar->getReporte()->getRelaciones()->hashcode());

	// test periodo
	ASSERT_STREQ("", consulta_a_recuperar->getPeriodo()->getEtiqueta().c_str());
	ASSERT_EQ(2, consulta_a_recuperar->getPeriodo()->getId()->numero());
	ASSERT_EQ(hashcode_periodo, consulta_a_recuperar->getPeriodo()->hashcode());

	ASSERT_STREQ("", consulta_a_recuperar->getPeriodo()->getDesde()->getEtiqueta().c_str());
	ASSERT_EQ(0, consulta_a_recuperar->getPeriodo()->getDesde()->getId()->numero());
	ASSERT_EQ(21, consulta_a_recuperar->getPeriodo()->getDesde()->getDia());
	ASSERT_EQ(9, consulta_a_recuperar->getPeriodo()->getDesde()->getMes());
	ASSERT_EQ(2017, consulta_a_recuperar->getPeriodo()->getDesde()->getAnio());
	ASSERT_EQ(hashcode_fecha_desde, consulta_a_recuperar->getPeriodo()->getDesde()->hashcode());

	
	ASSERT_STREQ("", consulta_a_recuperar->getPeriodo()->getHasta()->getEtiqueta().c_str());
	ASSERT_EQ(1, consulta_a_recuperar->getPeriodo()->getHasta()->getId()->numero());
	ASSERT_EQ(21, consulta_a_recuperar->getPeriodo()->getHasta()->getDia());
	ASSERT_EQ(12, consulta_a_recuperar->getPeriodo()->getHasta()->getMes());
	ASSERT_EQ(2017, consulta_a_recuperar->getPeriodo()->getHasta()->getAnio());
	ASSERT_EQ(hashcode_fecha_hasta, consulta_a_recuperar->getPeriodo()->getHasta()->hashcode());

    // test relaciones reporte
    ASSERT_EQ(19, consulta_a_recuperar->getPeriodo()->getRelacionesPeriodo()->getRelacionConConsultas()->getIdsGrupoComoUint()[0]);
    ASSERT_EQ(hashcode_relaciones_periodo, consulta_a_recuperar->getPeriodo()->getRelaciones()->hashcode());

	delete consulta;
	delete consulta_a_recuperar;
}

TEST(aplicacionAlmacenamiento, GuardarYCargarIDActualCorrectamente)
{
	GestorIDs::setIdActual(100);

	Termino* termino_corrupcion = new Termino("corrupcion", "etiqueta_corurp");
	termino_corrupcion->asignarNuevoId();

	Termino* termino_irregularidad = new Termino("irregularidad", "etiqueta_irregular");
	termino_irregularidad->asignarNuevoId();

	std::vector<Termino*> terminos_corrupcion;
	terminos_corrupcion.push_back(termino_corrupcion);
	terminos_corrupcion.push_back(termino_irregularidad);

	Concepto* concepto_corrupcion = new Concepto(terminos_corrupcion, "corrupcion");
	concepto_corrupcion->asignarNuevoId();

	IAdministradorAplicacion::getInstancia()->almacenar(termino_irregularidad);
	IAdministradorAplicacion::getInstancia()->almacenar(termino_corrupcion);
	IAdministradorAplicacion::getInstancia()->almacenar(concepto_corrupcion);

	Concepto* concepto_a_recuperar = new Concepto();
	concepto_a_recuperar->setId(new ID(*concepto_corrupcion->getId()));

	IAdministradorAplicacion::getInstancia()->recuperar(concepto_a_recuperar);

	IAdministradorAplicacion::getInstancia()->cerrarBD();
	unsigned long long int id_actual = GestorIDs::getIdActual();
	IAdministradorAplicacion::getInstancia()->abrirBD();

	unsigned long long int id_actual_recuperado = IAdministradorAplicacion::getInstancia()->recuperarIDActual();

	delete concepto_corrupcion;
	delete concepto_a_recuperar;

	ASSERT_EQ(id_actual, id_actual_recuperado);
}

TEST(aplicacionAlmacenamiento, GestorEntidadAlmacenarCorrectamente)
{
    GestorIDs::setIdActual(200);

	GestorEntidades gestor_conceptos;
	gestor_conceptos.gestionar<Concepto>();

    Termino* termino1 = new Termino("termino_ok", "gestorentidad-almacenamiento-test");
    termino1->asignarNuevoId();

    Termino* termino2 = new Termino("termino_ok2", "gestorentidad-almacenamiento-test");
    termino2->asignarNuevoId();

    std::vector<Termino*> terminos_corrupcion;
    terminos_corrupcion.push_back(termino1);
    terminos_corrupcion.push_back(termino2);

    Concepto* concepto1 = new Concepto(terminos_corrupcion, "gestorentidad-almacenamiento-test");
    concepto1->asignarNuevoId();

    GestorEntidades gestor_terminos;
    gestor_terminos.gestionar<Termino>();
    gestor_terminos.almacenar(termino1);
    gestor_terminos.almacenar(termino2);
    gestor_terminos.guardarCambios();

    gestor_conceptos.almacenar(concepto1);

    gestor_conceptos.guardarCambios();

    GestorEntidades gestor_conceptos_nuevo;
    gestor_conceptos_nuevo.gestionar<Concepto>();

    bool existe = gestor_conceptos_nuevo.existe(concepto1);

    delete concepto1;

    ASSERT_EQ(true, existe);
}

TEST(aplicacionAlmacenamiento, GestorEntidadEliminarCorrectamente)
{
    GestorIDs::setIdActual(200);

    GestorEntidades gestor_conceptos;
    gestor_conceptos.gestionar<Concepto>();

    Termino* termino1 = new Termino("termino_ok", "gestorentidad-almacenamiento-test");
    termino1->asignarNuevoId();

    Termino* termino2 = new Termino("termino_ok2", "gestorentidad-almacenamiento-test");
    termino2->asignarNuevoId();

    std::vector<Termino*> terminos_corrupcion;
    terminos_corrupcion.push_back(termino1);
    terminos_corrupcion.push_back(termino2);

    Concepto* concepto1 = new Concepto(terminos_corrupcion, "gestorentidad-almacenamiento-test");
    concepto1->asignarNuevoId();
    gestor_conceptos.eliminar(concepto1);

    gestor_conceptos.guardarCambios();

    GestorEntidades gestor_terminos;
    gestor_terminos.gestionar<Termino>();

    gestor_terminos.eliminar(termino1);
    gestor_terminos.eliminar(termino2);

    gestor_terminos.guardarCambios();

    GestorEntidades gestor_conceptos_nuevo;
    gestor_conceptos_nuevo.gestionar<Concepto>();
    bool existe1 = gestor_conceptos_nuevo.existe(concepto1);

    GestorEntidades gestor_terminos_nuevo;
    gestor_terminos_nuevo.gestionar<Termino>();

    bool existe2 = gestor_terminos_nuevo.existe(termino1);
    bool existe3 = gestor_terminos_nuevo.existe(termino2);

    delete concepto1;

    ASSERT_EQ(false, existe1);
    ASSERT_EQ(false, existe2);
    ASSERT_EQ(false, existe3);
}