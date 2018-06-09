#include "teamwindow.h"
#include "ui_teamwindow.h"

TeamWindow::TeamWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamWindow)
{
    ui->setupUi(this);

    ui->teamInfoNameInput->setReadOnly(true);
}

TeamWindow::TeamWindow(QWidget *parent, QString teamName) :
    QDialog(parent),
    ui(new Ui::TeamWindow)
{
    ui->setupUi(this);

    ui->teamInfoNameInput->setText(teamName);
    ui->teamInfoNameInput->setReadOnly(true);

    // Get the team information from the database
    dbHandler dbHand;
    Team selectedTeam = dbHand.findTeam(teamName);

    ui->teamInfoOffensiveRatingInput->setText(QString::number(selectedTeam.getOffensiveRating()));
    ui->teamInfoDefensiveRatingInput->setText(QString::number(selectedTeam.getDefensiveRating()));
}

TeamWindow::~TeamWindow()
{
    delete ui;
}

void TeamWindow::on_teamDetailsBackButton_clicked()
{
    hide();
    TeamDetails *td = new TeamDetails(this);
    td->show();
}
