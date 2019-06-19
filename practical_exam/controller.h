#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "dialog.h"
#include "repository.h"
#include "domain.h"


class dialog;

class Controller
{
public:
    Controller();
    Repository * repo;
    vector<dialog *> dialogs;

    void
    deleteItem(int index);

    vector<Programmer>
    getProgrammers();

    vector<Task>
    getTasks();

    void
    update();

    void
    addTask(string description, string status, int id);

    // Method for removing a task from the repository by index
    // in: ind the index of type int
    // out: -
    void
    removeTask(int ind) {this->repo->removeTask(ind);}

    // Start ("or update) task
    // in: ind the integer index of the task, the integer id and string name of the programmer
    // out: true if task can be updated or false otherwise
    bool
    startTask(int ind, int id, string name) { return this->repo->startTask(ind, id, name);}
};

#endif // CONTROLLER_H
