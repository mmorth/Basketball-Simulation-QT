#include "team.h"

Team::Team()
{
    this->teamName = "";
    this->offensiveRating = 0;
    this->defensiveRating = 0;
    this->gameScore = 0;
}

Team::Team(string teamName, int offensiveRating, int defensiveRating)
{
    this->teamName = teamName;
    this->offensiveRating = offensiveRating;
    this->defensiveRating = defensiveRating;
    this->gameScore = 0;
}

int Team::getOffensiveRating() const
{
    return offensiveRating;
}

void Team::setOffensiveRating(int value)
{
    offensiveRating = value;
}

int Team::getDefensiveRating() const
{
    return defensiveRating;
}

void Team::setDefensiveRating(int value)
{
    defensiveRating = value;
}

string Team::getTeamName() const
{
    return teamName;
}

void Team::setTeamName(const string &value)
{
    teamName = value;
}

int Team::getGameScore() const
{
    return gameScore;
}

void Team::setGameScore(int value)
{
    gameScore = value;
}
