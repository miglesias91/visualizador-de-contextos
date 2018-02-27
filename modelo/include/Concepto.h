#pragma once

// stl
#include <vector>

// modelo
#include <modelo/include/IEntidad.h>
#include <modelo/include/RelacionesConcepto.h>
#include <modelo/include/Termino.h>

namespace visualizador
{
namespace modelo
{

class Concepto : public IEntidad
{
public:

	// CONSTRUCTORES

	Concepto(std::string etiqueta = "");
	
	// Concepto(std::vector<Termino*> terminos, herramientas::utiles::Json * contenido, std::string etiqueta = "");

	Concepto(std::vector<Termino*> terminos, std::string etiqueta = "");

	virtual ~Concepto();

	// GETTERS

    relaciones::RelacionesConcepto * getRelacionesConcepto();

	std::vector<Termino*> getTerminos();

	// SETTERS

    void setRelacionesConcepto(relaciones::RelacionesConcepto * relaciones_concepto);

	void agregarTermino(Termino* termino_nuevo);

	// METODOS

    // metodos de IContieneJson

	virtual bool armarJson();

	virtual bool parsearJson();
	
    // metodos de IAlmacenable

	virtual std::string prefijoGrupo();
	
	virtual unsigned long long int hashcode();

    // metodos de IEntidad

    virtual IEntidad * clonar();

    // metodos de IRelacionable
    
    virtual bool recuperarContenidoDeRelaciones();

    virtual void actualizarRelaciones(herramientas::utiles::ID * id_nuevo, herramientas::utiles::ID * id_viejo = NULL);

    virtual void vincular();

    virtual void desvincular();

    // CONSULTAS

    // consultas de IRelacionable

    virtual bool tieneRelacionesDependientes();

private:

    // METODOS INTERNOS

	std::vector<Termino*> terminos;
  
    relaciones::RelacionesConcepto * relaciones_concepto;
};

};
};

