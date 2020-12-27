#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutapp.h"
#include "aboutqt.h"
#include "result.h"

#include <iostream>
#include <QDialog>
#include <ctime>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionAbout_QtCanobu, &QAction::triggered, this, &MainWindow::showAboutApp);
    connect(ui->actionAbout_Qt, &QAction::triggered, this, &MainWindow::showAboutQt);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close_app);

    sq.open("results.db");
    sq.table();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::close_app(){
    exit(1);
}

void MainWindow::showAboutApp(){
    AboutApp *popup = new AboutApp(this);
    popup->setModal(true);
    popup->show();
}

void MainWindow::showAboutQt(){
    AboutQt *popup = new AboutQt(this);
    popup->setModal(true);
    popup->show();
}

void game(int user, SQLite_Wrapper sq){
    srand(time(0));
    int bot = 1 + rand() % 3;

    int massive[3][3] = {
        {2, 0, 1},
        {1, 2, 0},
        {0, 1, 2}
    };

    user--;
    bot--;

    for (int i = 0; i < 3; ++i){
        if (bot == i){
            QString results[3][2] = {
                {"Victory", "Misc_Birthday_Cake.png"},
                {"Draw", "Misc_R.I.P.png"},
                {"Loss", "Server_MediaAddonServer.png"}
            };
            QString objects[3] = {"rock", "scissors", "paper"};

            cout << massive[user][bot] << endl;
            sq.insert("TEST_USER", massive[user][bot], user, bot);


            Result *popup = new Result(0);
            popup->changeWindowMode(results[massive[user][bot]][0], objects[bot], results[massive[user][bot]][1]);
            popup->setModal(true);
            popup->setWindowTitle("Result");
            popup->setWindowIcon(QIcon(":/main/img/main/Prefs_Menu.png"));
            popup->exec();
            break;
        }
    }
}

void MainWindow::on_pushButton_1_clicked()
{
    game(1, sq);
}

void MainWindow::on_pushButton_2_clicked()
{
    game(2, sq);
}

void MainWindow::on_pushButton_3_clicked()
{
    game(3, sq);
}
