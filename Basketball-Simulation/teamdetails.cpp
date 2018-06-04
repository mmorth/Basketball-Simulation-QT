#include "teamdetails.h"
#include "ui_teamdetails.h"
#include "gamesimulation.h"
#include <QStringListModel>
#include "dbhandler.h"

TeamDetails::TeamDetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamDetails)
{
    ui->setupUi(this);

    // Set the directions label to read only
    ui->directionsLabel->setReadOnly(true);

    QStringList teams = {"Dragons", "Gators", "Thunder", "Tigers", "Titans"};

    // Populate the listview with team names and make the listview not editable
    ui->teamListView->setModel(new QStringListModel(teams));
    ui->teamListView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Set the maximum size of a team name to be 30 characters
    ui->teamNameInput->setMaxLength(30);

    // Only allow the offensive and defensive ratings to accept integers between 30-100
    ui->offensiveRatingInput->setValidator( new QIntValidator(30, 100, this) );
    ui->defensiveRatingInput->setValidator( new QIntValidator(30, 100, this) );

    // Call to update the teams list view with the newly created team
    updateTeamsListView();
}

TeamDetails::~TeamDetails()
{
    delete ui;
}

void TeamDetails::on_createTeamButton_clicked()
{
    // Save the names of the columns you want to save in the database
    QString team_name = ui->teamNameInput->text();

    // Determine if input is valid and process
    if (team_name.length() >= 0)
    {
        addTeam(team_name, atoi(ui->offensiveRatingInput->text()), atoi(ui->defensiveRatingInput->text()));
    }
    else
    {
        ui->invalidInputIndicator->setText("Invalid Input. Check the input requirements.");
    }

    // Call to update the teams list view with the newly created team
    updateTeamsListView();

}

void TeamDetails::on_scoreBoardButton_clicked()
{
    // Switch to the Team Details window
    hide();
    GameSimulation *gs = new GameSimulation(this);
    gs->show();
}

void TeamDetails::updateTeamsListView()
{

}
