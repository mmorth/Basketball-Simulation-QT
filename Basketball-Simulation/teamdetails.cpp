#include "teamdetails.h"
#include "ui_teamdetails.h"
#include "gamesimulation.h"

TeamDetails::TeamDetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamDetails)
{
    ui->setupUi(this);

    ui->directionsLabel->setReadOnly(true);
}

TeamDetails::~TeamDetails()
{
    delete ui;
}

void TeamDetails::on_createTeamButton_clicked()
{

}

void TeamDetails::on_scoreBoardButton_clicked()
{
    // Switch to the Team Details window
    hide();
    GameSimulation *gs = new GameSimulation(this);
    gs->show();
}
