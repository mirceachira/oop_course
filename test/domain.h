#ifndef DOMAIN
#define DOMAIN
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;


class Bill {
private:
    string name;
    string serialNumber;
    int sum;
    bool isPaid;
public:

    /*
     * Default Bill constructor
     * In  - nothing
     * Out - nothing
     */
    Bill();

    /*
     * Parametrised bill constructor
     * In  - name, serialNumber, isPaid
     * Out - nothing
     */
    Bill(string name, string serialNumber, int sum, bool isPaid);

    /*
     * Copy constructor for bill class
     * In  - bill to copy
     * Out - nothing
     */
    Bill(const Bill& oldBill);

    /*
     * Destructor for bill class
     * In  - nothing
     * Out - nothing
     */
    ~Bill();

    /*
     * Get the name of the current bill
     * In  - nothing
     * Out - name of current bill as string
     */
    string
    getName();

    /*
     * Get the serial number of the current bill
     * In  - nothing
     * Out - name of current bill as string
     */
    string
    getSerialNumber();

    /*
     * Get the sum of the current bill
     * In  - nothing
     * Out - sum of current bill as int
     */
    int
    getSum();

    /*
     * Get the isPaid attribute of the current bill
     * In  - nothing
     * Out - isPaid of current bill as boolean
     */
    bool
    getIsPaid();

    /*
     * Set the name for this bill
     * In  - name as string
     * Out - nothing
     */
    void
    setName(string name);

    /*
     * Set the serial number for this bill
     * In  - name as string
     * Out - nothing
     */
    void
    setSerialNumber(string serialNumber);

    /*
     * Set the sum for this bill
     * In  - sum as integer
     * Out - nothing
     */
    void
    setSum(int sum);

    /*
     * Set the isPaid for this bill
     * In  - isPaid as boolean
     * Out - nothing
     */
    void
    setIsPaid(bool isPaid);
};

#endif // ifndef DOMAIN
