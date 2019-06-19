/********************************************************************************
** Form generated from reading UI file 'designerDjdOWj.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DESIGNERDJDOWJ_H
#define DESIGNERDJDOWJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *adoptAll;
    QPushButton *adoptCurrent;
    QPushButton *adoptSelect;
    QPushButton *nextDog;
    QTextEdit *currentPet;
    QTextEdit *adoptionList;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(651, 551);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        adoptAll = new QPushButton(centralwidget);
        adoptAll->setObjectName(QStringLiteral("adoptAll"));
        adoptAll->setGeometry(QRect(50, 440, 181, 31));
        adoptCurrent = new QPushButton(centralwidget);
        adoptCurrent->setObjectName(QStringLiteral("adoptCurrent"));
        adoptCurrent->setGeometry(QRect(50, 390, 181, 31));
        adoptSelect = new QPushButton(centralwidget);
        adoptSelect->setObjectName(QStringLiteral("adoptSelect"));
        adoptSelect->setGeometry(QRect(50, 490, 181, 31));
        nextDog = new QPushButton(centralwidget);
        nextDog->setObjectName(QStringLiteral("nextDog"));
        nextDog->setGeometry(QRect(50, 340, 181, 31));
        currentPet = new QTextEdit(centralwidget);
        currentPet->setObjectName(QStringLiteral("currentPet"));
        currentPet->setGeometry(QRect(40, 30, 191, 271));
        adoptionList = new QTextEdit(centralwidget);
        adoptionList->setObjectName(QStringLiteral("adoptionList"));
        adoptionList->setGeometry(QRect(270, 30, 341, 491));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        adoptAll->setText(QApplication::translate("MainWindow", "adopt from all", nullptr));
        adoptCurrent->setText(QApplication::translate("MainWindow", "adopt current", nullptr));
        adoptSelect->setText(QApplication::translate("MainWindow", "select by breed and age", nullptr));
        nextDog->setText(QApplication::translate("MainWindow", "next dog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DESIGNERDJDOWJ_H
