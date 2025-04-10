#include "iostream"
#include"func.h"
using namespace std;
int main (){
    setlocale(LC_ALL,"");
    cout<<"Введите количество автобусов"<<'\n';
    int n;
    cin>>n;
    Avtobus mas [n];
    for (int i=0;i<n;i++){
        cout<<"Введите ваши данные через пробел в фармате 1) фамилия водителя 2) госномер водителя 3) название остановки 4) номер остановки пример  Иванов Е878РС186  петухово 1245"<<'\n';
        vvod_polzovatel(mas[i]);
    }
    for (int i=0;i<n;i++){
        delete_pole_avtobus(mas[i]);
    }
    //delete_pole_avtobus(a);
    return 0;
}