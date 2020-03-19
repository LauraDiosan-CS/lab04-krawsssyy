#include "Repo.h"

Repo::Repo() {
	this->n = 0;
}
Repo::~Repo() {
	this->n = 0;
}
void Repo::addElement(Player p) {
	this->players[this->n++] = p;
}

Player* Repo::getAll() {
	return this->players;
}

int Repo::getSize()
{
	return this->n;
}