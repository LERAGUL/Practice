#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = nullptr);
    ~Search();

private slots:
    void on_pushButtonSearch1_clicked();

    void on_pushButtonSearch2_clicked();

    void on_pushButtonSearch1_3_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonMenu_clicked();

    void on_lineEditMar_textChanged(const QString &arg1);

    void on_lineEditFam_textChanged(const QString &arg1);

private:
    Ui::Search *ui;
};

#endif // SEARCH_H
