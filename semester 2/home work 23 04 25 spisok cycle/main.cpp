#include <iostream>
#include "list.h"
using namespace std;

void show_cycle (int number_show,list_elem*first,list_elem*last){
    cout<<"Количеcтво выводов циклической части "<<number_show<<'\n';
    for (int i=0;i<number_show;i++){
        auto curr=first;
        while (curr!=last){
            cout<<curr->value<<' ';
            curr=curr->next;
        }
        cout<<curr->value<<' ';
		cout<<'\n';
    }
}


void show_list_no_pos(list lst) {
	auto curr = lst.first;
	while (curr) {
		cout << curr->value << (curr->next ? " " : "");
		curr = curr->next;
	}
	cout << endl;
}

void show_list(list lst) {
	auto curr = lst.first;
	if (lst.last->next==lst.last){
		cout<<"Цикл на последнем элементе: "<<lst.last->value<<'\n';
		return;
	}
	while (curr) {
		cout << curr->value << (curr->next ? " " : "");
        if (!curr->next){
			cout<<'\n';
            cout<<"Далее список заканчивается. Далее нечего нет"<<'\n';
            return;
        }
        if (curr->number_of_visits<curr->next->number_of_visits){
			cout<<'\n';
            cout<<"Далее начинается цикл в списке"<<'\n';
			cout<<"от "<<lst.last->next->value<<" до "<<curr->value<<'\n';
			show_cycle(500,lst.last->next,curr);
            return;
        }
		curr->number_of_visits++;
		curr = curr->next;
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "");
	list lst;
	add_rand_h(lst,6);
	cout<<"Сейчас будет выведен список из чисел если хотите зациклить список, \n";
	cout<<"то введите значение элемента на который будет ссылаться последний, \n";
	cout<<"если список не циклический то введите любое другое число"<<'\n';
	cout<<"Важная ремарка, если таких элементов несколько, то ссылаться будут на последний"<<'\n';
	show_list_no_pos(lst);
	cout<<"введите ваш элемент"<<'\n';
	int vvod;
	cin>>vvod;
	cycle_create(lst, vvod);
	cout<<"Список:"<<'\n';
	show_list(lst);
	clear(lst);
    return 0;
}