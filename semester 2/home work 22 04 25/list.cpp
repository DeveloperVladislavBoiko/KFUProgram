#include "list.h"
#include <math.h>
#include <iostream>
#define EPS 1e-15

using namespace std;


void add(list_elem*& first, list_elem*& last, double value) {
	auto new_el = new list_elem;
	new_el->value = value;
	if (!first) {
		first = last = new_el;
		return;
	}
	new_el->prev = last;
    last->next=new_el;
    last=new_el;
}

void push_back(list& lst, double value)
{
	add(lst.first, lst.last, value);
}

bool remove(list_elem*& first, list_elem*& last, double rem_value) {
	if (!first || rem_value < first->value || rem_value > last->value)
		return false;
	if (fabs(first->value - rem_value) < EPS) {
		if (first->next) first->next->prev = nullptr;
		auto rem = first;
		first = first->next;
		if (!first) last = first;
		delete rem;
		return true;
	}
	if (fabs(last->value - rem_value) < EPS) {
		last->prev->next = nullptr;
		auto rem = last;
		last = last->prev;
		delete rem;
		return true;
	}
	auto curr = first->next;
	while (curr && fabs(curr->value - rem_value) > EPS) {
		curr = curr->next;
	}
	if (curr) {
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		delete curr;
	}
    return true;
}

bool remove(list& lst, double rem_value)
{
	return remove(lst.first, lst.last, rem_value);
}

int remove_all(list_elem*& first, list_elem*& last, double rem_value) {
	int i = 0;
	if (!first || rem_value < first->value || rem_value > last->value)
		return i;
	while (fabs(first->value - rem_value) < EPS) {
		if (first->next) first->next->prev = nullptr;
		auto rem = first;
		first = first->next;
		if (!first) last = first;
		delete rem;
		i++;
	}
	if (i > 0) return i;
	while (fabs(last->value - rem_value) < EPS) {
		last->prev->next = nullptr;
		auto rem = last;
		last = last->prev;
		delete rem;
		i++;
	}
	if (i > 0) return i;
	auto curr = first->next;
	while (curr && fabs(curr->value - rem_value) > EPS) {
		curr = curr->next;
	}
	while (curr && fabs(curr->value - rem_value) < EPS) {
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		auto rem = curr;
		curr = curr->next;
		delete rem;
		i++;
	}
	return i;
}

int remove_all(list& lst, double rem_value)
{
	return remove_all(lst.first, lst.last, rem_value);
}

bool perem_positive(list_elem*&a ,list_elem*& first , list_elem*& last, int  index){
	auto curr =a;
	if (!curr){
		return false;
	}
	while (curr->prev && index){
		curr=curr->prev;
		index--;
	}
	auto old=a;
	if (old->next)old->next->prev=old->prev;
	if (old->prev)old->prev->next=old->next;
	if (curr->prev){
		curr->prev->next=a;
		a->prev=curr->prev;
		a->next=curr;
		curr->prev=a;
		
	}else{
			first->prev=a;
			a->next=first;
			first=a;
			//first->next=nullptr;
	}
	return true;
}

bool perem_negative(list_elem*&a ,list_elem*& first , list_elem*& last, int  index){
	auto curr =a;
	index=-index;
	if (!curr){
		return false;
	}
	while (curr->next && index){
		curr=curr->next;
		index--;
	}
	auto old=a;
	if (old->next)old->next->prev=old->prev;
	if (old->prev)old->prev->next=old->next;
	if (curr->next){
		curr->next->prev=a;
		a->next=curr->next;
		a->prev=curr;
		curr->next=a;		
	}
	else{
			a->next=nullptr;
			last->next=a;
			a->prev=last;
			last=a;
	}
	return true;
}

bool perem(list_elem*&a , list& lst, int index){
	if (index>0){
		return perem_positive(a,lst.first, lst.last, index);
	}
	if (index<0){
		return perem_negative(a,lst.first, lst.last, index);
	}
	return a;//возвращаем true, если элемент есть, false если его нет
}

list_elem* elemGetIndex(list lst, int index){
	auto curr=lst.first;
	for (int i=0;i<index;i++){
		if(curr->next)curr=curr->next;
		else break;
	}
	return curr;
}


void clear(list& lst)
{
	auto curr = lst.first;
	while (curr) {
		auto rem = curr;
		curr = curr->next;
		delete rem;
	}
	lst.first = nullptr;
	lst.last = nullptr;
}