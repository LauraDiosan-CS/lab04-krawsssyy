#include "ui.h"
#include<iostream>
using namespace std;

void UI::handleAdd()
{
	int id;
	char* name;
	int playedGames;
	int wonGames;
	char s[20];
	cout << "Introduceti id = "; cin >> id; cout << endl;
	cout << "Introduceti nume = "; cin >> s; cout << endl;
	cout << "Introduceti numar de jocuri jucate = "; cin >> playedGames; cout << endl;
	cout << "Introduceti numar de jocuri castigate = "; cin >> wonGames; cout << endl;
	name = new char[strlen(s) + 1];
	strcpy_s(name, strlen(s) + 1, s);
	this->s.addElem(id, name, playedGames, wonGames);
}

void UI::handleShowID()
{
	int id;
	cout << "Introduceti id = "; cin >> id; cout << endl;
	Player* result = this->s.readPlayer(id);
	if (result != nullptr)
		cout << result;
	else
		cout << "Nu exista jucatorul cu acel id!";
}
void UI::handleShowAll()
{
	vector<Player> players = this->s.getAll();
	size_t size = players.size();
	for (vector<Player>::iterator it= players.begin(); it != players.end(); it++)
		cout << *it << endl;
}

void UI::handleUpdate()
{
	int idOrig;
	cout << " Introduceti id-ul = "; cin >> idOrig; cout << endl;
	int id;
	char* name;
	int playedGames;
	int wonGames;
	char s[20];
	cout << "Introduceti noul id = "; cin >> id; cout << endl;
	cout << "Introduceti noul nume = "; cin >> s; cout << endl;
	cout << "Introduceti noul numar de jocuri jucate = "; cin >> playedGames; cout << endl;
	cout << "Introduceti noul numar de jocuri castigate = "; cin >> wonGames; cout << endl;
	name = new char[strlen(s) + 1];
	strcpy_s(name, strlen(s) + 1, s);
	this->s.updatePlayer(idOrig, id, name, playedGames, wonGames);
}

void UI::handleDelete()
{
	int id;
	cout << " Introduceti id-ul = "; cin >> id; cout << endl;
	this->s.deletePlayer(id);
}

void UI::handleFilter()
{
	vector<Player> result = this->s.filterGames();
	this->handleShowAll();
}

void UI::handleOrder()
{
	vector<Player> result = this->s.orderDescdening();
	this->handleShowAll();

}

void UI::handleUndo()
{
	bool result = this->s.undo();
	if (result)
		cout << "Operatiune reusita!" << endl;
	else
		cout << "Nu aveti la ce face undo!" << endl;
}

void UI::showMenu()
{
	cout << "1. Adaugare jucator" << endl;
	cout << "2. Afisare jucator dupa id" << endl;
	cout << "3. Afisare toti jucatorii" << endl;
	cout << "4. Modificati un jucator" << endl;
	cout << "5. Stergeti un jucator" << endl;
	cout << "6. Filtratii doar jucatorii cu 0 jocuri castigate" << endl;
	cout << "7. Ordonati jucatorii descrescator dupa jocurile jucate" << endl;
	cout << "8. Undo" << endl;
	cout << "9. Iesire" << endl;
}

void UI::runConsole()
{
	char option = '0';
	while (option != '9')
	{
		this->showMenu();
		cin >> option;
		switch (option)
		{
		case '1':
			this->handleAdd();
			break;
		case '2':
			this->handleShowID();
			break;
		case '3':
			this->handleShowAll();
			break;
		case '4':
			this->handleUpdate();
			break;
		case '5':
			this->handleDelete();
			break;
		case '6':
			this->handleFilter();
			break;
		case '7':
			this->handleOrder();
			break;
		case '8':
			this->handleUndo();
			break;
		case '9':
			break;
		default:
			cout << "Optiune invalida" << endl;
			break;
		}
		cout << endl;
	}
}