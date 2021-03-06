#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QPixmap>
#include<QtSql>
#include<QFileInfo>
#include<QtDebug>
#include<iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db_conn_open();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_login_3_clicked()
{
    QString username = ui->username_3->text();
    QString password = ui->Password_3->text();
    encrypt(password);
    QSqlQuery qry;
    if(qry.exec("Select * from newer where username= '"+username+"' and password1= '"+password+"'"))
    {
        int count =0;
        while(qry.next())
        {
            count++;
        }
        if (count<1)
        {
            QMessageBox:: warning(this,"Incorrect Credentials","Please make sure you have entered the correct username and passowrd.");
        }
        else if (count>=1)
        {
            hide();
            firstwindow = new Dialog1(this);
            firstwindow->show();
        }
    }
    else
    {
        QMessageBox:: warning(this,"hey",qry.lastError().text());
    }
}
void MainWindow::on_pushButton_singup_3_clicked()
{
    hide();
    register1 =  new signup(this);
    register1->show();
}
void MainWindow:: db_conn_open()
{

    QDir data("/Users");
        if (!data.exists())
        {
            data.mkpath("/Users/DB");
        }
        QSqlDatabase info  =  QSqlDatabase::addDatabase("QSQLITE");
        info.setDatabaseName("/Users/bibhushansaakha/Desktop/mitra-main/mitra-2/users.db");
        info.open();
}
bool MainWindow :: setTable()
{
    QSqlQuery table1;
    QString qry="Create Table newer"
            "("
                "first_name varchar(50),"
                "last_name varchar(50),"
                "username varchar(50),"
               " password1 varchar(50),"
                "email varchar(100),"
            "DOB date"
            ");";
    if (table1.exec(qry))
        return true;
    return false;
}
void MainWindow::encrypt(QString &string_encrypt){

    QString p_text = string_encrypt;
    int k=598658, value,ascii;
    for (int i = 0; i < p_text.size(); i++)
    {
        ascii = (p_text[i]).QChar::unicode();
        if (ascii >= 48 && ascii <= 57)
        {
            value = ((ascii + k - 48) % 10 + 48);
            string_encrypt[i] = static_cast<char>(value);
        }
        else if (ascii >= 65 && ascii <= 90)
        {
            value = ((ascii + k - 65) % 26 + 65);
            string_encrypt[i] = static_cast<char>(value);
        }
        else if (ascii >= 97 && ascii <= 122)
        {
            value = ((ascii + k - 97) % 26 + 97);
            string_encrypt[i] = static_cast<char>(value);
        }
        else
        {
            string_encrypt[i] = static_cast<char>(ascii);
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    password1=new ForgotPassword(this);
    password1->show();
}

