#include<iostream>
#include <fstream>

using namespace std;
struct list_elem{
	string name;
	string pol;
	list_elem* next = nullptr;
};

void add(list_elem*& list, string value, string pol){
	auto new_el = new list_elem;
	new_el->name = value;
	new_el->pol=pol;
	list_elem* curr = list;
	while (curr && curr->next) {
		curr = curr->next;
	}
	if (curr) curr->next = new_el;
	else list = new_el;
}


int count(const list_elem* list){
	if (!list) return 0;
	auto curr = list;
	int i = 1;
	while (curr->next) {
		curr = curr->next;
		i++;
	}
	return i;
}

bool insert(list_elem*& list, string value, int position){
	if (position < 0 || position > count(list)) return false;
	auto new_el = new list_elem;
	new_el->name = value;
	if (position == 0) {
		new_el->next = list;
		list = new_el;
		return true;
	}
	auto curr = list;
	auto i = 1;
	while (i++ < position && curr->next) {
		curr = curr->next;
	}
	new_el->next = curr->next;
	curr->next = new_el;
	return true;
}


bool get(const list_elem* list, int position, string& result){
	if (position < 0 || position >= count(list)) return false;
	if (position == 0) {
		result = list->name;
		return true;
	}
	auto curr = list->next;
	auto i = 1;
	while (i++ < position && curr->next) {
		curr = curr->next;
	}
	result = curr->name;
	return true;
}

bool remove(list_elem*& list, int position)
{
	if (position < 0 || position >= count(list)) return false;
	if (position == 0) {
		auto old = list;
		list = list->next;
		delete old;
		return true;
	}
	auto curr = list;
	auto i = 0;
	while (++i < position && curr->next) {
		curr = curr->next;
	}
	auto old = curr->next;
	if (curr->next) curr->next = curr->next->next;
	delete old;
	return true;
}

void clear(list_elem*& list)
{
	auto curr = list;
	while (curr) {
		auto rem = curr;
		curr = curr->next;
		delete rem;
	}
	list = nullptr;
}

void show_list(list_elem* lst) {
	auto curr = lst;
	while (curr) {
		cout  << curr->name << ' '<<curr->pol<< endl;
		curr = curr->next;
	}
	cout << endl;
}

void razdel(list_elem* lst, list_elem*& list_m, list_elem*& list_g){
	auto curr = lst;
	while (curr) {
		if(curr->pol=="м"){
			add(list_m, curr->name, curr->pol);
		}
		if(curr->pol=="ж"){
			add(list_g, curr->name, curr->pol);
		}
		curr = curr->next;
	}
	cout << endl;
}

void sort (list_elem*a){
	auto curri = a;
	while(curri&& curri->next){
		auto currj=a;
		while(currj && currj->next){
			if(currj->name>currj->next->name){
				string old=currj->name;
				currj->name=currj->next->name;
				currj->next->name=old;
			}
			currj = currj->next;
		}
		curri=curri->next;
	}
}


int main() {
	setlocale(LC_ALL, "");
	ifstream f("sistem.txt");
	if (f) {
		list_elem* general_list = nullptr;
		while (!f.eof()) {
			string name;
			string pol;
			f >> name >> pol;
			add(general_list, name,pol);
		}
		f.close();
		list_elem* m=nullptr;
		list_elem* g=nullptr;
		razdel(general_list,m,g);
		clear(general_list);
		sort(m);
		sort(g);
		cout<<"мужчины:"<<'\n';
		show_list(m);
		cout<<"женчины:"<<'\n';
		show_list(g);
	}
	else {
		cout << "ошибка открытия файла" << endl;
	}
	return 0;
}
