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
	void setName(const string& name);
	void setStadium(const string& stadium);
	void setCoach(const string& coach);
	void setCity(const string& city);
	string getName();
	string getStadium();
	string getCoach();
	string getCity();
	list<Player> getPlayers();
	void setTeam(const string& name, const string& stadium, const string& coach, const string& city);
	void addPlayer(const Player& player);
	void removePlayer(const string& name);
	void showTeam();
	~Team();
};

Team* setTeam();