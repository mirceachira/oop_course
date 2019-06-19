#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <exception>

#include "repository.h"
#include "domain.h"
#include "utils.h"

using namespace std;


std::istream&
operator >> (std::istream& str, TextFileHandler& data)
{
    data.readNextRow(str);
    return str;
}


bool compare(Task a, Task b) {
    return strcmp(a.status.c_str(), b.status.c_str()) >= 0;
}

Repository::Repository()
{    
    TextFileHandler row;

    std::ifstream file("/home/mirceachira/Desktop/oop_course/test2/test2/tasks.csv");

    while (file >> row) {
        tasks.push_back(Task(row[0], row[1], std::stoi(row[2])));
    }

    std::ifstream usersFile("/home/mirceachira/Desktop/oop_course/test2/test2/users.csv");

    while (usersFile >> row) {
        programmers.push_back(Programmer(row[0], stoi(row[1])));
    }

    sort(this->tasks.begin(), this->tasks.end(), compare);
}

vector<Programmer>
Repository::getProgrammers() {
    return programmers;
}

vector<Task>
Repository::getTasks() {
    return tasks;
}


void
Repository::addTask(string description, string status, int id){
    this->tasks.push_back(Task(description, status, id));

    sort(this->tasks.begin(), this->tasks.end(), compare);
}
