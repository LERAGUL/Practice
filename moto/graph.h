#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>

namespace Ui {
class Graph;
}

class Graph : public QDialog
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = nullptr);
    ~Graph();


private slots:
    void on_pushButton_clicked();
    void showEvent(QShowEvent *);

    void on_pushButton_2_clicked();

private:
    Ui::Graph *ui;
};

#endif // GRAPH_H
