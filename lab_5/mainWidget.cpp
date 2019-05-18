#include <stdlib.h>

#include <QtWidgets>
#include <QLineEdit>
#include <QLabel>

#include "mainWidget.h"

using namespace std;

void clearWidgets(QLayout * layout) {
   if (! layout)
      return;
   while (auto item = layout->takeAt(0)) {
      delete item->widget();
      clearWidgets(item->layout());
   }

   delete layout;
}

void
MainWidget::userLayout()
{
    clearWidgets(this->layout());

    QGridLayout * mainLayout = new QGridLayout;

    create_button_ = new QPushButton("adopt from all", this);
    update_button_ = new QPushButton("adopt filtered by breed and age", this);

    connect(create_button_, SIGNAL(released()), this, SLOT(handlePushCreate()));
    connect(create_button_, SIGNAL(released()), this, SLOT(adoptFilteredLayout()));

    mainLayout->addWidget(create_button_, 0, 0);
    mainLayout->addWidget(update_button_, 1, 0);

    setLayout(mainLayout);
    setWindowTitle(tr("User panel"));
}

void
MainWidget::adminLayout()
{
    clearWidgets(this->layout());

    QGridLayout * mainLayout = new QGridLayout;

    // Initializing shi... stuff
    create_button_ = new QPushButton("create", this);
    update_button_ = new QPushButton("update", this);
    get_button_    = new QPushButton("get", this);
    get_all_button_    = new QPushButton("all", this);
    delete_button_ = new QPushButton("delete", this);

    connect(create_button_, SIGNAL(released()), this, SLOT(createLayout()));
    connect(update_button_, SIGNAL(released()), this, SLOT(updateLayout()));
    connect(get_button_, SIGNAL(released()), this, SLOT(getLayout()));
    connect(get_all_button_, SIGNAL(released()), this, SLOT(handlePushGetAll()));
    connect(delete_button_, SIGNAL(released()), this, SLOT(deleteLayout()));

    mainLayout->addWidget(create_button_, 0, 0);

    mainLayout->addWidget(update_button_, 5, 0);
    mainLayout->addWidget(get_button_, 6, 0);
    mainLayout->addWidget(get_all_button_, 7, 0);
    mainLayout->addWidget(delete_button_, 8, 0);

    setLayout(mainLayout);
    setWindowTitle(tr("Admin panel"));
}

void
MainWidget::userIntermediateLayout()
{
    clearWidgets(this->layout());

    // Choose html or csv panel
    html_button = new QPushButton("html", this);
    csv_button  = new QPushButton("csv", this);

    connect(html_button, SIGNAL(released()), this, SLOT(userPressedHTML()));
    connect(csv_button, SIGNAL(released()), this, SLOT(userPressedCSV()));

    QGridLayout * mainLayout = new QGridLayout;

    mainLayout->addWidget(html_button, 0, 0);
    mainLayout->addWidget(csv_button, 0, 1);

    setLayout(mainLayout);
    setWindowTitle(tr("User file type choice"));
}

void
MainWidget::userPressedHTML()
{
   this->fileType = 0;
   userLayout();
}

void
MainWidget::userPressedCSV()
{
   this->fileType = 1;
   userLayout();
}

// Constructor for main widget
MainWidget::MainWidget(QWidget * parent) :
    QWidget(parent)
{
   controller = new Controller();

    // Choose admin or user panel
    admin_button = new QPushButton("admin", this);
    user_button  = new QPushButton("user", this);

    connect(admin_button, SIGNAL(released()), this, SLOT(adminLayout()));
    connect(user_button, SIGNAL(released()), this, SLOT(userIntermediateLayout()));

    QGridLayout * mainLayout = new QGridLayout;

    mainLayout->addWidget(admin_button, 0, 0);
    mainLayout->addWidget(user_button, 0, 1);

    setLayout(mainLayout);
    setWindowTitle(tr("Start mode choice"));
}

// Destructor
MainWidget::~MainWidget()
{
    delete create_button_;
    delete update_button_;
    delete get_button_;
    delete delete_button_;

    delete textBrowser_;
}


void
MainWidget::createLayout()
{
    clearWidgets(this->layout());

    QGridLayout * mainLayout = new QGridLayout;

    submit_button = new QPushButton("submit", this);
    go_back_button = new QPushButton("back", this);

    breed_input = new QLineEdit(this);
    name_input = new QLineEdit(this);
    age_input = new QLineEdit(this);
    photo_input = new QLineEdit(this);

    connect(submit_button, SIGNAL(released()), this, SLOT(handlePushCreate()));
    connect(go_back_button, SIGNAL(released()), this, SLOT(adminLayout()));

    mainLayout->addWidget(go_back_button, 0, 0);

    mainLayout->addWidget(breed_input, 1, 1);
    mainLayout->addWidget(name_input, 2, 1);
    mainLayout->addWidget(age_input, 3, 1);
    mainLayout->addWidget(photo_input, 4, 1);

    mainLayout->addWidget(submit_button, 5, 0);

    setLayout(mainLayout);
    setWindowTitle(tr("Create panel"));
}

void
MainWidget::handlePushCreate()
{
    controller->controllerCreateEntry(
      breed_input->displayText().toStdString(),
      name_input->displayText().toStdString(),
      stoi(age_input->displayText().toStdString()),
      photo_input->displayText().toStdString()
   );
    adminLayout();
}

