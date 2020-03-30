#pragma once
#include "Repo.h"
#include "Player.h"
#include <stack>
#include <functional>
using namespace std;
class Service {
private:
	Repo<Player>& r;
	stack< vector<Player> > undoStack;
public:
	Service(Repo<Player>& repo);
	~Service() {};
	void addElem(int id, char* name, int playedGames, int wonGames);
	vector<Player> getAll();
	Player* readPlayer(int id);
	void updatePlayer(int idOrig, int id, char* name, int playedGames, int wonGames);
	void deletePlayer(int id);
    size_t getSize();
	void filterGames();
	void orderDescdening();
	bool undo();
};
