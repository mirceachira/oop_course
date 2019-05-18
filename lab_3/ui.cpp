#include <iostream>
#include <stdio.h>

#include "ui.h"
#include "controller.h"
#include "domain.h"
#include "tests.h"

void
printMenu(bool isAdministrator)
{
    printf("\nAvailable options:\n");
    printf("\t0  - close the application\n");
    if (isAdministrator) {
        printf("\t1  - get pet from stock by index\n");
        printf("\t2  - get all pets from stock\n");
        printf("\t3  - add new pet from stock\n");
        printf("\t4  - update an existing pet from stock\n");
        printf("\t5  - delete pet from stock\n");
    } else {
        printf("\t1  - adopt from all pets\n");
        printf("\t2  - select pets by breed and age\n");
        printf("\t3  - see current pet\n");
        printf("\t4  - see next pet\n");
        printf("\t5  - adopt current pet\n");
        printf("\t6  - see adopted pets\n");
    }
}

int
getNextOption(bool isAdministrator)
{
    int option;

    printMenu(isAdministrator);

    printf("Enter your option: ");
    scanf("%d", &option);

    int upperLimit = isAdministrator ? 5 : 6; // Relevant if more choices are added
    while (option < 0 || option > upperLimit) {
        printf("\nInvalid option!\n");
        printMenu(isAdministrator);
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
    bool isAdministrator;

    populateApplication(controller);

    runTests(controller);

    printf("Available mods:\n\t1 - administrator\n\t0 - user\nEnter your mode: ");
    std::cin >> isAdministrator;

    int currentOption = getNextOption(isAdministrator);
    while (currentOption != 0) {
        if (isAdministrator) {
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
                    this->uiUpdateEntry();
                    break;
                case 5:
                    this->uiDeleteEntry();
                    break;
            }
        } else {
            switch (currentOption) {
                case 1:
                    this->uiAdoptFromAllPets();
                    break;
                case 2:
                    this->uiSelectByBreedAndAge();
                    break;
                case 3:
                    this->uiGetCurrentPet();
                    break;
                case 4:
                    this->uiGetNextPet();
                    break;
                case 5:
                    this->uiAdoptCurrentPet();
                    break;
                case 6:
                    this->uiSeeAdoptedPets();
                    break;
            }
        }
        currentOption = getNextOption(isAdministrator);
    }
} // Ui::uiRunApplication

void
Ui::uiAdoptFromAllPets()
{
    controller.controllerAdoptFromAllPets();
}

void
Ui::uiSelectByBreedAndAge()
{
    string breed;
    std::cin >> breed;
    int age;
    std::cin >> age;

    controller.controllerSelectByBreedAndAge(breed, age);
}

void
Ui::uiGetCurrentPet()
{
    Dog currentDog = controller.controllerGetCurrentPet();

    displayEntry(currentDog);
}

void
Ui::uiGetNextPet()
{
    Dog currentDog = controller.controllerGetNextPet();

    displayEntry(currentDog);
}

void
Ui::uiAdoptCurrentPet()
{
    controller.controllerAdoptCurrentPet();
}

void
Ui::uiSeeAdoptedPets()
{
    DynamicVector<Dog> adoptedPets = controller.controllerGetAdoptedPets();

    for (int i = 0; i < adoptedPets.getSize(); i++)
        displayEntry(adoptedPets[i]);
}

void
displayEntry(Dog entry)
{
    std::cout << "\nDog:";
    std::cout << "\n\tbreed " << entry.getBreed();
    std::cout << "\n\tname  " << entry.getName();
    std::cout << "\n\tage   " << entry.getAge();
    std::cout << "\n\tphoto " << entry.getPhoto();
}

void
Ui::uiGetEntry()
{
    printf("Please enter the desired index:\n");
    int index;
    scanf("%d", &index);

    Dog foundEntry = controller.controllerGetEntry(index);

    displayEntry(foundEntry);
}

void
Ui::uiGetAllEntries()
{
    DynamicVector<Dog> entries = controller.controllerGetAllEntries();

    for (int i = 0; i < entries.getSize(); i++)
        displayEntry(entries[i]);
}

void
Ui::uiCreateEntry()
{
    string breed, name, photo;
    int age;

    printf("\tEnter breed:");
    std::cin >> breed;
    printf("\tEnter name:");
    std::cin >> name;
    printf("\tEnter photo:");
    std::cin >> photo;
    printf("\tEnter age:");
    std::cin >> age;

    bool result = controller.controllerCreateEntry(breed, name, age, photo);

    if (result == false) {
        std::cout << "Could not create entry";
    } else   {
        std::cout << "Entry created!";
    }
}

void
Ui::uiUpdateEntry()
{
    string breed, name, photo;
    int index, age;

    printf("\tEnter index to update:");
    std::cin >> index;
    printf("\tEnter breed:");
    std::cin >> breed;
    printf("\tEnter name:");
    std::cin >> name;
    printf("\tEnter photo:");
    std::cin >> photo;
    printf("\tEnter age:");
    std::cin >> age;

    bool result = controller.controllerUpdateEntry(index, breed, name, age, photo);

    if (result == false) {
        std::cout << "Could not update entry";
    } else   {
        std::cout << "Entry created!";
    }
}

void
Ui::uiDeleteEntry()
{
    int index;

    printf("\tEnter index to delete:");
    std::cin.clear();
    std::cin >> index;

    controller.controllerDeleteEntry(index);
}
