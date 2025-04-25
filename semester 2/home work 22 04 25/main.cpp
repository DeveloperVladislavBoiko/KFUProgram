#include <iostream>
#include "list.h"
using namespace std;

void show_list(list lst) {
	auto curr = lst.first;
	while (curr) {
		cout << curr->value << (curr->next ? " " : "");
		curr = curr->next;
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "");
	int n;
    cout<<"введите длину вашего списка"<<'\n';
    cin>>n;
	cout<<"введите элементы вашего списка"<<'\n';
    list lst;
	for (int i = 0; i < n; i++) {
        int vvod;
        cin>>vvod;
		push_back(lst, vvod);
	}
	cout<<"ваш список"<<'\n';
	show_list(lst);
	cout<<"введите индекс элемента вашего элемента указатель на который вы хотите передвинуть. Индексация с нуля"<<'\n';
    int index;
    cin>>index;
	while (index<0 || index>=n){
		cout<<"некоректный индекс введите другой"<<'\n';
		cin>>index;
	}
	cout<<"введите число позиций на сколько вы хотите сдвинуться назад можно отрицательные "<<'\n';
    int movement;
    cin>>movement;
	auto curr=elemGetIndex(lst,index);
	perem(curr,lst,movement);
	show_list(lst);
	clear(lst);
    return true;
}