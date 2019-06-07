#include "controller.h"
#include "repository.h"

Controller::Controller()
{
    this->repo = new Repository();
}

vector<Item>
Controller::getStock()
{
    return this->repo->getStock();
}

/*
 * Delete an item from the stock
 * in: the index of the item in the stock
 * out: -
 */
void
Controller::deleteItem(int index)
{
    return this->repo->deleteItem(index);
}

vector<Item>
Controller::getFiltered(string category)
{
    return this->repo->getFiltered(category);
}
