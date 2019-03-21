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

void    repositoryGetMedication(Stock *currentStock, int index);

void    repositoryGetAllMedications(Stock *currentStock);

void     repositoryAddMedication(Stock *currentStock, char name[100], int concentration, int quantity, float price);

void     repositoryUpdateMedication(Stock *currentStock, int index, char name[100], int concentration, int quantity, float price);

void    repositoryDeleteMedication(Stock *currentStock, int index);

void    repositorySearchMedications(Stock *currentStock, char    subString[100]);

void    repositorySearchMedicationsSorted(Stock *currentStock, char    subString[100]);

void    repositoryGetMedicationByQuantity(Stock *currentStock, int quantity);


#endif