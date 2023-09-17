#include "Team.h"

// Defini��o do construtor padr�o
Team::Team()
	: name(""), stadium(""), coach(""), city("")
{
}

// Defini��o do construtor parametrizado
Team::Team(const string& name, const string& stadium, const string& coach, const string& city)
{
	setTeam(name, stadium, coach, city);
}

// Defini��o do m�todo para configurar os atributos da classe
void Team::setTeam(const string& name, const string& stadium, const string& coach, const string& city)
{
	// Verifica��es usando exce��es
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

// Defini��o do m�todo para adicionar um jogador ao time
void Team::addPlayer(const Player& player)
{
	// Verifica��es usando exce��es
	if (players.size() == 25)
	{
		throw invalid_argument("Team is full");
	}

	// Adiciona o jogador ao vetor
	players.push_back(player);
}

// Defini��o do m�todo para remover um jogador do time
void Team::removePlayer(const string& name)
{
	// Verifica��es usando exce��es
	if (players.empty())
	{
		throw invalid_argument("Team is empty");
	}

	// Procura o jogador no vetor
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i].getName() == name)
		{
			// Remove o jogador do vetor
			players.erase(players.begin() + i);
			return;
		}
	}

	// Se o jogador n�o foi encontrado, lan�a uma exce��o
	throw invalid_argument("Player not found");
}