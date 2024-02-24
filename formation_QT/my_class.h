#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <QSqlQuery>
#include <QSqlQueryModel>

class my_class
{
public:


    my_class();
    my_class(int,double,QString,QString,QString,QString,QString);


    bool ajouter();
    bool modifier(int);
     QSqlQueryModel * afficher();
      bool supprimer(int);

      double reel;
      int integer;
      QString text, line, combo, date,time;


};

#endif // MY_CLASS_H
