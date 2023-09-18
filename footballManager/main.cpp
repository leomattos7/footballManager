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
				do {
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
	/*// Configure os jogadores do time
	Player* currentPlayer;
	currentPlayer = setDataPlayer();
	//.addPlayer(Player(currentPlayer->getName(), currentPlayer->getPosition(), currentPlayer->getAge(), currentPlayer->getNumber()));*/

	// Mostre o time
	for (auto& team : teams)
	{
		team.showTeam();
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
