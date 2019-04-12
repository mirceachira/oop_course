#include <iostream>
#include <vector>
#include <algorithm>

#include "repository.h"
#include "domain.h"

using namespace std;


Repository::Repository(){ }

Repository::Repository(const Repository& otherRepository)
{
    this->stock = otherRepository.stock;
}

Repository::~Repository(){ }

Bill
Repository::repositoryGetEntry(int index){ return stock[index]; }

vector<Bill>
Repository::repositoryGetAllEntries()
{
    sort(
        stock.begin(),
        stock.end(),
        [](Bill a, Bill b) { return a.getName() < b.getName(); }
    ); 
    return stock;
}

bool
Repository::repositoryCreateEntry(string name, string serialNumber, int sum, bool isPaid)
{
    for (auto i : stock)
        if (i.getSerialNumber() == serialNumber)
            return false;

    stock.push_back(Bill(name, serialNumber, sum, isPaid));
    return true;
}

void
Repository::repositoryUpdateEntry(int index, string name, string serialNumber, int sum, bool isPaid)
{
    stock[index].setSerialNumber(serialNumber);
    stock[index].setName(name);
    stock[index].setSum(sum);
    stock[index].setIsPaid(isPaid);
}

void
Repository::repositoryDeleteEntry(int index){ stock.erase(stock.begin() + index); }


int 
Repository::repositoryCalculateUnpaid() {
    int sum = 0;

    for (auto i: stock)
        if (i.getIsPaid() == false)
            sum += i.getSum();

    return sum;
}