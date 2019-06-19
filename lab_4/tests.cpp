#include <iostream>
#include <assert.h>

#include "ui.h"
#include "controller.h"
#include "repository.h"
#include "domain.h"

using namespace std;

/*
labrador,Goldy,12,https://google.com
labrador,Goldy 1,13,https://google.cm
labrador,Goldy 2,14,https://google.com
armadillo,Goldy 3,15,https://google.com
armadillo,Goldy 4,16,https://google.com
sarpe,Goldy 5,2,https://google.com
sarpe,Goldy 6,3,https://google.com
labrador sarpe,Goldy 7,4,https://google.com
labrador armadillo sarpe,Goldy 8,5,https://google.com
armadillo sarpe,Goldy 9,6,https://google.com
*/
void
populateApplication(Controller& currentController)
{
    currentController.controllerAdoptFromAllPets();
} // populateApplication


void
runTests(Controller& controller)
{
    cout << "Running tests..." << '\n';

    // Test add
    cout << "\tTesting get..." << '\n';
    Dog myDog = controller.controllerGetEntry(0);
    assert(myDog.getName().find("Goldy") == 0);
    assert(myDog.getBreed().find("labrador") == 0);
    assert(myDog.getAge() == 12 || myDog.getAge() == 6);
    assert(myDog.getPhoto().find("https://") == 0);

    cout << "\tTesting add..." << '\n';
    controller.controllerCreateEntry(
        "armadillo sarpe", "Goldy 10", 6, "https://google.com");
    Dog myDog2 = controller.controllerGetEntry(10);
    assert(myDog2.getName().find("Goldy 10") == 0);
    assert(myDog2.getBreed().find("armadillo sarpe") == 0);
    assert(myDog2.getAge() == 6);
    assert(myDog2.getPhoto().find("https://") == 0);

    cout << "\tTesting update..." << '\n';
    controller.controllerUpdateEntry(
        0, "labrador update", "Goldy update", 6, "https://update");
    Dog myDog3 = controller.controllerGetEntry(0);
    assert(myDog3.getName().find("Goldy update") == 0);
    assert(myDog3.getBreed().find("labrador update") == 0);
    assert(myDog3.getAge() == 6);
    assert(myDog3.getPhoto().find("https://update") == 0);

    cout << "\tTesting delete..." << '\n';
    controller.controllerDeleteEntry(0);
    Dog myDog4 = controller.controllerGetEntry(0);
    assert(myDog4.getName().find("Goldy 1") == 0);
    assert(myDog4.getBreed().find("labrador") == 0);
    assert(myDog4.getAge() == 13);
    assert(myDog4.getPhoto().find("https://") == 0);

    cout << "\tTesting see current..." << '\n';
    Dog myDog5 = controller.controllerGetCurrentPet();
    assert(myDog5.getName().find("Goldy") == 0);
    assert(myDog5.getBreed().find("labrador") == 0);
    assert(myDog5.getPhoto().find("https://") == 0);
    
    cout << "\tTesting see next..." << '\n';
    Dog myDog6 = controller.controllerGetNextPet();
    assert(myDog6.getName().find("Goldy 1") == 0);
    assert(myDog6.getBreed().find("labrador") == 0);
    assert(myDog6.getAge() == 13);
    assert(myDog6.getPhoto().find("https://") == 0);

    cout << "Finished runnning tests..." << '\n';
}
