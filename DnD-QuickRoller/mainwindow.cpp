#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int x = width() * 0.5;
    int y = height() * 0.4;
    setFixedSize(x,y);

    setWindowTitle("DnD Quick Roller");
    setStyleSheet("QMainWindow {background: 'grey';}");

    srand(time(0));

    rolledStats = {0, 0, 0, 0, 0, 0};
    choice1Tracker = 0;
    choice2Tracker = 1;
    choice3Tracker = 2;
    choice4Tracker = 3;
    choice5Tracker = 4;


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

    QWidget* choicesWidget = new QWidget();
    QHBoxLayout* layoutChoices = new QHBoxLayout();

    QWidget* choice1Widget = new QWidget();
    choice1Widget->setStyleSheet("background-color:white;");
    QVBoxLayout* layoutChoice1 = new QVBoxLayout();
    QToolButton* tButtonTopArrow1 = new QToolButton();
    tButtonTopArrow1->setArrowType(Qt::UpArrow);
    QLabel* choice1 = new QLabel("1");
    choice1->setStyleSheet("border: 3px solid black;");
    QToolButton* tButtonBottomArrow1 = new QToolButton();
    tButtonBottomArrow1->setArrowType(Qt::DownArrow);
    layoutChoice1->addWidget(tButtonTopArrow1);
    layoutChoice1->addWidget(choice1);
    layoutChoice1->addWidget(tButtonBottomArrow1);
    choice1Widget->setLayout(layoutChoice1);

    QWidget* choice2Widget = new QWidget();
    choice2Widget->setStyleSheet("background-color:white;");
    QVBoxLayout* layoutChoice2 = new QVBoxLayout();
    QToolButton* tButtonTopArrow2 = new QToolButton();
    tButtonTopArrow2->setArrowType(Qt::UpArrow);
    QLabel* choice2 = new QLabel("2");
    choice2->setStyleSheet("border: 3px solid black;");
    QToolButton* tButtonBottomArrow2 = new QToolButton();
    tButtonBottomArrow2->setArrowType(Qt::DownArrow);
    layoutChoice2->addWidget(tButtonTopArrow2);
    layoutChoice2->addWidget(choice2);
    layoutChoice2->addWidget(tButtonBottomArrow2);
    choice2Widget->setLayout(layoutChoice2);

    QWidget* choice3Widget = new QWidget();
    choice3Widget->setStyleSheet("background-color:white;");
    QVBoxLayout* layoutChoice3 = new QVBoxLayout();
    QToolButton* tButtonTopArrow3 = new QToolButton();
    tButtonTopArrow3->setArrowType(Qt::UpArrow);
    QLabel* choice3 = new QLabel("3");
    choice3->setStyleSheet("border: 3px solid black;");
    QToolButton* tButtonBottomArrow3 = new QToolButton();
    tButtonBottomArrow3->setArrowType(Qt::DownArrow);
    layoutChoice3->addWidget(tButtonTopArrow3);
    layoutChoice3->addWidget(choice3);
    layoutChoice3->addWidget(tButtonBottomArrow3);
    choice3Widget->setLayout(layoutChoice3);

    QWidget* choice4Widget = new QWidget();
    choice4Widget->setStyleSheet("background-color:white;");
    QVBoxLayout* layoutChoice4 = new QVBoxLayout();
    QToolButton* tButtonTopArrow4 = new QToolButton();
    tButtonTopArrow4->setArrowType(Qt::UpArrow);
    QLabel* choice4 = new QLabel("4");
    choice4->setStyleSheet("border: 3px solid black;");
    QToolButton* tButtonBottomArrow4 = new QToolButton();
    tButtonBottomArrow4->setArrowType(Qt::DownArrow);
    layoutChoice4->addWidget(tButtonTopArrow4);
    layoutChoice4->addWidget(choice4);
    layoutChoice4->addWidget(tButtonBottomArrow4);
    choice4Widget->setLayout(layoutChoice4);

    QWidget* choice5Widget = new QWidget();
    choice5Widget->setStyleSheet("background-color:white;");
    QVBoxLayout* layoutChoice5 = new QVBoxLayout();
    QToolButton* tButtonTopArrow5 = new QToolButton();
    tButtonTopArrow5->setArrowType(Qt::UpArrow);
    QLabel* choice5 = new QLabel("5");
    choice5->setStyleSheet("border: 3px solid black;");
    QToolButton* tButtonBottomArrow5 = new QToolButton();
    tButtonBottomArrow5->setArrowType(Qt::DownArrow);
    layoutChoice5->addWidget(tButtonTopArrow5);
    layoutChoice5->addWidget(choice5);
    layoutChoice5->addWidget(tButtonBottomArrow5);
    choice5Widget->setLayout(layoutChoice5);

    QWidget* choice6Widget = new QWidget();
    choice6Widget->setStyleSheet("background-color:white;");
    QVBoxLayout* layoutChoice6 = new QVBoxLayout();
    QToolButton* tButtonTopArrow6 = new QToolButton();
    tButtonTopArrow6->setArrowType(Qt::UpArrow);
    QLabel* choice6 = new QLabel("6");
    choice6->setStyleSheet("border: 3px solid black;");
    QToolButton* tButtonBottomArrow6 = new QToolButton();
    tButtonBottomArrow6->setArrowType(Qt::DownArrow);
    layoutChoice6->addWidget(tButtonTopArrow6);
    layoutChoice6->addWidget(choice6);
    layoutChoice6->addWidget(tButtonBottomArrow6);
    choice6Widget->setLayout(layoutChoice6);



    layoutChoices->addWidget(choice1Widget);
    layoutChoices->addWidget(choice2Widget);
    layoutChoices->addWidget(choice3Widget);
    layoutChoices->addWidget(choice4Widget);
    layoutChoices->addWidget(choice5Widget);
    layoutChoices->addWidget(choice6Widget);

    choicesWidget->setLayout(layoutChoices);


    QVBoxLayout* layoutMain = new QVBoxLayout();
    layoutMain->addWidget(numberWidget);
    layoutMain->addWidget(buttonRoll);
    layoutMain->addWidget(choicesWidget);


    QWidget* mainWidget = new QWidget();

    mainWidget->setLayout(layoutMain);

    setCentralWidget(mainWidget);

    connect(buttonRoll, SIGNAL (clicked()), this, SLOT (rollSlot()));

    connect(tButtonTopArrow1, SIGNAL (clicked()), this, SLOT (upChoice1()));
    connect(tButtonBottomArrow1, SIGNAL (clicked()), this, SLOT (downChoice1()));

    connect(tButtonTopArrow2, SIGNAL (clicked()), this, SLOT (upChoice2()));
    connect(tButtonBottomArrow2, SIGNAL (clicked()), this, SLOT (downChoice2()));

    connect(tButtonTopArrow3, SIGNAL (clicked()), this, SLOT (upChoice3()));
    connect(tButtonBottomArrow3, SIGNAL (clicked()), this, SLOT (downChoice3()));

    connect(tButtonTopArrow4, SIGNAL (clicked()), this, SLOT (upChoice4()));
    connect(tButtonBottomArrow4, SIGNAL (clicked()), this, SLOT (downChoice4()));

    connect(tButtonTopArrow5, SIGNAL (clicked()), this, SLOT (upChoice5()));
    connect(tButtonBottomArrow5, SIGNAL (clicked()), this, SLOT (downChoice5()));

    connect(tButtonTopArrow6, SIGNAL (clicked()), this, SLOT (upChoice6()));
    connect(tButtonBottomArrow6, SIGNAL (clicked()), this, SLOT (downChoice6()));

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

    for (int b = 6; b < 12; b++) {
        QString numberString = QString::number(rolledStats.at(b - 6));
        numberDisplays[b]->setText(numberString);
    }

}


