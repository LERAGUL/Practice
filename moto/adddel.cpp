#include "adddel.h"
#include "ui_adddel.h"
#include "string.h"
#include "stdio.h"
FILE *f,*f2;


AddDel::AddDel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDel)
{
    ui->setupUi(this);
    this->setWindowTitle("Добавить/удалить запись");
}

AddDel::~AddDel()
{
    delete ui;
}

void AddDel::on_pushButtonAdd_clicked()
{
    QString mar, god, num, fam, all;
    char *ALL;
    f=fopen("moto.txt","a");
    mar = ui->lineEditMar->text()+" ";
    god = ui->spinBox->text()+" ";
    num = ui->lineEditNum->text()+" ";
    fam = ui->lineEditFam->text()+"\n";
    ui->lineEditMar->clear();
    ui->spinBox->clear();
    ui->lineEditNum->clear();
    ui->lineEditFam->clear();
    all = mar + god + num + fam;
    ui->listWidget->addItem(all);
    all.toLocal8Bit();// перевод из QString в char
    ALL = all.toUtf8().data();// перевод из QString в char
    fputs(ALL,f);
    fclose(f);
    ui->pushButtonAdd->setEnabled(false);
    ui->spinBox->setValue(1990);
}

void AddDel::showEvent(QShowEvent *event)
{
    char str[100];
    ui->listWidget->clear();
    f=fopen("moto.txt","r");
    rewind(f);
    while (fgets (str,sizeof(str),f)!=NULL)
          ui->listWidget->addItem(str);
    fclose(f);
}


void AddDel::on_pushButtonMenu_clicked()
{
    fclose(f);
    this->close();
}

void AddDel::on_pushButtonDel_clicked()
{
    QString del;
    char *DEL,str[100];
    del = ui->listWidget->currentItem()->text();
    delete ui->listWidget->currentItem();
    del.toLocal8Bit();   //перевод из QString в char
    DEL = del.toUtf8().data(); //перевод из QString в char
    f2=fopen("moto2.txt","w");
    f=fopen("moto.txt","r");
    rewind(f);
    while (fgets (str,sizeof(str),f)!=NULL)// пока не конец файла считываю по строке
    {
        if (strcmp(str,DEL)!=0) fputs(str,f2);// если находит этот год в строке
    }
    fclose(f);
    fclose(f2);
    f=fopen("moto.txt","w");
    f2=fopen("moto2.txt","r");
    while (fgets (str,sizeof(str),f2)!=NULL)
    {
        fputs(str,f);
    }
    fclose(f);
    fclose(f2);
}

void AddDel::on_lineEditMar_textChanged(const QString &arg1)
{
    if(ui->lineEditMar->text()!="" && ui->lineEditNum->text()!="" && ui->lineEditFam->text()!="") ui->pushButtonAdd->setEnabled(true);
    ui->listWidget->clearSelection();
    ui->pushButtonDel->setEnabled(false);
    if(ui->lineEditMar->text()=="" || ui->lineEditNum->text()=="" || ui->lineEditFam->text()=="") ui->pushButtonAdd->setEnabled(false);
}

void AddDel::on_lineEditNum_textChanged(const QString &arg1)
{
    if(ui->lineEditMar->text()!="" && ui->lineEditNum->text()!="" && ui->lineEditFam->text()!="") ui->pushButtonAdd->setEnabled(true);
    ui->listWidget->clearSelection();
    ui->pushButtonDel->setEnabled(false);
     if(ui->lineEditMar->text()=="" || ui->lineEditNum->text()=="" || ui->lineEditFam->text()=="") ui->pushButtonAdd->setEnabled(false);
}

void AddDel::on_lineEditFam_textChanged(const QString &arg1)
{
    if(ui->lineEditMar->text()!="" && ui->lineEditNum->text()!="" && ui->lineEditFam->text()!="") ui->pushButtonAdd->setEnabled(true);
    ui->listWidget->clearSelection();
    ui->pushButtonDel->setEnabled(false);
     if(ui->lineEditMar->text()=="" || ui->lineEditNum->text()=="" || ui->lineEditFam->text()=="") ui->pushButtonAdd->setEnabled(false);
}


void AddDel::on_listWidget_clicked(const QModelIndex &index)
{
    ui->pushButtonDel->setEnabled(true);
}
