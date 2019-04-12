#ifndef REPO
#define REPO

#include "domain.h"
#include <vector>

using namespace std;


class Repository {
private:
    vector<Bill> stock;
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

    /*
     * Get entry by index
     * In  - index
     * Out - bill entry
     */
    Bill
    repositoryGetEntry(int index);

    /*
     * Get all bills sorted by name
     * In  - nothing
     * Out - current bill stock
     */
    vector<Bill>
    repositoryGetAllEntries();

    /*
     * Create an entry
     * In  - serialNumber, name, sum, isPaid
     * Out - true if the entry was create, false otherwise
     */
    bool
    repositoryCreateEntry(string name, string serialNumber, int sum, bool isPaid);

    /*
     * Update an entry by index
     * In  - index, serialNumber, name, sum, isPaid
     * Out - nothing
     */
    void
    repositoryUpdateEntry(int index, string name, string serialNumber, int sum, bool isPaid);

    /*
     * Delete an entry by index
     * In  - index,
     * Out - nothing
     */
    void
    repositoryDeleteEntry(int index);

    /*
    * Calculate unpaid bills total
     * In  - nothing
     * Out - unpaid total
    */
    int
    repositoryCalculateUnpaid();
};

#endif // ifndef REPO
