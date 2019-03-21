#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "repository.h"
#include "domain.h"
#include "utils.h"

void    repositoryInitialSetup(Stock **currentStock) {
    *currentStock = malloc(sizeof(Stock));
    (*currentStock)->length = 0;
}


void    repositoryGetMedication(Stock *currentStock, int index) {
    printf("Medication at index %d:\n", index);
    printf("\tname - %s\n", currentStock->medications[index].name);
    printf("\tconcentration - %d\n", currentStock->medications[index].concentration);
    printf("\tquantity - %d\n", currentStock->medications[index].quantity);
    printf("\tprice - %f\n", currentStock->medications[index].price);
    printf("\n");
}


void    repositoryGetAllMedications(Stock *currentStock) {
    printf("Printing all stock medication:\n");

    for (int i=0; i<currentStock->length; i++) {
        printf("\tmedication index - %d\n", i);
        printf("\tname - %s\n", currentStock->medications[i].name);
        printf("\tconcentration - %d\n", currentStock->medications[i].concentration);
        printf("\tquantity - %d\n", currentStock->medications[i].quantity);
        printf("\tprice - %f\n", currentStock->medications[i].price);
        printf("\n");
    }
}


void     repositoryAddMedication(Stock *currentStock, char name[100], int concentration, int quantity, float price) {
    // Check if medication already exists
    int index = -1;
    for (int i=0; i<currentStock->length; i++)
        if ( (currentStock->medications[i].concentration = concentration && strcmp(currentStock->medications[i].name, name) == 0) ) {
            index = i;
            break;
        }

    if (index == -1) {
        printf("Adding new medication!\n");
        Medication     newMedication;

        strcpy(newMedication.name, name);
        newMedication.concentration = concentration;
        newMedication.quantity = quantity;
        newMedication.price = price;

        currentStock->medications[currentStock->length++] = newMedication;
    }
    else {
        printf("Updating existing medication %d quantity\n", index);
        currentStock->medications[index].quantity = quantity;
    }
}


void     repositoryUpdateMedication(Stock *currentStock, int index, char name[100], int concentration, int quantity, float price) {
    strcpy(currentStock->medications[index].name, name);
    currentStock->medications[index].concentration = concentration;
    currentStock->medications[index].quantity = quantity;
    currentStock->medications[index].price = price;
}


void    repositoryDeleteMedication(Stock *currentStock, int index) {
    while (index < currentStock->length) {
        currentStock->medications[index] = currentStock->medications[index + 1];
        index++;
    }

    currentStock->length--;
}


void    repositorySearchMedications(Stock *currentStock, char    subString[100]) {
    Medication     tmpMedication, medicationResults[100];
    int            index=0;

    // Find all medications from stock that match the substring
    for (int i=0; i<currentStock->length; i++)
        if (strIsContained(currentStock->medications[i].name, subString) == 1)
            medicationResults[index++] = currentStock->medications[i];

    // Sort existing medications
    for (int i=0; i<index; i++)
        for (int j=0; j<index-i-1; j++) {
            if (strcmp(medicationResults[j].name, medicationResults[j+1].name) > 0) {
                tmpMedication = medicationResults[j];
                medicationResults[j] = medicationResults[j + 1];
                medicationResults[j + 1] = tmpMedication;
            }
        }

    // Display sorted medications
    printf("\nResults:\n");
    for (int i=0; i<index; i++) {
        printf("\tmedication index - %d\n", i);
        printf("\tname - %s\n", medicationResults[i].name);
        printf("\tconcentration - %d\n", medicationResults[i].concentration);
        printf("\tquantity - %d\n", medicationResults[i].quantity);
        printf("\tprice - %f\n", medicationResults[i].price);
        printf("\n");
    }
}


void    repositorySearchMedicationsSorted(Stock *currentStock, char    subString[100]) {
    Medication     tmpMedication, medicationResults[100];
    int            index=0;

    // Find all medications from stock that match the substring
    for (int i=0; i<currentStock->length; i++)
        if (strIsContained(currentStock->medications[i].name, subString) == 1)
            medicationResults[index++] = currentStock->medications[i];

    // Sort existing medications
    for (int i=0; i<index; i++)
        for (int j=0; j<index-i-1; j++) {
            if (medicationResults[j].concentration < medicationResults[j+1].concentration) {
                tmpMedication = medicationResults[j];
                medicationResults[j] = medicationResults[j + 1];
                medicationResults[j + 1] = tmpMedication;
            }
        }

    // Display sorted medications
    printf("\nResults:\n");
    for (int i=0; i<index; i++) {
        printf("\tmedication index - %d\n", i);
        printf("\tname - %s\n", medicationResults[i].name);
        printf("\tconcentration - %d\n", medicationResults[i].concentration);
        printf("\tquantity - %d\n", medicationResults[i].quantity);
        printf("\tprice - %f\n", medicationResults[i].price);
        printf("\n");
    }
}

void    repositoryGetMedicationByQuantity(Stock *currentStock, int quantity) {
    Medication     medicationResults[100];
    int            index=0;

    // Find all medications from stock that have atleast the given quantity
    for (int i=0; i < currentStock->length; i++)
        if (currentStock->medications[i].quantity > quantity)
            medicationResults[index++] = currentStock->medications[i];

    // Display sorted medications
    printf("\nResults:\n");
    for (int i=0; i<index; i++) {
        printf("\tmedication index - %d\n", i);
        printf("\tname - %s\n", medicationResults[i].name);
        printf("\tconcentration - %d\n", medicationResults[i].concentration);
        printf("\tquantity - %d\n", medicationResults[i].quantity);
        printf("\tprice - %f\n", medicationResults[i].price);
        printf("\n");
    }
}