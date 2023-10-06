#include "Player.h"

// Defini��o do construtor parametrizado
Player::Player(const string& name, int position, int age, int number)
{
    setPlayer(name, position, age, number);
}

// Defini��o do m�todo para configurar os atributos da classe
Player& Player::setPlayer(const string& name, int position, int age, int number)
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

    if (position < 0 || position > 4)
    {
        throw invalid_argument("Position cannot be empty");
    }

    // Atribui os valores aos membros
    this->name = name;
    this->age = age;
    this->number = number;
	switch (position)
	{
	case 1:
		this->position = "goalkeeper";
		break;
	case 2:
		this->position = "defender";
		break;
	case 3:
		this->position = "middle";
		break;
	case 4:
		this->position = "striker";
		break;
	}
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

// Defini��o do m�todo para configurar o nome do jogador
Player* setDataPlayer()
{
	string name;
	int position;
	int age;
	int number;
	cout << "Name: ";
	getline(cin, name);
	cout << "Position: " << endl;
	cout << "1 - Goleiro" << endl << "2 - Defensor" << endl << "3 - Meio-campista" << endl << "4 - Atacante" << endl;
	cin >> position;
	cout << "Age: ";
	cin >> age;
	cout << "Number: ";
	cin >> number;
	cin.ignore();
	Player* player = new Player(name, position, age, number);
	return player;
}
