#ifndef CONTROLLER
#define CONTROLLER

#include <stdio.h>
#include <stdlib.h>

#include "repository.h"
#include "controller.h"

typedef struct {
    Stock     *currentStock;
}    Controller;

void    controllerInitialSetup(Controller **currentController);

void    controllerGetMedication(Controller *currentController, int index);

void    controllerGetAllMedications(Controller *currentController);

void    controllerAddMedication(Controller *currentController, char name[100], int concentration, int  quantity, float price);

void    controllerUpdateMedication(Controller *currentController, int index, char name[100], int concentration, int  quantity, float price);

void    controllerDeleteMedication(Controller *currentController, int index);

void    controllerSearchMedication(Controller *currentController, char subString[100]);

void    controllerSearchMedicationSorted(Controller *currentController, char subString[100]);

void    controllerGetMedicationByQuantity(Controller *currentController, int quantity);

#endif