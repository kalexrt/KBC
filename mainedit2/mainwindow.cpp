#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->score_500->setStyleSheet("background-color:#006cff");
    getquestion(1);

   // ui->setupUi(this);
        this->setWindowFlags(Qt::FramelessWindowHint);
            //move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2);

            ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
            ui->lcdNumber->setDigitCount(8);

            ui->lcdNumber->display(QDateTime::currentDateTime().toString("00:30"));
            timer = new QTimer(this);
            connect(timer,&QTimer::timeout,this,&MainWindow::handle_timeout);
            timer->start(1000);
            flag=1;

}
//function to connect with the database
void  MainWindow:: connOpen(){
    mydb = QSqlDatabase :: addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/for u/Documents/qt/mainedit2/test.db");
    if(!mydb.open())
    {
        qDebug() << "Not connected";
    }
    else
    {
        qDebug() << "Connected";
    }
}
//function to close the database
void MainWindow :: connClose()
{
    mydb.close();
}
//function to return question and sets the options
QString MainWindow ::getquestion(int an)
{
connOpen();
referesh();
srand (time(0));
an--;
int a= rand()% 10+ an*10; //random number generator from (level-1)*10 to level *10


QSqlQuery query("SELECT * FROM level1 WHERE id ="+ QString::number(a)); // query to select the question from db
int idName = query.record().indexOf("question");// gets coloumn no. of question i.e. 1

while(query.next())
{
    this->question = query.value(idName).toString(); //converts the value of query to string and stores it to  string "question"

    this->optiona = query.value(2).toString(); //gets option a
    ui->option1->setText("A. " + optiona); //sets the option a to option 1 pushbutton
    this->optionb = query.value(3).toString();
    ui->option2->setText("B. " + optionb);
    this->optionc = query.value(4).toString();
    ui->option3->setText("C. " + optionc);
    this->optiond = query.value(5).toString();
    ui->option4->setText("D. " + optiond);
    this->answer = query.value(6).toString(); //gets the value of answer

    level++;
    if(level==3)
    {
    ui->score_1000->setStyleSheet("background-image: url(:/img/yellow.png)");
   // ui->score_500->setStyleSheet("background-image: url(:/img/black.png)");
    }
    if(level==4)
    {
    ui->score_2000->setStyleSheet("background-image: url(:/img/yellow.png)");
    ui->score_1000->setStyleSheet("background-image: url(:/img/black.png)");
    }
    if(level==5)
    {
    ui->score_5000->setStyleSheet("background-image: url(:/img/yellow.png)");
    ui->score_2000->setStyleSheet("background-image: url(:/img/black.png)");
    }
    if(level==6)
    {
    ui->score_10000->setStyleSheet("background-image: url(:/img/yellow.png)");
    ui->score_5000->setStyleSheet("background-image: url(:/img/black.png)");
    }
    if(level==7)
    {
    ui->score_25000->setStyleSheet("background-image: url(:/img/yellow.png)");
    ui->score_10000->setStyleSheet("background-image: url(:/img/black.png)");
    }
    if(level==8)
    {
    ui->score_50000->setStyleSheet("background-image: url(:/img/yellow.png)");
    ui->score_25000->setStyleSheet("background-image: url(:/img/black.png)");
    }
    if(level==9)
    {
    ui->score_50000->setStyleSheet("background-image: url(:/img/black.png)");
    ui->score_100000->setStyleSheet("background-image: url(:/img/yellow.png)");
    }





    qDebug() << a;

}
 ui->display_question->setText(question);//sets the question to the textbrowser widget display_question
return question;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow:: referesh()
{
    ui->option1->setVisible(true);
    ui->option2->setVisible(true);
    ui->option3->setVisible(true);
    ui->option4->setVisible(true);
}
//function to check the answer
void MainWindow::evaluateanswer(QString answerchosed)
{
    if(answer == answerchosed)
    {
        ui->statusbar->showMessage("Correct");
        ui->display_question->clear(); //buffers the widget display_question
        timer->start(1000);
        if(level == 1)
        {
            ui->statusbar -> showMessage(QString::number(level));


            getquestion(2); // gets a random question from another level

        }
        else if(level == 2)
        {
            ui->statusbar ->showMessage(QString::number(level));
            qDebug() << level;
            getquestion(3);
        }
        else if(level == 3)
        {
            ui->statusbar ->showMessage(QString::number(level));
            qDebug() << level;
            getquestion(4);
        }
        else if(level ==4)
        {
            ui->statusbar ->showMessage(QString::number(level));
            qDebug() << level;
            getquestion(5);
        }
        else if(level ==5)
        {
            ui->statusbar ->showMessage(QString::number(level));
            qDebug() << level;
            getquestion(6);
        }
        else if(level ==6)
        {
            ui->statusbar ->showMessage(QString::number(level));
            qDebug() << level;
            getquestion(7);
        }
        else if(level ==7)
        {
            ui->statusbar ->showMessage(QString::number(level));
            qDebug() << level;
            getquestion(8);
        }
        else
        {
            ui->display_question->setReadOnly(1); //makes lineEdit_getoption non-editable
            ui->option1->setVisible(false);
            ui->option2->setVisible(false);
            ui->option3->setVisible(false);
            ui->option4->setVisible(false);
            ui->display_question->setText("You have completed all levels.");

        }


    }

    else
    {
        //ui->statusbar->showMessage("Incorrect");
        close();
        lose= new EndScreen();
        lose -> show();
    }
}
void MainWindow::on_option1_clicked()
{
    this->answerchosen=optiona;
    evaluateanswer(answerchosen);
}

void MainWindow::on_option3_clicked()
{
    this->answerchosen=optionc;
    evaluateanswer(optionc);
}

void MainWindow::on_option2_clicked()
{
    this->answerchosen=optionb;
    evaluateanswer(optionb);
}

void MainWindow::on_option4_clicked()
{
    this->answerchosen=optiond;
    evaluateanswer(optiond);

}

void MainWindow::on_ll_fiftyfifty_clicked()
{
    if(ll_fifty== true)
        {
        if(answer == optiona )
        {
        ui->option2->setHidden(true);
        ui->option3->setHidden(true);
        }
        else if(answer == optionb )
        {
        ui->option1->setHidden(true);
        ui->option3->setHidden(true);
        }
        else if(answer == optionc )
        {
        ui->option2->setHidden(true);
        ui->option4->setHidden(true);
        }
        else
            {
            ui->option1->setHidden(true);
            ui->option3->setHidden(true);
            }

        }
        else
        {
            ui->ll_fiftyfifty->setDisabled(0);

        }
             ll_fifty=1;
        ui->ll_fiftyfifty->setHidden(1);

}


void MainWindow::on_ll_expert_clicked()
{
    if(ll_expert == true)
    {
    QMessageBox::StandardButton reply = QMessageBox::information(this,"Experts say","The answer can be "+answer+"\n Do you believe him?",QMessageBox::Yes,QMessageBox::No );
    if(reply == QMessageBox::Yes)
    {
        evaluateanswer(answer);
    }
    }


         ll_expert=false;
    ui->ll_expert->setHidden(1);

    }




void MainWindow::on_ll_audience_clicked()
{
    if(ll_audience == true)
    {

    Audiencepoll audiencepoll;
    int connector;
    if(answer == optiona)
    {
        connector = 1;
    }
    if(answer == optionb)
    {
        connector = 2;
    }
    if(answer == optionc)
    {
        connector = 3;
    }
    else
    {
        connector =4;
    }

    audiencepoll.answer(connector);
    audiencepoll.exec();
    ll_audience = false;

    }
    ui->ll_audience->setHidden(true);

}

void MainWindow::on_toMainWindowButton_clicked()
{
    this->hide();
}

void MainWindow::handle_timeout()
{
    if(flag == 1)
    {
      for(sec=30;sec>=0;sec--)
      {
         ui->lcdNumber->display(QDateTime::currentDateTime().toString(QString::number(min)+":"+QString::number(sec)));
         Delay_MSec(1000);
         if(sec==0)
         {
             hide();
             lose= new EndScreen();
             lose -> show();
         }

       }
    }
        timer->stop();
        hide();
    }


void MainWindow::Delay_MSec(unsigned int msec)
{
    QTime _Timer = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < _Timer)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

