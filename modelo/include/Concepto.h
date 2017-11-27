#pragma once

// stl
#include <vector>

// modelo
#include <modelo/include/IEntidad.h>
#include <modelo/include/IRelacionConGrupo.h>
#include <modelo/include/Termino.h>

namespace visualizador
{
namespace modelo
{

    class Termino; // forward declaration

class Concepto : public IEntidad
{
public:

	// CONSTRUCTORES

	Concepto(std::string etiqueta = "");
	
	Concepto(std::vector<Termino*> terminos, IJson* contenido, std::string etiqueta = "");

	Concepto(std::vector<Termino*> terminos, std::string etiqueta = "");

	virtual ~Concepto();

	// GETTERS

	std::vector<Termino*> getTerminos();

	// SETTERS

	void agregarTermino(Termino* termino_nuevo);

    // metodos de IAlmacenable

    virtual void setId(visualizador::aplicacion::ID* id_concepto);

	// METODOS

    // metodos de IContieneJson

	virtual void crearContenido();

	virtual bool parsearContenido(IJson* contenido);
	
    // metodos de IAlmacenable

	virtual std::string prefijoGrupo();
	
	virtual unsigned int hashcode();

    // metodos de IEntidad

    virtual IEntidad * clonar();

private:

    // METODOS INTERNOS

    void relacionarTerminos();

	std::vector<Termino*> terminos;
  
    // IRelacionConGrupo * relacion_consultas;
};

};
};

