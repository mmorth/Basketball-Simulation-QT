#ifndef TEAMDETAILS_H
#define TEAMDETAILS_H

#include <QDialog>
//#include "gamesimulation.h"

namespace Ui {
class TeamDetails;
}

class TeamDetails : public QDialog
{
    Q_OBJECT

public:
    explicit TeamDetails(QWidget *parent = 0);
    ~TeamDetails();

private slots:
    /**
     * @brief on_createTeamButton_clicked
     *      When clicked, it will create a team with the input information, if valid input.
     */
    void on_createTeamButton_clicked();

    /**
     * @brief on_scoreBoardButton_clicked
     *      Switches to the scoreboard window when the button is clicked
     */
    void on_scoreBoardButton_clicked();

private:
    Ui::TeamDetails *ui;
//    GameSimulation *gs;
};

#endif // TEAMDETAILS_H
