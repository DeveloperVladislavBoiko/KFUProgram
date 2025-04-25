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
    int N=5;
    int k;
    cin>>k;
    cout<<"введите элементы вашего массива "<<'\n';
	double vals[] = {1,1,1,1,1,1};
	list lst;
	for (int i = 0; i < N; i++) {
		add(lst, vals[i]);
    }
	cout << "'элементы множества'"<<'\n';
	//perem(lst,)
	show_list(lst);
    clear(lst);
	return 0;
}