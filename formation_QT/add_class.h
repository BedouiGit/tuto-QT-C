#ifndef ADD_CLASS_H
#define ADD_CLASS_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class add_class;
}

class add_class : public QDialog
{
    Q_OBJECT

public:
    explicit add_class(QWidget *parent = nullptr);
    ~add_class();

    QString get_date() const ;
    QString text() const ;
    QString add_combo() const;
    QString line() const ;
    int integer() const;
    double reel() const;
    QString get_time() const ;

    void fill_form(int);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::add_class *ui;
};

#endif // ADD_CLASS_H
