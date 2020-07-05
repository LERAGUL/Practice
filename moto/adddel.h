#ifndef ADDDEL_H
#define ADDDEL_H

#include <QDialog>

namespace Ui {
class AddDel;
}

class AddDel : public QDialog
{
    Q_OBJECT

public:
    explicit AddDel(QWidget *parent = nullptr);
    ~AddDel();

private slots:
    void on_pushButtonAdd_clicked();

    void showEvent(QShowEvent *event);

    void on_pushButtonMenu_clicked();

    void on_pushButtonDel_clicked();

    void on_lineEditMar_textChanged(const QString &arg1);

    void on_lineEditNum_textChanged(const QString &arg1);

    void on_lineEditFam_textChanged(const QString &arg1);

    void on_listWidget_clicked(const QModelIndex &index);

private:
    Ui::AddDel *ui;
};

#endif // ADDDEL_H
