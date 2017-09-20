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

	terminos.push_back(new Termino("corrupcion"));
	terminos.push_back(new Termino("irregularidad"));
	terminos.push_back(new Termino("irregularidades"));

	Concepto* concepto = new Concepto("corrupcion", terminos);

	concepto->agregarTermino(new Termino("desvio"));

	terminos = concepto->getTerminos();

	ASSERT_STREQ("corrupcion", terminos[0]->getEtiqueta().c_str());
	ASSERT_STREQ("corrupcion", terminos[0]->getValor().c_str());
	ASSERT_STREQ(visualizador::aplicacion::ConfiguracionAplicacion::prefijoTermino().c_str(), terminos[0]->getGrupo().c_str());
	ASSERT_EQ(0, terminos[0]->getId()->numero());

	ASSERT_STREQ("irregularidad", terminos[1]->getEtiqueta().c_str());
	ASSERT_STREQ("irregularidad", terminos[1]->getValor().c_str());
	ASSERT_STREQ(visualizador::aplicacion::ConfiguracionAplicacion::prefijoTermino().c_str(), terminos[1]->getGrupo().c_str());
	ASSERT_EQ(1, terminos[1]->getId()->numero());

	ASSERT_STREQ("irregularidades", terminos[2]->getEtiqueta().c_str());
	ASSERT_STREQ("irregularidades", terminos[2]->getValor().c_str());
	ASSERT_STREQ(visualizador::aplicacion::ConfiguracionAplicacion::prefijoTermino().c_str(), terminos[2]->getGrupo().c_str());
	ASSERT_EQ(2, terminos[2]->getId()->numero());

	ASSERT_STREQ("desvio", terminos[3]->getEtiqueta().c_str());
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

	Fecha* inicio_primavera_2017 = new Fecha("comienzo_primavera_2017", 21, 9, 2017);
	Fecha* fin_primavera_2017 = new Fecha("fin_primavera_2017", 21, 12, 2017);

	Periodo* primavera_2017 = new Periodo("primavera_2017", inicio_primavera_2017, fin_primavera_2017);

	Reporte* reporte = new Grafico("torta");

	std::vector<Termino*> terminos_corrupcion;
	terminos_corrupcion.push_back(new Termino("corrupcion"));
	terminos_corrupcion.push_back(new Termino("irregularidad"));

	Concepto* concepto_corrupcion = new Concepto("corrupcion", terminos_corrupcion);

	std::vector<Termino*> terminos_crisis;
	terminos_crisis.push_back(new Termino("crisis"));
	terminos_crisis.push_back(new Termino("conflicto"));
	terminos_crisis.push_back(new Termino("desorden"));

	Concepto* concepto_crisis = new Concepto("crisis", terminos_crisis);

	std::vector<Termino*> terminos_movilizacion;
	terminos_movilizacion.push_back(new Termino("movilizacion"));
	terminos_movilizacion.push_back(new Termino("paro"));
	terminos_movilizacion.push_back(new Termino("marcha"));

	Concepto* concepto_movilizacion = new Concepto("movilizacion", terminos_movilizacion);

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

	Consulta* consulta = new Consulta("primavera_2017", primavera_2017, reporte, conceptos, medios, secciones);

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

TEST(modelo, CreacionContenidoConcepto)
{
	visualizador::aplicacion::ConfiguracionAplicacion::leerConfiguracion("configuracion_aplicacion.json");

	visualizador::aplicacion::GestorIDs::setIdActual(0);

	std::vector<Termino*> terminos_movilizacion;
	terminos_movilizacion.push_back(new Termino("movilizacion"));
	terminos_movilizacion.push_back(new Termino("paro"));
	terminos_movilizacion.push_back(new Termino("marcha"));

	Concepto* concepto_movilizacion = new Concepto("movilizacion", terminos_movilizacion);

	concepto_movilizacion->crearContenido();

	std::string string_contenido = concepto_movilizacion->getContenido()->jsonString();

	ASSERT_STREQ("{\"terminos\":[0,1,2]}", string_contenido.c_str());
}

TEST(modelo, CreacionContenidoTermino)
{

}

TEST(modelo, CreacionContenidoConsulta)
{
}

TEST(modelo, CreacionContenidoFecha)
{
}

TEST(modelo, CreacionContenidoPeriodo)
{
}