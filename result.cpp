#include "result.h"
#include "ui_result.h"

Result::Result(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
}

Result::~Result()
{
    delete ui;
}

void Result::changeWindowMode(QString result, QString item, QString filename){
    ui->label_2->setText(result);
    ui->label->setText("<p><img src=':/main/img/main/" + filename + "'/></p>");
    ui->textBrowser->setText("Bot has chosen " + item);
}

void Result::on_pushButton_clicked()
{
    accept();
}
