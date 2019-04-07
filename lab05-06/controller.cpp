#include "controller.h"
#include "repository.h"
#include "domain.h"

Controller::Controller()
{
    Repository repository;

    this->repository = repository;
}

Controller::Controller(const Controller& otherController){ this->repository = otherController.repository; }

Controller::~Controller(){ }

Dog
Controller::controllerGetEntry(int index)
{
    return repository.repositoryGetEntry(index);
}

DynamicVector<Dog>
Controller::controllerGetAllEntries()
{
    return repository.repositoryGetAllEntries();
}

void
Controller::controllerCreateEntry(string breed, string name, int age, string photo)
{
    repository.repositoryCreateEntry(breed, name, age, photo);
}

void
Controller::controllerUpdateEntry(int index, string breed, string name, int age, string photo)
{
    repository.repositoryUpdateEntry(index, breed, name, age, photo);
}

void
Controller::controllerDeleteEntry(int index)
{
    repository.repositoryDeleteEntry(index);
}

void
Controller::controllerAdoptFromAllPets()
{
    repository.repositoryAdoptFromAllPets();
}

void
Controller::controllerSelectByBreedAndAge(string breed, int age)
{
    repository.repositorySelectByBreedAndAge(breed, age);
}

Dog
Controller::controllerGetCurrentPet()
{
    return repository.repositoryGetCurrentPet();
}

Dog
Controller::controllerGetNextPet()
{
    return repository.repositoryGetNextPet();
}

void
Controller::controllerAdoptCurrentPet()
{
    repository.repositoryAdoptCurrentPet();
}

DynamicVector<Dog>
Controller::controllerGetAdoptedPets()
{
    return repository.repositoryGetAdoptedPets();
}