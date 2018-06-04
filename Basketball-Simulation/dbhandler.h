#ifndef DBHANDLER_H
#define DBHANDLER_H

#include <QDebug>
#include <QSql>


class dbHandler
{
public:
    /**
     * @brief dbHandler
     *      Constructs a new default dbHandler object
     */
    dbHandler();

    /**
     * @brief dbHandler::createConnection
     *      Creates a connection to the database
     */
    void createConnection();

    /**
     * @brief dbHandler::addTeamTable
     *      Adds the team table
     */
    void addTeamTable();

    /**
     * @brief dbHandler::editTeam
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
     * @brief dbHandler::removeTeamTable
     *      Removes the team table
     */
    void removeTeamTable();

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
};

#endif // DBHANDLER_H
