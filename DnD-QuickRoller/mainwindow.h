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

    int choice1Tracker;

    void generateStats();


private slots:
    void rollSlot();
    void upChoice1();


};
#endif // MAINWINDOW_H
