#pragma once

// stl
#include <functional>
#include <string>

// modelo
#include <modelo/include/Concepto.h>
#include <modelo/include/IEntidad.h>
#include <modelo/include/RelacionesTermino.h>

namespace visualizador
{
namespace modelo
{

    class Concepto; // forward declaration

class Termino : public IEntidad
{
public:

	// CONSTRUCTORES
	Termino();

	Termino(std::string termino, std::string etiqueta = "");
	virtual ~Termino();

	// GETTERS
	
	std::string getValor();

	// SETTERS
	
	void setValor(std::string valor);

	// METODOS

    void relacionarConConcepto(Concepto * concepto);

    // metodos de IContieneJson

	virtual void crearContenido();

	virtual bool parsearContenido(IJson* contenido);
	
    // metodos de IAlmacenable

	virtual std::string prefijoGrupo();

	virtual unsigned int hashcode();

    // metodos de IEntidad

    virtual IEntidad * clonar();

    // metodos de IRelacionable

    virtual void vincular();

    virtual void desvincular();


private:

	static std::hash<std::string> hasher;

	std::string valor;

    relaciones::RelacionesTermino * relaciones_termino;
};

};
};

