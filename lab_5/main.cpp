#include <iostream>

#include <QtWidgets>

#include "mainWidget.h"

#include "ui.h"

using namespace std;


int main(int argc, char *argv[])
{
    // Ui ui;

    // ui.uiRunApplication();

    // Creates an instance of QApplication
    QApplication a(argc, argv);

    // This is our MainWidget class containing our GUI and functionality
    MainWidget w;
    w.show(); // Show main window

    // run the application and return execs() return value/code
    return a.exec();
}