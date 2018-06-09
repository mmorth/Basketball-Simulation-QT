#ifndef TEAMLOOK_H
#define TEAMLOOK_H

#include <QWidget>

namespace Ui {
class TeamLook;
}

class TeamLook : public QWidget
{
    Q_OBJECT

public:
    explicit TeamLook(QWidget *parent = 0);
    ~TeamLook();

private:
    Ui::TeamLook *ui;
};

#endif // TEAMLOOK_H
