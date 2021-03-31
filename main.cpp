#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <stdlib.h>
#include "Auto_Serviciu.h"
#include "Auto_Camioane.h"
#include "Auto_Autobuze.h"

using namespace std;

void citire(vector <Flota_Auto*>&vec)
{
    ifstream fin("flota_auto.in");
    string s;
    while(getline(fin,s) && !s.empty())
    {
        stringstream flux(s);
        int id,cap;
        string tip,d_ac,d_itp,model;
        bool x;
        flux >> id;
        flux.ignore();
        getline(flux,tip,';');
        getline(flux,d_ac,';');
        getline(flux,d_itp,';');
        flux >> x;
        flux.ignore();
        if(tip == "Serviciu")
        {
            getline(flux,model,';');
            flux >> cap;
            flux.ignore();
            vec.push_back(new Auto_Serviciu(id,tip,d_ac,d_itp,x,model,cap));
        }
        else if(tip == "Camion")
        {
            getline(flux,model,';');
            flux >> cap;
            flux.ignore();
            vec.push_back(new Auto_Camioane(id,tip,d_ac,d_itp,x,model,cap));
        }
        else if(tip == "Autobuz")
        {
            getline(flux,model,';');
            flux >> cap;
            flux.ignore();
            vec.push_back(new Auto_Autobuze(id,tip,d_ac,d_itp,x,model,cap));
        }
    }
}
void afisare(vector<Flota_Auto*> &vec)
{
    system("cls");
    for(int i = 0; i < vec.size();++i)
    {
        if(vec[i]->getTip() == "Serviciu")
        {
            cout <<"Id vehicol "<<vec[i]->getId()<<" Tip: "<<vec[i]->getTip()<<" Data achizitie "<<vec[i]->getData_achizitie()<<" Data expirare itp "<<vec[i]->getData_itp()<<endl;
            if(vec[i]->getFolosit() == true)
                cout << "Vehicolul este folosit in flota ";
            else
                cout << "Vehicolul nu este folosit in flota ";
            if(dynamic_cast<Auto_Serviciu*>(vec[i]))
            {
                Auto_Serviciu* as = dynamic_cast<Auto_Serviciu*>(vec[i]);
                cout << "Modelul vehicol " << as->getModel_s() << " Numar locuri: " << as->getCapacitate_s() << endl;
            }
            cout << endl;
        }
        if(vec[i]->getTip() == "Camion")
        {
            cout <<"Id vehicol "<<vec[i]->getId()<<" Tip: "<<vec[i]->getTip()<<" Data achizitie "<<vec[i]->getData_achizitie()<<" Data expirare itp "<<vec[i]->getData_itp()<<endl;
            if(vec[i]->getFolosit() == true)
                cout << "Vehicolul este folosit in flota ";
            else
                cout << "Vehicolul nu este folosit in flota ";
            if(dynamic_cast<Auto_Camioane*>(vec[i]))
            {
                Auto_Camioane* ac = dynamic_cast<Auto_Camioane*>(vec[i]);
                cout << "Modelul vehicol " << ac->getModel_c() << " Numar locuri: " << ac->getCapacitate_c() << endl;
            }
            cout << endl;
        }
        if(vec[i]->getTip() == "Autobuz")
        {
            cout <<"Id vehicol "<<vec[i]->getId()<<" Tip: "<<vec[i]->getTip()<<" Data achizitie "<<vec[i]->getData_achizitie()<<" Data expirare itp "<<vec[i]->getData_itp()<<endl;
            if(vec[i]->getFolosit() == true)
                cout << "Vehicolul este folosit in flota ";
            else
                cout << "Vehicolul nu este folosit in flota ";
            if(dynamic_cast<Auto_Autobuze*>(vec[i]))
            {
                Auto_Autobuze* aa = dynamic_cast<Auto_Autobuze*>(vec[i]);
                cout << "Modelul vehicol " << aa->getModel_a() << " Numar locuri: " << aa->getCapacitate_a() << endl;
            }
            cout << endl;
        }
    }
    system("pause");
}
void rescriere(vector<Flota_Auto*> vec)
{
    ofstream out("flota_auto.in");
    for(auto i:vec)
    {
        out << *i;
    }
}
void adaugare(vector<Flota_Auto*> &vec)
{
    system("cls");
    string tip;
    int id;
    cout << "ID vehicol:" <<endl;
    cin >> id;
    cin.ignore();
    cout <<"Introduceti tip vehicol : " << endl;
    getline(cin,tip);
    if(tip == "Serviciu")
    {
        string data_achizitie,data_itp,r,model;
        int capacitate;
        cout << " Data Achizitie :" << endl;
        getline(cin,data_achizitie);
        cout << " Data expirare ITP :" << endl;
        getline(cin,data_itp);
        cout << "Este Vehicolul folosit in flota?" << endl;
        getline(cin,r);
        bool folosit;
        if(r == "Da")
        {
            folosit = true;
        }
        else if(r == "Nu")
        {
            folosit = false;
        }
        cout << "Model vehicol:" << endl;
        getline(cin,model);
        cout << " Capacitate vehicol: " << endl;
        cin >> capacitate;
        cin.ignore();
        vec.push_back(new Auto_Serviciu(id,tip,data_achizitie,data_itp,folosit,model,capacitate));
    }
    else if(tip == "Camion")
    {
        string data_achizitie,data_itp,r,model;
        bool folosit;
        int capacitate;
        cout << " Data Achizitie :" << endl;
        getline(cin,data_achizitie);
        cout << " Data expirare ITP :" << endl;
        getline(cin,data_itp);
        cout << "Model vehicol:" << endl;
        getline(cin,model);
        cout << "Este Vehicolul folosit in flota?" << endl;
        getline(cin,r);
        if(r == "Da")
        {
            folosit = true;
        }
        else if(r == "Nu")
        {
            folosit = false;
        }
        cout << " Capacitate vehicol: " << endl;
        cin >> capacitate;
        cin.ignore();
        vec.push_back(new Auto_Camioane(id,tip,data_achizitie,data_itp,folosit,model,capacitate));
    }
    else if(tip == "Autobuz")
    {
        string data_achizitie,data_itp,r,model;
        bool folosit;
        int capacitate;
        cout << " Data Achizitie :" << endl;
        getline(cin,data_achizitie);
        cout << " Data expirare ITP :" << endl;
        getline(cin,data_itp);
        cout << "Este Vehicolul folosit in flota?" << endl;
        getline(cin,r);
        if(r == "Da")
        {
            folosit = true;
        }
        else if(r == "Nu")
        {
            folosit = false;
        }
        cout << "Model vehicol:" << endl;
        getline(cin,model);
        cout << "Capacitate vehicol: ";
        cin >> capacitate;
        cin.ignore();
        vec.push_back(new Auto_Autobuze(id,tip,data_achizitie,data_itp,folosit,model,capacitate));
    }
    else{
        cout << "Tipul de vehicol este invalid va rog incercati din nou" << endl;
    }
    rescriere(vec);
}

