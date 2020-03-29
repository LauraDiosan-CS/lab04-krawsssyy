#pragma once
#include "Entity.h"
#include <iostream>
using namespace std;
class Player : public Entity
{
private:
	char* name;
	int playedGames;
	int wonGames;
public:
	Player();
	Player(int id, char* name, int playedGames,int wonGames);
	Player(const Player& p);
	~Player();
	void setName(char* name);
	void setPlayedGames(int playedGames);
	void setWonGames(int wonGames);
	char* getName();
	int getPlayedGames();
	int getWonGames();
	Player& operator=(const Player& p);
	bool operator==(Player& p);
	friend ostream& operator<<(ostream& os, const Player& p);
};