void MainWindow::upChoice1() {
   QList<QLabel*> numberDisplays = centralWidget()->findChildren<QLabel *>();

   if (choice1Tracker == 0) {
       choice1Tracker = 5;
   } else {
       choice1Tracker--;
   }

   QString statString = QString::number(rolledStats.at(choice1Tracker));
   numberDisplays[6]->setText(statString);
}

void MainWindow::downChoice1() {
   QList<QLabel*> numberDisplays = centralWidget()->findChildren<QLabel *>();

   if (choice1Tracker == 5) {
       choice1Tracker = 0;
   } else {
       choice1Tracker++;
   }

   QString statString = QString::number(rolledStats.at(choice1Tracker));
   numberDisplays[6]->setText(statString);
}

void MainWindow::upChoice2() {
    QList<QLabel*> numberDisplays = centralWidget()->findChildren<QLabel *>();

    if (choice2Tracker == 0) {
        choice2Tracker = 5;
    } else {
        choice2Tracker--;
    }

    QString statString = QString::number(rolledStats.at(choice2Tracker));
    numberDisplays[7]->setText(statString);
 }

void MainWindow::downChoice2() {
    QList<QLabel*> numberDisplays = centralWidget()->findChildren<QLabel *>();

    if (choice2Tracker == 5) {
        choice2Tracker = 0;
    } else {
        choice2Tracker++;
    }

    QString statString = QString::number(rolledStats.at(choice2Tracker));
    numberDisplays[7]->setText(statString);
}

