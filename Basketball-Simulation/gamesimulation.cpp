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
    this->possessionsRemaining = 99;

    awayTeamPreviousQuarterScore = 0;
    homeTeamPreviousQuarterScore = 0;

    awayTeam.setGameScore(0);
    homeTeam.setGameScore(0);

    // Load the team information into the table
    ui->gameScoreBoard->setItem(1, 0, new QTableWidgetItem(QString::fromStdString(Gators.getTeamName())));
    ui->gameScoreBoard->setItem(2, 0, new QTableWidgetItem(QString::fromStdString(Dragons.getTeamName())));

    // Displays the number of possessions remaining
    ui->possessionIndicator->setText(QString::fromStdString("Possessions Remaining: " + std::to_string(possessionsRemaining + 1)));
}

GameSimulation::~GameSimulation()
{
    delete ui;
}

void GameSimulation::on_pushButton_simulatePossession_clicked()
{
    simulatePossessions(1);
}

void GameSimulation::on_pushButton_simulateQuarter_clicked()
{
    simulatePossessions((possessionsRemaining%25) + 1);
}

//       } else
//        { // Overtime
//            // Update the quarter scoreboard scores
//            ui->gameScoreBoard->setItem(1, 5, new QTableWidgetItem(QString::fromStdString(std::to_string(awayTeam.getGameScore() - awayTeamScore))));
//            ui->gameScoreBoard->setItem(2, 5, new QTableWidgetItem(QString::fromStdString(std::to_string(homeTeam.getGameScore() - homeTeamScore))));
//        }

//        // Update the final score
//        ui->gameScoreBoard->setItem(1, 6, new QTableWidgetItem(QString::fromStdString(std::to_string(awayTeam.getGameScore()))));
//        ui->gameScoreBoard->setItem(2, 6, new QTableWidgetItem(QString::fromStdString(std::to_string(homeTeam.getGameScore()))));

void GameSimulation::on_pushButton_simulateGame_clicked()
{
    simulatePossessions(possessionsRemaining);
}

void GameSimulation::on_pushButton_resetSimulation_clicked()
{
    // Update the possession and score information
    possessionsRemaining = 99;

    awayTeamPreviousQuarterScore = 0;
    homeTeamPreviousQuarterScore = 0;

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

    // Displays the number of possessions remaining
    ui->possessionIndicator->setText(QString::fromStdString("Possessions Remaining: " + std::to_string(possessionsRemaining + 1)));
}

// ------------------------------- Helper Functions -------------------------------------
void GameSimulation::simulatePossessions(int possessions)
{
    // Get a different random number at different times
    srand ( time(NULL) );

    // Simulate the first quarter if it is not over yet
    while (possessionsRemaining > 74 && possessions > 0)
    {
        possessions = simulatePossession(1, possessions);
    }

    // Simulate the second quarter if it is not over yet
    while (possessionsRemaining > 49 && possessions > 0)
    {
        possessions = simulatePossession(2, possessions);
    }

    // Simulate the third quarter if it is not over yet
    while (possessionsRemaining > 24 && possessions > 0)
    {
        possessions = simulatePossession(3, possessions);
    }

    // Simulate the fourth quarter if it is not over yet
    while (possessionsRemaining > -1 && possessions > 0)
    {
        possessions = simulatePossession(4, possessions);
    }

    // Update the final score
    ui->gameScoreBoard->setItem(1, 6, new QTableWidgetItem(QString::fromStdString(std::to_string(awayTeam.getGameScore()))));
    ui->gameScoreBoard->setItem(2, 6, new QTableWidgetItem(QString::fromStdString(std::to_string(homeTeam.getGameScore()))));
}

// else
//        { // Overtime
//            // Update the quarter scoreboard scores
//            ui->gameScoreBoard->setItem(1, 5, new QTableWidgetItem(awayTeamScoreDifference));
//            ui->gameScoreBoard->setItem(2, 5, new QTableWidgetItem(homeTeamScoreDifference));
//        }

int GameSimulation::simulatePossession(int quarter, int possessions)
{
    // Set the possessionsRemaining condition and table columns based on what quarter is being simulated
    int possessionsRemainingCondition;

    if (quarter == 1)
    {
        possessionsRemainingCondition = 74;
    }
    else if (quarter == 2)
    {
        possessionsRemainingCondition = 49;
    }
    else if (quarter == 3)
    {
        possessionsRemainingCondition = 24;
    }
    else if (quarter = 4)
    {
        possessionsRemainingCondition = -1;
    }

    // Determine the points scored for each team
    awayTeam.setGameScore(awayTeam.getGameScore() + rand() % 2);
    homeTeam.setGameScore(homeTeam.getGameScore() + rand() % 2);

    // Decrease the number of possessions to simulate and possessions remaining in the game
    possessionsRemaining--;
    possessions--;

    // Print the scoreboard in the first quarter section of the table for both teams
    QString awayTeamScoreDifference = QString::fromStdString(std::to_string(awayTeam.getGameScore() - awayTeamPreviousQuarterScore));
    QString homeTeamScoreDifference = QString::fromStdString(std::to_string(homeTeam.getGameScore() - homeTeamPreviousQuarterScore));

    ui->gameScoreBoard->setItem(1, quarter, new QTableWidgetItem(awayTeamScoreDifference));
    ui->gameScoreBoard->setItem(2, quarter, new QTableWidgetItem(homeTeamScoreDifference));

    // Store the previous quarter scores if the quarter just ended
    // Used to calculate the scores for following quarters
    if (possessionsRemaining == possessionsRemainingCondition)
    {
        awayTeamPreviousQuarterScore = awayTeam.getGameScore();
        homeTeamPreviousQuarterScore = homeTeam.getGameScore();
    }

    // Displays the number of possessions remaining
    ui->possessionIndicator->setText(QString::fromStdString("Possessions Remaining: " + std::to_string(possessionsRemaining + 1)));

    return possessions;
}
