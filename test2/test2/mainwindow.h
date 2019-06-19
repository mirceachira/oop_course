#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>

#include <QMainWindow>

#include "controller.h"
#include "dialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Controller * ctrl;
    vector<dialog*> dialogs;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
