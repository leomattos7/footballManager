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
Team& Team::setTeam(const string& name, const string& stadium, const string& coach, const string& city)
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

	return *this;
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

// Definição do método para configurar o nome do time
Team& Team::setName(const string& name)
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

// Definição do método para configurar o estádio do time
Team& Team::setStadium(const string& stadium)
{
	// Verificações usando exceções
	if (stadium.empty())
	{
		throw invalid_argument("Stadium cannot be empty");
	}

	// Atribui o valor ao membro
	this->stadium = stadium;
	return *this;
}

// Definição do método para configurar o técnico do time
Team& Team::setCoach(const string& coach)
{
	// Verificações usando exceções
	if (coach.empty())
	{
		throw invalid_argument("Coach cannot be empty");
	}

	// Atribui o valor ao membro
	this->coach = coach;
	return *this;
}

// Definição do método para configurar a cidade do time
Team& Team::setCity(const string& city)
{
	// Verificações usando exceções
	if (city.empty())
	{
		throw invalid_argument("City cannot be empty");
	}

	// Atribui o valor ao membro
	this->city = city;
	return *this;
}

// Definição do destrutor
Team::~Team()
{
}

Team* setDataTeam()
{
	string name, stadium, coach, city;

	cout << "Digite o nome do time: ";
	getline(cin, name);

	cout << "Digite o estádio do time: ";
	getline(cin, stadium);

	cout << "Digite o técnico do time: ";
	getline(cin, coach);

	cout << "Digite a cidade do time: ";
	getline(cin, city);

	Team* team = new Team(name, stadium, coach, city);
	return team;
}

Team* addNewTeam()
{
	Team* newTeamPtr = setDataTeam();
	if (newTeamPtr == nullptr)
	{
		cerr << "Erro ao criar um novo time." << endl;
		return NULL;
	}
	return newTeamPtr;
}

Team* findTeamByName(list<Team>& teamsList, const string& searchName) 
{
	for (auto it = teamsList.begin(); it != teamsList.end(); ++it) 
	{
		if (it->getName() == searchName) 
		{
			return const_cast<Team*>(&(*it));
		}
	}
	return nullptr;
}

void Team::sortPlayers()
{
	this->players.sort([](Player& player1, Player& player2) 
	{
		return player1.getNumber() < player2.getNumber();
	});
}

void Team::findPlayerByNumber(const int number)
{
	for (auto it = players.begin(); it != players.end(); ++it)
	{
		if (it->getNumber() == number)
		{
			lineup.push_back(*it);
		}
	}
	
}

static int choiceFormation()
{
	int choice;
	cout << "Escolha a formacao: " << endl;
	cout << "1 - 4-4-2" << endl;
	cout << "2 - 4-3-3" << endl;
	cout << "3 - 4-5-1" << endl;
	cout << "4 - 3-5-2" << endl;
	cout << "5 - 3-4-3" << endl;
	do
	{
		cin >> choice;
	} while (choice < 1 || choice > 5);
	system("cls");
	return choice;
}

void Team::setGoalkeeper()
{
	int playerNumber;
	cout << "Escolha o goleiro: " << endl;
	for (auto it = players.begin(); it != players.end(); ++it)
	{
		if (it->getPosition() == "Goleiro" || "goleiro")
		{
			cout << it->getNumber() << " - " << it->getName() << endl;
		}
	}
	cin >> playerNumber;
	findPlayerByNumber(playerNumber);
}

void Team::setDefenders()
{
	int maxDefenders;
	if(formation == 1 || formation == 2 || formation == 3)
	{
		maxDefenders = 4;
	}
	else
	{
		maxDefenders = 3;
	}
	int playerNumber;
	cout << "Escolha os defensores: " << endl;
	for (auto it = players.begin(); it != players.end(); ++it)
	{
		if (it->getPosition() == "zagueiro" || "lateral")
		{
			cout << it->getNumber() << " - " << it->getName() << endl;
		}
	}
	int i = 0;
	while (i < maxDefenders)
	{
		cin >> playerNumber;
		findPlayerByNumber(playerNumber);
		i++;
	}
}

void Team::setMidfielders()
{
	int maxMidfielders;
	if (formation == 1 || formation == 5)
	{
		maxMidfielders = 4;
	}
	else if (formation == 3 || formation == 4)
	{
		maxMidfielders = 5;
	}
	else
	{
		maxMidfielders = 3;
	}
	int playerNumber;
	cout << "Escolha os meio-campistas: " << endl;
	for (auto it = players.begin(); it != players.end(); ++it)
	{
		if (it->getPosition() == "meio-campista")
		{
			cout << it->getNumber() << " - " << it->getName() << endl;
		}
	}
	int i = 0;
	while (i < maxMidfielders)
	{
		cin >> playerNumber;
		findPlayerByNumber(playerNumber);
		i++;
	}
}

void Team::setStrikers()
{
	int maxStrikers;
	if (formation == 1 || formation == 4)
	{
		maxStrikers = 2;
	}
	else if (formation == 2 || formation == 5)
	{
		maxStrikers = 3;
	}
	else
	{
		maxStrikers = 1;
	}
	int playerNumber;
	cout << "Escolha os atacantes: " << endl;
	for (auto it = players.begin(); it != players.end(); ++it)
	{
		if (it->getPosition() == "atacante")
		{
			cout << it->getNumber() << " - " << it->getName() << endl;
		}
	}
	int i = 0;
	while (i < maxStrikers)
	{
		cin >> playerNumber;
		findPlayerByNumber(playerNumber);
		i++;
	}
}

void Team::setLineup()
{
	formation = choiceFormation();
	setGoalkeeper();
	setDefenders();
}