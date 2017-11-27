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
    this->admin_app = IAdministradorAplicacion::getInstancia();
    this->admin_bd = almacenamiento::IAdministradorAlmacenamiento::getInstancia();
}

GestorEntidades::~GestorEntidades()
{
    for (this->entidades_it = this->entidades_existentes.begin(); this->entidades_it != this->entidades_existentes.end(); this->entidades_it++)
    {
        if ((*this->entidades_it)->estaSucia())
        {
            this->admin_app->modificar(*this->entidades_it);
        }
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

bool GestorEntidades::guardarCambios()
{
    std::vector<visualizador::modelo::IAlmacenable*> almacenables_a_almacenar = visualizador::modelo::IEntidad::comoAlmacenables(this->entidades_a_almacenar);
    if (false == this->admin_app->almacenar(almacenables_a_almacenar))
    {
        return false;
    }

    std::vector<visualizador::modelo::IAlmacenable*> almacenables_a_eliminar = visualizador::modelo::IEntidad::comoAlmacenables(this->entidades_a_eliminar);
    if (false == this->admin_app->eliminar(almacenables_a_eliminar))
    {
        return false;
    }

    for (this->entidades_it = this->entidades_existentes.begin(); this->entidades_it != this->entidades_existentes.end(); this->entidades_it++)
    {
        if ((*this->entidades_it)->estaSucia())
        {
            this->admin_app->modificar(*this->entidades_it);
        }
    }

    for (this->entidades_it = this->entidades_a_almacenar.begin(); this->entidades_it != this->entidades_a_almacenar.end(); this->entidades_it++)
    {
        this->entidades_existentes.push_back(*this->entidades_it);
    }
    this->entidades_a_almacenar.clear();

    for (this->entidades_it = this->entidades_a_eliminar.begin(); this->entidades_it != this->entidades_a_eliminar.end(); this->entidades_it++)
    {
        delete (*this->entidades_it);
    }
    this->entidades_a_eliminar.clear();


    return true;
}

bool GestorEntidades::almacenar(visualizador::modelo::IEntidad * entidad_nueva)
{
    // si ya existe la entidad, entonces devuelvo 'false' indicando que no se agregó la nueva entidad
    // y tiro una excepcion avisando que ya existe una entidad igual.
    if (this->existe(entidad_nueva))
    {
        // TODO implementar 'ExcepcionTerminoExistente'.
        std::string mensaje("La entidad '" + entidad_nueva->getEtiqueta() + "' ya existe.");
        // throw std::exception(mensaje.c_str());
        return false;
    }

    // chequeo que la entidad a agregar no este en la lista de eliminados:
    // si estaba en la lista de eliminados, entonces quiere decir que esta en la bd y se queria sacar, pero ahora la queremos agregar.
    // Entonces lo que hago es sacarlo de la lista de "a eliminar" y lo vuelvo a agregar a la lista de "existentes".
    for (this->entidades_it = this->entidades_a_eliminar.begin(); this->entidades_it != this->entidades_a_eliminar.end(); this->entidades_it++)
    {
        if ((*this->entidades_it)->hashcode() == entidad_nueva->hashcode())
        {
            this->entidades_existentes.push_back(*this->entidades_it);
            this->entidades_a_eliminar.erase(this->entidades_it);
            return true;
        }
    }

    // si no estaba en la lista de eliminados, entonces lo agregar a la lista de 'a almacenar'.
    if (NULL == entidad_nueva->getId())
    {
        entidad_nueva->asignarNuevoId();
    }
    this->entidades_a_almacenar.push_back(entidad_nueva->clonar());

    return true;
}

bool GestorEntidades::eliminar(visualizador::modelo::IEntidad * entidad_a_eliminar)
{
    // chequeo que la entidad a eliminar no este en la lista de entidades que se quieren almacenar.
    // en caso que SI este, entonces directamente la elimino de la lista de entidades a almacenar. De esta forma evito tocar la bd.
    for (this->entidades_it = this->entidades_a_almacenar.begin(); this->entidades_it != this->entidades_a_almacenar.end(); this->entidades_it++)
    {
        if ((*this->entidades_it)->hashcode() == entidad_a_eliminar->hashcode())
        {
            // si NO apuntan a la misma entidad, entonces borro la que esta en "a almacenar"
            if (entidad_a_eliminar != *this->entidades_it)
            {
                delete *this->entidades_it;
            }

            this->entidades_a_almacenar.erase(this->entidades_it);
            return true;
        }
    }

    for (this->entidades_it = this->entidades_existentes.begin(); this->entidades_it != this->entidades_existentes.end(); this->entidades_it++)
    {
        if ((*this->entidades_it)->hashcode() == entidad_a_eliminar->hashcode())
        {
            this->entidades_a_eliminar.push_back(*this->entidades_it);
            this->entidades_existentes.erase(this->entidades_it);
            return true;
        }
    }

    return false;
}


visualizador::modelo::IEntidad * GestorEntidades::encontrar(visualizador::modelo::IEntidad * entidad_a_encontrar)
{
    for (this->entidades_it = this->entidades_existentes.begin(); this->entidades_it != this->entidades_existentes.end(); this->entidades_it++)
    {
        if ((*this->entidades_it)->hashcode() == entidad_a_encontrar->hashcode())
        {
            return *this->entidades_it;
        }
    }

    for (this->entidades_it = this->entidades_a_almacenar.begin(); this->entidades_it != this->entidades_a_almacenar.end(); this->entidades_it++)
    {
        if ((*this->entidades_it)->hashcode() == entidad_a_encontrar->hashcode())
        {
            return *this->entidades_it;;
        }
    }

    return NULL;
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