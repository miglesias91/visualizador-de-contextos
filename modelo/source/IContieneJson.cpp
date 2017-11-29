#include <modelo/include/IContieneJson.h>

using namespace visualizador::modelo;

IContieneJson::IContieneJson(IJson * json) : json(json)
{
}

IContieneJson::~IContieneJson()
{
    delete this->json;
    this->json = NULL;
}

IJson * IContieneJson::getJson()
{
    return this->json;
}

void IContieneJson::setJson(IJson * json)
{
    delete this->json;

    this->json = json;
}
