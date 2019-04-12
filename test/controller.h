#ifndef CONTROLLER
#define CONTROLLER

#include <vector>

#include "repository.h"
#include "domain.h"

using namespace std;


class Controller {
private:
    Repository repository;
public:

    /*
     * Default controller constuctor
     * In  - nothing
     * Out - nothing
     */
    Controller();

    /*
     * Copy repo constructor
     * In  - repo to copy
     * Out - nothing
     */
    Controller(const Controller& otherController);

    /*
     * Repo destructor
     * In  - nothing
     * Out - nothing
     */
    ~Controller();

    /*
     * Get entry by index
     * In  - index
     * Out - bill entry
     */
    Bill
    controllerGetEntry(int index);

    /*
     * Get all bills sorted by name
     * In  - nothing
     * Out - current bill stock
     */
    vector<Bill>
    controllerGetAllEntries();

    /*
     * Create an entry
     * In  - serialNumber, name, sum, isPaid
     * Out - true if the entry was create, false otherwise
     */
    bool
    controllerCreateEntry(string name, string serialNumber, int sum, bool isPaid);

    /*
     * Update an entry by index
     * In  - index, serialNumber, name, sum, isPaid
     * Out - nothing
     */
    void
    controllerUpdateEntry(int index, string name, string serialNumber, int sum, bool isPaid);

    /*
     * Delete an entry by index
     * In  - index,
     * Out - nothing
     */
    void
    controllerDeleteEntry(int index);

    /*
     * Calculate unpaid bills total
     * In  - nothing
     * Out - unpaid total
     */
    int
    controllerCalculateUnpaid();
};

#endif // ifndef CONTROLLER
