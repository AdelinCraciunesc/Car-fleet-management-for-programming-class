#ifndef AUTO_SERVICIU_H
#define AUTO_SERVICIU_H
#include "Flota_Auto.h"

class Auto_Serviciu: virtual public Flota_Auto
{
    public:
        Auto_Serviciu(int,string,string,string,bool,string,int);
        ostream& afisare(ostream&);
        virtual ~Auto_Serviciu();
        string getModel_s(){return this->model_s;}
        int getCapacitate_s(){return this->capacitate;}
    protected:
        string model_s;
        int capacitate;
};

#endif // AUTO_SERVICIU_H
