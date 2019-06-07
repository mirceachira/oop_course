#include <vector>

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

Repository::Repository()
{
    std::ifstream file("/home/mirceachira/Desktop/oop_course/test2/test2/input.csv");

    TextFileHandler row;

    while (file >> row) {
        stock.push_back(Item{ row[0], row[1], std::stoi(row[2]) });
    }

}

vector<Item>
Repository::getStock()
{
    return this->stock;
}


/*
 * Delete an item from the stock
 * in: the index of the item in the stock
 * out: -
 */
void
Repository::deleteItem(int index)
{
    this->stock.erase(this->stock.begin() + index);
}

vector<Item>
Repository::getFiltered(string category)
{
    vector<Item> v;

    for (auto i: this->stock)
    {
        if (i.category == category)
            v.push_back(i);
    }

    return v;
}
