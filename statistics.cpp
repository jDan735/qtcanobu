#include "statistics.h"
#include "ui_statistics.h"
#include "table.h"

#include <QStandardItemModel>
#include <QStandardItem>
#include <QSqlQuery>

statistics::statistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistics)
{
    ui->setupUi(this);


    QStandardItemModel *model = new QStandardItemModel;

    //Заголовки столбцов
    QStringList horizontalHeader;
    horizontalHeader.append("Username");
    horizontalHeader.append("User");
    horizontalHeader.append("Bot");
    horizontalHeader.append("Result");
    //ui->tableView->horizontalHeader()->setStretchLastSection(true);

    QStringList verticalHeader;
    SQLite_Wrapper sq;
    QSqlQuery query = sq.select();

    QString results[3] = {"Victory", "Draw", "Loss"};
    QString objects[3] = {"Rock", "Scissors", "Paper"};

    for (int i = 0; query.next(); ++i)
    {
        for (int k = 0; k < 4; ++k)
        {
            if (k == 3) {
                model->setItem(i, k, new QStandardItem(results[query.value(k).toString().toInt()]));
            } else if (k == 1 or k == 2) {
                model->setItem(i, k, new QStandardItem(objects[query.value(k).toString().toInt()]));
            } else {
                model->setItem(i, k, new QStandardItem(query.value(k).toString()));
            }
        }

        verticalHeader.append(QString::number(i + 1));
    }

    model->setHorizontalHeaderLabels(horizontalHeader);
    model->setVerticalHeaderLabels(verticalHeader);

    ui->tableView->setModel(model);
    ui->tableView->setStyleSheet("QTableView::item {padding-left: 20px;}");

    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
}

statistics::~statistics()
{
    delete ui;
}
