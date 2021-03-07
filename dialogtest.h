#ifndef DIALOGTEST_H
#define DIALOGTEST_H

#include <QDialog>

namespace Ui {
class Dialogtest;
}

class Dialogtest : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogtest(QWidget *parent = nullptr);
    ~Dialogtest();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialogtest *ui;
};

#endif // DIALOGTEST_H
