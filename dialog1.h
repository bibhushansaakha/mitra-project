#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include"dialog2.h"
#include "todo.h"
namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();

private slots:


    void on_Profile_clicked();

    void on_pushButton_3_clicked();

    void on_logouticon_clicked();

private:
    Ui::Dialog1 *ui;
     Dialog2 *profilewindow;
     todo* todo1;
};

#endif // DIALOG1_H
