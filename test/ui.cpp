#include <iostream>
#include <stdio.h>
#include <vector>

#include "ui.h"
#include "controller.h"
#include "domain.h"
#include "tests.h"

using namespace std;


void
printMenu()
{
    printf("\nAvailable options:\n");
    printf("\t0  - close the application\n");
    printf("\t1  - get entry from stock by index\n");
    printf("\t2  - get all entry from stock\n");
    printf("\t3  - add new bill in stock\n");
    printf("\t4  - calculate unpaid bills\n");
    // printf("\t4  - update an existing entry from stock\n");
    // printf("\t5  - delete entry from stock\n");
}

int
getNextOption()
{
    int option;

    printMenu();

    printf("Enter your option: ");
    scanf("%d", &option);

    while (option < 0 || option > 4) {
        printf("\nInvalid option!\n");
        printMenu();
        printf("\nChoose a valid option: ");
        scanf("%d", &option);
    }

    return option;
}

Ui::Ui()
{
    Controller controller;

    this->controller = controller;
}

Ui::Ui(const Ui& otherUi){ this->controller = otherUi.controller; }

Ui::~Ui(){ }

void
Ui::uiRunApplication()
{
    populateApplication(controller);

    runTests(controller);

    int currentOption = getNextOption();
    while (currentOption != 0) {
        switch (currentOption) {
            case 1:
                this->uiGetEntry();
                break;
            case 2:
                this->uiGetAllEntries();
                break;
            case 3:
                this->uiCreateEntry();
                break;
            case 4:
                this->uiCalculateUnpaid();
                break;
            case 5:
                this->uiDeleteEntry();
                break;
        }
        currentOption = getNextOption();
    }
} // Ui::uiRunApplication

void
displayEntry(Bill entry)
{
    cout << "\nBill:";
    cout << "\n\tserial number - " << entry.getSerialNumber();
    cout << "\n\tname          - " << entry.getName();
    cout << "\n\tsum           - " << entry.getSum();
    cout << "\n\tis paid       - " << entry.getIsPaid();
}

void
Ui::uiGetEntry()
{
    printf("Please enter the desired index:\n");
    int index;
    scanf("%d", &index);

    Bill foundEntry = controller.controllerGetEntry(index);

    displayEntry(foundEntry);
}

void
Ui::uiGetAllEntries()
{
    vector<Bill> entries = controller.controllerGetAllEntries();

    for (auto e : entries)
        displayEntry(e);
}

void
Ui::uiCreateEntry()
{
    string serialNumber, name;
    int sum;
    bool isPaid;

    printf("\tEnter serialNumber:");
    cin >> serialNumber;
    printf("\tEnter name:");
    cin >> name;
    printf("\tEnter sum:");
    cin >> sum;
    printf("\tEnter isPaid:");
    cin >> isPaid;

    bool result = controller.controllerCreateEntry(name, serialNumber, sum, isPaid);
    result ? printf("New bill created!") : printf("Failed to create bill");
}

void
Ui::uiUpdateEntry()
{
    string serialNumber, name;
    int index, sum;
    bool isPaid;

    printf("\tEnter index to update:");
    cin >> index;
    printf("\tEnter serialNumber:");
    cin >> serialNumber;
    printf("\tEnter name:");
    cin >> name;
    printf("\tEnter sum:");
    cin >> sum;
    printf("\tEnter isPaid:");
    cin >> isPaid;
    controller.controllerUpdateEntry(index, name, serialNumber, sum, isPaid);
}

void
Ui::uiDeleteEntry()
{
    int index;

    printf("\tEnter index to delete:");
    cin.clear();
    cin >> index;

    controller.controllerDeleteEntry(index);
}

void
Ui::uiCalculateUnpaid()
{ 
    int sum = controller.controllerCalculateUnpaid();
    cout << "You have " << sum << " left to pay!";
}
