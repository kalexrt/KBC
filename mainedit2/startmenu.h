#ifndef STARTMENU_H
#define STARTMENU_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class Startmenu;
}

class Startmenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Startmenu(QWidget *parent = nullptr);
    ~Startmenu();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_exit_clicked();

private:
    Ui::Startmenu *ui;
    MainWindow *mainwindow;
};

#endif // STARTMENU_H
