#ifndef TEAMDETAILS_H
#define TEAMDETAILS_H

#include <QDialog>
#include "teamwindow.h"

namespace Ui {
class TeamDetails;
}

class TeamDetails : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief TeamDetails
     *      Constructs the TeamDetails window
     * @param parent
     *      The parents window
     */
    explicit TeamDetails(QWidget *parent = 0);

    // The destructor for the TeamDetails class
    ~TeamDetails();

    /**
     * @brief TeamDetails::updateTeamsListView
     *      Updates the teams list view widget with all the current teams stored in the database
     */
    void updateTeamsListView();

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

    /**
     * @brief on_teamListView_doubleClicked
     *      Opens the team-specific window when a team name is double clicked
     * @param index
     *      The index of the team that was selected
     */
    void on_teamListView_doubleClicked(const QModelIndex &index);

private:
    /**
     * @brief ui
     *      Represents the ui of the window
     */
    Ui::TeamDetails *ui;
};

#endif // TEAMDETAILS_H
