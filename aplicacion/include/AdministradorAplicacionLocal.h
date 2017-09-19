#pragma once

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

	virtual bool almacenar(visualizador::modelo::IEntidad* entidad);

	virtual bool recuperar(visualizador::modelo::IEntidad* entidad);

	virtual std::vector<visualizador::modelo::IEntidad*> recuperarGrupo(std::string prefijo_grupo);
		
private:
	
};

};
};

