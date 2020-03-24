#pragma once
class Player
{
private:
	int id;
	char* name;
	int playedGames;
	int wonGames;
public:
	Player();
	Player(int id, char* name, int playedGames,int wonGames);
	Player(const Player& p);
	~Player();
	void setId(int id);
	void setName(char* name);
	void setPlayedGames(int playedGames);
	void setWonGames(int wonGames);
	int getId();
	char* getName();
	int getPlayedGames();
	int getWonGames();
	Player& operator=(const Player& p);
	bool operator==(const Player& p);
};