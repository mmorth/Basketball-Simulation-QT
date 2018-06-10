#ifndef DBHANDLER_H
#define DBHANDLER_H

#include <QDebug>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QStringList>
#include "team.h"

class dbHandler
{
public:
    /**
     * @brief dbHandler
     *      Constructs a new default dbHandler object
     */
    dbHandler();

    // The destructor for the dbHandler class
    ~dbHandler();

    /**
     * @brief editTeam
     *      Edits a team in the sqlite database
     * @param id
     *      The id of the team
     * @param teamName
     *      The name of the team
     * @param offensiveRating
     *      The offensive rating of the team
     * @param defensiveRating
     *      The defensive rating of the team
     */
    void editTeam(QString teamName, int offensiveRating, int defensiveRating);

    /**
     * @brief dbHandler::addValue
     *      Adds a new team information to the sqlite database
     * @param id
     *      The id of the new team
     * @param teamName
     *      The teamName of the new team
     * @param offensiveRating
     *      The offensiveRating of the new team
     * @param defensiveRating
     *      The defensiveRating of the new team
     */
    void addTeam(QString teamName, int offensiveRating, int defensiveRating);

    /**
     * @brief removeTeam
     *      Removes a team from the sqlite database
     * @param teamName
     *      The teamName of the Team to remove
     */
    void removeTeam(QString teamName);

    /**
     * @brief listTeams
     *      Returns a list of the teams in the database
     * @return
     *      A QSqlQueryModel representing the list of teams in the database
     */
    QStringList listTeams();

    /**
     * @brief findTeam
     *      Returns a Team based on the input teamName
     * @param teamName
     *      The teamName of the team to return
     * @return
     *      A Team representing the teamName input
     */
    Team findTeam(QString teamName);

private:
    /**
     * @brief db
     *      Represents the sqlite database
     */
    QSqlDatabase db;

};

#endif // DBHANDLER_H
