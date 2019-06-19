#ifndef REPO
#define REPO

#include <vector>

#include "domain.h"
#include "utils.h"

using namespace std;

class Repository {
private:
    vector<Dog> stock;
    User user;
    string filename = "database.txt";
    CsvHandler csvHandler;
    HtmlHandler htmlHandler;
public:
    /*
     * Default repo constuctor
     * In  - nothing
     * Out - nothing
     */
    Repository();
    /*
     * Copy repo constructor
     * In  - repo to copy
     * Out - nothing
     */
    Repository(const Repository& otherRepository);
    /*
     * Repo destructor
     * In  - nothing
     * Out - nothing
     */
    ~Repository();

    // Administrator
    /*
     * Get entry by index
     * In  - index
     * Out - dog entry
     */
    Dog
    repositoryGetEntry(int index);
    /*
     * Get all dogs
     * In  - nothing
     * Out - current dog stock
     */
    vector<Dog>
    repositoryGetAllEntries();
    /*
     * Create an entry
     * In  - breed, name, age, photo
     * Out - nothing
     */
    bool
    repositoryCreateEntry(string breed, string name, int age, string photo);
    /*
     * Update an entry by index
     * In  - index, breed, name, age, photo
     * Out - nothing
     */
    bool
    repositoryUpdateEntry(int index, string breed, string name, int age, string photo);
    /*
     * Delete an entry by index
     * In  - index
     * Out - nothing
     */
    void
    repositoryDeleteEntry(int index);
    
    // User
    /*
     * Set adoption stock to all pets
     * In  - nothing
     * Out - nothing
     */
    void
    repositoryAdoptFromAllPets();
    /*
     * Set adoption stock to pets of a certain breed and age
     * In  - breed, age
     * Out - nothing
     */
    void
    repositorySelectByBreedAndAge(string breed, int age);
    /*
     * Get the current dog proposed for adoption
     * In  - nothing
     * Out - current pet
     */
    Dog
    repositoryGetCurrentPet();
    /*
     * Get the next dog for adoption
     * In  - nothing
     * Out - next dog
     */
    Dog
    repositoryGetNextPet();
    /*
     * Adopt the current dog
     * In  - nothing
     * Out - nothing
     */
    void
    repositoryAdoptCurrentPet();
    /*
     * Get the adopted pets stock
     * In  - nothing
     * Out - adopted pets stock
     */
    vector<Dog>
    repositoryGetAdoptedPets();

    /*
     * Read from file
     * In  - nothing
     * Out - adopted pets stock
     */
    void
    readFromFile();

    /*
     * Write to file
     * In  - nothing
     * Out - adopted pets stock
     */
    void
    writeToFile(bool toHtml);
};

#endif // ifndef REPO
