#include <stdio.h>
#include <stdlib.h>

#include "repository.h"
#include "controller.h"

void    controllerInitialSetup(Controller **currentController) {
    *currentController = malloc(sizeof(Controller));
    repositoryInitialSetup(&((*currentController)->currentStock));
}


void    controllerGetMedication(Controller *currentController, int index) {
    repositoryGetMedication(currentController->currentStock, index);
}


void    controllerGetAllMedications(Controller *currentController) {
    repositoryGetAllMedications(currentController->currentStock);
}


void    controllerAddMedication(Controller *currentController, char name[100], int concentration, int  quantity, float price) {
    repositoryAddMedication(currentController->currentStock, name, concentration, quantity, price);
}

void    controllerUpdateMedication(Controller *currentController, int index, char name[100], int concentration, int  quantity, float price) {
    repositoryUpdateMedication(currentController->currentStock, index, name, concentration, quantity, price);
}


void    controllerDeleteMedication(Controller *currentController, int index) {
    repositoryDeleteMedication(currentController->currentStock, index);
}


void    controllerSearchMedication(Controller *currentController, char subString[100]) {
    repositorySearchMedications(currentController->currentStock, subString);
}

void    controllerSearchMedicationSorted(Controller *currentController, char subString[100]) {
    repositorySearchMedicationsSorted(currentController->currentStock, subString);
}

void    controllerGetMedicationByQuantity(Controller *currentController, int quantity) {
    repositoryGetMedicationByQuantity(currentController->currentStock, quantity);
}