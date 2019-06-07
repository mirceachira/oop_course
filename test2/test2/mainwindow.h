#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller.h"

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

private slots:
    void on_theButton_clicked();

    void on_filter_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
