#include "ui.h"

int
main(void)
{
    Ui * currentUi;

    initialSetup(&currentUi);
    populate(currentUi);
    runApplication(currentUi);
}

/*
 *  TODO:
 * implement copy logic? (see seminar 2 & 3)
 * move undo / redo in repository only
 * operation stack undo / redo
 * tests for repository and controller (not for domain)
 */
