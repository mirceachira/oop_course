#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <exception>

#include "repository.h"
#include "domain.h"
#include "utils.h"

using namespace std;


Repository::Repository(){ this->readFromFile(); }

Repository::Repository(const Repository& otherRepository)
{
    this->stock = otherRepository.stock;
    this->user  = otherRepository.user;
}

Repository::~Repository(){ }


class RepositoryException : public exception
{
public:
    const char *
    what(){ return "Repository exception"; }
};

class InputException : public RepositoryException {
public:
    const char *
    what(){ return "Invalid input exception"; }
};

Dog
Repository::repositoryGetEntry(int index){ return stock[index]; }

vector<Dog>
Repository::repositoryGetAllEntries()
{
    return stock;
}

bool
validateEntry(string breed, string name, int age, string photo)
{
    if (breed.length() <= 2)
        return true;

    if (name.length() <= 2)
        return true;

    if (age < 0 || age > 30)
        return true;

    if (photo.find("http") != 0 && photo.find("www") != 0)
        return true;

    return true;
}

bool
Repository::repositoryCreateEntry(string breed, string name, int age, string photo)
{
    try
    {
        if (validateEntry(breed, name, age, photo) == 0)
            throw InputException();
    }
    catch (InputException& e)
    {
        cout << e.what() << endl;
        return false;
    }


    stock.push_back(Dog(breed, name, age, photo));

    return true;
}

bool
Repository::repositoryUpdateEntry(int index, string breed, string name, int age, string photo)
{
    try
    {
        if (validateEntry(breed, name, age, photo) == 0)
            throw InputException();
    }
    catch (InputException& e)
    {
        cout << e.what() << endl;
        return false;
    }
    stock[index].setBreed(breed);
    stock[index].setName(name);
    stock[index].setAge(age);
    stock[index].setPhoto(photo);

    return true;
}

void
Repository::repositoryDeleteEntry(int index){ stock.erase(stock.begin() + index); }

void
Repository::repositoryAdoptFromAllPets(){ user.setStock(stock); }

void
Repository::repositorySelectByBreedAndAge(string breed, int age)
{
    vector<Dog> newStock;
    vector<Dog> tmpStock;

    std::copy_if(
        stock.begin(),
        stock.end(),
        back_inserter(tmpStock),
        [&age](Dog i){
        return i.getAge() < age;
    }
    );

    std::copy_if(
        stock.begin(),
        stock.end(),
        back_inserter(newStock),
        [&breed](Dog i){
        return i.getBreed().find(breed) == 0;
    }
    );

    user.setStock(newStock);
}

Dog
Repository::repositoryGetCurrentPet(){ return user.getCurrent(); };

Dog
Repository::repositoryGetNextPet(){ return user.getNext(); }

void
Repository::repositoryAdoptCurrentPet(){ user.adoptCurrent(); }

vector<Dog>
Repository::repositoryGetAdoptedPets(){ return user.getAdopted(); }

std::istream&
operator >> (std::istream& str, CsvHandler& data)
{
    data.readNextRow(str);
    return str;
}

void
Repository::readFromFile()
{
    std::ifstream file("plop.csv");

    CsvHandler row;

    std::vector<Dog> dv;

    while (file >> row) {
        this->repositoryCreateEntry(
            row[0], row[1], std::stoi(row[2]), row[3]
        );
    }
}

void
Repository::writeToFile()
{
    CsvHandler row;

    row.writeToFile(stock);

    bool toHtml = true;
    if (toHtml)
    {
        HtmlHandler html_row;
        html_row.writeToFile(stock);
    }
}
