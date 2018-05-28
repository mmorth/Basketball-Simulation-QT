#ifndef GAMESIMULATION_H
#define GAMESIMULATION_H

#include <QMainWindow>
#include "team.h"

namespace Ui {
class GameSimulation;
}

class GameSimulation : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameSimulation(QWidget *parent = 0);
    ~GameSimulation();

private slots:
    void on_pushButton_simulatePossession_clicked();

    void on_pushButton_simulateQuarter_clicked();

    void on_pushButton_simulateGame_clicked();

    void on_pushButton_resetSimulation_clicked();

private:
    Ui::GameSimulation *ui;

    Team awayTeam;
    Team homeTeam;

    int awayTeamScore;
    int homeTeamScore;
    int possessionsRemaining;
};

#endif // GAMESIMULATION_H
