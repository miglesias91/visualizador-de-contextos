// stl
#include <fstream>

// gtest
#include <gtest/gtest.h>

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>
#include <aplicacion/include/GestorIDs.h>

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
	visualizador::aplicacion::ConfiguracionAplicacion::leerConfiguracion("configuracion_aplicacion.json");

	visualizador::aplicacion::GestorIDs::setIdActual(0);

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
	visualizador::aplicacion::ConfiguracionAplicacion::leerConfiguracion("configuracion_aplicacion.json");

	visualizador::aplicacion::GestorIDs::setIdActual(0);

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

	std::string nombre = consulta->getEtiqueta();
	Periodo* periodo_recuperado = consulta->getPeriodo();
	Reporte* reporte_recuperado = consulta->getReporte();
	conceptos = consulta->getConceptos();
	medios = consulta->getMedios();
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
	ASSERT_STREQ("clarin", medios[0]->getEtiqueta().c_str());

	ASSERT_EQ(2, secciones.size());
	ASSERT_STREQ("economia", secciones[1]->getEtiqueta().c_str());

	delete consulta;
}

TEST(modelo, CreacionContenidoYValorAlmacenableConcepto)
{
	visualizador::aplicacion::ConfiguracionAplicacion::leerConfiguracion("configuracion_aplicacion.json");

	visualizador::aplicacion::GestorIDs::setIdActual(0);

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

	concepto_movilizacion->crearContenido();

	std::string json_contenido = concepto_movilizacion->getContenido()->jsonString();
	std::string json_almacenable = concepto_movilizacion->getValorAlmacenable();

	ASSERT_STREQ("{\"ids_terminos\":[0,1,2]}", json_contenido.c_str());
	ASSERT_STREQ("{\"etiqueta\":\"movilizacion\",\"contenido\":{\"ids_terminos\":[0,1,2]}}", json_almacenable.c_str());

	delete concepto_movilizacion;
}

TEST(modelo, CreacionContenidoYValorAlmacenableTermino)
{
	visualizador::aplicacion::ConfiguracionAplicacion::leerConfiguracion("configuracion_aplicacion.json");

	visualizador::aplicacion::GestorIDs::setIdActual(0);

	Termino* movilizacion = new Termino("movilizacion", "paro");
	movilizacion->asignarNuevoId();

	movilizacion->crearContenido();

	std::string json_contenido = movilizacion->getContenido()->jsonString();
	std::string json_almacenable = movilizacion->getValorAlmacenable();

	ASSERT_STREQ("{\"valor\":\"movilizacion\"}", json_contenido.c_str());
	ASSERT_STREQ("{\"etiqueta\":\"paro\",\"contenido\":{\"valor\":\"movilizacion\"}}", json_almacenable.c_str());

	delete movilizacion;
}

TEST(modelo, CreacionContenidoYValorAlmacenableFecha)
{
	visualizador::aplicacion::ConfiguracionAplicacion::leerConfiguracion("configuracion_aplicacion.json");

	visualizador::aplicacion::GestorIDs::setIdActual(0);

	Fecha* primero_de_enero = new Fecha(1, 1, 2017, "primero_enero");
	primero_de_enero->asignarNuevoId();

	primero_de_enero->crearContenido();

	std::string json_contenido = primero_de_enero->getContenido()->jsonString();
	std::string json_almacenable = primero_de_enero->getValorAlmacenable();

	ASSERT_STREQ("{\"dia\":1,\"mes\":1,\"anio\":2017}", json_contenido.c_str());
	ASSERT_STREQ("{\"etiqueta\":\"primero_enero\",\"contenido\":{\"dia\":1,\"mes\":1,\"anio\":2017}}", json_almacenable.c_str());

	delete primero_de_enero;
}

