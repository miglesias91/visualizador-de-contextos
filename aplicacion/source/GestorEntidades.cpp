#include <aplicacion/include/GestorEntidades.h>

using namespace visualizador::aplicacion;
using namespace visualizador;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

// almacenamiento
#include <almacenamiento/include/IAdministradorAlmacenamiento.h>

// modelo
#include <modelo/include/IEntidad.h>

GestorEntidades::GestorEntidades()
{
}

GestorEntidades::~GestorEntidades()
{
}

std::vector<modelo::Termino*> GestorEntidades::recuperarTerminos()
{
	std::vector<modelo::Termino*> terminos_recuperados;

	std::vector<almacenamiento::IAlmacenableClaveValor*> grupo;

	almacenamiento::IAdministradorAlmacenamiento::getInstancia()->abrir();
	almacenamiento::IAdministradorAlmacenamiento::getInstancia()->recuperarGrupo(ConfiguracionAplicacion::prefijoTermino(), grupo);
	almacenamiento::IAdministradorAlmacenamiento::getInstancia()->cerrar();

	modelo::Termino* termino_recuperado = NULL;
	for (std::vector<almacenamiento::IAlmacenableClaveValor*>::iterator it = grupo.begin(); it != grupo.end(); it++)
	{
		termino_recuperado = new modelo::Termino();
		termino_recuperado->parsearValorAlmacenable((*it)->getValor());
		terminos_recuperados.push_back(termino_recuperado);
	}

	return terminos_recuperados;
}


