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

void dbHandler::addTeam(QString teamName, int offensiveRating, int defensiveRating)
{
    QSqlQuery query;

    if (!query.exec("INSERT INTO Teams (team_name, offensive_rating, defensive_rating) VALUES ('" + teamName + "', '" + QString::number(offensiveRating) + "', '" + QString::number(defensiveRating) + "');"))
    {
        qDebug()<<query.lastError();
    }

}

void dbHandler::editTeam(QString teamName, int offensiveRating, int defensiveRating)
{
    QSqlQuery query;

    if (!query.exec("UPDATE teams SET offensive_rating = '" + QString::number(offensiveRating) + "', defensive_rating = '" + QString::number(defensiveRating) +
                    "' WHERE team_name = '" + teamName + "'; "))
    {
        qDebug()<<query.lastError();
        qDebug()<<"Error updating team";
    }

    db.close();
}

void dbHandler::removeTeam(QString teamName)
{
    QSqlQuery query;

    if (!query.exec("DELETE FROM Teams WHERE team_name = '" + teamName + "';"))
    {
        qDebug()<<query.lastError();
    }
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

Team dbHandler::findTeam(QString teamName)
{
    QSqlQuery query;

    query.exec("SELECT * FROM Teams WHERE team_name = '" + teamName + "';");

    query.first();

    // Get the offensive and defensive rating
    int offensiveRating = query.value(2).toInt();
    int defensiveRating = query.value(3).toInt();

    Team lookupTeam(teamName.toStdString(), offensiveRating, defensiveRating);

    return lookupTeam;
}