void
MainWidget::updateLayout()
{
    clearWidgets(this->layout());

    QGridLayout * mainLayout = new QGridLayout;

    submit_button = new QPushButton("submit", this);
    go_back_button = new QPushButton("back", this);

    index_input = new QLineEdit(this);
    breed_input = new QLineEdit(this);
    name_input = new QLineEdit(this);
    age_input = new QLineEdit(this);
    photo_input = new QLineEdit(this);

    connect(submit_button, SIGNAL(released()), this, SLOT(handlePushUpdate()));
    connect(go_back_button, SIGNAL(released()), this, SLOT(adminLayout()));

    mainLayout->addWidget(go_back_button, 0, 0);

    mainLayout->addWidget(index_input, 1, 1);
    mainLayout->addWidget(breed_input, 2, 1);
    mainLayout->addWidget(name_input, 3, 1);
    mainLayout->addWidget(age_input, 4, 1);
    mainLayout->addWidget(photo_input, 5, 1);

    mainLayout->addWidget(submit_button, 6, 0);

    setLayout(mainLayout);
    setWindowTitle(tr("Create panel"));
}

void
MainWidget::handlePushUpdate()
{
    controller->controllerUpdateEntry(
      stoi(index_input->displayText().toStdString()),
      breed_input->displayText().toStdString(),
      name_input->displayText().toStdString(),
      stoi(age_input->displayText().toStdString()),
      photo_input->displayText().toStdString()
   );
    adminLayout();
}

void
MainWidget::deleteLayout()
{
    clearWidgets(this->layout());

    QGridLayout * mainLayout = new QGridLayout;

    submit_button = new QPushButton("submit", this);
    go_back_button = new QPushButton("back", this);

    index_input = new QLineEdit(this);

    connect(submit_button, SIGNAL(released()), this, SLOT(handlePushDelete()));
    connect(go_back_button, SIGNAL(released()), this, SLOT(adminLayout()));

    mainLayout->addWidget(go_back_button, 0, 0);

    mainLayout->addWidget(index_input, 1, 1);

    mainLayout->addWidget(submit_button, 2, 0);

    setLayout(mainLayout);
    setWindowTitle(tr("Delete panel"));
}

void
MainWidget::handlePushDelete()
{
    controller->controllerDeleteEntry(
      stoi(index_input->displayText().toStdString())
   );
    adminLayout();
}

void
MainWidget::getLayout()
{
    clearWidgets(this->layout());

    QGridLayout * mainLayout = new QGridLayout;

    submit_button = new QPushButton("submit", this);
    go_back_button = new QPushButton("back", this);

    index_input = new QLineEdit(this);

    connect(submit_button, SIGNAL(released()), this, SLOT(handlePushGet()));
    connect(go_back_button, SIGNAL(released()), this, SLOT(adminLayout()));

    mainLayout->addWidget(go_back_button, 0, 0);

    mainLayout->addWidget(index_input, 1, 1);

    mainLayout->addWidget(submit_button, 2, 0);

    setLayout(mainLayout);
    setWindowTitle(tr("Get panel"));
}

void
MainWidget::handlePushGet()
{
   int index = stoi(index_input->displayText().toStdString());
   clearWidgets(this->layout());

    QGridLayout * mainLayout = new QGridLayout;

    go_back_button = new QPushButton("back", this);
    connect(go_back_button, SIGNAL(released()), this, SLOT(adminLayout()));
    mainLayout->addWidget(go_back_button, 0, 0);


   Dog foundDog = controller->controllerGetEntry(index);

   string txt = foundDog.getBreed() + foundDog.getName() + foundDog.getPhoto();
   QLabel *label = new QLabel(this);

   label->setText(txt.c_str());

   mainLayout->addWidget(label, 1, 0);   
    setLayout(mainLayout);
    setWindowTitle(tr("Get result"));
}


void
MainWidget::handlePushGetAll()
{
   clearWidgets(this->layout());

    QGridLayout * mainLayout = new QGridLayout;

    go_back_button = new QPushButton("back", this);
    connect(go_back_button, SIGNAL(released()), this, SLOT(adminLayout()));
    mainLayout->addWidget(go_back_button, 0, 0);


   vector<Dog> dogs = controller->controllerGetAllEntries();

   string txt = "";
   for (auto d : dogs) 
   {
      txt.append(d.getBreed() + d.getName() + d.getPhoto());
      txt.append("\n");
   }
   QLabel *label = new QLabel(this);

   label->setText(txt.c_str());

   mainLayout->addWidget(label, 1, 0);   
    setLayout(mainLayout);
    setWindowTitle(tr("Get result"));
}


void
MainWidget::adoptFromAllPets()
{
   controller->controllerAdoptFromAllPets();
}


void
MainWidget::adoptFilteredLayout()
{
    clearWidgets(this->layout());

    QGridLayout * mainLayout = new QGridLayout;

    submit_button = new QPushButton("submit", this);
    go_back_button = new QPushButton("back", this);

    breed_input = new QLineEdit(this);
    age_input = new QLineEdit(this);

    connect(submit_button, SIGNAL(released()), this, SLOT(handlePushFilterSelect()));
    connect(go_back_button, SIGNAL(released()), this, SLOT(adminLayout()));

    mainLayout->addWidget(go_back_button, 0, 0);

    mainLayout->addWidget(breed_input, 2, 1);
    mainLayout->addWidget(age_input, 3, 1);

    mainLayout->addWidget(submit_button, 4, 0);

    setLayout(mainLayout);
    setWindowTitle(tr("Filter panel"));
}

void
MainWidget::handlePushFilterSelect()
{
   controller->controllerSelectByBreedAndAge(
      breed_input->displayText().toStdString(),
      stoi(age_input->displayText().toStdString())
   );
   userLayout();
}



/*
TO DO:
  * get this to work
  * add current display
  * add next functionality
  * add dislay functionality for files

  * remake all in designer
  * rename
  * cleanup ffs
*/