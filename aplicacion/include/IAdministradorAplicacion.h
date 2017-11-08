#pragma once

// stl
#include <vector>

// modelo
#include <modelo/include/IEntidad.h>

namespace visualizador
{
namespace aplicacion
{

class IAdministradorAplicacion
{
public:

	static void iniciar(std::string path_configuracion);

	static void liberar();

	static void crearAdministradorAplicacionLocal();

	static void crearAdministradorAplicacionDistribuida();

	static bool administradorIniciado();

	// GETTERS

	static IAdministradorAplicacion* getInstancia();

	// SETTERS

	// METODOS

	virtual bool abrirBD() = 0;

	virtual bool cerrarBD() = 0;

	virtual bool almacenar(visualizador::modelo::IEntidad* entidad) = 0;

    virtual bool almacenar(std::vector<visualizador::modelo::IEntidad*> entidades) = 0;

	virtual bool recuperar(visualizador::modelo::IEntidad* entidad) = 0;

    virtual bool eliminar(visualizador::modelo::IEntidad * entidad) = 0;

    virtual bool eliminar(std::vector<visualizador::modelo::IEntidad*> entidades) = 0;

    virtual bool modificar(visualizador::modelo::IEntidad * entidad) = 0;

    virtual bool modificar(std::vector<visualizador::modelo::IEntidad*> entidades) = 0;

	virtual bool recuperarGrupo(std::string prefijo_grupo, std::vector<visualizador::modelo::IEntidad*>* entidades) = 0;

	virtual unsigned long long int recuperarIDActual();

	virtual void almacenarIDActual();

private:
	// ATRIBUTOS

	static IAdministradorAplicacion* administrador;
};

};
};

