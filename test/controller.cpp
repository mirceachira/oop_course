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

Controller::Controller(const Controller& otherController){ this->repository = otherController.repository; }

Controller::~Controller(){ }

Bill
Controller::controllerGetEntry(int index)
{
    return repository.repositoryGetEntry(index);
}

vector<Bill>
Controller::controllerGetAllEntries()
{
    return repository.repositoryGetAllEntries();
}

bool
Controller::controllerCreateEntry(string name, string serialNumber, int sum, bool isPaid)
{
    return repository.repositoryCreateEntry(name, serialNumber, sum, isPaid);
}

void
Controller::controllerUpdateEntry(int index, string name, string serialNumber, int sum, bool isPaid)
{
    repository.repositoryUpdateEntry(index, name, serialNumber, sum, isPaid);
}

void
Controller::controllerDeleteEntry(int index)
{
    repository.repositoryDeleteEntry(index);
}


int
Controller::controllerCalculateUnpaid() {
    return repository.repositoryCalculateUnpaid();
}