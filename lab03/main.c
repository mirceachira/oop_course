#include <string.h>

#include "ui.h"
#include "test.h"

/*
 * To compile on linux (with gcc):
 * gcc -Wall -Wextra -Werror *.h *.c
 *
 * To run the program:
 * ./a.out
 *
 * To run the tests:
 * ./a.out test
 *
 */
int
main(int argc, char * argv[])
{
    if (argc == 2 && strcmp(argv[1], "test") == 0) {
        runTests();
    } else {
        Ui * currentUi;

        initialSetup(&currentUi);
        populate(currentUi);
        runApplication(currentUi);
    }
}
