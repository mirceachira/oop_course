#include <QFile>
#include <QTextStream>

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_nextDog_clicked()
{
    QString theString = ui->currentDog->toPlainText();
    ui->currentDog->setText("");
}

void MainWindow::loadTextFile()
{
    QFile inputFile("plop.csv");
    inputFile.open(QIODevice::ReadOnly);

    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();

    ui->currentDog->setPlainText(line);
    QTextCursor cursor = ui->currentDog->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}
