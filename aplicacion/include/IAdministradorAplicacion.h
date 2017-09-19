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

	static void liberar();

	static void crearAdministradorAplicacionLocal();

	static void crearAdministradorAplicacionDistribuida();

	static bool administradorIniciado();

	// GETTERS

	static IAdministradorAplicacion* getInstancia();

	// SETTERS

	// METODOS

	virtual bool almacenar(visualizador::modelo::IEntidad* entidad) = 0;

	virtual bool recuperar(visualizador::modelo::IEntidad* entidad) = 0;

	virtual std::vector<visualizador::modelo::IEntidad*> recuperarGrupo(std::string prefijo_grupo) = 0;

private:

	static IAdministradorAplicacion* administrador;
};

};
};

