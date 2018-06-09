#include "dbhandler.h"

dbHandler::dbHandler()
{
    // Create and connect the SQLite database
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/mmorth/GIT/Basketball-Simulation-QT/build-Basketball-Simulation-Desktop_Qt_5_11_0_GCC_64bit-Debug/basketball_simulation_database.sqlite");

    if (!db.open())
    {
        qDebug()<<"DB NOT OPEN!!!!!";
    }
}

dbHandler::~dbHandler()
{
    db.close();
    db.removeDatabase("/home/mmorth/GIT/Basketball-Simulation-QT/build-Basketball-Simulation-Desktop_Qt_5_11_0_GCC_64bit-Debug/basketball_simulation_database.sqlite");
}

void dbHandler::addTeamTable()
{
    // Create and connect the SQLite database
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/mmorth/GIT/Basketball-Simulation-QT/build-Basketball-Simulation-Desktop_Qt_5_11_0_GCC_64bit-Debug/basketball_simulation_database.sqlite");
    db.open();

    // Create the teams table
    QString createTeamTableQuery = "CREATE TABLE Teams ("
            "ID int PRIMARY KEY,"
            "team_name VARCHAR(30) UNIQUE,"
            "offensive_rating integer,"
            "defensive_rating integer);";

    QSqlQuery query;

    if (!query.exec(createTeamTableQuery))
    {
        qDebug()<<query.lastError();
    }
}

void dbHandler::removeTeamTable()
{
    // Create and connect the SQLite database
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/mmorth/Code/Databases/basketball_simulation_database.sqlite");
    db.open();

    QString removeTeamTableQuery = "DROP TABLE teams;";
    QSqlQuery query;
    query.exec(removeTeamTableQuery);

    db.close();
}

void dbHandler::addTeam(QString teamName, int offensiveRating, int defensiveRating)
{

    qDebug()<<db.tables();

    QSqlQuery query;

    if (!query.exec("INSERT INTO Teams (team_name, offensive_rating, defensive_rating) VALUES ('" + teamName + "', '" + QString::number(offensiveRating) + "', '" + QString::number(defensiveRating) + "');"))
    {
        qDebug()<<query.lastError();
    }

}

void dbHandler::editTeam(QString teamName, int offensiveRating, int defensiveRating)
{
    // Create and connect the SQLite database
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/mmorth/Code/Databases/basketball_simulation_database.sqlite");
    db.open();

    QSqlQuery query;

    QString updateTeamQuery = "UPDATE teams SET offensive_rating = " + QString::number(offensiveRating) + " defensive_rating = " + QString::number(defensiveRating) +
            "WHERE team_name = " + teamName + "; ";

    query.exec(updateTeamQuery);

    if (!query.exec())
    {
        qDebug()<<"Error updating teams";
    }

    db.close();
}

QStringList dbHandler::listTeams()
{
    QSqlQuery query;

    query.exec("SELECT team_name FROM Teams;");

    QStringList teams;

    while (query.next()) {
            teams.append(query.value(0).toString());
    }

    return teams;
}
