#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "domain.h"

using namespace std;


Bill::Bill(){ }

Bill::Bill(string name, string serialNumber, int sum, bool isPaid)
{
    this->name         = name;
    this->serialNumber = serialNumber;
    this->sum    = sum;
    this->isPaid = isPaid;
}

Bill::Bill(const Bill& oldBill)
{
    this->name         = oldBill.name;
    this->serialNumber = oldBill.serialNumber;
    this->sum    = oldBill.sum;
    this->isPaid = oldBill.isPaid;
}

Bill::~Bill(){ }

string
Bill::getSerialNumber(){ return this->serialNumber; }

string
Bill::getName(){ return this->name; }

int
Bill::getSum(){ return this->sum; }

bool
Bill::getIsPaid(){ return this->isPaid; }

void
Bill::setSerialNumber(string serialNumber){ this->serialNumber = serialNumber; }

void
Bill::setName(string name){ this->name = name; }

void
Bill::setSum(int sum){ this->sum = sum; }

void
Bill::setIsPaid(bool isPaid){ this->isPaid = isPaid; }
