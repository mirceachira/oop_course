#ifndef DOMAIN
#define DOMAIN

#include <string>

using namespace std;


class Programmer
{
public:
    string name;
    int id;

    Programmer(string name, int id)
    {
        this->name = name;
        this->id = id;
    }
};


class Task
{
public:
    string description;
    string status;
    int id;
    string name=""; // programmer working on task

    Task(string d, string s, int id)
    {
        this->description = d;
        this->status = s;
        this->id = id;
    }
};


#endif // ifndef DOMAIN
