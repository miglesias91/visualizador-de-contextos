#include <modelo/include/IAlmacenable.h>

using namespace visualizador::modelo;

IAlmacenable::IAlmacenable(std::string grupo) : id(NULL), grupo(grupo), IHashable()
{
}

IAlmacenable::~IAlmacenable()
{
    delete this->id;
    this->id = NULL;
}

// GETTERS

visualizador::aplicacion::ID* IAlmacenable::getId()
{
    return this->id;
}

std::string IAlmacenable::getGrupo()
{
    return this->grupo;
}

// SETTERS

void IAlmacenable::setId(visualizador::aplicacion::ID* id)
{
    this->id = id;
}

void IAlmacenable::setGrupo(std::string grupo)
{
    this->grupo = grupo;
}

// METODOS

void IAlmacenable::asignarNuevoId()
{
    this->id = visualizador::aplicacion::GestorIDs::nuevoID();
}

bool IAlmacenable::comparador(IAlmacenable * a, IAlmacenable * b)
{
    return a->getId()->numero() < b->getId()->numero();
}