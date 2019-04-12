#include <iostream>
#include <assert.h>

#include "ui.h"
#include "controller.h"
#include "repository.h"
#include "domain.h"

using namespace std;

void
populateApplication(Controller& currentController)
{
    currentController.controllerCreateEntry(
        "taxa facultate a",
        "XXX1234",
        750,
        true
    );
    currentController.controllerCreateEntry(
        "taxa facultate c",
        "123",
        750,
        true
    );
    currentController.controllerCreateEntry(
        "taxa facultate d",
        "456",
        750,
        true
    );
    currentController.controllerCreateEntry(
        "taxa facultate e",
        "789",
        750,
        false
    );
    currentController.controllerCreateEntry(
        "taxa facultate 1",
        "101112",
        750,
        false
    );
    currentController.controllerCreateEntry(
        "taxa facultate 2",
        "131415",
        750,
        true
    );
} // populateApplication

void
runTests(Controller& controller)
{
    cout << "Running tests..." << '\n';

    // Test add
    cout << "\tTesting get..." << '\n';
    Bill myBill = controller.controllerGetEntry(0);
    assert(myBill.getName() == "taxa facultate a");
    assert(myBill.getSerialNumber() == "XXX1234");
    assert(myBill.getSum() == 750);
    assert(myBill.getIsPaid() == true);

    cout << "\tTesting add..." << '\n';
    controller.controllerCreateEntry(
        "taxa facultate test",
        "XXX",
        750,
        true
    );
    Bill myBill2 = controller.controllerGetEntry(6);
    assert(myBill2.getName() == "taxa facultate test");
    assert(myBill2.getSerialNumber() == "XXX");
    assert(myBill2.getSum() == 750);
    assert(myBill2.getIsPaid() == true);

    cout << "\tTesting delete..." << '\n';
    controller.controllerDeleteEntry(0);
    Bill myBill3 = controller.controllerGetEntry(0);
    assert(myBill3.getName() == "taxa facultate c");
    assert(myBill3.getSerialNumber() == "123");
    assert(myBill3.getSum() == 750);
    assert(myBill3.getIsPaid() == true);

    cout << "\tTesting get all..." << '\n';
    vector<Bill> orderedBills = controller.controllerGetAllEntries();
    assert(orderedBills[0].getSerialNumber() == "101112");
    assert(orderedBills[1].getSerialNumber() == "131415");
    assert(orderedBills[2].getSerialNumber() == "123");
    assert(orderedBills[3].getSerialNumber() == "456");
    assert(orderedBills[4].getSerialNumber() == "789");

    cout << "\tTesting calculate unpaid..." << '\n';
    assert(controller.controllerCalculateUnpaid() == 1500);

    cout << "Finished runnning tests..." << '\n';
}
