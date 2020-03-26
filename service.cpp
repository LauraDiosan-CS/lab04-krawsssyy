#include "Service.h"

void Service::addElem(int id, char* name, int playedGames, int wonGames)
{
	Player p(id, name, playedGames, wonGames);
	this->r.addElement(p);
}

Service::Service(Repo& repo) : r(repo) {};

Player* Service::getAll()
{
	 return this->r.getAll();
}

Player* Service::readPlays(int id)
{
	 return this->r.readPlayer(id);
}

void Service::updatePlayer(int idOrig, int id, char* name, int playedGames, int wonGames)
{
	Player p(id, name, playedGames, wonGames);
	this->r.updatePlayer(idOrig, p);
}

void Service::deletePlayer(int id)
{
	this->r.deletePlayer(id);
}

int Service::getSize()
{
	return this->r.getSize();
}

Player* Service::filterGames()
{
	Player* filtered = new Player[30];
	int i = 0;
	for (int j = 0; j < this->getSize(); j++)
	{
		if (this->getAll()[j].getWonGames() == 0)
			filtered[i++] = this->getAll()[j];
	}
	if(i)
		return filtered;
	return nullptr;
}

Player* Service::orderDescdening()
{
	Player* players = new Player[30];
	players = this->getAll();
	for(int i = 0; i < this->getSize(); i++)
		for(int j = i; j < this->getSize(); j++)
			if (players[i].getPlayedGames() > players[j].getPlayedGames())
			{
				Player aux = players[i];
				players[i] = players[j];
				players[j] = aux;
			}
	return players;
}
