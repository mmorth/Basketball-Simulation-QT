#include "gamesimulation.h"
#include "ui_gamesimulation.h"
#include <iostream>
#include <ctime>

GameSimulation::GameSimulation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameSimulation)
{
    ui->setupUi(this);

    // Setup the scoreboard table
    ui->gameScoreBoard->setRowCount(3);
    ui->gameScoreBoard->setColumnCount(7);
    ui->gameScoreBoard->horizontalHeader()->hide();
    ui->gameScoreBoard->verticalHeader()->hide();

    // Setup the column headers
    ui->gameScoreBoard->setItem(0, 0, new QTableWidgetItem("Teams"));
    ui->gameScoreBoard->setItem(0, 1, new QTableWidgetItem("Q1"));
    ui->gameScoreBoard->setItem(0, 2, new QTableWidgetItem("Q2"));
    ui->gameScoreBoard->setItem(0, 3, new QTableWidgetItem("Q3"));
    ui->gameScoreBoard->setItem(0, 4, new QTableWidgetItem("Q4"));
    ui->gameScoreBoard->setItem(0, 5, new QTableWidgetItem("OT"));
    ui->gameScoreBoard->setItem(0, 6, new QTableWidgetItem("Final"));

    // Create the teams
    Team Dragons("Dragons", 95, 95);
    Team Gators("Gators", 100, 90);

    this->awayTeam = Gators;
    this->homeTeam = Dragons;
    this->possessionsRemaining = 100;

    // Load the team information into the table
    ui->gameScoreBoard->setItem(1, 0, new QTableWidgetItem(QString::fromStdString(Gators.getTeamName())));
    ui->gameScoreBoard->setItem(2, 0, new QTableWidgetItem(QString::fromStdString(Dragons.getTeamName())));
}

GameSimulation::~GameSimulation()
{
    delete ui;
}

void GameSimulation::on_pushButton_simulatePossession_clicked()
{
    // Get a different random number at different times
    srand ( time(NULL) );

    homeTeamScore = homeTeam.getGameScore();
    awayTeamScore = awayTeam.getGameScore();

    homeTeam.setGameScore(homeTeam.getGameScore() + rand() % 2);
    awayTeam.setGameScore(awayTeam.getGameScore() + rand() % 2);


}

void GameSimulation::on_pushButton_simulateQuarter_clicked()
{
    // Get a different random number at different times
    srand ( time(NULL) );

    // Determine if there are still possessions left in the game
    if (this->possessionsRemaining > 0)
    {
        homeTeamScore = homeTeam.getGameScore();
        awayTeamScore = awayTeam.getGameScore();

        homeTeam.setGameScore(homeTeam.getGameScore() + rand() % 50);
        awayTeam.setGameScore(awayTeam.getGameScore() + rand() % 50);

        // Determine which quarter to load the updated team scores in
        if (possessionsRemaining <= 100 && possessionsRemaining > 75)
        { // first quarter
            // Update the quarter scoreboard scores
            ui->gameScoreBoard->setItem(1, 1, new QTableWidgetItem(QString::fromStdString(std::to_string(awayTeam.getGameScore() - awayTeamScore))));
            ui->gameScoreBoard->setItem(2, 1, new QTableWidgetItem(QString::fromStdString(std::to_string(homeTeam.getGameScore() - homeTeamScore))));
        } else if (possessionsRemaining <= 75 && possessionsRemaining > 50)
        { // second quarter
            // Update the quarter scoreboard scores
            ui->gameScoreBoard->setItem(1, 2, new QTableWidgetItem(QString::fromStdString(std::to_string(awayTeam.getGameScore() - awayTeamScore))));
            ui->gameScoreBoard->setItem(2, 2, new QTableWidgetItem(QString::fromStdString(std::to_string(homeTeam.getGameScore() - homeTeamScore))));
        } else if (possessionsRemaining <= 50 && possessionsRemaining > 25)
        { // third quarter
            // Update the quarter scoreboard scores
            ui->gameScoreBoard->setItem(1, 3, new QTableWidgetItem(QString::fromStdString(std::to_string(awayTeam.getGameScore() - awayTeamScore))));
            ui->gameScoreBoard->setItem(2, 3, new QTableWidgetItem(QString::fromStdString(std::to_string(homeTeam.getGameScore() - homeTeamScore))));
        } else if (possessionsRemaining <= 25 && possessionsRemaining > 0)
        { // fourth quarter
            // Update the quarter scoreboard scores
            ui->gameScoreBoard->setItem(1, 4, new QTableWidgetItem(QString::fromStdString(std::to_string(awayTeam.getGameScore() - awayTeamScore))));
            ui->gameScoreBoard->setItem(2, 4, new QTableWidgetItem(QString::fromStdString(std::to_string(homeTeam.getGameScore() - homeTeamScore))));
        } else
        { // Overtime
            // Update the quarter scoreboard scores
            ui->gameScoreBoard->setItem(1, 5, new QTableWidgetItem(QString::fromStdString(std::to_string(awayTeam.getGameScore() - awayTeamScore))));
            ui->gameScoreBoard->setItem(2, 5, new QTableWidgetItem(QString::fromStdString(std::to_string(homeTeam.getGameScore() - homeTeamScore))));
        }

        // Update the final score
        ui->gameScoreBoard->setItem(1, 6, new QTableWidgetItem(QString::fromStdString(std::to_string(awayTeam.getGameScore()))));
        ui->gameScoreBoard->setItem(2, 6, new QTableWidgetItem(QString::fromStdString(std::to_string(homeTeam.getGameScore()))));

        // Update possessions and scores
        this->possessionsRemaining -= 25;
    }
}

void GameSimulation::on_pushButton_simulateGame_clicked()
{

}

void GameSimulation::on_pushButton_resetSimulation_clicked()
{
    // Update the possession and score information
    possessionsRemaining = 100;

    awayTeamScore = 0;
    homeTeamScore = 0;

    awayTeam.setGameScore(0);
    homeTeam.setGameScore(0);

    // Clear the score board
    ui->gameScoreBoard->setItem(1, 1, new QTableWidgetItem());
    ui->gameScoreBoard->setItem(2, 1, new QTableWidgetItem());
    ui->gameScoreBoard->setItem(1, 2, new QTableWidgetItem());
    ui->gameScoreBoard->setItem(2, 2, new QTableWidgetItem());
    ui->gameScoreBoard->setItem(1, 3, new QTableWidgetItem());
    ui->gameScoreBoard->setItem(2, 3, new QTableWidgetItem());
    ui->gameScoreBoard->setItem(1, 4, new QTableWidgetItem());
    ui->gameScoreBoard->setItem(2, 4, new QTableWidgetItem());
    ui->gameScoreBoard->setItem(1, 5, new QTableWidgetItem());
    ui->gameScoreBoard->setItem(2, 5, new QTableWidgetItem());
    ui->gameScoreBoard->setItem(1, 6, new QTableWidgetItem());
    ui->gameScoreBoard->setItem(2, 6, new QTableWidgetItem());
}
