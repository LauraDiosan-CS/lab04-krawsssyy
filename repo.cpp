//#include "Repo.h"
//#include <vector>
//using namespace std;
//
//template <class T> Repo<T>::Repo() {
//	;
//}
//template <class T> Repo<T>::~Repo() {
//	this->entities.clear();
//	
//}
//template <class T> void Repo<T>::addElement(T& s) {
//	this->entities.push_back(s);
//}
//
//template<class T> vector<T> Repo<T>::getAll() {
//	return this->entities;
//}
//
//template <class T> int Repo<T>::getSize()
//{
//	return this->entities.size();
//}
//
//template <class T>void Repo<T>::updateEntity(int id, const T& p)
//{
//	for (int i = 0; i < this->entities.size(); i++)
//		if (this->entities[i].getID() == id)
//			this->entities[i] = p;
//}
//
//template <class T> T* Repo<T>::readEntity(int id)
//{
//	if (id)
//	{
//		for (auto entity : this->entities)
//			if (entity.getId() == id)
//			{
//				T* t = new T(entity);
//				return t;
//			}
//		return nullptr;
//	}
//	else
//		return this->entities;
//}
//
//template <class T> void Repo<T>::deleteEntity(int id)
//{
//	int i;
//	int p = this->entities.size();
//	for (i = 0; i < p; i++)
//		if (this->entities[i].getId() == id)
//			break;
//	if (i < p)
//	{
//		this->entities.erase(this->entities.begin() + i);
//	}
//
//
//}