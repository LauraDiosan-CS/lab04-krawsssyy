#include "Service.h"
using namespace std;

Service::Service(Repo<Player>& repo) : r(repo) {};

void Service::addElem(int id, char* name, int playedGames, int wonGames)
{
	Player p(id, name, playedGames, wonGames);
	this->undoStack.push(this->r.getAll());
	this->r.addElement(p);
}


vector<Player> Service::getAll()
{
	 return this->r.getAll();
}

Player* Service::readPlayer(int id)
{
	 return this->r.readEntity(id);
}

void Service::updatePlayer(int idOrig, int id, char* name, int playedGames, int wonGames)
{
	Player p(id, name, playedGames, wonGames);
	this->undoStack.push(this->r.getAll());
	this->r.updateEntity(idOrig, p);
}

void Service::deletePlayer(int id)
{
	this->undoStack.push(this->r.getAll());
	this->r.deleteEntity(id);
}

size_t Service::getSize()
{
	return this->r.getSize();
}

vector<Player> Service::filterGames()
{
	vector<Player> filtered;
	vector<Player> players = this->getAll();
	for (int j = 0; j < players.size(); j++)
	{
		if (players[j].getWonGames() == 0)
			filtered.push_back(players[j]);
	}
	this->undoStack.push(this->r.getAll());
	this->r.setVector(filtered);
	return filtered;
}

vector<Player> Service::orderDescdening()
{
	vector<Player> players = this->getAll();
	for(int i = 0; i < players.size(); i++)
		for(int j = i; j < players.size(); j++)
			if (players[i].getPlayedGames() > players[j].getPlayedGames())
			{
				Player aux = players[i];
				players[i] = players[j];
				players[j] = aux;
			}
	this->undoStack.push(this->r.getAll());
	this->r.setVector(players);
	return players;
}

bool Service::undo()
{
	if (this->undoStack.empty() == true)
		return false;
	else
	{
		vector<Player> last = undoStack.top();
		undoStack.pop();
		this->r.setVector(last);
	}
	
}