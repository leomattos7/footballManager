#include "Player.h"

// Definição do construtor parametrizado
Player::Player(const string& name, const string& position, int age, int number)
{
    setPlayer(name, position, age, number);
}

// Definição do método para configurar os atributos da classe
Player& Player::setPlayer(const string& name, const string& position, int age, int number)
{
    // Verificações usando exceções
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

// Definição do método para configurar o nome do jogador
Player& Player::setName(const string& name)
{
	// Verificações usando exceções
    if (name.empty())
    {
		throw invalid_argument("Name cannot be empty");
	}

	// Atribui o valor ao membro
	this->name = name;
    return *this;
}

// Definição do método para configurar a posição do jogador
Player& Player::setPosition(const string& position)
{
	// Verificações usando exceções
    if (position.empty())
    {
		throw invalid_argument("Position cannot be empty");
	}

	// Atribui o valor ao membro
	this->position = position;
    return *this;
}

// Definição do método para configurar a idade do jogador
Player& Player::setAge(int age)
{
	// Verificações usando exceções
    if (age < 0)
    {
		throw invalid_argument("Age cannot be negative");
	}

	// Atribui o valor ao membro
	this->age = age;
    return *this;
}

// Definição do método para configurar o número do jogador
Player& Player::setNumber(int number)
{
	// Verificações usando exceções
    if (number < 0)
    {
		throw invalid_argument("Number cannot be negative");
	}

	// Atribui o valor ao membro
	this->number = number;
    return *this;
}

// Definição do método para configurar o nome do jogador
Player* setDataPlayer()
{
	string name;
	string position;
	int age;
	int number;

	cout << "Name: ";
	getline(cin, name);

	cout << "Position: ";
	getline(cin, position);

	cout << "Age: ";
	cin >> age;

	cout << "Number: ";
	cin >> number;

	cin.ignore();

	Player* player = new Player(name, position, age, number);
	return player;
}
