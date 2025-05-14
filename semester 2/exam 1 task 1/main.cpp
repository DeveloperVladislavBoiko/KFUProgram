#include <iostream>
#include <sstream>
#include "stack.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	stack_elem* stack = nullptr;
	int n;
    cout<<"Введите размер вашего стека"<<'\n';
    cin>>n;
    while (n<=0){
        cout<<"размер не коректный, введите другой"<<'\n';
        cin>>n;
    }
    cout<<"Введите пары элементов вашего стека"<<'\n';
    for (int i=0;i<n;i++){
        int v1,v2;
        cin>>v1>>v2;
        push(stack,v1,v2);
    }
    int sum;
    cout<<"Введите значение, которое не должно быть суммой"<<'\n';
    cin>>sum;
    replase(stack,sum);
    show_stack(stack);
    clear(stack);
    return 0;
}