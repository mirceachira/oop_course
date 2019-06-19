#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListIterator>

#include <iostream>

#include "controller.h"
#include "dialog.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->ctrl = new Controller();
    ui->setupUi(this);
    ui->centralWidget->hide();

    for (auto i: this->ctrl->getProgrammers()){
        dialog * d = new dialog;
        d->setProgrammer(i);
        dialogs.push_back(d);
        d->show();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
