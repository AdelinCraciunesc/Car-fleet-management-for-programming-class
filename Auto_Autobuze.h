#ifndef AUTO_AUTOBUZE_H
#define AUTO_AUTOBUZE_H
#include "Flota_Auto.h"

class Auto_Autobuze:virtual public Flota_Auto
{
    public:
        Auto_Autobuze(int,string,string,string,bool,string,int);
        virtual ~Auto_Autobuze();
        ostream& afisare(ostream&);
        string getModel_a(){return this->model_a;}
        int getCapacitate_a(){return this->capacitate;}
    protected:
        string model_a;
        int capacitate;
};

#endif // AUTO_AUTOBUZE_H
