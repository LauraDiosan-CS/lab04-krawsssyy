#pragma once
class Player
{
private:
	char* name;
	int playedGames;
	int wonGames;
public:
	Player();
	Player(char* name, int playedGames,int wonGames);
	Player(const Player& p);
	~Player();
	void setName(char* name);
	void setPlayedGames(int playedGames);
	void setWonGames(int wonGames);
	char* getName();
	int getPlayedGames();
	int getWonGames();
	Player& operator=(const Player& p);
	bool operator==(const Player& p);
};