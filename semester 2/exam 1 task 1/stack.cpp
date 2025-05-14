#include "stack.h"
#include<iostream>
using namespace std;
void push(stack_elem*& top, int value1, int value2)
{
	stack_elem* new_el = new stack_elem;
	new_el->value1 = value1;
    new_el->value2 = value2;
	new_el->next = top;
	top = new_el;
}


void replase(stack_elem*top,int sum){
    auto curr=top;
    while(curr){
        if ((curr->value1+curr->value2)==sum){
            curr->value1=0;
            curr->value2=0;
        }
        curr=curr->next;
    }
}

void show_stack(stack_elem*top){
    auto curr=top;
    while(curr){
        cout<<curr->value1<<' '<<curr->value2<<'\n';
        curr=curr->next;
    }
}
void clear(stack_elem*top){
    auto curr=top;
    while(curr){
        auto old=curr;
        curr=curr->next;
        delete old;
    }
}
