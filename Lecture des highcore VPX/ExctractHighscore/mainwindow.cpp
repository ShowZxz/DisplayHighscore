#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "highscore.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //showFullScreen();


}

MainWindow::~MainWindow()
{
    delete ui;
}



