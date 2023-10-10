#include "Player.h"

class Team
{
private:
	string name;
	string stadium;
	string coach;
	string city;
	int formation;
	list<Player> players;
	list<Player> lineup;

	int points;
	int mGoals;
	int cGoals;

public:
	Team();
	Team(const string& name, const string& stadium, const string& coach, const string& city);
	Team& setTeam(const string& name, const string& stadium, const string& coach, const string& city);
	Team& setName(const string& name);
	Team& setStadium(const string& stadium);
	Team& setCoach(const string& coach);
	Team& setCity(const string& city);
	string getName() { return name; }
	string getStadium() { return stadium; }
	string getCoach() { return coach; }
	string getCity() { return city; }
	list<Player> getPlayers() { return players; }
	void addPlayer(const Player& player);
	void removePlayer(const string& name);
	void sortPlayers();
	void showTeam();
	void findPlayerByNumber(const int number);
	void setGoalkeeper();
	void setDefenders();
	void setMidfielders();
	void setStrikers();
	void setLineup();
	void showLineup();
	void sortLineup();
	~Team();
};

Team* setDataTeam();

Team* addNewTeam();

Team* findTeamByName(list<Team>& teamsList, const string& searchName);
