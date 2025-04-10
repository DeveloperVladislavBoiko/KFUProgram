#include <iostream>
#include"func.h"
#include<string>
#include<sstream>
using namespace std;
int main (){
    setlocale(LC_ALL,"");
    stek_elem* stack1=nullptr;
    string s("Работаем со стеком и строками наконец то");
    stringstream ss(s);
    string word;
    while (ss>>word){
        push(stack1, word);
    }
    while (stack1){
        cout<<pop(stack1);
    }
    return 0;
}