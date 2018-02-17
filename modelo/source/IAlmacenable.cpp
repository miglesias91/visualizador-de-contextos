#include <modelo/include/IAlmacenable.h>

using namespace visualizador::modelo;

herramientas::utiles::GestorIDs IAlmacenable::gestor_ids;

IAlmacenable::IAlmacenable(std::string grupo) : id(NULL), grupo(grupo), IHashable()
{
}

IAlmacenable::~IAlmacenable()
{
    delete this->id;
    this->id = NULL;
}

// GETTERS

herramientas::utiles::ID* IAlmacenable::getId()
{
    return this->id;
}

std::string IAlmacenable::getGrupo()
{
    return this->grupo;
}

herramientas::utiles::GestorIDs * IAlmacenable::getGestorIDs()
{
    return &gestor_ids;
}

// SETTERS

void IAlmacenable::setId(herramientas::utiles::ID* id)
{
    if (NULL != this->id)
    {
        delete this->id;
    }

    this->id = id;
}

void IAlmacenable::setGrupo(std::string grupo)
{
    this->grupo = grupo;
}

// METODOS

void IAlmacenable::asignarNuevoId()
{
    this->setId(gestor_ids.nuevoID());
}

bool IAlmacenable::comparador(IAlmacenable * a, IAlmacenable * b)
{
    return a->getId()->numero() < b->getId()->numero();
}