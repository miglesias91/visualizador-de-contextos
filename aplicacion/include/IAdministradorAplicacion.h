#pragma once

// stl
#include <vector>

// modelo
// #include <modelo/include/IEntidad.h>
#include <modelo/include/IAlmacenable.h>

namespace visualizador
{
namespace aplicacion
{

class IAdministradorAplicacion
{
public:
    IAdministradorAplicacion();
    virtual ~IAdministradorAplicacion();

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

    virtual bool borrarBD() = 0;

    virtual bool almacenar(visualizador::modelo::IAlmacenable* almacenable) = 0;

    virtual bool almacenar(std::vector<visualizador::modelo::IAlmacenable*> almacenables) = 0;

    virtual bool recuperar(visualizador::modelo::IAlmacenable* almacenable) = 0;

    virtual bool eliminar(visualizador::modelo::IAlmacenable * almacenable) = 0;

    virtual bool eliminar(std::vector<visualizador::modelo::IAlmacenable*> almacenables) = 0;

    virtual bool modificar(visualizador::modelo::IAlmacenable * almacenable) = 0;

    virtual bool modificar(std::vector<visualizador::modelo::IAlmacenable*> almacenables) = 0;

    virtual bool recuperarGrupo(std::string prefijo_grupo, std::vector<visualizador::modelo::IAlmacenable*>* almacenables) = 0;

	virtual unsigned long long int recuperarIDActual() = 0;

	virtual void almacenarIDActual() = 0;

private:
	// ATRIBUTOS

	static IAdministradorAplicacion* administrador;
};

};
};

