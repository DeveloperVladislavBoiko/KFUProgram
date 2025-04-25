#pragma once
#include<iostream>
using namespace std;


struct list_elem
{
	double value;
	list_elem* next = nullptr;
	list_elem* prev = nullptr;
    int number_visit=0;
};

struct list {
	list_elem* first = nullptr;
	list_elem* last  = nullptr;
};

void show_list(list lst) {
	auto curr = lst.first;
	while (curr) {
		cout << curr->value << (curr->next ? " " : "");
		curr = curr->next;
	}
	cout << endl;
}

void addWithoutVisibility(list& lst, double value);
bool remove(list& lst, double rem_value);
int remove_all(list& lst, double rem_value);
bool is_in_list(list lst, double value);
void clear(list& lst);
void add(list_elem*& first, list_elem*& last, double value);
void add(list& lst, double value);