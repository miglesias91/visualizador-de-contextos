#pragma once

// stl
#include <vector>

namespace visualizador
{
namespace aplicacion
{

template<class T>
class GestorEntidad
{
public:
	GestorEntidad();
	~GestorEntidad();

	std::vector<T> recuperarTodos();
};
};
};

