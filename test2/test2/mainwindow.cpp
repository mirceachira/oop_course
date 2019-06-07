#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListIterator>

#include <iostream>

#include "controller.h"
#include "tests.h"
//#include "utils.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->ctrl = new Controller();
    ui->setupUi(this);

    for (auto i: this->ctrl->getStock()){
        string newVal = (i.name + ", " + i.category + ", " + to_string(i.quantity));
        ui->theList->addItem(QString(newVal.c_str()));
    }

    runTests();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_theButton_clicked()
{
    for(int i = 0; i < ui->theList->count(); ++i)
    {
        QListWidgetItem* item = ui->theList->item(i);
        if (item->isSelected())
           this->ctrl->deleteItem(i);
    }

    ui->theList->clear();
    for (auto i: this->ctrl->getStock()){
        string newVal = (i.name + ", " + i.category + ", " + to_string(i.quantity));
        ui->theList->addItem(QString(newVal.c_str()));
    }

}

void MainWindow::on_filter_clicked()
{
    string category = ui->filterInput->text().toUtf8().constData();

    if (!category.length())
        return;

    ui->theList->clear();
    for (auto i: this->ctrl->getFiltered(category)){
        string newVal = (i.name + ", " + i.category + ", " + to_string(i.quantity));
        ui->theList->addItem(QString(newVal.c_str()));
    }
}
