// gtest
#include <gtest/gtest.h>

// modelo
#include <modelo/Concepto.h>
#include <modelo/Fecha.h>

using namespace visualizador::modelo;

TEST(modelo, GettersYSettersCorrectos)
{
	std::vector<Termino*> terminos;

	terminos.push_back(new Termino("corrupcion"));
	terminos.push_back(new Termino("irregularidad"));
	terminos.push_back(new Termino("irregularidades"));

	Concepto* concepto;
}
