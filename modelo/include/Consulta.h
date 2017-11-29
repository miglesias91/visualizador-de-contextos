#pragma once

// stl
#include <ctime>
#include <chrono>

// modelo
#include <modelo/include/IEntidad.h>
#include <modelo/include/Concepto.h>
#include <modelo/include/Seccion.h>
#include <modelo/include/Medio.h>
#include <modelo/include/Periodo.h>
#include <modelo/include/Reporte.h>

#include <modelo/include/RelacionesConsulta.h>

namespace visualizador
{
namespace modelo
{

class Consulta : public IEntidad
{
public:
	// CONSTRUCTORES

	Consulta(std::string etiqueta = "");
	
	Consulta(Periodo* periodo, Reporte* reporte, std::vector<Concepto*> conceptos, std::vector<Medio*> medios, std::vector<Seccion*> secciones, std::string etiqueta = "");

	virtual ~Consulta();

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

	// METODOS

    // metodos de IContieneJson

	virtual void crearContenido();

	virtual bool parsearContenido(IJson* contenido);
    
    // metodos de IAlmacenable

	virtual std::string prefijoGrupo();
	
	virtual unsigned int hashcode();
    
    // metodos de IEntidad

    virtual IEntidad * clonar();

    // metodos de IRelacionable

    virtual void vincular();

    virtual void desvincular();

private:

	Periodo* periodo;
	Reporte* reporte;

	std::vector<Concepto*> conceptos;
	std::vector<Medio*> medios;
	std::vector<Seccion*> secciones;

    relaciones::RelacionesConsulta * relaciones_consulta;
};

};
};

