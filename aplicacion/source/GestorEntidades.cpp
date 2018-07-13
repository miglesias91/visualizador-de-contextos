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
    this->admin_app = IAdministradorAplicacion::getInstanciaAdminEntidades();
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

// GETTERS

std::vector<visualizador::modelo::IEntidad*> visualizador::aplicacion::GestorEntidades::getEntidadesAAlmacenar()
{
    return this->entidades_a_almacenar;
}

std::vector<visualizador::modelo::IEntidad*> visualizador::aplicacion::GestorEntidades::getEntidadesAEliminar()
{
    return this->entidades_a_eliminar;
}

void GestorEntidades::registrar() {
    herramientas::utiles::Json registro;
    std::vector<herramientas::utiles::Json*> registros;

    std::for_each(this->entidades_a_almacenar.begin(), this->entidades_a_almacenar.end(), [=](visualizador::modelo::IEntidad * entidad) {
        herramientas::utiles::Json json_entidad;
        json_entidad.agregarAtributoValor("id", entidad->getId()->string());
        json_entidad.agregarAtributoValor("usuario", entidad->getGrupo());
    });
}

// SETTERS

// METODOS

bool GestorEntidades::guardarCambios() {
    this->registrar();

    for (this->entidades_it = this->entidades_a_almacenar.begin(); this->entidades_it != this->entidades_a_almacenar.end(); this->entidades_it++)
    {
        visualizador::modelo::IEntidad * entidad_a_almacenar = *this->entidades_it;
        this->admin_app->almacenar(entidad_a_almacenar);
        this->admin_app->almacenar(entidad_a_almacenar->getRelaciones());
        entidad_a_almacenar->vincular();

        this->entidades_existentes.push_back(*this->entidades_it);
    }
    this->entidades_a_almacenar.clear();

    for (this->entidades_it = this->entidades_a_eliminar.begin(); this->entidades_it != this->entidades_a_eliminar.end(); this->entidades_it++)
    {
        visualizador::modelo::IEntidad * entidad_a_eliminar = *this->entidades_it;
        this->admin_app->eliminar(entidad_a_eliminar);
        this->admin_app->eliminar(entidad_a_eliminar->getRelaciones());
        entidad_a_eliminar->desvincular();
        delete (*this->entidades_it);
    }
    this->entidades_a_eliminar.clear();

    for (this->entidades_it = this->entidades_existentes.begin(); this->entidades_it != this->entidades_existentes.end(); this->entidades_it++)
    {
        if ((*this->entidades_it)->estaSucia())
        {
            this->admin_app->modificar(*this->entidades_it);
        }
    }

    return true;
}

bool GestorEntidades::recuperar(visualizador::modelo::IEntidad * entidad_a_recuperar)
{
    if (this->admin_app->recuperar(entidad_a_recuperar))
    {
        if (this->admin_app->recuperar(entidad_a_recuperar->getRelaciones()))
        {
            if(entidad_a_recuperar->recuperarContenidoDeRelaciones())
            {
                return true;
            }
        }
    }

    return false;
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

bool GestorEntidades::almacenar(visualizador::modelo::IEntidad * entidad_nueva)
{
    // si ya existe la entidad, entonces devuelvo 'false' indicando que no se agregó la nueva entidad
    // y tiro una excepcion avisando que ya existe una entidad igual.
    if (this->existe(entidad_nueva))
    {
        // TODO implementar 'ExcepcionTerminoExistente'.
        // std::string mensaje("La entidad '" + entidad_nueva->getEtiqueta() + "' ya existe.");
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

bool GestorEntidades::modificar(visualizador::modelo::IEntidad * entidad_a_modificar)
{
    // si la entidad a modificar esta en 'existentes', entonces agrego su nuevo valor a 'almacenar' y la elimino de 'existentes'.
    for (this->entidades_it = this->entidades_existentes.begin(); this->entidades_it != this->entidades_existentes.end(); this->entidades_it++)
    {
        if ((*this->entidades_it)->getId()->numero() == entidad_a_modificar->getId()->numero())
        {
            // agrego el valor nuevo
            this->entidades_a_almacenar.push_back(entidad_a_modificar->clonar());

            // saco el valor viejo de 'existentes' y elimino su memoria, xq ahora uso la memoria del clon del nuevo valor.
            delete *this->entidades_it;
            this->entidades_existentes.erase(this->entidades_it);
            return true;
        }
    }

    // si la entidad a modificar esta en 'a_almacenar', la elimino de 'existentes' y dsp la agrego con su nuevo alor..
    for (this->entidades_it = this->entidades_a_almacenar.begin(); this->entidades_it != this->entidades_a_almacenar.end(); this->entidades_it++)
    {
        if ((*this->entidades_it)->getId()->numero() == entidad_a_modificar->getId()->numero())
        {
            // saco el valor viejo de 'existentes' y elimino su memoria, xq ahora uso la memoria del clon del nuevo valor.
            delete *this->entidades_it;
            this->entidades_a_almacenar.erase(this->entidades_it);

            // agrego el nuevo valor a almacenar
            this->entidades_a_almacenar.push_back(entidad_a_modificar->clonar());

            return true;
        }
    }

    return false;
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