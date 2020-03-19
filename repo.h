#pragma once
#include "Player.h"

class Repo {
private:
	Player players[20];
	int n;
public:
	Repo();
	~Repo();
	void addElement(Player s);
	Player* getAll();
	int getSize();
};