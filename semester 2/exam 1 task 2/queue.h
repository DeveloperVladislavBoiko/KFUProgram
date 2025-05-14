#pragma once
#include <iostream>
#include<string>
using namespace std;
struct queue_elem {
	int a;
	queue_elem* next;
	queue_elem* prev;
};

struct queue {
	queue_elem* first = nullptr;
	queue_elem* last = nullptr;
};

//void enqueue(queue_elem*& first, queue_elem*& last, int x);
void enqueue(queue& q, int x);
//bool dequeue(queue_elem*& first, queue_elem*& last, int& x);
bool dequeue(queue& q, int& x);
void clear(queue& q);
bool vvod_queue(string file_name, queue&a, int&n);
void split(queue& a1,queue& a2,queue& a3);