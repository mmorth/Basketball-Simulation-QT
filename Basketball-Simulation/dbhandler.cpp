#include "dbhandler.h"

dbHandler::dbHandler()
{

}

void dbHandler::addTeamTable()
{
    createConnection();

    // Create the teams table
    QString createTeamTableQuery = "CREATE TABLE teams ("
            "ID int NOT NULL AUTO_INCREMENT,"
            "team_name VARCHAR(30) UNIQUE,"
            "offensive_rating integer,"
            "defensive_rating integer);";

    QSqlQuery query;

    if (!query.exec(createTeamTableQuery))
    {
        qDebug()<<"Cannot create team table";
    }

    closeConnection();
}

void dbHandler::removeTeamTable()
{
    createConnection();

    QString removeTeamTableQuery = "DROP TABLE teams;";
    QSqlQuery query;
    query.exec(removeTeamTableQuery);

    closeConnection();
}

void dbHandler::createConnection()
{
    // Create and connect the SQLite database
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/mmorth/Code/Databases/basketball_simulation_database.sqlite");

    // Determine if the database was opened correctly
    if (!db.open())
    {
        qDebug()<<"DBCreateFail";
    }
}

void dbHandler::closeConnection()
{
    QSqlDatabase db;

    db.close();
}

void dbHandler::addTeam(QString teamName, int offensiveRating, int defensiveRating)
{
    createConnection();

    QSqlQuery query;

    QString insertTeamQuery = "INSERT INTO teams (team_name, offensive_rating, defensive_rating)"
                  "VALUES (" + teamName + ", " + offensiveRating + ", " + defensiveRating + "); ";

    query.exec(insertTeamQuery);

    if (!query.exec())
    {
        qDebug()<<"Error adding to teams";
    }

    closeConnection();
}

void dbHandler::editTeam(QString teamName, int offensiveRating, int defensiveRating)
{
    createConnection();

    QSqlQuery query;

    QString updateTeamQuery = "UPDATE teams SET offensive_rating = " + QString::number(offensiveRating) + " defensive_rating = " + QString::number(defensiveRating) +
            "WHERE team_name = " + teamName + "; ";

    query.exec(updateTeamQuery);

    if (!query.exec())
    {
        qDebug()<<"Error updating teams";
    }

    closeConnection();
}
