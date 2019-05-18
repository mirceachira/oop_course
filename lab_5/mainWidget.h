#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLineEdit>

#include "controller.h"


class QPushButton;
class QTextBrowser;

// This is the declaration of our MainWidget class
// The definition/implementation is in mainwidget.cpp
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit
    MainWidget(QWidget * parent = 0); // Constructor
    ~MainWidget();                    // Destructor

    Controller * controller;

private slots:
    void
    adminLayout();

    void
    userLayout();
    void
    userIntermediateLayout();
    void
    userPressedHTML();
    void
    userPressedCSV();

    // Admin options layouts
    void
    createLayout();
    void
    handlePushCreate();

    void
    updateLayout();
    void
    handlePushUpdate();

    void
    deleteLayout();
    void
    handlePushDelete();

    void
    getLayout();
    void
    handlePushGet();

    void
    handlePushGetAll();

    // User options layouts
    void
    adoptFromAllPets();

    void
    adoptFilteredLayout();
    void
    handlePushFilterSelect();

    
    

private:
    QPushButton * admin_button;
    QPushButton * user_button;

    QPushButton * html_button;
    QPushButton * csv_button;
    QPushButton * submit_button;
    QPushButton * go_back_button;
    int fileType; 

    QPushButton * create_button_;
    QLineEdit * breed_input;
    QLineEdit * name_input;
    QLineEdit * age_input;
    QLineEdit * photo_input;
    QLineEdit * index_input;

    QPushButton * update_button_;
    QPushButton * get_button_;
    QPushButton * get_all_button_;
    QPushButton * delete_button_;

    QTextBrowser * textBrowser_;
};

#endif // MAINWIDGET_H
