#include <vector>

#include <QMessageBox>

#include "ui.h"
#include "controller.h"
#include "domain.h"
#include "utils.h"


Ui::Ui(QWidget * parent) : QWidget(parent)
{
    Controller controller;

    this->controller = controller;
    this->initGUI();
    this->currentDogsInRepoList = this->controller.controllerGetAllEntries();
    this->populateRepoList();
}

Ui::~Ui()
{ }

void
Ui::initGUI()
{
    // General layout of the window
    QHBoxLayout * layout = new QHBoxLayout{ this };

    // Prepare left side components - vertical layout with:
    // - list
    // - form layout with the song data
    // - grid layout with buttons: add, delete, update, filter
    QWidget * leftWidget   = new QWidget{ };
    QVBoxLayout * leftSide = new QVBoxLayout{ leftWidget };

    // list
    this->repoList = new QListWidget{ };
    // set the selection model
    this->repoList->setSelectionMode(QAbstractItemView::SingleSelection);

    // song data
    QWidget * songDataWidget = new QWidget{ };
    QFormLayout * formLayout = new QFormLayout{ songDataWidget };
    this->breedEdit = new QLineEdit{ };
    this->nameEdit  = new QLineEdit{ };
    this->photoEdit = new QLineEdit{ };
    this->ageEdit   = new QLineEdit{ };
    formLayout->addRow("&breed:", breedEdit);
    formLayout->addRow("&name:", nameEdit);
    formLayout->addRow("&photo:", photoEdit);
    formLayout->addRow("&age:", ageEdit);

    // buttons
    QWidget * buttonsWidget  = new QWidget{ };
    QGridLayout * gridLayout = new QGridLayout{ buttonsWidget };
    this->addButton    = new QPushButton{ "Add" };
    this->deleteButton = new QPushButton{ "Delete" };
    this->filterButton = new QPushButton{ "Filter" };

    gridLayout->addWidget(addButton, 0, 0);
    gridLayout->addWidget(deleteButton, 0, 1);
    gridLayout->addWidget(filterButton, 0, 2);

    // add everything to the left layout
    leftSide->addWidget(new QLabel{ "All dogs" });
    leftSide->addWidget(repoList);
    leftSide->addWidget(songDataWidget);
    leftSide->addWidget(buttonsWidget);

    // middle component: just two button - to add the songs from the reposiotory to the playlist
    QWidget * middleWidget      = new QWidget{ };
    QVBoxLayout * vLayoutMiddle = new QVBoxLayout{ middleWidget };
    this->moveOneSongButton = new QPushButton{ ">> Move one song" };
    QWidget * upperPart = new QWidget{ };
    QVBoxLayout * vLayoutUpperPart = new QVBoxLayout{ upperPart };
    vLayoutUpperPart->addWidget(this->moveOneSongButton);
    vLayoutMiddle->addWidget(upperPart);

    // Prepare right side components - vertical layout with:
    // - list
    // - grid layout with buttons: add, delete, update, filter
    QWidget * rightWidget   = new QWidget{ };
    QVBoxLayout * rightSide = new QVBoxLayout{ rightWidget };

    // list
    this->playList = new QListWidget{ };

    // add everything to the right layout
    rightSide->addWidget(new QLabel{ "Playlist" });
    rightSide->addWidget(playList);

    // add the three layouts to the main layout
    layout->addWidget(leftWidget);
    layout->addWidget(middleWidget);
    layout->addWidget(rightWidget);

    // connect the signals and slots
    this->connectSignalsAndSlots();
} // Ui::initGUI

void
Ui::populateRepoList()
{
    // clear the list, if there are elements in it
    if (this->repoList->count() > 0)
        this->repoList->clear();

    for (auto song : this->currentSongsInRepoList) {
        QString itemInList      = QString::fromStdString(song.getArtist() + " - " + song.getTitle());
        QListWidgetItem * item3 = new QListWidgetItem(itemInList);
        this->repoList->addItem(item3);
    }

    // set the selection on the first item in the list
    if (this->currentSongsInRepoList.size() > 0)
        this->repoList->setCurrentRow(0);
}

int
Ui::getRepoListSelectedIndex()
{
    if (this->repoList->count() == 0)
        return -1;

    // get selected index
    QModelIndexList index = this->repoList->selectionModel()->selectedIndexes();
    if (index.size() == 0) {
        this->titleEdit->clear();
        this->artistEdit->clear();
        this->durationEdit->clear();
        this->linkEdit->clear();
        return -1;
    }

    int idx = index.at(0).row();
    return idx;
}

void
Ui::listItemChanged()
{
    int idx = this->getRepoListSelectedIndex();

    if (idx == -1)
        return;

    std::vector<Song> songs = this->currentSongsInRepoList;

    // get the song at the selected index
    if (idx >= songs.size())
        return;

    Song s = songs[idx];

    this->artistEdit->setText(QString::fromStdString(s.getArtist()));
    this->titleEdit->setText(QString::fromStdString(s.getTitle()));
    this->durationEdit->setText(QString::fromStdString(s.getDuration().toString()));
    this->linkEdit->setText(QString::fromStdString(s.getSource()));
}

void
Ui::connectSignalsAndSlots()
{
    // add a connection: function listItemChanged() will be called when an item in the list is selected
    QObject::connect(this->repoList, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));

    // add button connections
    QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addNewSong()));
}

void
Ui::addNewSong()
{
    std::string artist   = this->artistEdit->text().toStdString();
    std::string title    = this->titleEdit->text().toStdString();
    std::string duration = this->durationEdit->text().toStdString();
    // get minutes and seconds
    std::vector<std::string> durationTokens = tokenize(duration, ':');

    if (durationTokens.size() != 2) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", "The duration must have minutes and seconds, separated by \":\"!");
        return;
    }
    std::string source = this->linkEdit->text().toStdString();

    try
    {
        this->ctrl.addSongToRepository(artist, title, stod(durationTokens[0]), stod(durationTokens[1]), source);
        // refresh the list
        this->currentSongsInRepoList = this->ctrl.getAllSongs();
        this->populateRepoList();
    }
    catch (SongException& e)
    {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", QString::fromStdString(e.getErrorsAsString()));
    }
    catch (DuplicateSongException& e)
    {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", e.what());
    }
}