void MainWindow::upChoice3() {
     QList<QLabel*> numberDisplays = centralWidget()->findChildren<QLabel *>();

     if (choice3Tracker == 0) {
         choice3Tracker = 5;
     } else {
         choice3Tracker--;
     }

     QString statString = QString::number(rolledStats.at(choice3Tracker));
     numberDisplays[8]->setText(statString);
  }

void MainWindow::downChoice3() {
     QList<QLabel*> numberDisplays = centralWidget()->findChildren<QLabel *>();

     if (choice3Tracker == 5) {
         choice3Tracker = 0;
     } else {
         choice3Tracker++;
     }

     QString statString = QString::number(rolledStats.at(choice3Tracker));
     numberDisplays[8]->setText(statString);
  }

void MainWindow::upChoice4() {
      QList<QLabel*> numberDisplays = centralWidget()->findChildren<QLabel *>();

      if (choice4Tracker == 0) {
          choice4Tracker = 5; // NOTE: need to make separate trackers for the choices
      } else {
          choice4Tracker--;
      }

      QString statString = QString::number(rolledStats.at(choice4Tracker));
      numberDisplays[9]->setText(statString);
   }

void MainWindow::downChoice4() {
      QList<QLabel*> numberDisplays = centralWidget()->findChildren<QLabel *>();

      if (choice4Tracker == 5) {
          choice4Tracker = 0;
      } else {
          choice4Tracker++;
      }

      QString statString = QString::number(rolledStats.at(choice4Tracker));
      numberDisplays[9]->setText(statString);
   }

void MainWindow::upChoice5() {
       QList<QLabel*> numberDisplays = centralWidget()->findChildren<QLabel *>();

       if (choice5Tracker == 0) {
           choice5Tracker = 5;
       } else {
           choice5Tracker--;
       }

       QString statString = QString::number(rolledStats.at(choice5Tracker));
       numberDisplays[10]->setText(statString);
    }

void MainWindow::downChoice5() {
       QList<QLabel*> numberDisplays = centralWidget()->findChildren<QLabel *>();

       if (choice5Tracker == 5) {
           choice5Tracker = 0;
       } else {
           choice5Tracker++;
       }

       QString statString = QString::number(rolledStats.at(choice5Tracker));
       numberDisplays[10]->setText(statString);
    }

void MainWindow::upChoice6() {
        QList<QLabel*> numberDisplays = centralWidget()->findChildren<QLabel *>();

        if (choice6Tracker == 0) {
            choice6Tracker = 5;
        } else {
            choice6Tracker--;
        }

        QString statString = QString::number(rolledStats.at(choice6Tracker));
        numberDisplays[11]->setText(statString);
}

void MainWindow::downChoice6() {
        QList<QLabel*> numberDisplays = centralWidget()->findChildren<QLabel *>();

        if (choice6Tracker == 5) {
            choice6Tracker = 0;
        } else {
            choice6Tracker++;
        }

        QString statString = QString::number(rolledStats.at(choice6Tracker));
        numberDisplays[11]->setText(statString);
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
