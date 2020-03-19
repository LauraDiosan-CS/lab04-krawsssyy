#include <assert.h>
#include <string>
#include "repo.h"
#include "player.h"

void testPlayer()
{
	char* name1;
	char* name2;
	name1 = new char[7];
	name2 = new char[8];
	strcpy_s(name1, sizeof "Andrei" , "Andrei");
	strcpy_s(name2, sizeof "Gabriel", "Gabriel");
	Player p1(name1, 10, 5);
	Player p2(name2, 7, 7);
	assert(!strcmp(p1.getName(), "Andrei"));
	assert(!strcmp(p2.getName(), "Gabriel"));
	assert(p1.getPlayedGames() == 10);
	assert(p2.getPlayedGames() == 7);
	assert(p1.getWonGames() == 5);
	assert(p2.getWonGames() == 7);
	char* name3 = new char[4];
	strcpy_s(name3, sizeof "Ana", "Ana");
	p1.setName(name3);
	assert(!strcmp(p1.getName(), "Ana"));
	p2.setPlayedGames(15);
	assert(p2.getPlayedGames() == 15);
	p1.setWonGames(9);
	assert(p1.getWonGames() == 9);
	delete[] name1;
	name1 = nullptr;
	delete[] name2;
	name2 = nullptr;
	delete[] name3;
	name3 = nullptr;
}

void testRepo()
{
	char* name1 = new char[10];
	char* name2 = new char[10];
	strcpy_s(name1, sizeof "Andrei", "Andrei");
	strcpy_s(name2, sizeof "Gabriel", "Gabriel");
	Player p1(name1, 10, 5);
	Player p2(name2, 7, 7);
	Repo r;
	r.addElement(p1);
	assert(r.getSize() == 1);
	r.addElement(p2);
	assert(r.getSize() == 2);
	Player players[2];
	players[0] = p1;
	players[1] = p2;
	assert(r.getAll()[0] == p1);
	assert(r.getAll()[1] == p2);
	delete[] name1;
	name1 = nullptr;
	delete[] name2;
	name2 = nullptr; 
}

/* crud repo*/