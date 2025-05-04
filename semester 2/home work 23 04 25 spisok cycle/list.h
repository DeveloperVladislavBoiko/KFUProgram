#pragma once
#include<iostream>
using namespace std;


struct list_elem
{
	double value;
    int number_of_visits=0;
	list_elem* next = nullptr;
	list_elem* prev = nullptr;
};

struct list {
	list_elem* first = nullptr;
	list_elem* last  = nullptr;
};


void add(list& lst, double value);
bool remove(list& lst, double rem_value);
int remove_all(list& lst, double rem_value);
bool is_in_list(list lst, double value);
void clear(list& lst);
void add_rand_h(list& lst,int line);
void cycle_create(list lst, int elem_cycle);

