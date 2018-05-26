#include "gamesimulation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameSimulation w;
    w.show();

    return a.exec();
}
