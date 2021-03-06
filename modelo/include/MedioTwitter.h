#pragma once

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

    MedioTwitter();

    MedioTwitter(std::string nombre_usuario, std::string etiqueta = "");

	virtual ~MedioTwitter();

	// GETTERS

    virtual std::string getNombreUsuario();

    //virtual scraping::twitter::modelo::Cuenta * getCuentaAScrapear();

    // metodos de Medio

    //virtual scraping::extraccion::Medio * getMedioAScrapear();

	// SETTERS

    virtual void setNombreUsuario(std::string nombre_usuario);

    //virtual void setCuentaAScrapear(scraping::twitter::modelo::Cuenta * medio_a_scrapear);

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

    // virtual void actualizarRelaciones(herramientas::utiles::ID * id_nuevo, herramientas::utiles::ID * id_viejo = NULL);

    virtual void vincular();

    virtual void desvincular();

    // CONSULTAS

    // consultas de IRelacionable

    // virtual bool tieneRelacionesDependientes();

private:

    // ATRIBUTOS

    std::string nombre_usuario;
};

};
};
