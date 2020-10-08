#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("DnD Quick Roller");
    setStyleSheet("QMainWindow {background: 'grey';}");

    QWidget* numberWidget = new QWidget();
    QHBoxLayout* layoutNumbers = new QHBoxLayout();
    QLabel* num1 = new QLabel("1");
    QLabel* num2 = new QLabel("2");
    QLabel* num3 = new QLabel("3");
    QLabel* num4 = new QLabel("4");
    QLabel* num5 = new QLabel("5");
    QLabel* num6 = new QLabel("6");
    layoutNumbers->addWidget(num1);
    layoutNumbers->addWidget(num2);
    layoutNumbers->addWidget(num3);
    layoutNumbers->addWidget(num4);
    layoutNumbers->addWidget(num5);
    layoutNumbers->addWidget(num6);
    numberWidget->setLayout(layoutNumbers);

    QPushButton* buttonRoll = new QPushButton("Roll");

    QVBoxLayout* layoutMain = new QVBoxLayout();
    layoutMain->addWidget(numberWidget);
    layoutMain->addWidget(buttonRoll);

    QWidget* mainWidget = new QWidget();

    mainWidget->setLayout(layoutMain);

    setCentralWidget(mainWidget);







}

MainWindow::~MainWindow()
{
    delete ui;
}

