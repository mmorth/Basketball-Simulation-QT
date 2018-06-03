#include "dbhandler.h"

dbHandler::dbHandler()
{

}

void dbHandler::addTeamTable()
{
    createConnection();

    // Create the teams table
    QString createTeamTableQuery = "CREATE TABLE teams ("
            "ID integer UNIQUE,"
            "team_name VARCHAR(30) UNIQUE,"
            "offensive_rating integer,"
            "defensive_rating integer);";

    QSqlQuery query;

    if (!query.exec(createTeamTableQuery))
    {
        qDebug()<<"Cannot create team table";
    }

    db.close();
}

void dbHandler::removeTeamTable()
{
    createConnection();

    QString removeTeamTableQuery = "DROP TABLE teams;";
    QSqlQuery query;
    query.exec(removeTeamTableQuery);

    db.close();
}

void dbHandler::createConnection()
{
    createConnection();

    // Create and connect the SQLite database
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/mmorth/Code/Databases/basketball_simulation_database.sqlite");

    // Determine if the database was opened correctly
    if (!db.open())
    {
        qDebug()<<"DBCreateFail";
    }

    db.close();
}

void dbHandler::addTeam(int id, QString teamName, int offensiveRating, int defensiveRating)
{
    createConnection();

    QSqlQuery query;

    query.prepare("INSERT INTO teams ("
                  "ID,"
                  "team_name,"
                  "offensive_rating,"
                  "defensive_rating)"
                  "VALUES (?,?,?,?);");

    query.addBindValue(id);
    query.addBindValue(teamName);
    query.addBindValue(offensiveRating);
    query.addBindValue(defensiveRating);

    if (!query.exec())
    {
        qDebug()<<"Error adding to teams";
    }

    db.close();
}
