#include "controller.h"
#include "repository.h"

Controller::Controller()
{
    this->repo = new Repository();
}

vector<Programmer>
Controller::getProgrammers() {
    return repo->getProgrammers();
}

vector<Task>
Controller::getTasks() {
    return repo->getTasks();
}

void
Controller::update(){
    for (auto i: this->dialogs){
        i->update();
        i->show();
    }
}

void
Controller::addTask(string description, string status, int id) {
    this->repo->addTask(description, status, id);
}
