#ifndef UI
#define UI

#include "controller.h"

void
printMenu();

int
getNextOption();

void
displayEntry(Bill entry);


class Ui {
private:
    Controller controller;
public:
    Ui();
    Ui(const Ui& otherUi);
    ~Ui();
    void
    uiRunApplication();
    void
    uiGetEntry();
    void
    uiGetAllEntries();
    void
    uiCreateEntry();
    void
    uiUpdateEntry();
    void
    uiDeleteEntry();
    void
    uiCalculateUnpaid();
};

#endif // ifndef UI
