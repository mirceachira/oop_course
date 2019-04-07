#ifndef UI
#define UI

#include "controller.h"

void
printMenu(bool isAdministrator);

int
getNextOption(bool isAdministrator);

void
displayEntry(Dog entry);


class Ui {
private:
    Controller controller;
public:
    // Utilities
    Ui();
    Ui(const Ui& otherUi);
    ~Ui();
    void
    uiRunApplication();

    // Administrator
    void
    uiGetEntry();
    void
    uiGetAllEntries();
    void
    uiCreateEntry();
    void
    uiUpdateEntry();
    void
    uiDeleteEntry();

    // User
    void
    uiAdoptFromAllPets();
    void
    uiSelectByBreedAndAge();
    void
    uiGetCurrentPet();
    void
    uiGetNextPet();
    void
    uiAdoptCurrentPet();
    void
    uiSeeAdoptedPets();
};

#endif // ifndef UI
