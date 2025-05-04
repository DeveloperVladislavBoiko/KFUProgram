
#pragma once
#include<iostream>
#include <string>
#include<fstream>
using namespace std;

struct List
{
	int value;
	List* next = nullptr;
};


void add(List*& list, int value);
bool insert(List*& list, int value, int position);
bool get(const List* list, int position, int& result);
int count(const List* list);
bool remove(List*& list, int position);
List* chekcing_for_cycle(List*& list);
void clear_not_cycle(List*&list);
void create_rand_list(List*& lst,int line);
void show_list(List* list);
void show_list(List* list, int line);
void cycle_create( List*& lst, int elem_cycle);
void clear (List*& list, List*& cycle);


bool Explanation_of_the_program_operation();