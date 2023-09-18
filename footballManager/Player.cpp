#include "Player.h"

// Defini��o do construtor parametrizado
Player::Player(const string& name, const string& position, int age, int number)
{
    setPlayer(name, position, age, number);
}

// Defini��o do m�todo para configurar os atributos da classe
Player& Player::setPlayer(const string& name, const string& position, int age, int number)
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

// Defini��o do m�todo para configurar o nome do jogador
Player& Player::setName(const string& name)
{
	// Verifica��es usando exce��es
    if (name.empty())
    {
		throw invalid_argument("Name cannot be empty");
	}

	// Atribui o valor ao membro
	this->name = name;
    return *this;
}

// Defini��o do m�todo para configurar a posi��o do jogador
Player& Player::setPosition(const string& position)
{
	// Verifica��es usando exce��es
    if (position.empty())
    {
		throw invalid_argument("Position cannot be empty");
	}

	// Atribui o valor ao membro
	this->position = position;
    return *this;
}

// Defini��o do m�todo para configurar a idade do jogador
Player& Player::setAge(int age)
{
	// Verifica��es usando exce��es
    if (age < 0)
    {
		throw invalid_argument("Age cannot be negative");
	}

	// Atribui o valor ao membro
	this->age = age;
    return *this;
}

// Defini��o do m�todo para configurar o n�mero do jogador
Player& Player::setNumber(int number)
{
	// Verifica��es usando exce��es
    if (number < 0)
    {
		throw invalid_argument("Number cannot be negative");
	}

	// Atribui o valor ao membro
	this->number = number;
    return *this;
}

