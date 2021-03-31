#ifndef FLOTA_AUTO_H
#define FLOTA_AUTO_H
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Flota_Auto
{
    public:
        Flota_Auto(int,string,string,string,bool);
        virtual ~Flota_Auto();
        friend ostream& operator <<(ostream&,Flota_Auto&);
        virtual ostream& afisare(ostream&);
        int getId(){return this->id;}
        string getTip(){return this->tip;}
        string getData_itp(){return this->data_itp;}
        string getData_achizitie(){return this->data_achizitie;}
        bool getFolosit(){return this->folosit;}
    protected:
        int id;
        string tip,data_achizitie,data_itp;
        bool folosit;

};
#endif // FLOTA_AUTO_H
