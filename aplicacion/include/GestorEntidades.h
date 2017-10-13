#pragma once

// stl
#include <vector>

// aplicacion
#include <almacenamiento/include/IAdministradorAlmacenamiento.h>

// modelo
#include <modelo/include/Termino.h>

namespace visualizador
{
namespace aplicacion
{

class GestorEntidades
{
public:

	static std::vector<visualizador::modelo::Termino*> recuperarTerminos();

private:

	GestorEntidades();

	~GestorEntidades();
};
};
};

