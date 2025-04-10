#include <iostream>
#include"func.h"
using namespace std;

void push(stek_elem*& top, string value){
    stek_elem* new_el = new stek_elem;
    new_el->value=value;
    new_el->next=top;
    top=new_el;
}


string pop (stek_elem*& top){
    string result =top->value;
    auto old_el=top;
    top =top->next;
    delete old_el;
    return result;
}