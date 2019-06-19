#include <iostream>


#include "dialog.h"
#include "ui_dialog.h"


using namespace std;

dialog::dialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dialog)
{
    ui->setupUi(this);
}


void
dialog::setProgrammer(Programmer p) {
    this->p = p;
    this->setWindowTitle(QString(p.name.c_str()));
}

void
dialog::update() {
    ui->taskList->clear();
    for (auto i: this->ctrl->getTasks()){
        string disp = i.status + " " + i.description + " " + to_string(i.id);
        if (i.status == "in progress")
            disp += i.name;
        ui->taskList->addItem(QString(disp.c_str()));
    }
}


dialog::~dialog()
{
    delete ui;
}

void dialog::on_addButton_clicked()
{
    string description = ui->taskName->text().toUtf8().constData();
    string status = "open";
    int id = this->p.id;

    this->ctrl->addTask(description, status, id);
    this->ctrl->update();
}

void dialog::on_removeButton_clicked()
{
    for (int i=0; i < this->ctrl->getTasks().size(); i++) {
        if (ui->taskList->item(i)->isSelected())
            this->ctrl->removeTask(i);
    }
    this->ctrl->update();
}

void dialog::on_startButton_clicked()
{
    for (int i=0; i < this->ctrl->getTasks().size(); i++) {
        if (ui->taskList->item(i)->isSelected())
            try{
                this->ctrl->startTask(i, this->p.id, this->p.name);
        } catch (MyException& e) {
                ui->taskName->setText("Invalid task!");
        }
    }
    this->ctrl->update();
}

void dialog::on_pushButton_clicked()
{

    for (int i=0; i < this->ctrl->getTasks().size(); i++) {
        if (this->ctrl->getTasks()[i].name == this->p.name)
            this->ctrl->removeTask(i);
    }
    this->ctrl->update();
}
