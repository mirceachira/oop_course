#include <iostream>
#include <stdio.h>
#include <string.h>

#include "domain.h"

using namespace std;

Dog::Dog(){ }

Dog::Dog(string breed, string name, int age, string photo)
{
    this->breed = breed;
    this->name  = name;
    this->age   = age;
    this->photo = photo;
}

Dog::Dog(const Dog& oldDog)
{
    this->breed = oldDog.breed;
    this->name  = oldDog.name;
    this->age   = oldDog.age;
    this->photo = oldDog.photo;
}

Dog::~Dog(){ }

string
Dog::getBreed(){ return this->breed; }

string
Dog::getName(){ return this->name; }

int
Dog::getAge(){ return this->age; }

string
Dog::getPhoto(){ return this->photo; }

void
Dog::setBreed(string breed){ this->breed = breed; }

void
Dog::setName(string name){ this->name = name; }

void
Dog::setAge(int age){ this->age = age; }

void
Dog::setPhoto(string photo){ this->photo = photo; }

User::User(){ }

User::User(DynamicVector<Dog> stock, int index, DynamicVector<Dog> adopted)
{
    stock   = stock;
    index   = index;
    adopted = adopted;
}

User::User(const User& oldUser)
{
    stock   = oldUser.stock;
    index   = oldUser.index;
    adopted = oldUser.adopted;
}

Dog
User::getCurrent(){ return stock[index]; }

Dog
User::getNext()
{
    index >= stock.getSize() ? index = 0 : index++;
    return stock[index];
}

void
User::adoptCurrent()
{
    adopted.add(stock[index]);
    stock.remove(index);
}

void
User::setStock(const DynamicVector<Dog> newStock){ stock = newStock; index = 0; };

DynamicVector<Dog>
User::getAdopted(){ return this->adopted; }
