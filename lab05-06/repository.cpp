#include <iostream>

#include "repository.h"
#include "domain.h"
#include "utils.h"


Repository::Repository(){ }

Repository::Repository(const Repository& otherRepository)
{
    this->stock = otherRepository.stock;
    this->user  = otherRepository.user;
}

Repository::~Repository(){ }

Dog
Repository::repositoryGetEntry(int index){ return stock[index]; }

DynamicVector<Dog>
Repository::repositoryGetAllEntries()
{
    return stock;
}

void
Repository::repositoryCreateEntry(string breed, string name, int age, string photo)
{
    stock.add(Dog(breed, name, age, photo));
}

void
Repository::repositoryUpdateEntry(int index, string breed, string name, int age, string photo)
{
    stock[index].setBreed(breed);
    stock[index].setName(name);
    stock[index].setAge(age);
    stock[index].setPhoto(photo);
}

void
Repository::repositoryDeleteEntry(int index){ stock.remove(index); }

void
Repository::repositoryAdoptFromAllPets(){ user.setStock(stock); }

void
Repository::repositorySelectByBreedAndAge(string breed, int age)
{
    DynamicVector<Dog> newStock;

    for (int i = 0; i < stock.getSize(); i++) {
        if (stock[i].getAge() < age) {
            if (breed.length() == 0)
                newStock.add(stock[i]);
            else if (stock[i].getBreed().find(breed) == 0)
                newStock.add(stock[i]);
        }
    }

    user.setStock(newStock);
}

Dog
Repository::repositoryGetCurrentPet(){ return user.getCurrent(); };

Dog
Repository::repositoryGetNextPet(){ return user.getNext(); }

void
Repository::repositoryAdoptCurrentPet(){ user.adoptCurrent(); }

DynamicVector<Dog>
Repository::repositoryGetAdoptedPets(){ return user.getAdopted(); }
