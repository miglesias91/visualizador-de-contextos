#pragma once

// stl
#include <vector>

// aplicacion
#include <almacenamiento/include/IAdministradorAlmacenamiento.h>

namespace visualizador
{
namespace aplicacion
{

template<class T>
class GestorEntidad
{
public:
	GestorEntidad() {};

	~GestorEntidad() {};

	template<class T>
	std::vector<T> recuperarTodos()
	{
		std::vector<T> entidades;

		std::vector<almacenamiento::IAlmacenableClaveValor*> grupo;

		T entidad_aux;
		almacenamiento::IAdministradorAlmacenamiento::getInstancia()->recuperarGrupo(entidad_aux.prefijoGrupo(), grupo);

		for (std::vector<almacenamiento::IAlmacenableClaveValor*>::iterator it = grupo.begin(); it != grupo.end(); it++)
		{
			T nueva_entidad;
			nueva_entidad.parsearValorAlmacenable((*it)->getValor());
			entidades.push_back(nueva_entidad);
		}

		return entidades;
	}
};
};
};

