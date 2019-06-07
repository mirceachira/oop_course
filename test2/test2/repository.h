#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>

#include "domain.h"

using namespace std;

class Repository
{
public:
    vector<Item> stock;
    Repository();
    vector<Item>
    getStock();
    void
    deleteItem(int index);
    vector<Item>
    getFiltered(string category);
};

#endif // REPOSITORY_H
