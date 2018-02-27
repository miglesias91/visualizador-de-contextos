#pragma once

// stl
#include <functional>
#include <string>

// herramientas
#include <utiles/include/Fecha.h>

// modelo
#include <modelo/include/IEntidad.h>

#include <modelo/include/RelacionesFecha.h>

namespace visualizador
{
namespace modelo
{

class Fecha : public herramientas::utiles::Fecha, public IEntidad
{
public:

	// CONSTRUCTORES

	Fecha(std::string etiqueta = "");

	Fecha(unsigned int dia, unsigned int mes, unsigned int anio, std::string etiqueta = "");

	virtual ~Fecha();

    // GETTERS

    // getters de IRelacionable

    relaciones::RelacionesFecha * getRelacionesFecha();

	// SETTERS

    // setters de IRelacionable

    void setRelacionesFecha(relaciones::RelacionesFecha * relaciones_fecha);

    // METODOS

    // metodos de IContieneJson

    virtual void crearJson();

    virtual bool parsearJson(IJson* json);

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

    // OPERADORES

private:
  
    relaciones::RelacionesFecha * relaciones_fecha;
};

};
};

