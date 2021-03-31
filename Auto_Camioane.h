#ifndef AUTO_CAMIOANE_H
#define AUTO_CAMIOANE_H
#include "Flota_Auto.h"

class Auto_Camioane: virtual public Flota_Auto
{
    public:
        Auto_Camioane(int,string,string,string,bool,string,int);
        virtual ~Auto_Camioane();
        ostream& afisare(ostream&);
        string getModel_c(){return this->model_c;}
        int getCapacitate_c(){return this->capacitate;}
    protected:
        string model_c;
        int capacitate;
};

#endif // AUTO_CAMIOANE_H
