// stl
#include <fstream>

// gtest
#include <gtest/gtest.h>

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

// modelo
#include <modelo/include/Concepto.h>
#include <modelo/include/Consulta.h>
#include <modelo/include/Fecha.h>
#include <modelo/include/Grafico.h>
#include <modelo/include/Medio.h>
#include <modelo/include/Periodo.h>

using namespace visualizador::modelo;

TEST(modelo, GettersYSettersConceptoYTerminos)
{
    IAlmacenable::getGestorIDs()->setIdActual(0);

	std::vector<Termino*> terminos;

	Termino* termino_corrupcion = new Termino("corrupcion", "corrupcion");
	termino_corrupcion->asignarNuevoId();

	Termino* termino_irregularidad = new Termino("irregularidad");
	termino_irregularidad->asignarNuevoId();
	
	Termino* termino_irregularidades = new Termino("irregularidades", "irregularidades");
	termino_irregularidades->asignarNuevoId();

	terminos.push_back(termino_corrupcion);
	terminos.push_back(termino_irregularidad);
	terminos.push_back(termino_irregularidades);

	Concepto* concepto = new Concepto(terminos, "corrupcion");
	concepto->asignarNuevoId();

	Termino* termino_desvio = new Termino("desvio", "desvio_etiqueta");
	termino_desvio->asignarNuevoId();

	concepto->agregarTermino(termino_desvio);

	terminos = concepto->getTerminos();

	ASSERT_STREQ("corrupcion", terminos[0]->getEtiqueta().c_str());
	ASSERT_STREQ("corrupcion", terminos[0]->getValor().c_str());
	ASSERT_STREQ(visualizador::aplicacion::ConfiguracionAplicacion::prefijoTermino().c_str(), terminos[0]->getGrupo().c_str());
	ASSERT_EQ(0, terminos[0]->getId()->numero());

	ASSERT_STREQ("", terminos[1]->getEtiqueta().c_str());
	ASSERT_STREQ("irregularidad", terminos[1]->getValor().c_str());
	ASSERT_STREQ(visualizador::aplicacion::ConfiguracionAplicacion::prefijoTermino().c_str(), terminos[1]->getGrupo().c_str());
	ASSERT_EQ(1, terminos[1]->getId()->numero());

	ASSERT_STREQ("irregularidades", terminos[2]->getEtiqueta().c_str());
	ASSERT_STREQ("irregularidades", terminos[2]->getValor().c_str());
	ASSERT_STREQ(visualizador::aplicacion::ConfiguracionAplicacion::prefijoTermino().c_str(), terminos[2]->getGrupo().c_str());
	ASSERT_EQ(2, terminos[2]->getId()->numero());

	ASSERT_STREQ("desvio_etiqueta", terminos[3]->getEtiqueta().c_str());
	ASSERT_STREQ("desvio", terminos[3]->getValor().c_str());
	ASSERT_STREQ(visualizador::aplicacion::ConfiguracionAplicacion::prefijoTermino().c_str(), terminos[3]->getGrupo().c_str());
	ASSERT_EQ(4, terminos[3]->getId()->numero());

	ASSERT_STREQ("corrupcion", concepto->getEtiqueta().c_str());
	ASSERT_STREQ(visualizador::aplicacion::ConfiguracionAplicacion::prefijoConcepto().c_str(), concepto->getGrupo().c_str());
	ASSERT_EQ(3, concepto->getId()->numero());

	delete concepto;
}

