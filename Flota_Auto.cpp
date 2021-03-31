#include "Flota_Auto.h"

Flota_Auto::Flota_Auto(int id,string tip,string data_achizitie,string data_itp,bool folosit)
{
    this->id = id;
    this->tip = tip;
    this->data_achizitie = data_achizitie;
    this->data_itp = data_itp;
    this->folosit = folosit;
}
ostream& Flota_Auto::afisare(ostream& out)
{
    out << id << ";" << tip << ";" << data_achizitie << ";" << data_itp << ";" << folosit;
    return out;
}
ostream& operator << (ostream& out ,Flota_Auto& flota)
{
    return flota.afisare(out);
}
Flota_Auto::~Flota_Auto()
{

}
