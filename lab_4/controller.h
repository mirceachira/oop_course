#ifndef CONTROLLER
#define CONTROLLER

#include <vector>

#include "repository.h"
#include "domain.h"
#include "utils.h"

using namespace std;

class Controller {
private:
    Repository repository;
    TextFileHandler* handler;
public:
    // Utilities
    Controller();
    Controller(TextFileHandler* handler);
    Controller(const Controller& otherController);
    ~Controller();

    // Administrator
    Dog
    controllerGetEntry(int index);
    vector<Dog>
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
    vector<Dog>
    controllerGetAdoptedPets();
};

#endif // ifndef CONTROLLER
