#include "player.h"
#include <cstddef>
#include <string>

Player::Player()
{
	this->name = NULL;
	this->playedGames = 0;
	this->wonGames = 0;
}

Player::Player(char* name, int playedGames, int wonGames)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->playedGames = playedGames;
	this->wonGames = wonGames;
}
Player::Player(const Player& p)
{
	this->name = new char[strlen(p.name) + 1];
	strcpy_s(this->name, strlen(p.name) + 1, p.name);
	this->playedGames = p.playedGames;
	this->wonGames = p.wonGames;
}

Player::~Player()
{
	if (this->name)
	{
		delete[] this->name;
		this->name = NULL;
	}

}

void Player::setName(char* name)
{
	if (this->name)
	{
		delete[] this->name;
		this->name = NULL;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Player::setPlayedGames(int playedGames)
{
	this->playedGames = playedGames;
}

void Player::setWonGames(int wonGames)
{
	this->wonGames = wonGames;
}

char* Player::getName()
{
	return this->name;
}

int Player::getPlayedGames()
{
	return this->playedGames;
}

int Player::getWonGames()
{
	return this->wonGames;
}

Player& Player::operator=(const Player& p)
{
	this->setName(p.name);
	this->setPlayedGames(p.playedGames);
	this->setWonGames(p.wonGames);
	return *this;
}

bool Player:: operator==(const Player& p) {
	return strcmp(this->name, p.name) == 0 && this->playedGames == p.playedGames && this->wonGames == p.wonGames;
}