#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutapp.h"
#include "aboutqt.h"

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
    popup->show();
}

void MainWindow::showAboutQt(){
    AboutQt *popup = new AboutQt(this);
    popup->show();
}