void casare(vector<Flota_Auto*> &vec)
{
    system("cls");
    int id;
    cout << "Introduceti Id-ul vehicolului de casat:";
    cin >> id;
    for(int i = 0; i < vec.size();++i)
    {
        if(vec[i]->getId() == id)
        {
            delete vec[i];
            vec.erase(vec.begin()+i);
            rescriere(vec);
            return;
        }
    }

}

void exp_itp(vector<Flota_Auto*> &vec)
{
    system("cls");
    time_t acum = time(0);
    tm* timp = localtime(&acum);
    int anc = timp->tm_year + 1900;
    int lunac = timp->tm_mon + 1;
    int zic = timp->tm_mday;
    struct data{
        int zi,an,luna;
    }d;
    bool ok = false;
    for(int i=0;i<vec.size();i++)
    {
        string s;
        s = vec[i]->getData_itp();
        stringstream fluxs(s);
        fluxs >> d.zi;
        fluxs.ignore();
        fluxs >> d.luna;
        fluxs.ignore();
        fluxs >> d.an;
        fluxs.ignore();
        if(anc == d.an && lunac == d.luna)
        {
            cout << "ITP expirat la masina cu ID-ul: ";
            cout << vec[i]->getId()<<endl;
            ok = true;
        }
    }
    if(ok == false)
        cout << "Nici un ITP expirat in flota" <<endl;
    system("pause");
}

void vechime(vector<Flota_Auto*> &vec)
{
    system("cls");
    cout << "Introduceti tipul vehicolului pentru generarea statisticii de vechime :" <<endl;
    string t;
    getline(cin,t);
    for(int i=0;i<vec.size();i++)
    {
        if(t == vec[i]->getTip())
        {
            time_t acum = time(0);
            tm* timp = localtime(&acum);
            int anc = timp->tm_year + 1900;
            int lunac = timp->tm_mon;
            int zic = timp->tm_mday;
            struct data{
                int zi,an,luna;
            }d;
            string s;
            s = vec[i]->getData_achizitie();
            stringstream fluxs(s);
            fluxs >> d.zi;
            fluxs.ignore();
            fluxs >> d.luna;
            fluxs.ignore();
            fluxs >> d.an;
            fluxs.ignore();
            cout << "Vechime vehicol(in ani) : " << anc - d.an <<" La id-ul: "<<vec[i]->getId()<< endl;
//        cout << "Vechime vehicol(in luni) : " << d.luna << endl;
//        cout << "Vechime vehicol(in zile) : " << zic - d.zi << endl;
        }
    }
    system("pause");
}

void nr_folosite(vector<Flota_Auto*> &vec)
{
    system("cls");
    int nr = 0;
    bool a;
    for(int i=0;i<vec.size();i++)
    {
        a = vec[i]->getFolosit();
        if(a == true)
            nr++;
    }
    cout << "Numarul de vehicole care nu sunt folosite: " << nr << endl;
    system("pause");
}
int main()
{
    vector<Flota_Auto*> vec;
    citire(vec);
    bool meniu = true;
    do
    {
        system("cls");
        cout << "1.Adaugare:\n2.Afisare Flota Auto\n3.Casare Vehicol\n4.Verificare ITP Vehicole\n5.Generare statistica vechime\n6.Numarul de vehicole care nu sunt folosite\n7.Inchidere Meniu\nIntroduceti operatia:";
        int op;
        cin >> op;
        cin.ignore();
        switch(op)
        {
            case 1:
            {
                adaugare(vec);
                break;
            }
            case 2:
            {
                afisare(vec);
                break;
            }
            case 3:
            {
                 casare(vec);
                 break;
            }
            case 4:
            {
                exp_itp(vec);
                break;
            }
            case 5:
            {
                vechime(vec);
                break;
            }
            case 6:
            {
                nr_folosite(vec);
                break;
            }
            case 7:
            {
                meniu = false;
                break;
            }
            default:
                cout << "Default" << endl;
        }

    }while(meniu);
    for(int i=0;i<vec.size();i++)
    {
        delete vec[i];
    }
    return 0;
}
