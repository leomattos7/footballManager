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

	// Adiciona o jogador na lista
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

	// Se o jogador n�o foi encontrado, lan�a uma exce��o
	throw invalid_argument("Player not found");
}

// Defini��o do m�todo para mostrar os dados do time
void Team::showTeam()
{
	cout << "Name: " << getName() << endl;
	cout << "Stadium: " << getStadium() << endl;
	cout << "Coach: " << getCoach() << endl;
	cout << "City: " << getCity() << endl;
	cout << "Players: " << endl;

	for (Player& player : players)
	{
		cout << "Name: " << player.getName();
		cout << ", Position: " << player.getPosition();
		cout << ", Age: " << player.getAge();
		cout << ", Number: " << player.getNumber() << endl;
	}
	cout << endl;
}

// Defini��o do m�todo para configurar o nome do time
void Team::setName(const string& name)
{
	// Verifica��es usando exce��es
	if (name.empty())
	{
		throw invalid_argument("Name cannot be empty");
	}

	// Atribui o valor ao membro
	this->name = name;
}

// Defini��o do m�todo para configurar o est�dio do time
void Team::setStadium(const string& stadium)
{
	// Verifica��es usando exce��es
	if (stadium.empty())
	{
		throw invalid_argument("Stadium cannot be empty");
	}

	// Atribui o valor ao membro
	this->stadium = stadium;
}

// Defini��o do m�todo para configurar o t�cnico do time
void Team::setCoach(const string& coach)
{
	// Verifica��es usando exce��es
	if (coach.empty())
	{
		throw invalid_argument("Coach cannot be empty");
	}

	// Atribui o valor ao membro
	this->coach = coach;
}

// Defini��o do m�todo para configurar a cidade do time
void Team::setCity(const string& city)
{
	// Verifica��es usando exce��es
	if (city.empty())
	{
		throw invalid_argument("City cannot be empty");
	}

	// Atribui o valor ao membro
	this->city = city;
}

// Defini��o do m�todo para obter o nome do time
string Team::getName()
{
	return name;
}

// Defini��o do m�todo para obter o est�dio do time
string Team::getStadium()
{
	return stadium;
}

// Defini��o do m�todo para obter o t�cnico do time
string Team::getCoach()
{
	return coach;
}

// Defini��o do m�todo para obter a cidade do time
string Team::getCity()
{
	return city;
}

// Defini��o do m�todo para obter a lista de jogadores do time
list<Player> Team::getPlayers()
{
	return players;
}

// Defini��o do destrutor
Team::~Team()
{
}

Team* setTeam()
{
	string name, stadium, coach, city;

	cout << "Digite o nome do time: ";
	getline(cin, name);

	cout << "Digite o est�dio do time: ";
	getline(cin, stadium);

	cout << "Digite o t�cnico do time: ";
	getline(cin, coach);

	cout << "Digite a cidade do time: ";
	getline(cin, city);

	Team* team = new Team(name, stadium, coach, city);
	return team;
}