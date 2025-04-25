#pragma once
struct list_elem
{
	double value;
	list_elem* next = nullptr;
	list_elem* prev = nullptr;
};

struct list {
	list_elem* first = nullptr;
	list_elem* last  = nullptr;
};

void push_back(list& lst, double value);
bool remove(list& lst, double rem_value);
int remove_all(list& lst, double rem_value);
list_elem* elemGetIndex(list lst, int index);
void clear(list& lst);
bool perem(list_elem*&a , list& lst, int index);