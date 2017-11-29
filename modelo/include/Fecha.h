#pragma once

// stl
#include <functional>
#include <string>

// modelo
#include <modelo/include/IEntidad.h>

#include <modelo/include/RelacionesFecha.h>

namespace visualizador
{
namespace modelo
{

class Fecha : public IEntidad
{
public:

	// CONSTRUCTORES

	Fecha(std::string etiqueta = "");

	Fecha(unsigned int dia, unsigned int mes, unsigned int anio, std::string etiqueta = "");

	virtual ~Fecha();

    // GETTERS

	unsigned int getDia();
	unsigned int getMes();
	unsigned int getAnio();

	std::string getStringDia();
	std::string getStringMes();
	std::string getStringAnio();

    std::string getNombreMes();

    std::string getStringDDMMAAAA(std::string separador = "");

    std::string getStringDDmesAAAA(std::string separador = "");

    relaciones::RelacionesFecha * getRelacionesFecha();

	// SETTERS

	void setDia(std::string dia);
	void setMes(std::string mes);
	void setAnio(std::string anio);

	void setDia(unsigned int dia);
	void setMes(unsigned int mes);
	void setAnio(unsigned int anio);

    void setRelacionesFecha(relaciones::RelacionesFecha * relaciones_fecha);

    // METODOS

    // metodos de IContieneJson

    virtual void crearJson();

    virtual bool parsearJson(IJson* json);

    // metodos de IAlmacenable

    virtual std::string prefijoGrupo();

    virtual unsigned int hashcode();

    // metodos de IEntidad

    virtual IEntidad * clonar();

    // metodos de IRelacionable

    virtual bool recuperarContenidoDeRelaciones();

    virtual void actualizarRelaciones();
    
    virtual void vincular();

    virtual void desvincular();

private:

	static std::hash<unsigned int> hasher;

    static std::string nombres_meses[];

	unsigned int dia;
	unsigned int mes;
	unsigned int anio;
  
    relaciones::RelacionesFecha * relaciones_fecha;
};

};
};

