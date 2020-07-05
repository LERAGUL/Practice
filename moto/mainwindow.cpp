#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adddel.h"
#include "search.h"
#include "graph.h"
#include <QDialog>
#include "stdio.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Меню");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAdd_clicked()
{
    AddDel w;
    w.setModal(true);
    w.exec();
}

void MainWindow::on_pushButtonSearch_clicked()
{
    Search w;
    w.setModal(true);
    w.exec();
}

void MainWindow::on_pushButtonGraf_clicked()
{
    Graph w;
    w.setModal(true);
    w.exec();
}
