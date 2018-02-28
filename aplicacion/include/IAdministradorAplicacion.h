#pragma once

// stl
#include <vector>

// log
#include <spdlog/spdlog.h>

// almacenamiento
#include <almacenamiento/include/IAdministradorAlmacenamiento.h>

// modelo
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

    static bool administradorEntidadesIniciado();

	// GETTERS

    almacenamiento::IAdministradorAlmacenamiento * getAdminAlmacenamiento();
    
    static IAdministradorAplicacion* getInstanciaAdminEntidades();

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

    template <class ENTIDAD>
    bool recuperarGrupo(std::string prefijo_grupo, std::vector<ENTIDAD*>* entidades_recuperadas);

	virtual unsigned long long int recuperarIDActual() = 0;

	virtual void almacenarIDActual() = 0;

protected:

    void iniciarDB(std::string path_config_db);

    // ATRIBUTOS

    almacenamiento::IAdministradorAlmacenamiento* admin_almacenamiento;

    unsigned long long int handler_almacenamiento;

private:
	// ATRIBUTOS

    static IAdministradorAplicacion* administrador_entidades;
    
};

template<typename ENTIDAD>
bool IAdministradorAplicacion::recuperarGrupo(std::string prefijo_grupo, std::vector<ENTIDAD*>* entidades_recuperadas)
{
    std::vector<almacenamiento::IAlmacenableClaveValor*> grupo;

    this->admin_almacenamiento->recuperarGrupo(prefijo_grupo, grupo);

    ENTIDAD* entidad = NULL;
    for (std::vector<almacenamiento::IAlmacenableClaveValor*>::iterator it = grupo.begin(); it != grupo.end(); it++)
    {
        entidad = new ENTIDAD();
        unsigned long long int id = std::stoull((*it)->getClave());
        entidad->setId(new herramientas::utiles::ID(id));

        this->recuperar(entidad);

        entidades_recuperadas->push_back(entidad);

        delete *it;
    }
    grupo.clear();

    return true;
};


};
};

