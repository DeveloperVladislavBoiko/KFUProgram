#include <iostream>
#include "queue.h"
#include<string>
using namespace std;
void show_queue(queue& q) {
	int value;
	while (dequeue(q, value)) {
		cout << value << " ";
	}
	cout << endl;
}
int main() {
    queue a1;
    int n1;
    //cout<<"введите длину первой очереди"<<'\n';
    //cin>>n1;
    if(!vvod_queue("file1.txt", a1, n1)){
        cout<<"В файле указан не коректный размер очереди (<0), программа не работает"<<'\n';
        return 0;
    }
    queue a2;
    int n2;
    //cout<<"введите длину второй очереди"<<'\n';
    //cin>>n2;
    if(!vvod_queue("file2.txt", a2,n2)){
        cout<<"В файле указан не коректный размер очереди (<0), программа не работает"<<'\n';
        return 0;
    }
    queue a3;
    split(a1,a2,a3);
    if (n1 or n2 ){
        cout<<"новая очередь"<<'\n';
        show_queue(a3);
    }
    else {
        cout<<"новая очередь пуста"<<'\n';
    }
    clear(a3);
    return 0;
}