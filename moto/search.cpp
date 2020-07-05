#include "search.h"
#include "ui_search.h"
#include <QDebug>
#include "iostream"
using namespace std;

FILE *a;

Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    this->setWindowTitle("Поиск");
}

Search::~Search()
{
    delete ui;
}

void Search::on_pushButtonSearch1_clicked()
{
    QString mar;
    char *MAR,str[100];
    int i=0;
    ui->textEdit->clear();
    mar = ui->lineEditMar->text();
    mar.toLocal8Bit();
    MAR = mar.toUtf8().data();
    a=fopen("moto.txt","r");
    rewind(a);
    while(fgets(str,sizeof(str),a)!=NULL)
    {
       if (strstr(str, MAR)!=NULL)
       {
           qDebug() << QString::fromLocal8Bit(str); //перевод из char в QString
           ui->textEdit->append(str);
           i=1;
       }
       mar = ui->lineEditMar->text();
       mar.toLocal8Bit();
       MAR = mar.toUtf8().data();
    }
    if (i==0) ui->textEdit->append("no information");
    ui->pushButtonSearch1->setEnabled(false);
    fclose(a);
}

void Search::on_pushButtonSearch2_clicked()
{
    QString fam;
    char *FAM,str[100];
    int i=0;
    ui->textEdit->clear();
    fam = ui->lineEditFam->text();
    fam.toLocal8Bit();
    FAM = fam.toUtf8().data();
    a=fopen("moto.txt","r");
    rewind(a);
    while(fgets(str,sizeof(str),a)!=NULL)
    {
       if (strstr(str, FAM)!=NULL)
       {
           qDebug() << QString::fromLocal8Bit(str);
           ui->textEdit->append(str);
           i=1;
       }
       fam = ui->lineEditFam->text();
       fam.toLocal8Bit();
       FAM = fam.toUtf8().data();
    }
    if (i==0) ui->textEdit->append("no information");
    fclose(a);
    ui->pushButtonSearch2->setEnabled(false);
}

void Search::on_pushButtonSearch1_3_clicked()
{
    QString god;
    char *GOD,str[100],year[5];
    int i=0;
    ui->textEdit->clear();
    god = ui->spinBox->text();
    god.toLocal8Bit();
    GOD = god.toUtf8().data();
    a=fopen("moto.txt","r");
    rewind(a);
    int j=atoi(GOD);
    sprintf(year,"%d",j);
        while(fgets(str,sizeof(str),a)!=NULL)
        {
           while (j<=2019)
           {
               if (strstr(str, year)!=NULL)
               {
                   qDebug() << QString::fromLocal8Bit(str);
                   ui->textEdit->append(str);
                   i=1;
               }
            j++;
            sprintf(year,"%d",j);
            }
           god = ui->spinBox->text();
           god.toLocal8Bit();
           GOD = god.toUtf8().data();
           j=atoi(GOD);
           sprintf(year,"%d",j);
        }
    if (i==0) ui->textEdit->append("no information");
    fclose(a);
}

void Search::on_pushButtonClear_clicked()
{
    ui->textEdit->clear();
    ui->lineEditFam->clear();
    ui->lineEditMar->clear();
    ui->pushButtonSearch1->setEnabled(false);
    ui->pushButtonSearch2->setEnabled(false);
}

void Search::on_pushButtonMenu_clicked()
{
    fclose(a);
    this->close();
}

void Search::on_lineEditMar_textChanged(const QString &arg1)
{
    if ((ui->lineEditMar->text())!="") ui->pushButtonSearch1->setEnabled(true);
}

void Search::on_lineEditFam_textChanged(const QString &arg1)
{
    if ((ui->lineEditFam->text())!="") ui->pushButtonSearch2->setEnabled(true);
}
