#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Player
{
private:
	string name;
	string position;
	int age;
	int number;

public:
	Player();
	Player(const string& name, const string& position, int age, int number);
	void setPlayer(const string& name, const string& position, int age, int number);
	string getName();
	string getPosition();
	int getAge();
	int getNumber();
	~Player();
};

#endif