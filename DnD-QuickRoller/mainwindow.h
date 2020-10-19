#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include <algorithm>
#include <iostream>
#include <QStyle>
#include <QToolButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;

    std::vector <int> rolledStats;

    int choice1Tracker, choice2Tracker, choice3Tracker,
    choice4Tracker, choice5Tracker, choice6Tracker;

    QList<QLabel*> numbersList;
    QList<QLabel*> choicesList;

    void generateStats();


private slots:
    void rollSlot();
    void upChoice1();
    void upChoice2();
    void upChoice3();
    void upChoice4();
    void upChoice5();
    void upChoice6();

    void downChoice1();
    void downChoice2();
    void downChoice3();
    void downChoice4();
    void downChoice5();
    void downChoice6();


};
#endif // MAINWINDOW_H
