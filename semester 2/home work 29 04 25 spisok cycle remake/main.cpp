#include <iostream>
#include "list.h"
#include<fstream>
using namespace std;



int main() {
	setlocale(LC_ALL, "");
	List* lst=nullptr;
	create_rand_list(lst,10);
	cout<<'\n';
	if(!Explanation_of_the_program_operation()){
		cout<<"ошибка чтения файла предупреждения, программа не может объяснить принцип работы, но она работает"<<'\n';
	}
	show_list(lst);
	cout<<"введите ваш элемент"<<'\n';
	int vvod;
	cin>>vvod;
	cycle_create(lst, vvod);
	List* cycle=chekcing_for_cycle(lst);
	if (cycle){
		cout<<"Ваш список циклический, введите количество выводов элементов списка перед пренудительной остановкой"<<'\n';
		int line;
		cin>>line;
		cout<<"Ваш список: "<<'\n';
		show_list(lst, line);
	}
	else{
		cout<<"Ваш список не циклический"<<'\n';
		cout<<"Ваш список: "<<'\n';
		show_list(lst);
	}
	clear(lst, cycle);
    return 0;
}