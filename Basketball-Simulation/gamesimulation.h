#ifndef GAMESIMULATION_H
#define GAMESIMULATION_H

#include <QMainWindow>

namespace Ui {
class GameSimulation;
}

class GameSimulation : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameSimulation(QWidget *parent = 0);
    ~GameSimulation();

private:
    Ui::GameSimulation *ui;
};

#endif // GAMESIMULATION_H
