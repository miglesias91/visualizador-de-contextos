#include <aplicacion/include/GestorEntidad.h>

using namespace visualizador::aplicacion;

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>

// modelo
#include <modelo/include/IEntidad.h>

template <class T>
GestorEntidad::GestorEntidad()
{
}

template <class T>
GestorEntidad::~GestorEntidad()
{
}

template<class T>
std::vector<T> GestorEntidad<T>::recuperarTodos()
{
	std::vector<visualizador::modelo::IEntidad*> entidades;

	std::string prefijo = T::prefijoGrupo();

	std::vector<almacenamiento::IAlmacenableClaveValor*> grupo;

	almacenamiento::IAdministradorAlmacenamiento::getInstancia()->recuperarGrupo(prefijo_grupo, grupo);

	for()

	return std::vector<T>();
}


