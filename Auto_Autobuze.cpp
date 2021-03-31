#include "Auto_Autobuze.h"

Auto_Autobuze::Auto_Autobuze(int id,string tip,string data_achizitie,string data_itp,bool folosit,string model_a,int capacitate):Flota_Auto(id,tip,data_achizitie,data_itp,folosit)
{
    this->model_a = model_a;
    this->capacitate = capacitate;
}
ostream& Auto_Autobuze::afisare(ostream& out)
{
    Flota_Auto::afisare(out);
    out << ";" << model_a << ";" << capacitate << endl;
    return out;
}
Auto_Autobuze::~Auto_Autobuze()
{
    //dtor
}
