#include <string.h>

#include "ui.h"
#include "test.h"


void    populate(Ui *currentUi) {
    controllerAddMedication(
        currentUi->currentController,
        "algocalmin",
        12,
        13,
        19
    );
    controllerAddMedication(
        currentUi->currentController,
        "algoceva",
        12,
        13523,
        1
    );
    controllerAddMedication(
        currentUi->currentController,
        "algoaltceva",
        12,
        134,
        12
    );
    controllerAddMedication(
        currentUi->currentController,
        "strepsil c",
        12,
        131,
        76
    );
    controllerAddMedication(
        currentUi->currentController,
        "strepsil b",
        12,
        243,
        22
    );
    controllerAddMedication(
        currentUi->currentController,
        "strepsil a",
        14,
        54,
        42
    );
    controllerAddMedication(
        currentUi->currentController,
        "panadol",
        13,
        333,
        11
    );
    controllerAddMedication(
        currentUi->currentController,
        "restantsonium",
        12,
        22,
        123
    );
    controllerAddMedication(
        currentUi->currentController,
        "algebra",
        12,
        111,
        10
    );
    controllerAddMedication(
        currentUi->currentController,
        "medicament",
        12,
        1,
        1223
    );
    controllerAddMedication(
        currentUi->currentController,
        "medicament lol",
        12,
        0,
        13
    );
}
