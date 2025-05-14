#pragma once
#include <string>
using namespace std;

struct stack_elem {
	int value1;
    int value2;
	stack_elem* next;
};

void push(stack_elem*& top, int value1, int value2);
void replase(stack_elem*top,int sum);
void show_stack(stack_elem*top);
void clear(stack_elem*top);