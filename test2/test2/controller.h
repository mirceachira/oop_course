#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "repository.h"

class Controller
{
public:
    Controller();
    Repository * repo;
    vector<Item>
    getStock();

    void
    deleteItem(int index);

    vector<Item>
    getFiltered(string category);
};

#endif // CONTROLLER_H
