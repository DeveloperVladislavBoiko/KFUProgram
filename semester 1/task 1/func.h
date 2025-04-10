#pragma onse
#include "iostream"
using namespace std;

struct Avtobus {
    char* familia=new char[30];
    char* gos_nomer=new char[30];
    int nomer_marhrut;
    char* name_ostanovki=new char[30];
};

void zapoln_standart (Avtobus& a){
    a.familia="фамилия не введена";
    a.gos_nomer="госномер не введен";
    a.name_ostanovki="имя остановки не введено";
    a.nomer_marhrut=-1;
}

void delete_pole_avtobus (Avtobus &a){
    delete[] a.familia;
    delete[] a.gos_nomer;
    delete[] a.name_ostanovki;
    a.familia=nullptr;
    a.gos_nomer=nullptr;
    a.name_ostanovki=nullptr;
}


void vvod_polzovatel(Avtobus &a){
    cin>>a.familia>>a.gos_nomer>>a.name_ostanovki>>a.nomer_marhrut;
}
    /*switch(index_vvod)
    {
        case 0:
        cin>>a.familia;
        break;

    case 1:
        cin>>a.gos_nomer;
        break;

    case 2:
        cin>>a.name_ostanovki;
        break;

    case 3:
        cin>>a.nomer_marhrut;
        break;
    }*/
