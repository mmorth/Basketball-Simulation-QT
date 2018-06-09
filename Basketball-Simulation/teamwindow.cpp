#include "teamwindow.h"
#include "ui_teamwindow.h"
#include <QIntValidator>

TeamWindow::TeamWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamWindow)
{
    ui->setupUi(this);

    // Only allow the offensive and defensive ratings to accept integers between 30-100
    ui->teamInfoOffensiveRatingInput->setValidator( new QIntValidator(30, 100, this) );
    ui->teamInfoDefensiveRatingInput->setValidator( new QIntValidator(30, 100, this) );

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

void TeamWindow::on_updateTeamButton_clicked()
{
    dbHandler dbHand;
    dbHand.editTeam(ui->teamInfoNameInput->text(), ui->teamInfoOffensiveRatingInput->text().toInt(), ui->teamInfoDefensiveRatingInput->text().toInt());

    hide();
    TeamDetails *td = new TeamDetails(this);
    td->show();
}

void TeamWindow::on_deleteTeamButton_clicked()
{
    dbHandler dbHand;
    dbHand.removeTeam(ui->teamInfoNameInput->text());

    hide();
    TeamDetails *td = new TeamDetails(this);
    td->show();
}
