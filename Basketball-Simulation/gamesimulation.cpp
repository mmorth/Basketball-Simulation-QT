#include "gamesimulation.h"
#include "ui_gamesimulation.h"
#include <iostream>
#include <ctime>

GameSimulation::GameSimulation(QWidget *parent) :
    QMainWindow(parent), // Set the parent as the main window
    ui(new Ui::GameSimulation) // Link the GameSimulation class to its .ui file
{
    // Setup the ui
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
    Team Dragons("Dragons", 100, 100);
    Team Gators("Gators", 80, 80);

    // Setup the team information and default values
    this->awayTeam = Gators;
    this->homeTeam = Dragons;

    awayTeamPreviousQuarterScore = 0;
    homeTeamPreviousQuarterScore = 0;

    awayTeam.setGameScore(0);
    homeTeam.setGameScore(0);

    // Setup the initial possessions and set overtime to false
    this->possessionsRemaining = 99;

    overtime = false;

    // Load the team information into the table and prevent the user from editing the data in the table
    ui->gameScoreBoard->setItem(1, 0, new QTableWidgetItem(QString::fromStdString(Gators.getTeamName())));
    ui->gameScoreBoard->setItem(2, 0, new QTableWidgetItem(QString::fromStdString(Dragons.getTeamName())));
    ui->gameScoreBoard->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Displays the number of possessions remaining and prevent it from being edited by the user
    ui->possessionIndicator->setText(QString::fromStdString("Possessions Remaining: " + std::to_string(possessionsRemaining + 1)));
    ui->possessionIndicator->setReadOnly(true);

    // Create a new random number seed
    srand ( time(NULL) );
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

void GameSimulation::on_pushButton_simulateGame_clicked()
{
    simulatePossessions(possessionsRemaining+1);
}

void GameSimulation::on_pushButton_resetSimulation_clicked()
{
    // Update the possession and score information
    possessionsRemaining = 99;

    awayTeamPreviousQuarterScore = 0;
    homeTeamPreviousQuarterScore = 0;

    awayTeam.setGameScore(0);
    homeTeam.setGameScore(0);

    overtime = false;

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
    while (possessionsRemaining > -1 && possessions > 0 && !overtime)
    {
        possessions = simulatePossession(4, possessions);
    }

    // Check if game is tied after regulation
    if (!overtime && awayTeam.getGameScore() == homeTeam.getGameScore() && possessionsRemaining == -1)
    {
        possessionsRemaining = 9;
        overtime = true;
    }

    // Simulate overtime if the score is tied after regulation
    while (possessionsRemaining > -1 && possessions > 0 && overtime)
    {
        possessions = simulatePossession(5, possessions);
    }

    if (awayTeam.getGameScore() == homeTeam.getGameScore() && possessionsRemaining == -1 && overtime)
    {
        possessionsRemaining = 9;
        overtime = true;
    }

    // Displays the number of possessions remaining
    ui->possessionIndicator->setText(QString::fromStdString("Possessions Remaining: " + std::to_string(possessionsRemaining + 1)));

    // Update the final score
    ui->gameScoreBoard->setItem(1, 6, new QTableWidgetItem(QString::fromStdString(std::to_string(awayTeam.getGameScore()))));
    ui->gameScoreBoard->setItem(2, 6, new QTableWidgetItem(QString::fromStdString(std::to_string(homeTeam.getGameScore()))));
}

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
    else if (quarter == 4)
    {
        possessionsRemainingCondition = -1;
    }
    else if (overtime)
    {
        quarter = 5;
        possessionsRemainingCondition = -2; // The overtime scores should not reset after each overtime
    }

    // Determine the points scored for each team
    determineScoringOutcome();

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

    return possessions;
}

void GameSimulation::determineScoringOutcome()
{
    int awayTeamScoreIncrease = 0;
    int homeTeamScoreIncrease = 0;

    // Determine the score increase for the away team
    int awayTeamRandNum = rand() % 1000;

    double awayToHomeTeamRatio = awayTeam.getOffensiveRating() / (double) homeTeam.getDefensiveRating();
    double homeToAwayTeamRatio = homeTeam.getOffensiveRating() / (double) homeTeam.getDefensiveRating();

    if (awayToHomeTeamRatio > homeToAwayTeamRatio) {
        homeToAwayTeamRatio = 1;
    }
    else
    {
        awayToHomeTeamRatio = 1;
    }

    awayTeamScoreIncrease = determineScoreIncrease(awayTeamRandNum, awayToHomeTeamRatio);

    awayTeam.setGameScore(awayTeam.getGameScore() + awayTeamScoreIncrease);

    // Determine the score increase for the home team
    int homeTeamRandNum = rand() % 1000;



    homeTeamScoreIncrease = determineScoreIncrease(homeTeamRandNum, homeToAwayTeamRatio);

    homeTeam.setGameScore(homeTeam.getGameScore() + homeTeamScoreIncrease);
}

int GameSimulation::determineScoreIncrease(int randNum, double teamRatio)
{
    int teamScoreIncrease;

    double teamScoreDecision = randNum * teamRatio;

    if (teamScoreDecision > 900)
    {
        teamScoreIncrease = 3;
    }
    else if (teamScoreDecision > 650)
    {
        teamScoreIncrease = 2;
    }
    else if (teamScoreDecision > 400)
    {
        teamScoreIncrease = 1;
    }
    else
    {
        teamScoreIncrease = 0;
    }

    return teamScoreIncrease;
}
