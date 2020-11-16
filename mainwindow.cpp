#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutapp.h"
#include "aboutqt.h"
#include "result.h"

#include <QDialog>
#include <ctime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionAbout_QtCanobu, &QAction::triggered, this, &MainWindow::showAboutApp);
    connect(ui->actionAbout_Qt, &QAction::triggered, this, &MainWindow::showAboutQt);
}

MainWindow::~MainWindow()
{
    delete ui;
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

void game(int user){
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
                {"Победа", "Misc_Birthday_Cake.png"},
                {"Проигрыш", "Misc_R.I.P.png"},
                {"Ничья", "Server_MediaAddonServer.png"}
            };
            QString objects[3] = {" камень", "и ножницы", "а бумага"};

            Result *popup = new Result(0);
            popup->changeWindowMode(results[massive[user][bot]][0], objects[bot], results[massive[user][bot]][1]);
            popup->setModal(true);
            popup->setWindowTitle("Результат");
            popup->setWindowIcon(QIcon(":/main/img/main/" + results[massive[user][bot]][1]));
            popup->exec();
            break;
        }
    }
}

void MainWindow::on_pushButton_1_clicked()
{
    game(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    game(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    game(3);
}
