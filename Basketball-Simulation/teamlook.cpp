#include "teamlook.h"
#include "ui_teamlook.h"

TeamLook::TeamLook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeamLook)
{
    ui->setupUi(this);

    // Make the team name uneditable
    ui->teamInfoNameInput->setReadOnly(true);


}

TeamLook::~TeamLook()
{
    delete ui;
}
