#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include "controller.h"
#include "domain.h"

class Controller;

namespace Ui {
class dialog;
}

class dialog : public QWidget
{
    Q_OBJECT

public:
    explicit dialog(QWidget *parent = 0);
    ~dialog();

    Programmer p = Programmer("dumy", 123);
    vector<Task> tasks;
    Controller * ctrl = NULL;

    void
    setProgrammer(Programmer p);
    void
    update();

    void
    setController(Controller * &ctrl)
    {
        this->ctrl = ctrl;
    }


private slots:
    void on_addButton_clicked();

    void on_removeButton_clicked();

    void on_startButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::dialog *ui;
};

#endif // DIALOG_H
