#pragma once
#include "Player.h"

class Repo {
private:
	Player players[30];
	int n;
public:
	Repo();
	~Repo();
	void addElement(Player s);
	Player* getAll();
	int getSize();
	void updatePlayer(int id, const Player& p);
	void deletePlayer(int id);
	Player* readPlayer(int id = 0);
};

