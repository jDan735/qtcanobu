#ifndef RESULT_H
#define RESULT_H

#include <QDialog>

namespace Ui {
class Result;
}

class Result : public QDialog
{
    Q_OBJECT

public slots:
    void changeWindowMode(QString result, QString item, QString filename);

private slots:
    void on_pushButton_clicked();

public:
    explicit Result(QWidget *parent = nullptr);
    ~Result();

private:
    Ui::Result *ui;
};

#endif // RESULT_H
