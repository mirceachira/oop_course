#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>

#include "domain.h"


class MyException : public exception
{
public:
    const char *
    what(){ return "My custom exception"; }
};

using namespace std;

class Repository
{
public:
    vector<Programmer> programmers;
    vector<Task> tasks;

    Repository();
    vector<Programmer>
    getProgrammers();

    vector<Task>
    getTasks();

    void
    addTask(string description, string status, int id);

    // Method for removing a task from the repository by index
    // in: ind the index of type int
    // out: -
    void
    removeTask(int ind) { this->tasks.erase(this->tasks.begin() + ind);}

    // Start ("or update) task
    // in: ind the integer index of the task, the integer id and string name of the programmer
    // out: true if task can be updated or false otherwise
    bool
    startTask(int ind, int id, string name) {
        if (this->tasks[ind].status != "open")
            throw MyException();

        this->tasks[ind].status = "in progress";
        this->tasks[ind].id = id;
        this->tasks[ind].name = name;

        return true;
    }
};

#endif // REPOSITORY_H
