#include <assert.h>

#include "controller.h"
#include "tests.h"

void runTests(){
    Controller * ctrl = new Controller();

    assert(ctrl->getStock().size() == 5);
    assert(ctrl->getStock()[0].name == "orange juice");
    ctrl->deleteItem(0);
    assert(ctrl->getStock().size() == 4);
    assert(ctrl->getStock()[0].name == "water");
    ctrl->deleteItem(1);
    assert(ctrl->getStock().size() == 3);
    assert(ctrl->getStock()[0].name == "water");
}
