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

Player Service::readPlays(int id)
{
	 return this->r.readPlayer(id);
}

void Service::updatePlayer(int id, const Player& p)
{
	this->r.updatePlayer(id, p);
}

void Service::deletePlayer(int id)
{
	this->r.deletePlayer(id);
}

int Service::getSize()
{
	return this->r.getSize();
}