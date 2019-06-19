#include "dialog.h"
#include <vector>
#include <QApplication>
#include <assert.h>
#include <iostream>

#include "controller.h"

using namespace std;


void test(Controller * ctrl) {
    // Test remove task
    assert(ctrl->getTasks()[0].description== "task B2");
    assert(ctrl->getTasks().size() == 12);
    ctrl->removeTask(0);
    assert(ctrl->getTasks().size() == 11);
    ctrl->removeTask(0);
    assert(ctrl->getTasks().size() == 10);
    assert(ctrl->getTasks()[0].description== "task A23");

    // Test update
    ctrl->startTask(0, 10, "dummy");
    assert(ctrl->getTasks()[0].description == "task A23");
    assert(ctrl->getTasks()[0].status == "in progress");
    assert(ctrl->getTasks()[0].name == "dummy");
    assert(ctrl->getTasks()[0].id == 10);
    ctrl->removeTask(0);
    ctrl->update();
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller * ctrl = new Controller();

    vector<dialog*> dialogs;

    for (auto i: ctrl->getProgrammers()) {
        dialog * d = new dialog;
        d->setProgrammer(i);
        d->setController(ctrl);
        ctrl->dialogs.push_back(d);
        ctrl->update();
    }

    test(ctrl);

    return a.exec();
}
