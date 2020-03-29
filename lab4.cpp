#include <iostream>
#include "tests.h"
#include "repo.h"
#include "player.h"
#include "service.h"
#include "ui.h"
using  namespace std;

int main()
{
	testPlayer();
	testRepo();
	testService();
	Repo<Player> r;
	Service s(r);
	UI ui(s);
	ui.runConsole();
	return 0;
}