#include <assert.h>
#include <string>
#include "repo.h"
#include "player.h"
#include "service.h"

void testPlayer()
{
	char* name1;
	char* name2;
	name1 = new char[7];
	name2 = new char[8];
	strcpy_s(name1, sizeof "Andrei" , "Andrei");
	strcpy_s(name2, sizeof "Gabriel", "Gabriel");
	Player p1(1, name1, 10, 5);
	Player p2(2, name2, 7, 7);
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
	Player p1(1, name1, 10, 5);
	Player p2(2, name2, 7, 7);
	Repo r;
	r.addElement(p1);
	assert(r.getSize() == 1);
	r.addElement(p2);
	assert(r.getSize() == 2);
	assert(r.getAll()[0] == p1);
	assert(r.getAll()[1] == p2);
	assert(*r.readPlayer(1) == p1);
	assert(*r.readPlayer(2) == p2);
	Player p3 = p2;
	r.deletePlayer(2);
	assert(r.getSize() == 1);
	r.updatePlayer(1, p3);
	assert(*r.readPlayer(2) == p2); 
	delete[] name1;
	name1 = nullptr;
	delete[] name2;
	name2 = nullptr; 
}

void testService()
{
	char* name1 = new char[10];
	char* name2 = new char[10];
	strcpy_s(name1, sizeof "Andrei", "Andrei");
	strcpy_s(name2, sizeof "Gabriel", "Gabriel");
	Player p1(1, name1, 10, 5);
	Player p2(2, name2, 7, 7);
	Repo r;
	Service serv(r);
	serv.addElem(1, name1, 10, 5);
	assert(serv.getSize() == 1);
	serv.addElem(2, name2, 7, 7);
	assert(serv.getSize() == 2);
	assert(serv.getAll()[0] == p1);
	assert(serv.getAll()[1] == p2);
	assert(*serv.readPlays(1) == p1);
	assert(*serv.readPlays(2) == p2);
	Player p3 = p2;
	serv.deletePlayer(2);
	assert(serv.getSize() == 1);
	serv.updatePlayer(1, 2, name2, 7, 7);
	assert(*serv.readPlays(2) == p2);
	assert(serv.filterGames() == nullptr);
	serv.addElem(3, name1, 10, 9);
	Player p4(3, name1, 10, 9);
	assert(serv.orderDescdening()[1] == p4);
	assert(serv.orderDescdening()[0] == p2);
	Player p5(4, name2, 3, 0);
	serv.addElem(4, name2, 3, 0);
	assert(serv.filterGames()[0] == p5);
	delete[] name1;
	name1 = nullptr;
	delete[] name2;
	name2 = nullptr;
}
