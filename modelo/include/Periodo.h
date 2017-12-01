#pragma once

// modelo
#include <modelo/include/IEntidad.h>
#include <modelo/include/Fecha.h>

#include <modelo/include/RelacionesPeriodo.h>

namespace visualizador
{
namespace modelo
{

class Periodo : public IEntidad
{
public:

	// CONSTRUCTORES

	Periodo(std::string etiqueta = "");
	Periodo(Fecha* desde, Fecha* hasta, std::string etiqueta = "");
	virtual ~Periodo();

	// GETTERS

	Fecha* getDesde();
	Fecha* getHasta();

    relaciones::RelacionesPeriodo * getRelacionesPeriodo();

	// SETTERS

	void setDesde(Fecha* desde);
	void setHasta(Fecha* hasta);

    void setRelacionesPeriodo(relaciones::RelacionesPeriodo * relaciones_periodo);

    // METODOS

    // metodos de IContieneJson

    virtual void crearJson();

    virtual bool parsearJson(IJson* json);

    // metodos de IAlmacenable

    virtual std::string prefijoGrupo();

    virtual unsigned int hashcode();

    // metodos de IEntidad

    virtual IEntidad * clonar();

    // metodos de IRelacionable

    virtual bool recuperarContenidoDeRelaciones();

    virtual void actualizarRelaciones(visualizador::aplicacion::ID * id_nuevo, visualizador::aplicacion::ID * id_viejo = NULL);

    virtual void vincular();

    virtual void desvincular();

private:
	
    Fecha* desde;
	Fecha* hasta;
  
    relaciones::RelacionesPeriodo * relaciones_periodo;
};

};
};
