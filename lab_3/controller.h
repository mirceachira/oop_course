#ifndef CONTROLLER
#define CONTROLLER

#include "repository.h"
#include "domain.h"

class Controller {
private:
    Repository repository;
public:
    // Utilities
    Controller();
    Controller(const Controller& otherController);
    ~Controller();

    // Administrator
    Dog
    controllerGetEntry(int index);
    DynamicVector<Dog>
    controllerGetAllEntries();
    bool
    controllerCreateEntry(string breed, string name, int age, string photo);
    bool
    controllerUpdateEntry(int index, string breed, string name, int age, string photo);
    void
    controllerDeleteEntry(int index);

    // User
    void
    controllerAdoptFromAllPets();
    void
    controllerSelectByBreedAndAge(string breed, int age);
    Dog
    controllerGetCurrentPet();
    Dog
    controllerGetNextPet();
    void
    controllerAdoptCurrentPet();
    DynamicVector<Dog>
    controllerGetAdoptedPets();
};

#endif // ifndef CONTROLLER
