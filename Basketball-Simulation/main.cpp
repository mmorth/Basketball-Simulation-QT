#include "gamesimulation.h"
#include <QApplication>
#include <QDebug>
#include <QSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameSimulation w;
    w.show();

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/mmorth/Code/Databases/basketball_simulation_database.sqlite");

    if (!db.open())
    {
        qDebug()<<"DBCreateFail";
    }

    return a.exec();
}
