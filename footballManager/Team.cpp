#include "Team.h"

// Definição do construtor padrão
Team::Team()
	: name(""), stadium(""), coach(""), city("")
{
}

// Definição do construtor parametrizado
Team::Team(const string& name, const string& stadium, const string& coach, const string& city)
{
	setTeam(name, stadium, coach, city);
}

// Definição do método para configurar os atributos da classe
void Team::setTeam(const string& name, const string& stadium, const string& coach, const string& city)
{
	// Verificações usando exceções
	if (name.empty())
	{
		throw invalid_argument("Name cannot be empty");
	}

	if (stadium.empty())
	{
		throw invalid_argument("Stadium cannot be empty");
	}

	if (coach.empty())
	{
		throw invalid_argument("Coach cannot be empty");
	}

	if (city.empty())
	{
		throw invalid_argument("City cannot be empty");
	}

	// Atribui os valores aos membros
	this->name = name;
	this->stadium = stadium;
	this->coach = coach;
	this->city = city;
}

// Definição do método para adicionar um jogador ao time
void Team::addPlayer(const Player& player)
{
	// Verificações usando exceções
	if (players.size() == 25)
	{
		throw invalid_argument("Team is full");
	}

	// Adiciona o jogador na lista
	players.push_back(player);
}

// Definição do método para remover um jogador do time
void Team::removePlayer(const string& name)
{
	// Verificações usando exceções
	if (players.empty())
	{
		throw invalid_argument("Team is empty");
	}

	// Procura o jogador na lista
	for (list<Player>::iterator it = players.begin(); it != players.end(); it++)
	{
		// Se o jogador foi encontrado, remove-o da lista
		if (it->getName() == name)
		{
			players.erase(it);
			return;
		}
	}

	// Se o jogador não foi encontrado, lança uma exceção
	throw invalid_argument("Player not found");
}

// Definição do método para mostrar os dados do time
void Team::showTeam()
{
	cout << "Name: " << name << endl;
	cout << "Stadium: " << stadium << endl;
	cout << "Coach: " << coach << endl;
	cout << "City: " << city << endl;
	cout << "Players: " << endl;

	for (Player& player : players)
	{
		cout << "Name: " << player.getName();
		cout << ", Position: " << player.getPosition();
		cout << ", Age: " << player.getAge();
		cout << ", Number: " << player.getNumber() << endl;
	}
}

// Definição do destrutor
Team::~Team()
{
}