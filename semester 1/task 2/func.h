#pragma once
#include <iostream>
#include<string>
using namespace std;


struct stek_elem{
    string value;
    stek_elem *next;
};


void push(stek_elem*& top, string );
string pop (stek_elem*& top);








//                                            список(односвязный и двусвязный )
//                                           /
//                                 линейные <--- стек 
//                                /          \
//динамические структуры данных <             очередь - дек 
//                               \
//                               \
//                               \
//                               \
//                                 нелинейные <




// стек реализует способ LIFO  


// jxthtlm реализует способ FIFO 