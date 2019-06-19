#include <vector>

#include "controller.h"
#include "repository.h"
#include "domain.h"

using namespace std;

Controller::Controller()
{
    Repository repository;
    this->repository = repository;
}

Controller::Controller(TextFileHandler* handler)
{
    this->handler = handler;
    Repository repository;
    this->repository = repository;
}

Controller::Controller(const Controller& otherController){
    this->repository = otherController.repository;
    this->handler = otherController.handler;
}

Controller::~Controller(){ }

Dog
Controller::controllerGetEntry(int index)
{
    return repository.repositoryGetEntry(index);
}

vector<Dog>
Controller::controllerGetAllEntries()
{
    return repository.repositoryGetAllEntries();
}

bool
Controller::controllerCreateEntry(string breed, string name, int age, string photo)
{
    bool result = repository.repositoryCreateEntry(breed, name, age, photo);
    if (result)
        this->handler->writeToFile(repository.repositoryGetAdoptedPets());

    return result;
}

bool
Controller::controllerUpdateEntry(int index, string breed, string name, int age, string photo)
{
    bool result = repository.repositoryUpdateEntry(index, breed, name, age, photo);
    if (result)
        this->handler->writeToFile(repository.repositoryGetAdoptedPets());

    return result;
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
    this->handler->writeToFile(repository.repositoryGetAdoptedPets());
}

vector<Dog>
Controller::controllerGetAdoptedPets()
{
    return repository.repositoryGetAdoptedPets();
}