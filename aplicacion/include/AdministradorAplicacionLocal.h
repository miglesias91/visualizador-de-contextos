#pragma once

// almacenamiento
#include <almacenamiento/include/IAdministradorAlmacenamiento.h>

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>

namespace visualizador
{
namespace aplicacion
{

class AdministradorAplicacionLocal : public IAdministradorAplicacion
{
public:
	AdministradorAplicacionLocal();
	virtual ~AdministradorAplicacionLocal();

	// METODOS

	virtual bool abrirBD();

	virtual bool cerrarBD();

    virtual bool borrarBD();

	//virtual bool almacenar(visualizador::modelo::IEntidad* entidad);

 //   virtual bool almacenar(std::vector<visualizador::modelo::IEntidad*> entidades);

	//virtual bool recuperar(visualizador::modelo::IEntidad* entidad);

 //   virtual bool eliminar(visualizador::modelo::IEntidad * entidad);
 //   
 //   virtual bool eliminar(std::vector<visualizador::modelo::IEntidad*> entidades);

 //   virtual bool modificar(visualizador::modelo::IEntidad * entidad);

 //   virtual bool modificar(std::vector<visualizador::modelo::IEntidad*> entidades);

	//virtual bool recuperarGrupo(std::string prefijo_grupo, std::vector<visualizador::modelo::IEntidad*>* entidades);
    
    virtual bool almacenar(visualizador::modelo::IAlmacenable* almacenable);

    virtual bool almacenar(std::vector<visualizador::modelo::IAlmacenable*> almacenables);

    virtual bool recuperar(visualizador::modelo::IAlmacenable* almacenable);

    virtual bool eliminar(visualizador::modelo::IAlmacenable * almacenable);

    virtual bool eliminar(std::vector<visualizador::modelo::IAlmacenable*> almacenables);

    virtual bool modificar(visualizador::modelo::IAlmacenable * almacenable);

    virtual bool modificar(std::vector<visualizador::modelo::IAlmacenable*> almacenables);

    virtual bool recuperarGrupo(std::string prefijo_grupo, std::vector<visualizador::modelo::IAlmacenable*>* almacenables);

    virtual unsigned long long int recuperarIDActual();

    virtual void almacenarIDActual();

private:
    almacenamiento::IAdministradorAlmacenamiento* admin_almacenamiento;
};

};
};

