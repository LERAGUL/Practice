#include "graph.h"
#include "ui_graph.h"
#include <QGraphicsTextItem>
QGraphicsScene *scene;
FILE *b;

Graph::Graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);
    this->setWindowTitle("График");
}

Graph::~Graph()
{
    delete ui;
}

void Graph::showEvent(QShowEvent *)
{
    scene = new QGraphicsScene(ui->graphicsView);
    int x=0,y=0,x1=0,y1=225;
    QPen pen(Qt::black);
    while (x<=435)
    {
    scene->addLine(x,y,x1,y1,pen);
    x=x+15;
    x1=x1+15;
    }
    x=0;y=0;x1=435;y1=0;
    while (y<=225)
    {
    scene->addLine(x,y,x1,y1,pen);
    y=y+15;
    y1=y1+15;
    }
    ui->graphicsView->setScene(scene);
    QGraphicsTextItem *textItem = new QGraphicsTextItem("1990");
    textItem->setPos(-18, 225);
    QGraphicsTextItem *textItem1 = new QGraphicsTextItem("1995");
    textItem1->setPos(59 ,225);
    QGraphicsTextItem *textItem2 = new QGraphicsTextItem("2000");
    textItem2->setPos(136, 225);
    QGraphicsTextItem *textItem3 = new QGraphicsTextItem("2005");
    textItem3->setPos(210, 225);
    QGraphicsTextItem *textItem4 = new QGraphicsTextItem("2010");
    textItem4->setPos(285, 225);
    QGraphicsTextItem *textItem5 = new QGraphicsTextItem("2015");
    textItem5->setPos(360, 225);
    QGraphicsTextItem *textItem6 = new QGraphicsTextItem("год");
    textItem6->setPos(430, 225);
    scene->addItem(textItem);
    scene->addItem(textItem1);
    scene->addItem(textItem2);
    scene->addItem(textItem3);
    scene->addItem(textItem4);
    scene->addItem(textItem5);
    scene->addItem(textItem6);
    QGraphicsTextItem *textItem01 = new QGraphicsTextItem("1");
    textItem01->setPos(-18, 200);
    QGraphicsTextItem *textItem02 = new QGraphicsTextItem("2");
    textItem02->setPos(-18, 185);
    QGraphicsTextItem *textItem03 = new QGraphicsTextItem("3");
    textItem03->setPos(-18, 170);
    QGraphicsTextItem *textItem04 = new QGraphicsTextItem("4");
    textItem04->setPos(-18, 155);
    QGraphicsTextItem *textItem05 = new QGraphicsTextItem("5");
    textItem05->setPos(-18, 140);
    QGraphicsTextItem *textItem06 = new QGraphicsTextItem("6");
    textItem06->setPos(-18, 125);
    QGraphicsTextItem *textItem07 = new QGraphicsTextItem("7");
    textItem07->setPos(-18, 110);
    QGraphicsTextItem *textItem08 = new QGraphicsTextItem("8");
    textItem08->setPos(-18, 95);
    QGraphicsTextItem *textItem09 = new QGraphicsTextItem("9");
    textItem09->setPos(-18, 80);
    QGraphicsTextItem *textItem10 = new QGraphicsTextItem("10");
    textItem10->setPos(-20, 65);
    QGraphicsTextItem *textItem11 = new QGraphicsTextItem("11");
    textItem11->setPos(-20, 50);
    QGraphicsTextItem *textItem12 = new QGraphicsTextItem("12");
    textItem12->setPos(-20, 35);
    QGraphicsTextItem *textItem13 = new QGraphicsTextItem("13");
    textItem13->setPos(-20, 20);
    QGraphicsTextItem *textItem14 = new QGraphicsTextItem("14");
    textItem14->setPos(-20,5);
    QGraphicsTextItem *textItem15 = new QGraphicsTextItem("15");
    textItem15->setPos(-20,-10);
    QGraphicsTextItem *textItem16 = new QGraphicsTextItem("кол-во");
    textItem16->setPos(-30,-25);
    scene->addItem(textItem01);
    scene->addItem(textItem02);
    scene->addItem(textItem03);
    scene->addItem(textItem04);
    scene->addItem(textItem05);
    scene->addItem(textItem06);
    scene->addItem(textItem07);
    scene->addItem(textItem08);
    scene->addItem(textItem09);
    scene->addItem(textItem10);
    scene->addItem(textItem11);
    scene->addItem(textItem12);
    scene->addItem(textItem13);
    scene->addItem(textItem14);
    scene->addItem(textItem15);
    scene->addItem(textItem16);
}

void Graph::on_pushButton_clicked()
{
    char str[100],year[5]="1990";
    int i=0,i1=0,dx=0,dx1=15;
    b=fopen("moto.txt","r");
    rewind(b);
    int j=atoi(year);
    while(fgets(str,sizeof(str),b)!=NULL)
    {
        if (strstr(str, year)!=NULL) ++i;
    }
    j++;
    sprintf(year,"%d",j);
    rewind(b);
    while (j<=2019)
    {
        while(fgets(str,sizeof(str),b)!=NULL)
        {
            if (strstr(str, year)!=NULL) ++i1;
        }
        QPen pen(Qt::red);
        scene->addLine(dx,225-i*15,dx1,225-i1*15,pen);
        ui->graphicsView->setScene(scene);
        dx=dx+15;
        dx1=dx1+15;
        i=i1;
        i1=0;
        j++;
        sprintf(year,"%d",j);
        rewind(b);
    }
    fclose(b);
}

void Graph::on_pushButton_2_clicked()
{
    fclose(b);
    this->close();
}
