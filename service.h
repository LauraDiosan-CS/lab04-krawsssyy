#pragma once
#include "Repo.h"
#include "Player.h"
class Service {
private:
	Repo& r;
public:
	Service(Repo& repo);
	~Service() {};
	void addElem(int id, char* name, int playedGames, int wonGames);
	Player* getAll();
	Player* readPlays(int id = 0);
	void updatePlayer(int idOrig, int id, char* name, int playedGames, int wonGames);
	void deletePlayer(int id);
	int getSize();
	Player* filterGames();
	Player* orderDescdening();
};