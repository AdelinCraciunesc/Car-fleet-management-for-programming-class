#include "Auto_Camioane.h"

Auto_Camioane::Auto_Camioane(int id,string tip,string data_achizitie,string data_itp,bool folosit,string model_c,int capacitate):Flota_Auto(id,tip,data_achizitie,data_itp,folosit)
{
    this->model_c = model_c;
    this->capacitate = capacitate;
}
ostream& Auto_Camioane::afisare(ostream& out)
{
    Flota_Auto::afisare(out);
    out << ";" << model_c << ";" << capacitate << endl;
    return out;
}
Auto_Camioane::~Auto_Camioane()
{
    //dtor
}
