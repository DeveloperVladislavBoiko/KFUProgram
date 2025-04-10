#pragma once
#include <string>
using namespace std;


struct stack_elem {
	char value;
	int index=-1;
	stack_elem* next;
};

void push(stack_elem*& top, char value, int index);
char pop(stack_elem*& top);
char reverse_staples(char a);
int search_staples(const string& input, int& index1, int&index2);