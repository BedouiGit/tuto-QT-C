#include "my_class.h"

my_class::my_class()
{

}



my_class::my_class(int i,double d,QString s1 ,QString s2,QString s3 ,QString s4 ,QString s5 ){
    integer=i;
    reel=d;
    combo=s1;
    line=s2;
    text=s3;
    date=s4;
    time=s5;
}


bool my_class::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO CRUD (V_INT, REEL,COMBO,LINE,TEXT,V_DATE,TIME) "
                        "VALUES (:integer, :reel, :combo,:line,:text,:date,:time)");
    query.bindValue(":integer", integer);
    query.bindValue(":reel",reel); //remplir la valeur d'une maniere securisée
    query.bindValue(":combo", combo);
    query.bindValue(":line", line);
    query.bindValue(":text", text);
    query.bindValue(":date", date);
    query.bindValue(":time", time);

    return    query.exec();

}

bool my_class::modifier(int selected){

    QSqlQuery query;


    query.prepare(" UPDATE CRUD SET LINE= :line ,REEL= :reel ,COMBO= :combo,TEXT= :text ,V_DATE= :date "
                  ",TIME= :time where V_INT= :integer");
    query.bindValue(":integer", selected);
    query.bindValue(":reel",reel); //remplir la valeur d'une maniere securisée
    query.bindValue(":combo", combo);
    query.bindValue(":line", line);
    query.bindValue(":text", text);
    query.bindValue(":date", date);
    query.bindValue(":time", time);

    return    query.exec();

}

 QSqlQueryModel * my_class::afficher(){

     QSqlQueryModel * modal=new QSqlQueryModel();
     modal->setQuery("SELECT * FROM CRUD");

     return modal;

 }
  bool my_class::supprimer(int selected){

      QSqlQuery query;
      query.prepare("Delete from CRUD where V_INT = :sel ");
      query.bindValue(":sel", selected);
      return    query.exec();


  }
