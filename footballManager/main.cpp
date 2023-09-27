#include <fstream>
#include "Team.h"


int main()
{
	list<Team> teams;
	while (1)
	{
		cout << "1 - Criar um novo time" << endl;
		cout << "2 - Sair" << endl;
		int option;
		cin >> option;
		cin.ignore();
		if (option == 1)
		{
			teams.push_back(*addNewTeam());
		}
		else if (option == 2)
		{
			break;
		}
		else
		{
			cerr << "Opção inválida." << endl;
		}
	}

	while (1)
	{
		cout << "1 - Adicionar um jogador a um time" << endl;
		cout << "2 - Sair" << endl;
		int option;
		cin >> option;
		cin.ignore();
		if (option == 1)
		{
			cout << "Digite o nome do time: ";
			string searchName;
			getline(cin, searchName);
			Team* team = findTeamByName(teams, searchName);
			if (team == nullptr)
			{
				cerr << "Time não encontrado." << endl;
				break;
			}
			else
			{
				do 
				{
					team->addPlayer(*setDataPlayer());
					cout << "Deseja adicionar outro jogador? (s/n) ";
					char option;
					cin >> option;
					cin.ignore();
					if (option == 'n')
					{
						break;
					}
				} while (1);
			}
		}
		else if (option == 2)
		{
			break;
		}
	}

	// Mostre o time
	for (auto& team : teams)
	{
		team.sortPlayers();
		team.showTeam();
	}

	return 0;
}