TEST(modelo, GettersYSettersConsulta)
{
    IAlmacenable::getGestorIDs()->setIdActual(0);

	Fecha* inicio_primavera_2017 = new Fecha(21, 9, 2017, "comienzo_primavera_2017");
	inicio_primavera_2017->asignarNuevoId();

	Fecha* fin_primavera_2017 = new Fecha(21, 12, 2017, "fin_primavera_2017");
	fin_primavera_2017->asignarNuevoId();

	Periodo* primavera_2017 = new Periodo(inicio_primavera_2017, fin_primavera_2017, "primavera_2017");
	primavera_2017->asignarNuevoId();

	Reporte* reporte = new Grafico("torta");
	reporte->asignarNuevoId();

	std::vector<Termino*> terminos_corrupcion;

	Termino* termino_corrupcion = new Termino("corrupcion", "corrupcion");
	termino_corrupcion->asignarNuevoId();

	Termino* termino_irregularidad = new Termino("irregularidad", "irregularidad");
	termino_irregularidad->asignarNuevoId();

	terminos_corrupcion.push_back(termino_corrupcion);
	terminos_corrupcion.push_back(termino_irregularidad);

	Concepto* concepto_corrupcion = new Concepto(terminos_corrupcion, "corrupcion");
	concepto_corrupcion->asignarNuevoId();

	std::vector<Termino*> terminos_crisis;

	Termino* termino_crisis = new Termino("crisis", "crisis");
	termino_crisis->asignarNuevoId();

	Termino* termino_conflicto = new Termino("conflicto", "conflicto");
	termino_conflicto->asignarNuevoId();

	Termino* termino_desorden = new Termino("desorden", "desorden");
	termino_desorden->asignarNuevoId();

	terminos_crisis.push_back(termino_crisis);
	terminos_crisis.push_back(termino_conflicto);
	terminos_crisis.push_back(termino_desorden);

	Concepto* concepto_crisis = new Concepto(terminos_crisis, "crisis");
	concepto_crisis->asignarNuevoId();

	Termino* termino_movilizacion = new Termino("movilizacion", "movilizacion");
	termino_movilizacion->asignarNuevoId();

	Termino* termino_paro = new Termino("paro", "paro");
	termino_paro->asignarNuevoId();

	Termino* termino_marcha = new Termino("marcha", "marcha");
	termino_marcha->asignarNuevoId();

	std::vector<Termino*> terminos_movilizacion;
	terminos_movilizacion.push_back(termino_movilizacion);
	terminos_movilizacion.push_back(termino_paro);
	terminos_movilizacion.push_back(termino_marcha);

	Concepto* concepto_movilizacion = new Concepto(terminos_movilizacion, "movilizacion");
	concepto_movilizacion->asignarNuevoId();

	std::vector<Concepto*> conceptos;
	conceptos.push_back(concepto_corrupcion);
	conceptos.push_back(concepto_crisis);
	conceptos.push_back(concepto_movilizacion);

	// estos news de los medios en verdad no deberian usarse nunca. (PONER LOS NEW COMO METODOS PRIVADOS.
	MedioTwitter* medio_clarin = new MedioTwitter("clarincom", "twitter_clarin");
	medio_clarin->asignarNuevoId();

	MedioTwitter* medio_infobae = new MedioTwitter("infobae", "twitter_infobae");
	medio_infobae->asignarNuevoId();

	std::vector<MedioTwitter*> medios;
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

	std::string nombre = consulta->getEtiqueta();
	Periodo* periodo_recuperado = consulta->getPeriodo();
	Reporte* reporte_recuperado = consulta->getReporte();
	conceptos = consulta->getConceptos();
	medios = consulta->getMediosTwitter();
	secciones = consulta->getSecciones();

	ASSERT_STREQ("primavera_2017", nombre.c_str());
	ASSERT_EQ(19, consulta->getId()->numero());

	ASSERT_STREQ("primavera_2017", periodo_recuperado->getEtiqueta().c_str());

	ASSERT_STREQ("comienzo_primavera_2017", periodo_recuperado->getDesde()->getEtiqueta().c_str());
	ASSERT_EQ(21, periodo_recuperado->getDesde()->getDia());
	ASSERT_EQ(9, periodo_recuperado->getDesde()->getMes());
	ASSERT_EQ(2017, periodo_recuperado->getDesde()->getAnio());

	ASSERT_STREQ("fin_primavera_2017", periodo_recuperado->getHasta()->getEtiqueta().c_str());
	ASSERT_EQ(21, periodo_recuperado->getHasta()->getDia());
	ASSERT_EQ(12, periodo_recuperado->getHasta()->getMes());
	ASSERT_EQ(2017, periodo_recuperado->getHasta()->getAnio());

	ASSERT_STREQ("torta", reporte_recuperado->getEtiqueta().c_str());

	ASSERT_EQ(3, conceptos.size());
	ASSERT_STREQ("crisis", conceptos[1]->getEtiqueta().c_str());

	ASSERT_EQ(3, conceptos[1]->getTerminos().size());
	ASSERT_STREQ("desorden", conceptos[1]->getTerminos()[2]->getEtiqueta().c_str());

	ASSERT_EQ(2, medios.size());
    ASSERT_STREQ("twitter_clarin", medios[0]->getEtiqueta().c_str());
    ASSERT_STREQ("clarincom", medios[0]->getNombreUsuario().c_str());

	ASSERT_EQ(2, secciones.size());
	ASSERT_STREQ("economia", secciones[1]->getEtiqueta().c_str());
    
    delete consulta;

}

