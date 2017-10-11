// #include <aplicacion/include/GestorEntidad.h>
//
//using namespace visualizador::aplicacion;
//
//// aplicacion
//#include <almacenamiento/include/IAdministradorAlmacenamiento.h>
//
//// modelo
//#include <modelo/include/IEntidad.h>

//template <class T>
//GestorEntidad<T>::GestorEntidad()
//{
//}
//
//template <class T>
//GestorEntidad<T>::~GestorEntidad()
//{
//}
//
//template<class T>
//std::vector<T> GestorEntidad<T>::recuperarTodos()
//{
//	std::vector<T> entidades;
//
//	std::vector<almacenamiento::IAlmacenableClaveValor*> grupo;
//
//	T entidad_aux = new T();
//	almacenamiento::IAdministradorAlmacenamiento::getInstancia()->recuperarGrupo(entidad_aux->prefijoGrupo(), grupo);
//	delete entidad_aux;
//
//	for (std::vector<almacenamiento::IAlmacenableClaveValor*>::iterator it = grupo.begin(); it != grupo.end(); it++)
//	{
//		T nueva_entidad = new T();
//		nueva_entidad->parsearValorAlmacenable((*it)->getValor());
//		entidades.push_back(nueva_entidad);
//	}
//
//	return entidades;
//}


