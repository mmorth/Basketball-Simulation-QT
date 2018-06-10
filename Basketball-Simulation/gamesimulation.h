#ifndef GAMESIMULATION_H
#define GAMESIMULATION_H

#include <QMainWindow>
#include "team.h"
#include "teamdetails.h"
#include "dbhandler.h"

#include <QtSql>
#include <QDebug>
#include <QFileInfo>

/**
 *Represents the ui for the GameSimulation class
 */
namespace Ui {
class GameSimulation;
}

/**
 * @brief The GameSimulation class
 *      Represents a basketball game simulation class
 */
class GameSimulation : public QMainWindow
{
    // Convert this object to a Qt object
    Q_OBJECT

public:
    /**
     * @brief GameSimulation::GameSimulation
     *      Creates a GameSimulation class that shows a basketball game simulation
     * @param parent
     *      The parent widget
     */
    explicit GameSimulation(QWidget *parent = 0);

    /**
     * @brief GameSimulation::~GameSimulation
     *      The GameSimulation destructor
     */
    ~GameSimulation();

    /**
     * @brief GameSimulation::simulatePossessions
     *      Simulates a certain number of basketball possessions
     * @param possessions
     *      The number of possessions to simulate
     */
    void simulatePossessions(int possessions);

    /**
     * @brief GameSimulation::simulatePossession
     *      Simulates a single basketball possession
     * @param quarter
     *      The current quarter the game is in
     * @param possessions
     *      The number of possessions that will be simulated
     * @return
     *      The number of possessions remaining
     */
    int simulatePossession(int quarter, int possessions);

    /**
     * @brief determineScoringOutcome
     *      Determines and returns the scoring outcome for each team in a possession
     */
    void determineScoringOutcome();

    /**
     * @brief determineScoreIncrease
     *      Determines the score increase for a team for a given possession
     * @return
     *      The score increase for a team in a given possession
     */
    int determineScoreIncrease(int randNum, int teamRatio);

    /**
     * @brief GameSimulation::updateTeamsComboboxes
     *      Update the teams comboboxes with the current teams stored in the database
     */
    void updateTeamsComboboxes();

private slots:
    /**
     * @brief GameSimulation::on_pushButton_simulatePossession_clicked
     *      Simulates a basketball possession when the "Possession" button is clicked and released
     */
    void on_pushButton_simulatePossession_clicked();

    /**
     * @brief GameSimulation::on_pushButton_simulateQuarter_clicked
     *      Simulates a quarter when the "Quarter" button is clicked and released
     */
    void on_pushButton_simulateQuarter_clicked();

    /**
     * @brief GameSimulation::on_pushButton_simulateGame_clicked
     *      Simulates the remainder of the game when the "Game" button is clicked.
     */
    void on_pushButton_simulateGame_clicked();

    /**
     * @brief GameSimulation::on_pushButton_resetSimulation_clicked
     *
     */
    void on_pushButton_resetSimulation_clicked();

    /**
     * @brief on_pushButton_clicked
     *      Switches to the Team Details window
     */
    void on_teamDetailsButton_clicked();

    /**
     * @brief on_awayTeamCombobox_activated
     *      Changes the away team when the combobox selection is changed
     * @param arg1
     *      The name of the Team that was selected
     */
    void on_awayTeamCombobox_activated(const QString &arg1);

    /**
     * @brief on_homeTeamComboBox_activated
     *      Changes the away team when the combobox selection is changed
     * @param arg1
     *      The name of the Team that was selected
     */
    void on_homeTeamComboBox_activated(const QString &arg1);

private:
    /**
     * @brief ui
     *      The ui for the GameSimulation class
     */
    Ui::GameSimulation *ui;

    /**
     * @brief teamDetails
     *      Represents the ui for the TeamDetails class
     */
    TeamDetails *teamDetails;

    /**
     * @brief awayTeam
     *      Stores the information about the away basketball team
     */
    Team awayTeam;

    /**
     * @brief homeTeam
     *      Stores the information about the home basketball team
     */
    Team homeTeam;

    /**
     * @brief awayTeamPreviousQuarterScore
     *      Stores the number of points scored by the away team in the previous quarters
     *      Used to calculated how many points they scored in one quarter
     */
    int awayTeamPreviousQuarterScore;

    /**
     * @brief homeTeamPreviousQuarterScore
     *      Stores the number of points scored by the home team in the previous quarters
     *      Used to calculate how many points they scored in one quarter
     */
    int homeTeamPreviousQuarterScore;

    /**
     * @brief possessionsRemaining
     *      Stores the number of possessions remaining in the basketball game
     */
    int possessionsRemaining;

    /**
     * @brief overtime
     *      Has a value of true if the game is in overtime. Has a value of false otherwise.
     */
    bool overtime;

    /**
     * @brief resetGame
     *      Resets the game simulation
     */
    void resetGame();
};

#endif // GAMESIMULATION_H
