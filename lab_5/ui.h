#ifndef UI
#define UI

#include <QtWidgets/QMainWindow>
#include <QListWidget>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "controller.h"


class Ui : public QWidget
{
    Q_OBJECT

public:
    Ui(QWidget *parent = 0);
    ~Ui();

private:
    Controller controller;
    std::vector<Dog> currentDogsInRepoList;

    //Ui::Seminar6Class ui;

    QListWidget* repoList;
    QLineEdit* breedEdit;
    QLineEdit* nameEdit;
    QLineEdit* photoEdit;
    QLineEdit* ageEdit;
    QPushButton* addButton;
    QPushButton* deleteButton;
    QPushButton* filterButton;
    QPushButton* moveOneDogButton;

    QListWidget* adoptionList;

    void initGUI();
    void populateRepoList();
    int getRepoListSelectedIndex();

    void connectSignalsAndSlots();

private slots:
    // When an item in the list is clicked, the text boxes get filled with the item's information
    void listItemChanged();

    void addNewDog();
};

#endif // ifndef UI
