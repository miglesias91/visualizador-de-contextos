// gtest
#include <gtest/gtest.h>

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>
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

TEST(aplicacionAlmacenamiento, GuardarYCargarNuevoConcepto)
{
	visualizador::aplicacion::IAdministradorAplicacion::crearAdministradorAplicacionLocal();

	visualizador::aplicacion::ConfiguracionAplicacion::leerConfiguracion("configuracion_aplicacion.json");

	visualizador::aplicacion::GestorIDs::setIdActual(0);

	Termino* termino_corrupcion = new Termino("corrupcion", "etiqueta_corurp");
	termino_corrupcion->asignarNuevoId();

	Termino* termino_irregularidad = new Termino("irregularidad","etiqueta_irregular");
	termino_irregularidad->asignarNuevoId();

	std::vector<Termino*> terminos_corrupcion;
	terminos_corrupcion.push_back(termino_corrupcion);
	terminos_corrupcion.push_back(termino_irregularidad);

	Concepto* concepto_corrupcion = new Concepto(terminos_corrupcion, "corrupcion");
	concepto_corrupcion->asignarNuevoId();


	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(termino_irregularidad);
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(termino_corrupcion);
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(concepto_corrupcion);

	Concepto* concepto_a_recuperar = new Concepto();
	concepto_a_recuperar->setId(concepto_corrupcion->getId());

	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(concepto_a_recuperar);

	ASSERT_STREQ("corrupcion", concepto_a_recuperar->getEtiqueta().c_str());
	ASSERT_EQ(2, concepto_a_recuperar->getId()->numero());

	ASSERT_STREQ("etiqueta_corurp", concepto_a_recuperar->getTerminos()[0]->getEtiqueta().c_str());
	ASSERT_EQ(0, concepto_a_recuperar->getTerminos()[0]->getId()->numero());
	ASSERT_STREQ("corrupcion", concepto_a_recuperar->getTerminos()[0]->getValor().c_str());

	ASSERT_STREQ("etiqueta_irregular", concepto_a_recuperar->getTerminos()[1]->getEtiqueta().c_str());
	ASSERT_EQ(1, concepto_a_recuperar->getTerminos()[1]->getId()->numero());
	ASSERT_STREQ("irregularidad", concepto_a_recuperar->getTerminos()[1]->getValor().c_str());
}

TEST(aplicacionAlmacenamiento, GuardarYCargarNuevaConsulta)
{
	visualizador::aplicacion::IAdministradorAplicacion::crearAdministradorAplicacionLocal();

	visualizador::aplicacion::ConfiguracionAplicacion::leerConfiguracion("configuracion_aplicacion.json");

	visualizador::aplicacion::GestorIDs::setIdActual(0);

	Fecha* inicio_primavera_2017 = new Fecha(21, 9, 2017);
	inicio_primavera_2017->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(inicio_primavera_2017);

	Fecha* fin_primavera_2017 = new Fecha(21, 12, 2017);
	fin_primavera_2017->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(fin_primavera_2017);

	Periodo* primavera_2017 = new Periodo(inicio_primavera_2017, fin_primavera_2017);
	primavera_2017->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(primavera_2017);

	Reporte* reporte = new Grafico("torta");
	reporte->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(reporte);

	std::vector<Termino*> terminos_corrupcion;

	Termino* termino_corrupcion = new Termino("corrupcion");
	termino_corrupcion->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(termino_corrupcion);

	Termino* termino_irregularidad = new Termino("corrupcion");
	termino_irregularidad->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(termino_irregularidad);

	terminos_corrupcion.push_back(termino_corrupcion);
	terminos_corrupcion.push_back(termino_irregularidad);

	Concepto* concepto_corrupcion = new Concepto(terminos_corrupcion, "corrupcion");
	concepto_corrupcion->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(concepto_corrupcion);

	Termino* termino_crisis = new Termino("crisis");
	termino_crisis->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(termino_crisis);

	Termino* termino_conflicto = new Termino("conflicto");
	termino_conflicto->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(termino_conflicto);

	Termino* termino_desorden = new Termino("desorden");
	termino_desorden->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(termino_desorden);

	std::vector<Termino*> terminos_crisis;
	terminos_crisis.push_back(termino_crisis);
	terminos_crisis.push_back(termino_conflicto);
	terminos_crisis.push_back(termino_desorden);

	Concepto* concepto_crisis = new Concepto(terminos_crisis, "crisis");
	concepto_crisis->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(concepto_crisis);

	Termino* termino_movilizacion = new Termino("movilizacion");
	termino_movilizacion->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(termino_movilizacion);

	Termino* termino_paro = new Termino("paro");
	termino_paro->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(termino_paro);

	Termino* termino_marcha = new Termino("marcha");
	termino_marcha->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(termino_marcha);

	std::vector<Termino*> terminos_movilizacion;
	terminos_movilizacion.push_back(termino_movilizacion);
	terminos_movilizacion.push_back(termino_paro);
	terminos_movilizacion.push_back(termino_marcha);

	Concepto* concepto_movilizacion = new Concepto(terminos_movilizacion);
	concepto_movilizacion->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(concepto_movilizacion);

	std::vector<Concepto*> conceptos;
	conceptos.push_back(concepto_corrupcion);
	conceptos.push_back(concepto_crisis);
	conceptos.push_back(concepto_movilizacion);

	// estos news de los medios en verdad no deberian usarse nunca. (PONER LOS NEW COMO METODOS PRIVADOS.
	Medio* medio_clarin = new Medio("clarin");
	medio_clarin->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(medio_clarin);

	Medio* medio_infobae = new Medio("infobae");
	medio_infobae->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(medio_infobae);

	std::vector<Medio*> medios;
	medios.push_back(medio_clarin);
	medios.push_back(medio_infobae);

	// estos news de las secciones en verdad no deberian usarse nunca. (PONER LOS NEW COMO METODOS PRIVADOS.
	Seccion* seccion_politica = new Seccion("politica");
	seccion_politica->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(seccion_politica);

	Seccion* seccion_economia = new Seccion("economia");
	seccion_economia->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(seccion_economia);

	std::vector<Seccion*> secciones;
	secciones.push_back(seccion_politica);
	secciones.push_back(seccion_economia);

	Consulta* consulta = new Consulta(primavera_2017, reporte, conceptos, medios, secciones, "primavera_2017");
	consulta->asignarNuevoId();
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->almacenar(consulta);

	// AHORA RECUPERO TODO

	Consulta* consulta_a_recuperar = new Consulta();
	consulta_a_recuperar->setId(consulta->getId());

	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(consulta_a_recuperar);
}