#include "gamesimulation.h"
#include <QApplication>
#include "dbhandler.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameSimulation w;
    w.show();

    return a.exec();
}
