#include "queue.h"
#include<fstream>
#include <iostream>
#include "queue.h"
#include<string>
using namespace std;
void enqueue(queue_elem*& first, queue_elem*& last, int x)
{
	auto new_el = new queue_elem;
	new_el->a = x;
	new_el->next = nullptr;
	new_el->prev = last;
	if (!first) first = new_el;
	else last->next = new_el;
	last = new_el;
}

void enqueue(queue& q, int x)
{
	enqueue(q.first, q.last, x);
}

bool dequeue(queue_elem*& first, queue_elem*& last, int& x)
{
	if (!first) return false;
	x = first->a;
	if (first->next) first->next->prev = nullptr;
	else last = nullptr;
	auto old_el = first;
	first = first->next;
	delete old_el;
	return true;
}

bool dequeue(queue& q, int& x)
{
	return dequeue(q.first, q.last, x);
}

void clear(queue& q)
{
	int x;
	while (dequeue(q, x));
}

bool vvod_queue(string file_name, queue&a, int& n){
	ifstream file;
	file.open(file_name);
	file>>n;
	if (n<0){
		return false;
	}
    for (int i=0;i<n;i++) {
        int value;
        file >> value;
        enqueue(a, value);
    }
	return true;
}

void split(queue& a1,queue& a2,queue& a3){
    int v1;
    int v2;
    bool flag1=true;
    bool flag2=true;
    while (flag1 or flag2){
        flag1=dequeue(a1,v1);
        flag2=dequeue(a2,v2);
        if (flag1){
            enqueue(a3,v1);
        }
        if (flag2){
            enqueue(a3,v2);
        }
    }
}