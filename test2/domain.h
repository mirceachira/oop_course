#ifndef DOMAIN
#define DOMAIN

#include <string>

using namespace std;

class Item
{
public:
    int quantity;
    string category;
    string name;

    Item(string category, string name, int quantity)
    {
        this->name = name;
        this->category = category;
        this->quantity = quantity;
    }
};

#endif // ifndef DOMAIN