TEST(modelo, CreacionJsonYValorAlmacenableConcepto)
{
    IAlmacenable::getGestorIDs()->setIdActual(0);

	Termino* termino_movilizacion = new Termino("movilizacion");
	termino_movilizacion->asignarNuevoId();

	Termino* termino_paro = new Termino("paro", "termino_importante");
	termino_paro->asignarNuevoId();

	Termino* termino_marcha = new Termino("marcha");
	termino_marcha->asignarNuevoId();

	std::vector<Termino*> terminos_movilizacion;
	terminos_movilizacion.push_back(termino_movilizacion);
	terminos_movilizacion.push_back(termino_paro);
	terminos_movilizacion.push_back(termino_marcha);

	Concepto* concepto_movilizacion = new Concepto(terminos_movilizacion, "movilizacion");
	concepto_movilizacion->asignarNuevoId();

	concepto_movilizacion->armarJson();
    std::string json_entidad_almacenable = concepto_movilizacion->getValorAlmacenable();

    concepto_movilizacion->getRelaciones()->armarJson();
    std::string json_relaciones_almacenable = concepto_movilizacion->getRelaciones()->getValorAlmacenable();

    delete concepto_movilizacion;

	ASSERT_STREQ("{\"etiqueta\":\"movilizacion\",\"contenido\":{}}", json_entidad_almacenable.c_str());
    ASSERT_STREQ("{\"relaciones_concepto\":{\"ids_terminos\":[0,1,2],\"ids_consultas\":[]}}", json_relaciones_almacenable.c_str());
}

TEST(modelo, CreacionJsonYValorAlmacenableTermino)
{
    IAlmacenable::getGestorIDs()->setIdActual(0);

	Termino* movilizacion = new Termino("movilizacion", "paro");
	movilizacion->asignarNuevoId();

	movilizacion->armarJson();

	std::string json_contenido = movilizacion->getJson()->jsonString();
	std::string json_almacenable = movilizacion->getValorAlmacenable();

    delete movilizacion;

	ASSERT_STREQ("{\"valor\":\"movilizacion\"}", json_contenido.c_str());
	ASSERT_STREQ("{\"etiqueta\":\"paro\",\"contenido\":{\"valor\":\"movilizacion\"}}", json_almacenable.c_str());
}

TEST(modelo, CreacionJsonYValorAlmacenableFecha)
{
	Fecha* primero_de_enero = new Fecha(1, 1, 2017, "primero_enero");
	primero_de_enero->asignarNuevoId();

	primero_de_enero->armarJson();

	std::string json_contenido = primero_de_enero->getJson()->jsonString();
	std::string json_almacenable = primero_de_enero->getValorAlmacenable();

    delete primero_de_enero;

	ASSERT_STREQ("{\"dia\":1,\"mes\":1,\"anio\":2017}", json_contenido.c_str());
	ASSERT_STREQ("{\"etiqueta\":\"primero_enero\",\"contenido\":{\"dia\":1,\"mes\":1,\"anio\":2017}}", json_almacenable.c_str());
}

