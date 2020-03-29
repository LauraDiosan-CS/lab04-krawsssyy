#pragma once
#include "Entity.h"
#include <vector>
using namespace std;

template <class T> class Repo {
private:
	vector<T> entities;
public:
	Repo() { this->entities.reserve(100); }
	~Repo() {
		this->entities.clear();
	}
	void addElement(T& s) {
		this->entities.push_back(s);
	}
	vector<T> getAll() {
		return this->entities;
	}
	size_t getSize() {
		return this->entities.size();
	}
	void updateEntity(int id, const T& p) {
		for (int i = 0; i < this->entities.size(); i++)
			if (this->entities[i].getId() == id)
				this->entities[i] = p;
	}
	void deleteEntity(int id) {
		int i;
		size_t p = this->entities.size();
		for (i = 0; i < p; i++)
			if (this->entities[i].getId() == id)
				break;
		if (i < p)
		{
			this->entities.erase(this->entities.begin() + i);
		}
	}
	T* readEntity(int id) {
		for (int i = 0; i < this->entities.size(); i++)
			if (entities[i].getId() == id)
			{
				T* t = new T(entities[i]);
				return t;
			}
		return nullptr;
	}
	void setVector(vector<T> t) {
		this->entities.clear();
		this->entities.resize(t.size());
		copy(t.begin(), t.end(), this->entities.begin());
	}
};

