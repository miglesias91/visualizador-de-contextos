#pragma once

// modelo
#include <modelo/include/IEntidad.h>

namespace visualizador
{
namespace modelo
{

class Medio : public IEntidad
{
public:

	// CONSTRUCTORES

	Medio(std::string etiqueta = "");

	virtual ~Medio();

	// GETTERS

	// SETTERS

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

    //IRelacionConGrupo * relacion_consultas;


};

};
};
