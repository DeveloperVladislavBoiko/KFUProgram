
#include "list.h"
#include <math.h>
#include<random>
#include<iostream>
#include<vector>
using namespace std;


void add(List*& list, int value)
{
	auto new_el = new List;
	new_el->value = value;
	List* curr = list;
	while (curr && curr->next) {
		curr = curr->next;
	}
	if (curr) curr->next = new_el;
	else list = new_el;
}

bool insert(List*& list, int value, int position)
{
	if (position < 0 || position > count(list)) return false;
	auto new_el = new List;
	new_el->value = value;
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

bool get(const List* list, int position, int& result)
{
	if (position < 0 || position >= count(list)) return false;
	if (position == 0) {
		result = list->value;
		return true;
	}
	auto curr = list->next;
	auto i = 1;
	while (i++ < position && curr->next) {
		curr = curr->next;
	}
	result = curr->value;
	return true;
}

int count(const List* list)
{
	if (!list) return 0;
	auto curr = list;
	int i = 1;
	while (curr->next) {
		curr = curr->next;
		i++;
	}
	return i;
}

bool remove(List*& list, int position)
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


List* chekcing_for_cycle(List*& list)
{
	if (!list){
		return nullptr;
	}
	auto curr_normal=list;
	auto curr_speed=list->next;
	while (curr_normal!=curr_speed && curr_speed!=nullptr){
		curr_normal=curr_normal->next;
		if (!curr_speed->next){
			break;
		}
		curr_speed=curr_speed->next->next;
	}
	if (!curr_speed || !curr_speed->next){/////список не циклический
		return nullptr;
	}
	return curr_normal;
}

void clear_not_cycle(List*& list){
	auto curr=list;
	while (curr){
		auto prev=curr;
		curr=curr->next;
		delete prev;
	}
}

void clear (List*& list, List*& cycle){
	if (!list){
		return;
	}
	if(cycle){
		vector<List*>delete_elem={cycle};
		auto curr=cycle;
		while (curr!=curr->next){//элементы циклической части записываем в вектор, не удаляем, иначе на следующем шаге (цикле) будет двойное удаление одного фрагмента памяти
			auto del=curr->next;
			curr->next=curr->next->next;
			del->next=nullptr;
			delete_elem.push_back(del);
		}
		curr->next=nullptr;///для случая когда цикл на последнем элементе, остальным случаям он не вредит
		curr=list;
		while (curr){
			if (!curr->next){
				break;
			}
			else {
				auto prev=curr;
				curr=curr->next;
				delete prev;
			}
		}
		for (auto i:delete_elem){
			delete i;
		}
	}
	else {
		clear_not_cycle(list);
	}
}

void create_rand_list(List*& list, int line)
{
	srand(time(nullptr));
	int chet=0;
	if (!list){
		auto new_el = new List;
    	new_el->value = rand()%100;
		list=new_el;
		chet++;
	}
	List* curr = list;
	while (curr && curr->next) {
		curr = curr->next;
	}
	for (int i=0;i<line-chet;i++){
        auto new_el = new List;
    	new_el->value = rand()%100;
    	curr->next=new_el;
		curr=curr->next;    
    }
}


void show_list(List* list)
{
	auto curr = list;
	while (curr) {
		cout<<(curr->value)<<' ';
		curr = curr->next;
	}
	cout<<'\n';
}


void show_list(List* list, int line)
{
	int chet=0;
	auto curr = list;
	while (curr and (chet<line)) {
		cout<<(curr->value)<<' ';
		curr = curr->next;
		chet++;
	}
	cout<<'\n';
}

void cycle_create( List*& lst, int elem_cycle) {
	auto curr = lst;
	List* cycle=nullptr;
	while (curr->next) {
		if (curr->value==elem_cycle){
			cycle=curr;
		}
		curr = curr->next;
	}
	if (curr->value==elem_cycle){
		cycle=curr;
	}
	curr->next=cycle;
}


bool Explanation_of_the_program_operation() {
	ifstream explanation_of_the_program_operation;
	explanation_of_the_program_operation.open("sistem_explanation.txt");
	if (explanation_of_the_program_operation.is_open()){
		while (explanation_of_the_program_operation){
			string str;
			getline(explanation_of_the_program_operation,str);
			cout<<str<<'\n';
		}
		explanation_of_the_program_operation.close();
		return true;
	}
	return false;
}