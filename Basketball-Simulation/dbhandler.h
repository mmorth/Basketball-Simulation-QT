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
    void dbHandler::createConnection();

    /**
     * @brief dbHandler::addTeamTable
     *      Adds the team table
     */
    void dbHandler::addTeamTable();

    /**
     * @brief dbHandler::removeTeamTable
     *      Removes the team table
     */
    void dbHandler::removeTeamTable();

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
    void dbHandler::addValue(int id, QString teamName, int offensiveRating, int defensiveRating);
};

#endif // DBHANDLER_H
