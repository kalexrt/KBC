#include "startmenu.h"
#include "ui_startmenu.h"

Startmenu::Startmenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Startmenu)
{
    ui->setupUi(this);
}

Startmenu::~Startmenu()
{
    delete ui;
    delete mainwindow;
}

void Startmenu::on_pushButton_start_clicked()
{
    //hide();
    mainwindow =new MainWindow(this);
    mainwindow->show();
}

void Startmenu::on_pushButton_exit_clicked()
{
   close();
}
