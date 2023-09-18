#include "Player.h"

class Team
{
private:
	string name;
	string stadium;
	string coach;
	string city;
	list<Player> players;

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
	void showTeam();
	~Team();
};

Team* setDataTeam();