#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int x = width() * 0.7;
    int y = height() * 0.3;
    setFixedSize(x,y);

    setWindowTitle("DnD Quick Roller");
    setStyleSheet("QMainWindow {background: 'grey';}");

    srand(time(0));

    QWidget* numberWidget = new QWidget();
    numberWidget->setStyleSheet("background-color:white;");
    QHBoxLayout* layoutNumbers = new QHBoxLayout();
    QLabel* num1 = new QLabel("1");
    //num1->setStyleSheet("background-color:green;");
    QLabel* num2 = new QLabel("2");
    //num2->setStyleSheet("background-color:brown;");
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

    connect(buttonRoll, SIGNAL (clicked()), this, SLOT (rollSlot()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

// SLOTS

void MainWindow::rollSlot() {

    generateStats();

    QList<QLabel*> numberDisplays = centralWidget()->findChildren<QLabel *>();

    // std::cout << numberDisplays.size() << std::endl; // gives 6

    for (int b = 0; b < numberDisplays.size(); b++) {
        QString numberString = QString::number(rolledStats.at(b));
        numberDisplays[b]->setText(numberString);
    }


}


// HELPER FUNCTIONS

void MainWindow::generateStats() {
    rolledStats.clear();

    for (int i = 0; i < 6; i++) {
        std::vector <int> tempStat;
        int tempVal;
        for (int i = 0; i < 4; i++) {
            tempVal = rand() % 6 + 1;
            tempStat.push_back(tempVal);
        }

        std::sort(tempStat.begin(), tempStat.begin() + 4);
        tempStat.erase(tempStat.begin());

        int stat = 0;
        for (int x = 0; x < tempStat.size(); x++) {
            stat += tempStat.at(x);
        }

        rolledStats.push_back(stat);
    }

}
