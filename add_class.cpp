#include "add_class.h"
#include "ui_add_class.h"

add_class::add_class(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_class)
{
    ui->setupUi(this);
}

add_class::~add_class()
{
    delete ui;
}


//config ok et cancel
void add_class::on_buttonBox_accepted()
{
accept();
}

void add_class::on_buttonBox_rejected()
{
reject();
}


//recuperation des donnees du formulaire

QString add_class::get_date() const { //date
    return ui->dateEdit->date().toString("dd.MM.yyyy");
}

QString add_class::text() const { //text edit
    return ui->textEdit->toPlainText();
}

QString add_class::add_combo() const { //combo box

    return ui->comboBox->currentText();
}

QString add_class::line() const { //line edit

    return ui->lineEdit->text();
}

int add_class::integer() const{ //integer

    return ui->spinBox->value();
}

double add_class::reel() const{ //float

    return ui->doubleSpinBox->value();
}

QString add_class::get_time() const { //time

    return ui->timeEdit->time().toString("hh:mm");
}

//remplissage des champs du formulaire a partir de la base

void add_class::fill_form(int selected ) {
    QSqlQuery query;
    query.prepare("select * from CRUD where V_INT= :integer");
    query.bindValue(":integer", selected);
    query.exec();
    while(query.next()){
        ui->dateEdit->setDate(QDate::fromString(query.value(5).toString(),"dd.MM.yyyy"));//date
        ui->timeEdit->setTime(QTime::fromString(query.value(6).toString(),"hh:mm"));//time
 ui->textEdit->setText(query.value(4).toString());//text edit
  ui->lineEdit->setText(query.value(3).toString()); //line edit
   ui->comboBox->setCurrentText(query.value(2).toString()); //combobox
    ui->spinBox->setValue(selected);// integer
     ui->doubleSpinBox->setValue(query.value(1).toReal()); // reel

    }

}

