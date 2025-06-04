#include <iostream>
#include "tree.h"
#include<cmath>
#include <algorithm>
#include"readFile.h"

using namespace std;

void show_tree(tree t, bypass_type type) {
    auto q = bypass(t, type);
    while (q.size() > 0) {
        auto curr = q.front();
        if (curr) {
            cout << curr->bal << "(" << curr->level << ") " 
                 << curr->name << " " << curr->familia;
        }
        else {
            cout << "-";
        }
        cout << " ";
        q.pop();
    }
    cout << endl;
}


void show_tree(tree t, bypass_type type, double bal) {
    auto q = bypass(t, type);
	bool flag=true;
    while (q.size() > 0) {
        auto curr = q.front();
        if (curr &&curr->bal>bal) {
            cout <<"Балл: ("<< curr->bal<<")" << " Уровень в дереве: (" << curr->level<<")"
			<< " Инициалы: (" << curr->name<<")" << " Фамилия: (" << curr->familia<<")"<<'\n';
			flag=false;
		}
        q.pop();
    }
	if (flag){
		cout<<"Нет подходящих значений"<<'\n';
	}
	else {
		cout << endl;	
	}
}




int main() {
    tree t;
	if (!load_tree_from_file(t, "fileSistem.txt")){
		cout<<"Ошибка открытия файла с данными. Файл не найден, либо пуст"<<'\n';
		return 0;
	}  
	double porog;
	cout<<"Введите число больше больше которого должен быть балл"<<'\n';
	cin>>porog;
	show_tree(t, wide,porog);
    drop_tree(t);
	return 0;
}
