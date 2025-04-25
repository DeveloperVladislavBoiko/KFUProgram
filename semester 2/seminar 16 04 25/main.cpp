#include <iostream>
#include "list.h"
#include<fstream>
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
    int N;
	ifstream f;
	f.open("sistem.txt");
	f>>N;
	if (!f){
		cout<<" файла нет"<<'\n';
		return 0;
	}
	if (f.eof()){
		cout<<" файл пуст"<<'\n';
		return 0;
	}
    cout<<"введите элементы вашего массива "<<'\n';
	double vals[] = {1,1,1,1,1,1};
	list lst;
	for (int i = 0; i < N; i++) {
        double n;
        f>>n;
        if (!is_in_list(lst, n)){
		    add(lst, n);
        }
	}
	f.close();
	cout << "'элементы множества'"<<'\n';
	show_list(lst);
	clear(lst);
    return 0;
}