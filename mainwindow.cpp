#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->Button_0,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->Button_1,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->Button_2,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->Button_3,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->Button_4,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->Button_5,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->Button_6,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->Button_7,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->Button_8,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->Button_9,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->Button_dot,SIGNAL(clicked()),this,SLOT(dot()));

    connect(ui->Button_pm,SIGNAL(clicked()),this,SLOT(functions()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;
    all_numbers = (ui->label->text() + button->text()).toDouble();
    new_label = QString::number(all_numbers, 'g', 16);
    ui->label->setText(new_label);
}

void MainWindow::dot()
{
    if(ui->label->text().contains(".") != true){
        ui->label->setText(ui->label->text()+".");
    }
}

void MainWindow::functions()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;
    if(button->text() == "+/-")
    {
        all_numbers = (ui->label->text() + button->text()).toDouble();
        all_numbers *= -1;
        new_label = QString::number(all_numbers, 'g', 16);
        ui->label->setText(new_label);
    }
    else{
        all_numbers = (ui->label->text() + button->text()).toDouble();
        all_numbers *= -1;
        new_label = QString::number(all_numbers, 'g', 16);
        ui->label->setText(new_label);
    }
}






//void MainWindow::element()
//{
//    QPushButton *button = (QPushButton *)sender();
//    double number_save;
//    number_save = (ui->label->text()).toDouble();
//    ui->label->setText(button->text());
//}

//void MainWindow::equal()
//{
//    QPushButton *button = (QPushButton *)sender();
//    ui->label->setText(button->text());
//}


//connect(ui->Button_equal,SIGNAL(clicked()),this,SLOT(equal()));
//connect(ui->Button_multiply,SIGNAL(clicked()),this,SLOT(element()));
//connect(ui->Button_divide,SIGNAL(clicked()),this,SLOT(element()));
//connect(ui->Button_minus,SIGNAL(clicked()),this,SLOT(element()));
//connect(ui->Button_plus,SIGNAL(clicked()),this,SLOT(element()));
//connect(ui->Button_dot,SIGNAL(clicked()),this,SLOT(dot()));
//connect(ui->Button_AC,SIGNAL(clicked()),this,SLOT(clear()));
