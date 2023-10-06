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
	Player() : name(""), position(0), age(0), number(0) { }
	Player(const string& name, int position, int age, int number);
	Player& setPlayer(const string& name, int position, int age, int number);
	Player& setName(const string& name);
	Player& setPosition(const string& position);
	Player& setAge(int age);
	Player& setNumber(int number);
	string getName() {return name;}
	string getPosition() {return position;}
	int getAge() {return age;}
	int getNumber() {return number;}
	~Player() { }
};

Player* setDataPlayer();

#endif