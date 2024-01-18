#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "highscore.h"
#include "QLabel"

#include <QApplication>
#include <QDir>
#include <QTextEdit>
#include <QFileInfoList>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <QGuiApplication>
#include <QScreen>
#include <QPixmap>
#include <QVBoxLayout>
#include <QSettings>
#include <QProcess>
#include <QFrame>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);



}

MainWindow::~MainWindow()
{
    delete ui;
}



