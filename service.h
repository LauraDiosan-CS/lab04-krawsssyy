#pragma once
#include "Repo.h"
#include "Player.h"
class Service {
private:
	Repo& r;
public:
	Service(Repo& repo);
	void addElem(int id, char* name, int playedGames, int wonGames);
	Player* getAll();
	Player readPlays(int id = 0);
	void updatePlayer(int id, const Player& p);
	void deletePlayer(int id);
	int getSize();
};