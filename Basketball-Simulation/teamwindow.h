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
    explicit TeamWindow(QWidget *parent = 0);
    explicit TeamWindow(QWidget *parent = 0, QString teamName = "Team");
    ~TeamWindow();

private slots:
    void on_teamDetailsBackButton_clicked();

    void on_updateTeamButton_clicked();

    void on_deleteTeamButton_clicked();

private:
    Ui::TeamWindow *ui;
};

#endif // TEAMWINDOW_H
