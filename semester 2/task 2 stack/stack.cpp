#include <iostream>
#include <string>
#include "stack.h"
using namespace std;


void push(stack_elem*& top, char value, int index)
{
	stack_elem* new_el = new stack_elem;
	new_el->value = value;
	new_el->next = top;
	new_el->index=index;
	top = new_el;
}

char pop(stack_elem*& top)
{
	char result = top->value;
	auto old_el = top;
	top = top->next;
	delete old_el;
	return result;
}

char reverse_staples(char a){
	switch (a)
	{
	case ')':
		return '(';
	case ']':
		return '[';
	case '}':
		return '{';
	case '>':
		return '<';
	default:
		return -1;
	}
}

int search_staples(const string& input, int& index1, int&index2) {
	index1=-1;
	index2=-1;
	int index_proh;
    stack_elem * stack_open=nullptr;
	for (int i=0;i<input.size();i++) {
		char ch=input[i];
        if (ch == '('  || ch == '{' || ch == '[' || ch=='<') {
            push(stack_open, ch,i);
			index_proh=i;
        }
		if (ch == ')'  || ch == '}' || ch == ']' || ch=='>') {
			if (stack_open){
				char sim=pop(stack_open);
            	if (not(sim==reverse_staples(ch))){
					index1=index_proh;
					index2=i;
					return -1;
				}
			}
			else {
				index1=i;
				return -2;
			}
        }
    }
	if (!stack_open) {
		return 1; 
	}
	else {
		index1=stack_open->index;
		return 0;
	};
}
