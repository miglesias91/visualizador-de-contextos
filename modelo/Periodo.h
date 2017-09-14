#pragma once

namespace visualizador
{
namespace modelo
{

class Periodo
{
public:
	Periodo();
	virtual ~Periodo();

private:
	Fecha* desde;
	Fecha* hasta;
};

};
};
