#include "gamesimulation.h"
#include "ui_gamesimulation.h"
#include <iostream>

GameSimulation::GameSimulation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameSimulation)
{
    ui->setupUi(this);

    // Setup the scoreboard table
//    ui->gameScoreBoard->setRowCount(3);
//    ui->gameScoreBoard->setColumnCount(7);

//    printf("Got here");

    // Setup the column headers
//    ui->gameScoreBoard->horizontalHeaderItem(0)->setText("Teams");
//    ui->gameScoreBoard->setItem(0, 0, new QTableWidgetItem("Teams"));
//    ui->gameScoreBoard->setItem(0, 1, "Q1");
//    ui->gameScoreBoard->setItem(0, 2, "Q2");
//    ui->gameScoreBoard->setItem(0, 3, "Q3");
//    ui->gameScoreBoard->setItem(0, 4, "Q4");
//    ui->gameScoreBoard->setItem(0, 5, "OT");
//    ui->gameScoreBoard->setItem(0, 6, "Final");
}

GameSimulation::~GameSimulation()
{
    delete ui;
}

void GameSimulation::on_pushButton_simulatePossession_clicked()
{

}

void GameSimulation::on_pushButton_simulateQuarter_clicked()
{

}

void GameSimulation::on_pushButton_simulateGame_clicked()
{

}

void GameSimulation::on_pushButton_resetSimulation_clicked()
{

}
