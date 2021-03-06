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
	
    Fecha* desde;
	Fecha* hasta;
  
    relaciones::RelacionesPeriodo * relaciones_periodo;
};

};
};
