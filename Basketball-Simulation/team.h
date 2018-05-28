#include <string>

using namespace std;

#ifndef TEAM_H
#define TEAM_H


class Team
{
private:
    string teamName;
    int offensiveRating;
    int defensiveRating;
    int gameScore;


public:
    Team(string teamName, int offensiveRating, int defensiveRating, int gameScore);

    string getTeamName() const;
    void setTeamName(const string &value);
    int getOffensiveRating() const;
    void setOffensiveRating(int value);
    int getDefensiveRating() const;
    void setDefensiveRating(int value);
    int getGameScore() const;
    void setGameScore(int value);
};

#endif // TEAM_H
