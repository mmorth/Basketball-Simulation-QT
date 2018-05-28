#include <string>

using namespace std;

#ifndef TEAM_H
#define TEAM_H


class Team
{
private:
    /**
     * @brief teamName
     *      Stores the team name
     */
    string teamName;

    /**
     * @brief offensiveRating
     *      Stores the offensive rating of the team
     */
    int offensiveRating;

    /**
     * @brief defensiveRating
     *      Stores the defensive rating of the team
     */
    int defensiveRating;

    /**
     * @brief gameScore
     *      Stores the number of points the team currently has in a game
     */
    int gameScore;


public:
    /**
     * @brief Team
     *      Constructs a blank team (useless)
     */
    Team();

    /**
     * @brief Team
     *      Stores a team with a team name, offensive and defensive rating, and the current score of the team in a game
     * @param teamName
     *      The name of the team
     * @param offensiveRating
     *      The offensive rating of the team
     * @param defensiveRating
     *      The defensive rating of the team
     */
    Team(string teamName, int offensiveRating, int defensiveRating);

    /**
     * @brief getTeamName
     *      Returns the team name
     * @return
     *      The team name
     */
    string getTeamName() const;

    /**
     * @brief setTeamName
     *      Sets the team name
     * @param value
     *      The team name to set
     */
    void setTeamName(const string &value);

    /**
     * @brief getOffensiveRating
     *      Returns the offensive rating of the team
     * @return
     *      The offensive rating of the team
     */
    int getOffensiveRating() const;

    /**
     * @brief setOffensiveRating
     *      Sets the offensive rating of the team
     * @param value
     *      The offensive rating of the team to set
     */
    void setOffensiveRating(int value);

    /**
     * @brief getDefensiveRating
     *      Returns the defensive rating of the team
     * @return
     *      The defensive rating of the team
     */
    int getDefensiveRating() const;

    /**
     * @brief setDefensiveRating
     *      Sets the defensive rating of the team
     * @param value
     *      The defensive rating of the team to set
     */
    void setDefensiveRating(int value);

    /**
     * @brief getGameScore
     *      Returns the current score of the team in a game
     * @return
     *      The current score of the team in a game
     */
    int getGameScore() const;

    /**
     * @brief setGameScore
     *      Sets the current score of a team in a game
     * @param value
     *      The current score of the team in the game
     */
    void setGameScore(int value);
};

#endif // TEAM_H
