#include "Player.h"

// Defini��o do construtor padr�o
Player::Player()
    : name(""), position(""), age(0), number(0)
{
}

// Defini��o do construtor parametrizado
Player::Player(const string& name, const string& position, int age, int number)
{
    setPlayer(name, position, age, number);
}

// Defini��o do m�todo para configurar os atributos da classe
void Player::setPlayer(const string& name, const string& position, int age, int number)
{
    // Verifica��es usando exce��es
    if (age < 0)
    {
        throw invalid_argument("Age cannot be negative");
    }

    if (number < 0)
    {
        throw invalid_argument("Number cannot be negative");
    }

    if (name.empty())
    {
        throw invalid_argument("Name cannot be empty");
    }

    if (position.empty())
    {
        throw invalid_argument("Position cannot be empty");
    }

    // Atribui os valores aos membros
    this->name = name;
    this->position = position;
    this->age = age;
    this->number = number;
}

// Defini��o do m�todo para obter o nome do jogador
string Player::getName()
{
	return name;
}

// Defini��o do m�todo para obter a posi��o do jogador
string Player::getPosition()
{
	return position;
}

// Defini��o do m�todo para obter a idade do jogador
int Player::getAge()
{
	return age;
}

// Defini��o do m�todo para obter o n�mero do jogador
int Player::getNumber()
{
	return number;
}

// Defini��o do destrutor
Player::~Player()
{
    // N�o � necess�rio neste caso
}