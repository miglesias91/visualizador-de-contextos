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

	terminos.push_back(new Termino("corrupcion", "corrupcion"));
	terminos.push_back(new Termino("irregularidad"));
	terminos.push_back(new Termino("irregularidades", "irregularidades"));

	Concepto* concepto = new Concepto(terminos, "corrupcion");

	concepto->agregarTermino(new Termino("desvio", "desvio_etiqueta"));

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
}

TEST(modelo, GettersYSettersConsulta)
{
	visualizador::aplicacion::ConfiguracionAplicacion::leerConfiguracion("configuracion_aplicacion.json");

	visualizador::aplicacion::GestorIDs::setIdActual(0);

	Fecha* inicio_primavera_2017 = new Fecha(21, 9, 2017, "comienzo_primavera_2017");
	Fecha* fin_primavera_2017 = new Fecha(21, 12, 2017, "fin_primavera_2017");

	Periodo* primavera_2017 = new Periodo(inicio_primavera_2017, fin_primavera_2017, "primavera_2017");

	Reporte* reporte = new Grafico("torta");

	std::vector<Termino*> terminos_corrupcion;
	terminos_corrupcion.push_back(new Termino("corrupcion", "corrupcion"));
	terminos_corrupcion.push_back(new Termino("irregularidad", "irregularidad"));

	Concepto* concepto_corrupcion = new Concepto(terminos_corrupcion, "corrupcion");

	std::vector<Termino*> terminos_crisis;
	terminos_crisis.push_back(new Termino("crisis", "crisis"));
	terminos_crisis.push_back(new Termino("conflicto", "conflicto"));
	terminos_crisis.push_back(new Termino("desorden", "desorden"));

	Concepto* concepto_crisis = new Concepto(terminos_crisis, "crisis");

	std::vector<Termino*> terminos_movilizacion;
	terminos_movilizacion.push_back(new Termino("movilizacion", "movilizacion"));
	terminos_movilizacion.push_back(new Termino("paro", "paro"));
	terminos_movilizacion.push_back(new Termino("marcha", "marcha"));

	Concepto* concepto_movilizacion = new Concepto(terminos_movilizacion, "movilizacion");

	std::vector<Concepto*> conceptos;
	conceptos.push_back(concepto_corrupcion);
	conceptos.push_back(concepto_crisis);
	conceptos.push_back(concepto_movilizacion);

	// estos news de los medios en verdad no deberian usarse nunca. (PONER LOS NEW COMO METODOS PRIVADOS.
	Medio* medio_clarin = new Medio("clarin");
	Medio* medio_infobae = new Medio("infobae");

	std::vector<Medio*> medios;
	medios.push_back(medio_clarin);
	medios.push_back(medio_infobae);

	// estos news de las secciones en verdad no deberian usarse nunca. (PONER LOS NEW COMO METODOS PRIVADOS.
	Seccion* seccion_politica = new Seccion("politica");
	Seccion* seccion_economia = new Seccion("economia");

	std::vector<Seccion*> secciones;
	secciones.push_back(seccion_politica);
	secciones.push_back(seccion_economia);

	Consulta* consulta = new Consulta(primavera_2017, reporte, conceptos, medios, secciones, "primavera_2017");

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
}

TEST(modelo, CreacionContenidoYValorAlmacenableConcepto)
{
	visualizador::aplicacion::ConfiguracionAplicacion::leerConfiguracion("configuracion_aplicacion.json");

	visualizador::aplicacion::GestorIDs::setIdActual(0);

	std::vector<Termino*> terminos_movilizacion;
	terminos_movilizacion.push_back(new Termino("movilizacion"));
	terminos_movilizacion.push_back(new Termino("paro", "termino_importante"));
	terminos_movilizacion.push_back(new Termino("marcha"));

	IEntidad* concepto_movilizacion = new Concepto(terminos_movilizacion, "movilizacion");

	concepto_movilizacion->crearContenido();

	std::string json_contenido = concepto_movilizacion->getContenido()->jsonString();
	std::string json_almacenable = concepto_movilizacion->getValorAlmacenable();

	ASSERT_STREQ("{\"ids_terminos\":[0,1,2]}", json_contenido.c_str());
	ASSERT_STREQ("{\"etiqueta\":\"movilizacion\",\"contenido\":{\"ids_terminos\":[0,1,2]}}", json_almacenable.c_str());
}

TEST(modelo, CreacionContenidoYValorAlmacenableTermino)
{
	visualizador::aplicacion::ConfiguracionAplicacion::leerConfiguracion("configuracion_aplicacion.json");

	visualizador::aplicacion::GestorIDs::setIdActual(0);

	IEntidad* movilizacion = new Termino("movilizacion", "paro");

	movilizacion->crearContenido();

	std::string json_contenido = movilizacion->getContenido()->jsonString();
	std::string json_almacenable = movilizacion->getValorAlmacenable();

	ASSERT_STREQ("{\"valor\":\"movilizacion\"}", json_contenido.c_str());
	ASSERT_STREQ("{\"etiqueta\":\"paro\",\"contenido\":{\"valor\":\"movilizacion\"}}", json_almacenable.c_str());
}