TEST(modelo, CreacionJsonYValorAlmacenablePeriodo)
{
    IAlmacenable::getGestorIDs()->setIdActual(0);

	Fecha* primero_de_enero = new Fecha(1, 1, 2017);
	primero_de_enero->asignarNuevoId();

	Fecha* primero_de_febrero = new Fecha(1, 2, 2017);
	primero_de_febrero->asignarNuevoId();

	Periodo* periodo_enero = new Periodo(primero_de_enero, primero_de_febrero);
	periodo_enero->asignarNuevoId();

	periodo_enero->armarJson();
	std::string json_entidad_almacenable = periodo_enero->getValorAlmacenable();

    periodo_enero->getRelaciones()->armarJson();
    std::string json_relaciones_almacenable = periodo_enero->getRelaciones()->getValorAlmacenable();
    
    delete periodo_enero;

    ASSERT_STREQ("{\"etiqueta\":\"\",\"contenido\":{}}", json_entidad_almacenable.c_str());
    ASSERT_STREQ("{\"relaciones_periodo\":{\"id_fecha_desde\":0,\"id_fecha_hasta\":1,\"ids_consultas\":[]}}", json_relaciones_almacenable.c_str());

}

TEST(modelo, CreacionJsonYValorAlmacenableConsulta)
{
    IAlmacenable::getGestorIDs()->setIdActual(0);

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
	MedioTwitter* medio_clarin = new MedioTwitter("clarin");
	medio_clarin->asignarNuevoId();

	MedioTwitter* medio_infobae = new MedioTwitter("infobae");
	medio_infobae->asignarNuevoId();

	std::vector<MedioTwitter*> medios;
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

	consulta->armarJson();
	std::string json_entidad_almacenable = consulta->getValorAlmacenable();

    consulta->getRelaciones()->armarJson();
    std::string json_relaciones_almacenable = consulta->getRelaciones()->getValorAlmacenable();

    delete consulta;

    ASSERT_STREQ("{\"etiqueta\":\"primavera_2017\",\"contenido\":{}}", json_entidad_almacenable.c_str());
    ASSERT_STREQ("{\"relaciones_consulta\":{\"id_periodo\":2,\"id_reporte\":3,\"ids_conceptos\":[6,10,14],\"ids_medios_twitter\":[15,16],\"ids_medios_facebook\":[],\"ids_secciones\":[17,18]}}", json_relaciones_almacenable.c_str());
}

TEST(modelo, ComparacionFechas)
{
    Fecha primero_de_enero(1, 1, 2017);
    Fecha primero_de_enero_2(1, 1, 2017);

    Fecha primero_de_diciembre(1, 12, 2017);
    Fecha primero_de_diciembre_2(1,12,2017);

    ASSERT_EQ(true, primero_de_enero < primero_de_diciembre);
    ASSERT_EQ(false, primero_de_enero > primero_de_diciembre);
    ASSERT_EQ(false, primero_de_enero < primero_de_enero_2);
    ASSERT_EQ(false, primero_de_enero > primero_de_enero_2);

    ASSERT_EQ(true, primero_de_enero <= primero_de_diciembre);
    ASSERT_EQ(false, primero_de_enero >= primero_de_diciembre);
    ASSERT_EQ(true, primero_de_enero <= primero_de_enero_2);
    ASSERT_EQ(true, primero_de_enero >= primero_de_enero_2);

    ASSERT_EQ(true, primero_de_enero == primero_de_enero_2);
    ASSERT_EQ(false, primero_de_enero == primero_de_diciembre);
}