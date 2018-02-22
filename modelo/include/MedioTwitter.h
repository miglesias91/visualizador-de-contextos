#pragma once

// scraping::extraccion
#include <twitter/include/Cuenta.h>

// modelo
#include <modelo/include/Medio.h>

namespace visualizador
{
namespace modelo
{

class MedioTwitter : public Medio
{
public:

	// CONSTRUCTORES

    MedioTwitter(std::string etiqueta = "");

	virtual ~MedioTwitter();

	// GETTERS

    virtual scraping::twitter::modelo::Cuenta * getCuentaAScrapear();

    //relaciones::RelacionesMedio * getRelacionesMedio();

	// SETTERS

    virtual void setCuentaAScrapear(scraping::twitter::modelo::Cuenta * medio_a_scrapear);

    //void setRelacionesMedio(relaciones::RelacionesMedio * relaciones_medio);

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

    // virtual void actualizarRelaciones(herramientas::utiles::ID * id_nuevo, herramientas::utiles::ID * id_viejo = NULL);

    virtual void vincular();

    virtual void desvincular();

    // CONSULTAS

    // consultas de IRelacionable

    // virtual bool tieneRelacionesDependientes();

private:

    // ATRIBUTOS

    std::string nombre_usuario;

    // fecha creacion
    // fecha primer tweet analizado
    // foto
    // etc etc...

    scraping::twitter::modelo::Cuenta * cuenta_a_scrapear;
};

};
};
