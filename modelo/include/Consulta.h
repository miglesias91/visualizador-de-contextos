#pragma once

// stl
#include <ctime>
#include <chrono>

// modelo
#include <modelo/include/IEntidad.h>
#include <modelo/include/Concepto.h>
#include <modelo/include/Seccion.h>
#include <modelo/include/Medio.h>
#include <modelo/include/MedioTwitter.h>
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
	
	Consulta(Periodo* periodo, Reporte* reporte, std::vector<Concepto*> conceptos, std::vector<MedioTwitter*> medios_twitter, std::vector<Seccion*> secciones, std::string etiqueta = "");

	virtual ~Consulta();

    // GETTERS

    Periodo* getPeriodo();
    Reporte* getReporte();

    std::vector<Concepto*> getConceptos();
    std::vector<MedioTwitter*> getMediosTwitter();
    std::vector<Seccion*> getSecciones();

    relaciones::RelacionesConsulta * getRelacionesConsulta();

    // SETTERS

    void setPeriodo(Periodo* periodo);
    void setReporte(Reporte* reporte);

    void agregarConcepto(Concepto* concepto);
    void agregarMedioTwitter(MedioTwitter* medio_twitter);
    void agregarSeccion(Seccion* seccion);

    void setRelacionesConsulta(relaciones::RelacionesConsulta * relaciones_consulta);

	// METODOS

    // metodos de IContieneJson

	virtual bool armarJson();

	virtual bool parsearJson();
    
    // metodos de IAlmacenable

	virtual std::string prefijoGrupo();
	
	virtual unsigned long long int hashcode();
    
    // metodos de IEntidad

    virtual IEntidad * clonar();

    // metodos de IRelacionable

    virtual bool recuperarContenidoDeRelaciones();

    virtual void actualizarRelaciones(herramientas::utiles::ID * id_nuevo, herramientas::utiles::ID * id_viejo = NULL);

    virtual void vincular();

    virtual void desvincular();

    // CONSULTAS

    // consultas de IRelacionable

    virtual bool tieneRelacionesDependientes();

private:

	Periodo* periodo;
	Reporte* reporte;

	std::vector<Concepto*> conceptos;
	std::vector<MedioTwitter*> medios_twitter;
	std::vector<Seccion*> secciones;

    relaciones::RelacionesConsulta * relaciones_consulta;
};

};
};

