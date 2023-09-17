#include "Team.h"

int main()
{
    vector<Team> teams;
    teams.push_back(Team("Flamengo", "Maracanã", "Jorge Jesus", "Rio de Janeiro"));
    Team& flamengo = teams[0];
    flamengo.addPlayer(Player("Diego Alves", "Goleiro", 34, 1));
    flamengo.addPlayer(Player("Rafinha", "Lateral", 34, 13));
    flamengo.addPlayer(Player("Rodrigo Caio", "Zagueiro", 26, 3));
    flamengo.addPlayer(Player("Pablo Marí", "Zagueiro", 26, 24));
    flamengo.addPlayer(Player("Filipe Luís", "Lateral", 34, 16));
    flamengo.addPlayer(Player("Willian Arão", "Volante", 27, 5));
    flamengo.addPlayer(Player("Gerson", "Volante", 22, 8));
    flamengo.addPlayer(Player("Arrascaeta", "Meia", 25, 14));
    flamengo.addPlayer(Player("Everton Ribeiro", "Meia", 30, 7));
    flamengo.addPlayer(Player("Bruno Henrique", "Atacante", 28, 27));
    flamengo.addPlayer(Player("Gabriel Barbosa", "Atacante", 23, 9));

    flamengo.showTeam();

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
