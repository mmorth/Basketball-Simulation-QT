#include "gamesimulation.h"
#include "ui_gamesimulation.h"

GameSimulation::GameSimulation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameSimulation)
{
    ui->setupUi(this);
}

GameSimulation::~GameSimulation()
{
    delete ui;
}
