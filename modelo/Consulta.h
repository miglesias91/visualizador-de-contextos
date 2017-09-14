#pragma once

// stl
#include <ctime>
#include <chrono>

// modelo
#include <modelo/IEntidad.h>
#include <modelo/Concepto.h>
#include <modelo/Seccion.h>
#include <modelo/Medio.h>
#include <modelo/Periodo.h>
#include <modelo/Reporte.h>

namespace visualizador
{
namespace modelo
{

class Consulta : public IEntidad
{
public:
	// CONSTRUCTORES

	Consulta();
	virtual ~Consulta();

	// METODOS

	// GETTERS

	Periodo* getPeriodo();
	Reporte* getReporte();

	std::vector<Concepto*> getConceptos();
	std::vector<Medio*> getMedios();
	std::vector<Seccion*> getSecciones();

	// SETTERS

	void setPeriodo(Periodo* periodo);
	void setReporte(Reporte* reporte);

	void agregarConcepto(Concepto* concepto);
	void agregarMedio(Medio* medio);
	void agregarSeccion(Seccion* seccion);

	virtual void crearContenido();

private:

	std::vector<Concepto*> conceptos;
	std::vector<Medio*> medios;
	std::vector<Seccion*> secciones;

	Periodo* periodo;

	Reporte* reporte;

	
};

};
};

