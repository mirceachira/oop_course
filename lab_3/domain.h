#ifndef DOMAIN
#define DOMAIN
#include <string.h>
#include <iostream>

#include "utils.h"

using namespace std;

class Dog {
private:
    string breed;
    string name;
    int age;
    string photo;
public:

    /*
     * Default dog constructor
     * In  - nothing
     * Out - nothing
     */
    Dog();

    /*
     * Parametrised dog constructor
     * In  - breed, name, age, photo
     * Out - nothing
     */
    Dog(string breed, string name, int age, string photo);

    /*
     * Copy constructor for dog class
     * In  - dog to copy
     * Out - nothing
     */
    Dog(const Dog& oldDog);

    /*
     * Destructor for dog class
     * In  - nothing
     * Out - nothing
     */
    ~Dog();

    /*
     * Get the breed of the current dog
     * In  - nothing
     * Out - breed of current dog as string
     */
    string
    getBreed();

    /*
     * Get the name of the current dog
     * In  - nothing
     * Out - name of current dog as string
     */
    string
    getName();

    /*
     * Get the age of the current dog
     * In  - nothing
     * Out - age of current dog as int
     */
    int
    getAge();

    /*
     * Get the photo of the current dog
     * In  - nothing
     * Out - photo of current dog as string
     */
    string
    getPhoto();

    /*
     * Set the breed for this dog
     * In  - breed as string
     * Out - nothing
     */
    void
    setBreed(string breed);

    /*
     * Set the name for this dog
     * In  - name as string
     * Out - nothing
     */
    void
    setName(string name);

    /*
     * Set the age for this dog
     * In  - age as integer
     * Out - nothing
     */
    void
    setAge(int age);

    /*
     * Set the photo for this dog
     * In  - photo url as string
     * Out - nothing
     */
    void
    setPhoto(string photo);
};


class User {
private:
    DynamicVector<Dog> stock;
    int index;
    DynamicVector<Dog> adopted;
public:

    /*
     * Default constructor for user
     * In  - 
     * Out - nothing
     */
    User();
    /*
     * Parametrised constructor for user
     * In  - stock, index, adopted
     * Out - nothing
     */
    User(DynamicVector<Dog> stock, int index, DynamicVector<Dog> adopted);
    /*
     * Copy constructor for user
     * In  - user to copy
     * Out - nothing
     */
    User(const User& oldUser);
    /*
     * Get the current pet
     * In  - nothing
     * Out - current pet
     */
    Dog
    getCurrent();
    /*
     * Get the next pet
     * In  - nothing
     * Out - next pet
     */
    Dog
    getNext();
    /*
     * Adopt the current pet
     * In  - nothing
     * Out - nothing
     */
    void
    adoptCurrent();
    /*
     * Set the stock for user
     * In  - new stock to set
     * Out - nothing
     */
    void
    setStock(const DynamicVector<Dog> newStock);
    /*
     * Get the adopted pets
     * In  - nothing
     * Out - current adopted pets
     */
    DynamicVector<Dog>
    getAdopted();
};


#endif // ifndef DOMAIN
