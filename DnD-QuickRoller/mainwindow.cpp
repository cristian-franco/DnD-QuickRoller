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
    num1->setStyleSheet("border: 3px solid black;");
    num2->setStyleSheet("border: 3px solid black;");
    num3->setStyleSheet("border: 3px solid black;");
    num4->setStyleSheet("border: 3px solid black;");
    num5->setStyleSheet("border: 3px solid black;");
    num6->setStyleSheet("border: 3px solid black;");
//    num1->setAlignment(Qt::AlignHCenter);
//    num2->setStyleSheet("border: 3px solid black;");
//    num3->setStyleSheet("border: 3px solid black;");
//    num4->setStyleSheet("border: 3px solid black;");
//    num5->setStyleSheet("border: 3px solid black;");
//    num6->setStyleSheet("border: 3px solid black;");
    layoutNumbers->addWidget(num1);
    layoutNumbers->addWidget(num2);
    layoutNumbers->addWidget(num3);
    layoutNumbers->addWidget(num4);
    layoutNumbers->addWidget(num5);
    layoutNumbers->addWidget(num6);
    numberWidget->setLayout(layoutNumbers);

    QPushButton* buttonRoll = new QPushButton("Roll");

    QWidget* choiceWidget = new QWidget();
    choiceWidget->setStyleSheet("background-color:white;");
    QHBoxLayout* layoutChoices = new QHBoxLayout();
    QLabel* choice1 = new QLabel("1");
    //num1->setStyleSheet("background-color:green;");
    QLabel* choice2 = new QLabel("2");
    //num2->setStyleSheet("background-color:brown;");
    QLabel* choice3 = new QLabel("3");
    QLabel* choice4 = new QLabel("4");
    QLabel* choice5 = new QLabel("5");
    QLabel* choice6 = new QLabel("6");
    choice1->setStyleSheet("border: 3px solid black;");
    choice2->setStyleSheet("border: 3px solid black;");
    choice3->setStyleSheet("border: 3px solid black;");
    choice4->setStyleSheet("border: 3px solid black;");
    choice5->setStyleSheet("border: 3px solid black;");
    choice6->setStyleSheet("border: 3px solid black;");
    layoutChoices->addWidget(choice1);
    layoutChoices->addWidget(choice2);
    layoutChoices->addWidget(choice3);
    layoutChoices->addWidget(choice4);
    layoutChoices->addWidget(choice5);
    layoutChoices->addWidget(choice6);
    choiceWidget->setLayout(layoutChoices);

    QToolButton* tButtonArrow1 = new QToolButton();
    tButtonArrow1->setArrowType(Qt::UpArrow);


    QVBoxLayout* layoutMain = new QVBoxLayout();
    layoutMain->addWidget(numberWidget);
    layoutMain->addWidget(buttonRoll);
    layoutMain->addWidget(tButtonArrow1);
    layoutMain->addWidget(choiceWidget);


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

//     std::cout << numberDisplays.size() << std::endl; // gives 6

    for (int b = 0; b < 6; b++) {
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