TEST(modelo, CreacionContenidoYValorAlmacenableFecha)
{
	visualizador::aplicacion::ConfiguracionAplicacion::leerConfiguracion("configuracion_aplicacion.json");

	visualizador::aplicacion::GestorIDs::setIdActual(0);

	IEntidad* primero_de_enero = new Fecha(1, 1, 2017, "primero_enero");

	primero_de_enero->crearContenido();

	std::string json_contenido = primero_de_enero->getContenido()->jsonString();
	std::string json_almacenable = primero_de_enero->getValorAlmacenable();

	ASSERT_STREQ("{\"dia\":1,\"mes\":1,\"anio\":2017}", json_contenido.c_str());
	ASSERT_STREQ("{\"etiqueta\":\"primero_enero\",\"contenido\":{\"dia\":1,\"mes\":1,\"anio\":2017}}", json_almacenable.c_str());
}

TEST(modelo, CreacionContenidoYValorAlmacenablePeriodo)
{
	visualizador::aplicacion::ConfiguracionAplicacion::leerConfiguracion("configuracion_aplicacion.json");

	visualizador::aplicacion::GestorIDs::setIdActual(0);

	Fecha* primero_de_enero = new Fecha(1, 1, 2017);
	Fecha* primero_de_febrero = new Fecha(1, 2, 2017);

	IEntidad* periodo_enero = new Periodo(primero_de_enero, primero_de_febrero);

	periodo_enero->crearContenido();

	std::string json_contenido_enero = periodo_enero->getContenido()->jsonString();
	std::string json_almacenable = periodo_enero->getValorAlmacenable();

	ASSERT_STREQ("{\"id_fecha_desde\":0,\"id_fecha_hasta\":1}", json_contenido_enero.c_str());
	ASSERT_STREQ("{\"etiqueta\":\"\",\"contenido\":{\"id_fecha_desde\":0,\"id_fecha_hasta\":1}}", json_almacenable.c_str());
}

TEST(modelo, CreacionContenidoYValorAlmacenableConsulta)
{
	visualizador::aplicacion::ConfiguracionAplicacion::leerConfiguracion("configuracion_aplicacion.json");

	visualizador::aplicacion::GestorIDs::setIdActual(0);

	Fecha* inicio_primavera_2017 = new Fecha(21, 9, 2017);
	Fecha* fin_primavera_2017 = new Fecha(21, 12, 2017);

	Periodo* primavera_2017 = new Periodo(inicio_primavera_2017, fin_primavera_2017);

	Reporte* reporte = new Grafico("torta");

	std::vector<Termino*> terminos_corrupcion;
	terminos_corrupcion.push_back(new Termino("corrupcion"));
	terminos_corrupcion.push_back(new Termino("irregularidad"));

	Concepto* concepto_corrupcion = new Concepto(terminos_corrupcion, "corrupcion");

	std::vector<Termino*> terminos_crisis;
	terminos_crisis.push_back(new Termino("crisis"));
	terminos_crisis.push_back(new Termino("conflicto"));
	terminos_crisis.push_back(new Termino("desorden"));

	Concepto* concepto_crisis = new Concepto(terminos_crisis, "crisis");

	std::vector<Termino*> terminos_movilizacion;
	terminos_movilizacion.push_back(new Termino("movilizacion"));
	terminos_movilizacion.push_back(new Termino("paro"));
	terminos_movilizacion.push_back(new Termino("marcha"));

	Concepto* concepto_movilizacion = new Concepto(terminos_movilizacion);

	std::vector<Concepto*> conceptos;
	conceptos.push_back(concepto_corrupcion);
	conceptos.push_back(concepto_crisis);
	conceptos.push_back(concepto_movilizacion);

	// estos news de los medios en verdad no deberian usarse nunca. (PONER LOS NEW COMO METODOS PRIVADOS.
	Medio* medio_clarin = new Medio("clarin");
	Medio* medio_infobae = new Medio("infobae");

	std::vector<Medio*> medios;
	medios.push_back(medio_clarin);
	medios.push_back(medio_infobae);

	// estos news de las secciones en verdad no deberian usarse nunca. (PONER LOS NEW COMO METODOS PRIVADOS.
	Seccion* seccion_politica = new Seccion("politica");
	Seccion* seccion_economia = new Seccion("economia");

	std::vector<Seccion*> secciones;
	secciones.push_back(seccion_politica);
	secciones.push_back(seccion_economia);

	Consulta* consulta = new Consulta(primavera_2017, reporte, conceptos, medios, secciones, "primavera_2017");

	consulta->crearContenido();

	std::string json_contenido_consulta = consulta->getContenido()->jsonString();
	std::string json_almacenable = consulta->getValorAlmacenable();

	ASSERT_STREQ("{\"id_periodo\":2,\"id_reporte\":3,\"ids_conceptos\":[6,10,14],\"ids_medios\":[15,16],\"ids_secciones\":[17,18]}", json_contenido_consulta.c_str());
	ASSERT_STREQ("{\"etiqueta\":\"primavera_2017\",\"contenido\":{\"id_periodo\":2,\"id_reporte\":3,\"ids_conceptos\":[6,10,14],\"ids_medios\":[15,16],\"ids_secciones\":[17,18]}}", json_almacenable.c_str());
}