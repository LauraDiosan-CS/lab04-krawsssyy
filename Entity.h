#pragma once
class Entity {
protected:
	int id;
public:
	Entity() { this->id = 0; }
	Entity(int id) { this->id = id; }
	Entity(const Entity& e) { this->id = e.id; }
	~Entity() {};
	int getId() { return this->id; }
	Entity& operator=(const Entity& e) { this->id = e.id; return *this; }
};