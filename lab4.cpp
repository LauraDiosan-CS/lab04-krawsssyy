#include <iostream>
#include "tests.h"
#include "repo.h"
#include "player.h"
#include "service.h"
using  namespace std;

int main()
{
	testPlayer();
	testRepo();
	testService();
	cout << "Hello world!";
	return 0;
}