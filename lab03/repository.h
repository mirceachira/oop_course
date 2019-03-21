#ifndef REPOSITORY
#define REPOSITORY

#include <string.h>
#include <stdlib.h>

#include "domain.h"
#include "utils.h"


typedef struct {
    Medication     medications[100];
    int            length;
}    Stock;


void    repositoryInitialSetup(Stock **currentStock);

Medication repositoryGetMedication(Stock *currentStock, int index);

Stock *repositoryGetAllMedications(Stock *currentStock);

int     repositoryAddMedication(Stock *currentStock, char name[100], int concentration, int quantity, float price);

void     repositoryUpdateMedication(Stock *currentStock, int index, char name[100], int concentration, int quantity, float price);

void    repositoryDeleteMedication(Stock *currentStock, int index);

Stock    repositorySearchMedications(Stock *currentStock, char    subString[100]);

Stock    repositorySearchMedicationsSorted(Stock *currentStock, char    subString[100]);

Stock    repositoryGetMedicationByQuantity(Stock *currentStock, int quantity);


#endif