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

Player* Repo::readPlayer(int id)
{
	if (id)
	{
		for (auto player : this->players)
			if (player.getId() == id)
			{
				Player* pp = new Player(player);
				return pp;
			}
		return nullptr;
	}
	else
		return this->players;
}

void Repo::deletePlayer(int id)
{
	int i;
	int p = this->getSize();
	for (i = 0; i < p; i++)
		if (this->players[i].getId() == id)
			break;
	if (i < p)
	{
		for (int j = i; j < p - 1; j++)
			this->players[j] = this->players[j + 1];
		this->n--;

	}


}