TEST(modelo, CreacionContenidoYValorAlmacenablePeriodo)
{
	visualizador::aplicacion::ConfiguracionAplicacion::leerConfiguracion("configuracion_aplicacion.json");

	visualizador::aplicacion::GestorIDs::setIdActual(0);

	Fecha* primero_de_enero = new Fecha(1, 1, 2017);
	primero_de_enero->asignarNuevoId();

	Fecha* primero_de_febrero = new Fecha(1, 2, 2017);
	primero_de_febrero->asignarNuevoId();

	Periodo* periodo_enero = new Periodo(primero_de_enero, primero_de_febrero);
	periodo_enero->asignarNuevoId();

	periodo_enero->crearContenido();

	std::string json_contenido_enero = periodo_enero->getContenido()->jsonString();
	std::string json_almacenable = periodo_enero->getValorAlmacenable();

	ASSERT_STREQ("{\"id_fecha_desde\":0,\"id_fecha_hasta\":1}", json_contenido_enero.c_str());
	ASSERT_STREQ("{\"etiqueta\":\"\",\"contenido\":{\"id_fecha_desde\":0,\"id_fecha_hasta\":1}}", json_almacenable.c_str());

	delete periodo_enero;
}

TEST(modelo, CreacionContenidoYValorAlmacenableConsulta)
{
	visualizador::aplicacion::ConfiguracionAplicacion::leerConfiguracion("configuracion_aplicacion.json");

	visualizador::aplicacion::GestorIDs::setIdActual(0);

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

	consulta->crearContenido();

	std::string json_contenido_consulta = consulta->getContenido()->jsonString();
	std::string json_almacenable = consulta->getValorAlmacenable();

	ASSERT_STREQ("{\"id_periodo\":2,\"id_reporte\":3,\"ids_conceptos\":[6,10,14],\"ids_medios\":[15,16],\"ids_secciones\":[17,18]}", json_contenido_consulta.c_str());
	ASSERT_STREQ("{\"etiqueta\":\"primavera_2017\",\"contenido\":{\"id_periodo\":2,\"id_reporte\":3,\"ids_conceptos\":[6,10,14],\"ids_medios\":[15,16],\"ids_secciones\":[17,18]}}", json_almacenable.c_str());

	delete consulta;
}

TEST(modelo, GettersYSettersIJson)
{
	IJson* json = new IJson("{\"etiqueta\":\"primavera_2017\",\"contenido\":{\"id_periodo\":2,\"id_reporte\":3,\"ids_conceptos\":[6,10,14],\"ids_medios\":[15,16],\"ids_secciones\":[17,18]}}");

	std::string etiqueta = json->getAtributoValorString("etiqueta");

	IJson* contenido = json->getAtributoValorJson("contenido");

	ASSERT_STREQ("{\"id_periodo\":2,\"id_reporte\":3,\"ids_conceptos\":[6,10,14],\"ids_medios\":[15,16],\"ids_secciones\":[17,18]}", contenido->jsonString().c_str());

	unsigned long long int id_periodo = contenido->getAtributoValorUint("id_periodo");
	unsigned long long int id_reporte = contenido->getAtributoValorUint("id_reporte");
	std::vector<unsigned long long int> ids_conceptos = contenido->getAtributoArrayUint("ids_conceptos");

	ASSERT_STREQ("{\"id_periodo\":2,\"id_reporte\":3,\"ids_conceptos\":[6,10,14],\"ids_medios\":[15,16],\"ids_secciones\":[17,18]}", contenido->jsonString().c_str());

	std::vector<unsigned long long int> ids_medios = contenido->getAtributoArrayUint("ids_medios");
	std::vector<unsigned long long int> ids_secciones = contenido->getAtributoArrayUint("ids_secciones");

	ASSERT_STREQ("primavera_2017", etiqueta.c_str());
	ASSERT_STREQ("{\"id_periodo\":2,\"id_reporte\":3,\"ids_conceptos\":[6,10,14],\"ids_medios\":[15,16],\"ids_secciones\":[17,18]}", contenido->jsonString().c_str());

	ASSERT_EQ(2, id_periodo);
	ASSERT_EQ(3, id_reporte);
	
	ASSERT_EQ(6, ids_conceptos[0]);
	ASSERT_EQ(10, ids_conceptos[1]);
	ASSERT_EQ(14, ids_conceptos[2]);

	ASSERT_EQ(15, ids_medios[0]);
	ASSERT_EQ(16, ids_medios[1]);

	ASSERT_EQ(17, ids_secciones[0]);
	ASSERT_EQ(18, ids_secciones[1]);

	delete json;
	delete contenido;
}