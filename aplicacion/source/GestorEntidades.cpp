#include <aplicacion/include/GestorEntidades.h>

using namespace visualizador::aplicacion;
using namespace visualizador;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>
#include <aplicacion/include/IAdministradorAplicacion.h>


// almacenamiento
#include <almacenamiento/include/IAdministradorAlmacenamiento.h>


// modelo
#include <modelo/include/IEntidad.h>

GestorEntidades::GestorEntidades()
{
}

GestorEntidades::~GestorEntidades()
{
    for (this->entidades_it = this->entidades_existentes.begin(); this->entidades_it != this->entidades_existentes.end(); this->entidades_it++)
    {
        delete (*this->entidades_it);
    }
    this->entidades_existentes.clear();

    for (this->entidades_it = this->entidades_a_almacenar.begin(); this->entidades_it != this->entidades_a_almacenar.end(); this->entidades_it++)
    {
        delete (*this->entidades_it);
    }
    this->entidades_a_almacenar.clear();

    for (this->entidades_it = this->entidades_a_eliminar.begin(); this->entidades_it != this->entidades_a_eliminar.end(); this->entidades_it++)
    {
        delete (*this->entidades_it);
    }
    this->entidades_a_eliminar.clear();
}

std::vector<modelo::Termino*> GestorEntidades::gestionarTerminos()
{
    std::vector<almacenamiento::IAlmacenableClaveValor*> grupo;

    almacenamiento::IAdministradorAlmacenamiento::getInstancia()->recuperarGrupo(ConfiguracionAplicacion::prefijoTermino(), grupo);

    modelo::Termino* termino_recuperado = NULL;
    std::vector<modelo::Termino*> terminos_recuperados;
    for (std::vector<almacenamiento::IAlmacenableClaveValor*>::iterator it = grupo.begin(); it != grupo.end(); it++)
    {
        termino_recuperado = new modelo::Termino();
        termino_recuperado->parsearValorAlmacenable((*it)->getValor());
        this->entidades_existentes.push_back(termino_recuperado);

        terminos_recuperados.push_back(termino_recuperado);
        delete *it;
    }
    grupo.clear();

    return terminos_recuperados;
}

void GestorEntidades::almacenar(visualizador::modelo::IEntidad * entidad_nueva)
{
    // chequeo que el termino a agregar no este en la lista de eliminados:
    // si estaba en la lista de eliminados, entonces quiere decir que esta en la bd y se quiere sacar.
    // Entonces lo que hago es sacarlo de la lista de "a eliminar" y lo vuelvo a agregar a la QListWidget.
    for (this->entidades_it = this->entidades_a_eliminar.begin(); this->entidades_it != this->entidades_a_eliminar.end(); this->entidades_it++)
    {
        if ((*this->entidades_it)->hashcode() == entidad_nueva->hashcode())
        {
            delete *this->entidades_it;
            this->entidades_existentes.push_back(entidad_nueva);
            this->entidades_a_eliminar.erase(this->entidades_it);
            return;
        }
    }

    // si no estaba en la lista de eliminados, entonces lo agregar a la lista de 'a almacenar'.
    this->entidades_a_almacenar.push_back(entidad_nueva);
}

void GestorEntidades::eliminar(visualizador::modelo::IEntidad * entidad_a_eliminar)
{
    this->entidades_it = std::find(this->entidades_a_almacenar.begin(), this->entidades_a_almacenar.end(), entidad_a_eliminar);
    if (this->entidades_a_almacenar.end() != this->entidades_it)
    {
        visualizador::modelo::IEntidad* entidad_a_devolver = *this->entidades_it;
        delete entidad_a_eliminar;
        this->entidades_a_almacenar.erase(this->entidades_it);
    }
    else
    {
        this->entidades_it = std::find(this->entidades_existentes.begin(), this->entidades_existentes.end(), entidad_a_eliminar);
        this->entidades_existentes.erase(this->entidades_it);
        this->entidades_a_eliminar.push_back(entidad_a_eliminar);
    }
}

bool GestorEntidades::existe(visualizador::modelo::IEntidad * entidad_a_chequear)
{
    for (this->entidades_it = this->entidades_existentes.begin(); this->entidades_it != this->entidades_existentes.end(); this->entidades_it++)
    {
        if ((*this->entidades_it)->hashcode() == entidad_a_chequear->hashcode())
        {
            return true;
        }
    }

    for (this->entidades_it = this->entidades_a_almacenar.begin(); this->entidades_it != this->entidades_a_almacenar.end(); this->entidades_it++)
    {
        if ((*this->entidades_it)->hashcode() == entidad_a_chequear->hashcode())
        {
            return true;
        }
    }

    return false;
}