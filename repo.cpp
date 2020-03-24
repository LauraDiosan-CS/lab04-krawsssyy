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

void Repo::updatePlayer(int id, const Player& p)
{
	for (int i = 0; i < this->getSize(); i++)
		if (this->getAll()[i].getId() == id)
			this->getAll()[i] = p;
}

Player Repo::readPlayer(int id)
{
	if (id != 0)
	{
		for (Player player : this->players)
			if (player.getId() == id)
				return player;
	}
	else
		this->getAll();
}

void Repo::deletePlayer(int id)
{
	int i;
	int p = this->getSize();
	for (i = 0; i < p; i++)
		if (this->getAll()[i].getId() == id)
			break;
	if (i < p)
	{
		for (int j = i; j < p - 1; j++)
			this->getAll()[j] = this->getAll()[j + 1];
		this->n--;

	}


}