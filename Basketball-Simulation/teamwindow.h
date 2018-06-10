#ifndef TEAMWINDOW_H
#define TEAMWINDOW_H

#include <QDialog>
#include "teamdetails.h"
#include "dbhandler.h"

namespace Ui {
class TeamWindow;
}

class TeamWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief TeamWindow
     *      Constructs a default TeamWindow
     * @param parent
     *      The parent window
     */
    explicit TeamWindow(QWidget *parent = 0);

    /**
     * @brief TeamWindow
     *      Constructs a TeamWindow with the teamName of the team to display
     * @param parent
     *      The parent window
     * @param teamName
     *      The name of the team to display in the TeamWindow
     */
    explicit TeamWindow(QWidget *parent = 0, QString teamName = "Team");

    // The destructor
    ~TeamWindow();

private slots:
    /**
     * @brief on_teamDetailsBackButton_clicked
     *      Goes back to the TeamDetails window when the Back button is clicked
     */
    void on_teamDetailsBackButton_clicked();

    /**
     * @brief on_updateTeamButton_clicked
     *      Updates a team's information when the Update button is clicked
     */
    void on_updateTeamButton_clicked();

    /**
     * @brief on_deleteTeamButton_clicked
     *      Deletes a team from the sqlite database when the Delete button is clicked
     */
    void on_deleteTeamButton_clicked();

private:
    /**
     * @brief ui
     *      Represents the ui for a TeamWindow
     */
    Ui::TeamWindow *ui;
};

#endif // TEAMWINDOW_H
