#include "aboutqt.h"
#include "ui_aboutqt.h"

AboutQt::AboutQt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutQt)
{
    ui->setupUi(this);
}

AboutQt::~AboutQt()
{
    delete ui;
}

void AboutQt::on_pushButton_2_clicked()
{
    accept();
}
