#include "Auto_Serviciu.h"

Auto_Serviciu::Auto_Serviciu(int id,string tip,string data_achizitie,string data_itp,bool folosit,string model_s,int capacitate):Flota_Auto(id,tip,data_achizitie,data_itp,folosit)
{
    this->model_s = model_s;
    this->capacitate = capacitate;
}
ostream& Auto_Serviciu::afisare(ostream& out)
{
    Flota_Auto::afisare(out);
    out <<";"<< model_s << ";" << capacitate << endl;
    return out;
}
Auto_Serviciu::~Auto_Serviciu()
{
    //dtor
}
