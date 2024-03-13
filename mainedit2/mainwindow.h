#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QTimer>
#include <QDateTime>
#include <QDesktopWidget>
#include <QApplication>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>
#include <QProcess>
#include <QString>
#include "audiencepoll.h"
#include "endscreen.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void  connOpen();
    void connClose();
    QString getquestion(int);
    void evaluateanswer(QString);
    ~MainWindow();
    QTimer *timer;
    void handle_timeout(void);
    int min=0,sec=0;
    void Delay_MSec(unsigned int msec);
    int flag=0;

private slots:
    void on_option1_clicked();

    void on_option3_clicked();

    void on_option2_clicked();

    void on_option4_clicked();

    void on_ll_fiftyfifty_clicked();
    void referesh();
    void on_ll_expert_clicked();



    void on_ll_audience_clicked();

    void on_toMainWindowButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
    QString question;
    QString optiona;
    QString optionb;
    QString optionc;
    QString optiond;
    QString answer;
    QString answerchosen;
    int ans;
    int level =1;
    bool ll_fifty = true;
    bool ll_expert = true;
    bool ll_audience = true;
    EndScreen *lose;

};
#endif // MAINWINDOW_H
